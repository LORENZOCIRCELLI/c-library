#ifndef QUEUE_H
#define QUEUE_H

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
typedef struct Queue Queue;

void initialize_queue(Queue *queue);

bool isEmpty(Queue *queue);

bool enqueue(Queue *queue, int data);
bool dequeue(Queue *queue);
Node *peek(Queue *queue);

bool destroy(Queue *queue);

#endif
