#ifndef LIST_H
#define LIST_H

#include <immintrin.h>
#include <stdbool.h>
#include <stdint.h>

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

typedef struct Node Node;
typedef struct List List;

List *initialize_list(void);

bool is_empty(List *list);
u32 list_size(List *list);

Node *create_node(void *data);

bool insert_node_beggining(List *list, void *data);
bool insert_node_end(List *list, void *data);
bool insert_node_pos(List *list, void *data, u32 pos);
bool update_node(List *list, void *data, void *nData);
bool remove_node(List *list, void *data);

bool destroy_list(List *list);

#endif
