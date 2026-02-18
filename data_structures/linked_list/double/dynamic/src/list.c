#include "../include/list.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  void *data;
  Node *next;
  Node *prev;
};

struct List {
  Node *head;
  u32 size;
};

List *initialize_list(void) {
  List *list = (List *)malloc(sizeof(List));
  if (list == NULL) {
    printf("Error: failure in list memory allocation!\n");
    return NULL;
  }
  list->head = NULL;
  list->size = 0;
  return list;
}

bool is_empty(List *list) {
  if (!list) {
    printf("Error: list isn't initialized!\n");
    return 0;
  }
  return list->size == 0;
}

u32 list_size(List *list) {
  if (!list) {
    printf("Error: list isn't initialized\n");
    return 0;
  }
  return list->size;
}

Node *create_node(void *data) {
  Node *node = (Node *)malloc(sizeof(Node));
  if (!node) {
    printf("Error: failure in node memory allocation!\n");
    return NULL;
  }
  node->data = data;
  node->next = NULL;
  return node;
}

bool insert_node_beggining(List *list, void *data) {
  if (!list) {
    printf("Error: list isn't initialized\n");
    return 0;
  }

  Node *node = create_node(data);
  if (!node) {
    return 0;
  }
  if (is_empty(list)) {
    list->head = node;
    list->size++;
    return 1;
  }
  list->head->prev = node;
  node->next = list->head;
  list->head = node;
  list->size++;
  return 1;
}

bool insert_node_end(List *list, void *data) {
  if (!list) {
    printf("List isn't initialized!\n");
    return 0;
  }

  Node *node = create_node(data);
  if (!node) {
    return 0;
  }
  if (is_empty(list)) {
    list->head = node;
    list->size++;
    return 1;
  }

  Node *curr = list->head;
  Node *prev = list->head;
  while (curr && curr->next != NULL) {
    curr = curr->next;
  }
  node->prev = curr;
  curr->next = node;
  node->next = list->head;
  list->size++;
  return 1;
}

bool insert_node_pos(List *list, void *data, u32 pos) {
  if (pos > list->size) {
    char answer;
    printf("Error: pos is bigger than list size!\n");
    return 0;
  }

  if (!list) {
    printf("Error: List isn't initialized!\n");
    return 0;
  }

  if (pos == 0) {
    insert_node_beggining(list, data);
    return 1;
  }

  if (pos == list->size) {
    insert_node_end(list, data);
    return 1;
  }

  Node *node = create_node(data);
  if (!node) {
    return 0;
  }
  Node *curr = list->head;
  Node *prev = list->head;
  for (u32 i = 0; i < pos; i++) {
    prev = curr;
    curr = curr->next;
  }
  curr->prev = node;
  prev->next = node;
  node->prev = prev;
  node->next = curr;
  list->size++;
  return 1;
}

bool update_node(List *list, void *data, void *nData) {
  if (!list) {
    printf("Error: list isn't initialized\n");
    return 0;
  }
  Node *curr = list->head;
  while (curr && curr->data != data) {
    curr = curr->next;
  }

  if (!curr) {
    printf("Error: the input data don't exists!\n");
    return 0;
  }
  curr->data = nData;
  return 1;
}

bool remove_node(List *list, void *data) {
  if (!list) {
    printf("Error: list isn't initialized\n");
    return 0;
  }
  Node *curr = list->head;
  Node *prev = list->head;
  while (curr && curr->data != data) {
    prev = curr;
    curr = curr->next;
  }
  if (!curr) {
    printf("Error: the input data don't exists!\n");
    return 0;
  }
  prev->next = curr->next;
  curr->next->prev = prev;
  free(curr);
  list->size--;
  return 1;
}

bool destroy(List *list) {
  if (!list) {
    printf("Error: list isn't initialized\n");
    return 0;
  }
  Node *curr = list->head;
  Node *temp = list->head;
  while (curr) {
    temp = curr;
    curr = curr->next;
    free(temp);
  }
  free(list);
  return 1;
}
