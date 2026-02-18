#include "../include/stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  i32 data;
  Node *next;
};

struct Stack {
  Node *top;
  u32 size;
};

Stack *initialize_stack(void) {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  if (!stack) {
    printf("Error: failure in stack memory allocation!\n");
    return NULL;
  }
  stack->top = NULL;
  stack->size = 0;
  return stack;
}

bool isEmpty(Stack *stack) {
  if (!stack) {
    printf("Error: stack don't exist!\n");
    return -1;
  }
  return stack->size == 0;
}

bool push(Stack *stack, i32 data) {
  if (!stack) {
    printf("Error: stack don't exist!\n");
    return 0;
  }
  Node *node = (Node *)malloc(sizeof(Node));
  if (!node) {
    printf("Error: failure in node memory allocation!\n");
    return 0;
  }
  node->data = data;
  node->next = stack->top;
  stack->top = node;
  stack->size++;
  return 1;
}

bool pop(Stack *stack) {
  if (!stack) {
    printf("Error: stack don't exist!\n");
    return 0;
  }
  Node *temp = stack->top;
  stack->top = temp->next;
  stack->size--;
  free(temp);
  return 1;
}

Node *peek(Stack *stack) {
  if (!stack) {
    printf("Error: stack don't exist!\n");
    return 0;
  }

  return stack->top;
}

bool clear(Stack *stack) {
  if (!stack) {
    printf("Error: stack don't exist!\n");
    return 0;
  }
  Node *curr = stack->top;
  while (curr) {
    Node *temp = curr;
    curr = curr->next;
    free(temp);
  }
  free(stack);
  return 1;
}
