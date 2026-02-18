#ifndef DEQUE_H
#define DEQUE_H

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

typedef struct Node Node;
typedef struct Deque Deque;

Deque *initialize_deque(void);
u32 is_empty(Deque *deque);

bool push_front(Deque *deque, i32 value);
bool push_back(Deque *deque, i32 value);
bool pop_front(Deque *deque);
bool pop_back(Deque *deque);

Node *get_front(Deque *deque);
Node *get_back(Deque *deque);

bool destroy(Deque *deque);

#endif
