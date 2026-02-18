#include "../include/Queue.h"
#include <stdio.h>
#include <stdlib.h>

struct Node {
  Node *next;
  int data;
};

struct Queue {
  Node *tail;
  Node *head;
  u32 size;
};

Queue *init_queue(void) {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  if (!queue) {
    printf("Error: failure in queue memory allocation!\n");
    return NULL;
  }
  queue->head = NULL;
  queue->tail = NULL;
  queue->size = 0;
  return queue;
}

bool enqueue(Queue *queue, i32 data) {

  if (!queue) {
    printf("Error: the queue don't exist!\n");
    return 0;
  }

  Node *node = (Node *)malloc(sizeof(Node));

  if (!node) {
    printf("Error: failure in node memory allocation!\n");
    return 0;
  }
  node->data = data;
  node->next = NULL;
  if (queue->size == 0) {
    queue->head = node;
    queue->tail = node;
    queue->size++;
    return 1;
  }
  queue->tail->next = node;
  queue->tail = node;
  queue->size++;
  return queue;
}

bool dequeue(Queue *queue) {
  if (!queue) {
    printf("Error: the queue don't exist!\n");
    return 0;
  }
  Node *temp = queue->head;
  queue->head = queue->head->next;
  free(temp);
  return 1;
}

Node *peek(Queue *queue) {
  if (!queue) {
    printf("Error: the queue don't exist!\n");
    return NULL;
  }
  return queue->head;
}

bool destroy(Queue *queue) {
  if (!queue) {
    printf("Error: the queue don't exist!\n");
    return 0;
  }
  Node *curr = queue->head;
  while (curr) {
    Node *temp = curr;
    curr = curr->next;
    free(temp);
  }
  free(queue);
  return 1;
}
