#ifndef STACK_H
#define STACK_H
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
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
typedef struct Stack Stack;

Stack *initialize_stack(void);
bool isEmpty(Stack *stack);

bool push(Stack *stack, i32 data);
bool pop(Stack *stack);

Node *peek(Stack *stack);
bool clear(Stack *stack);

#endif
