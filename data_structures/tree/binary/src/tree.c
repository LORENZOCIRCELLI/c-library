#include "../include/tree.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Treenode {
  i32 data;
  Treenode *left;
  Treenode *right;
};

Treenode *createNode(i32 data) {
  Treenode *node = (Treenode *)malloc(sizeof(Treenode));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

Treenode *insert(Treenode *root, i32 data) {

  Treenode *node = createNode(data);

  if (node == NULL) {
    printf("Error: Fail in node memory allocation!\n");
    return 0;
  }

  if (root == NULL) {
    return createNode(data);
  }

  if (data < root->data) {
    root->left = insert(root->left, data);
  }

  if (data > root->data) {
    root->right = insert(root->right, data);
  }

  return root;
}

Treenode *search(Treenode *root, i32 data) {
  if (root == NULL || root->data == data) {
    return root;
  }
  if (data < root->data) {
    return search(root->left, data);
  }
  return search(root->right, data);
}

void inorder(Treenode *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

void postorder(Treenode *root) {
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
  }
}

void preorder(Treenode *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

Treenode *deleteNode(Treenode *root, i32 data) {
  if (root == NULL) {
    return root;
  }

  if (data < root->data) {
    root->left = deleteNode(root->left, data);
  } else if (data > root->data) {
    root->right = deleteNode(root->right, data);
  } else {
    if (root->left == NULL) {
      Treenode *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      Treenode *temp = root->left;
      free(root);
      return temp;
    }

    Treenode *temp = findMin(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

Treenode *findMin(Treenode *root) {
  while (root->left != NULL) {
    root = root->left;
  }
  return root;
}
