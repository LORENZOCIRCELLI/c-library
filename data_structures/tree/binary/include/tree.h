#ifndef TREE_H
#define TREE_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;
typedef double f64;

typedef struct Treenode Treenode;

Treenode *createNode(i32 data);

Treenode *insert(Treenode *root, i32 data);
Treenode *deleteNode(Treenode *root, i32 data);

void inorder(Treenode *root);
void postorder(Treenode *root);
void preorder(Treenode *root);

Treenode *search(Treenode *root, i32 data);
Treenode *getDeepestRightmostNode(Treenode *root);
Treenode *findMin(Treenode *root);

#endif
