#include "../include/Deque.h"
#include <stdio.h>
#include <stdlib.h>

struct Node {
  i32 data;
  Node *next;
  Node *prev;
};

struct Deque {
  Node *head;
  Node *tail;
  u32 size;
};

Deque *initialize_deque(void) {
  Deque *deque = (Deque *)malloc(sizeof(Deque));
  if (!deque) {
    printf("Error: failure in deque memory allocation!\n");
    return NULL;
  }
  deque->head = NULL;
  deque->tail = NULL;
  deque->size = 0;
  return deque;
}

u32 is_empty(Deque *deque) {
  if (!deque) {
    printf("Error: the deque don't exist!\n");
    return 0;
  }
  return deque->size == 0;
}

bool push_front(Deque *deque, i32 data) {
  if (!deque) {
    printf("Error: the deque don't exist!\n");
    return 0;
  }
  Node *node = (Node *)malloc(sizeof(Node));
  if (!deque) {
    printf("Error: failure in deque memory allocation!\n");
    return NULL;
  }
  node->data = data;
  node->prev = NULL;
  node->next = NULL;

  if (deque->size == 0) {
    deque->head = node;
    deque->tail = node;
    deque->size++;
    return 1;
  }

  node->next = deque->head;
  deque->head->prev = node;
  deque->head = node;
  deque->size++;
  return 1;
}

bool push_back(Deque *deque, i32 data) {
  if (!deque) {
    printf("Error: the deque don't exist!\n");
    return 0;
  }
  Node *node = (Node *)malloc(sizeof(Node));
  if (!deque) {
    printf("Error: failure in deque memory allocation!\n");
    return NULL;
  }
  node->data = data;
  node->prev = NULL;
  node->next = NULL;

  if (deque->size == 0) {
    deque->head = node;
    deque->tail = node;
    deque->size++;
    return 1;
  }
  node->prev = deque->tail;
  deque->tail->next = node;
  deque->size++;
  return 1;
}

bool pop_front(Deque *deque) {
  if (!deque) {
    printf("Error: the deque don't exist!\n");
    return 0;
  }
  Node *temp = deque->head;
  deque->head = deque->head->next;

  if (deque->head) {
    deque->head->prev = NULL;
  } else {
    deque->tail = NULL;
  }
  free(temp);
  deque->size--;
  return 1;
}

bool pop_back(Deque *deque) {
  if (!deque) {
    printf("Error: the deque don't exist!\n");
    return 0;
  }
  Node *temp = deque->tail;
  deque->tail = deque->tail->prev;

  if (deque->tail) {
    deque->tail->next = NULL;
  } else {
    deque->head = NULL;
  }

  free(temp);
  return 1;
}

Node *get_front(Deque *deque) {
  if (!deque) {
    printf("Error: the deque don't exist!\n");
    return 0;
  }
  return deque->head;
}

Node *get_back(Deque *deque) {
  if (!deque) {
    printf("Error: the deque don't exist!\n");
    return 0;
  }
  return deque->tail;
}

bool destroy(Deque *deque) {
  if (!deque) {
    printf("Error: the deque don't exist!\n");
    return 0;
  }
  Node *curr = deque->head;
  while (curr) {
    Node *temp = curr;
    curr = curr->next;
    free(curr);
  }
  free(deque);
  return 1;
}
