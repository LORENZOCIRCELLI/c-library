#include "../include/tree.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int main(void) {
  Treenode *root = NULL;
  root = insert(root, 8);
  root = insert(root, 13);
  root = insert(root, 3);
  root = insert(root, 6);
  root = insert(root, 21);
  root = insert(root, 6);
  root = insert(root, 9);
  root = insert(root, 10);
  root = insert(root, 5);

  printf("Inorder: ");
  inorder(root);

  Treenode *result = search(root, 6);

  if (result) {
    printf("Found!\n");
  } else {
    printf("Not found!\n");
  }
  root = deleteNode(root, 3);

  printf("After deletion:");
  inorder(root);
  return 0;
}
