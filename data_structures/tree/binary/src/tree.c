#include "../include/tree.h"
#include <corecrt_search.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Treenode {
  int data;
  Treenode *left;
  Treenode *right;
};

Treenode *createNode(int data) {
  Treenode *node = (Treenode *)malloc(sizeof(Treenode));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

bool insert(Treenode **root, int data) {

  Treenode *node = createNode(data);
  if (*root == NULL) {
    *root = node;
    return 1;
  }

  Treenode *temp;
  Treenode *queue[100];
  i32 front = -1, rear = -1;

  queue[++rear] = *root;

  while (front != rear) {
    temp = queue[++front];
    if (temp->left == NULL) {
      temp->left = node;
      return 1;
    } else {
      queue[++rear] = temp->left;
    }
    if (temp->right == NULL) {
      temp->right = node;
      return 1;
    } else {
      queue[++rear] = temp->right;
    }
  }
  return 0;
}

Treenode *getDeepestRightmostNode(Treenode *root) {
  Treenode *temp;
  Treenode *queue[100];
  int front = -1, rear = -1;
  queue[++rear] = root;
  while (front != rear) {
    temp = queue[++front];

    if (temp->left != NULL) {
      queue[++rear] = temp->left;
    }
    if (temp->right != NULL) {
      queue[++rear] = temp->right;
    }
  }
  return temp;
}

bool inorderTraversal(Treenode *root) {
  if (root == NULL) {
    return 0;
  }
  inorderTraversal(root->left);
  printf("%d ", root->data);
  inorderTraversal(root->right);
  return 1;
}
