#ifndef VECTOR_H
#define VECTOR_H
#include <stdbool.h>
#include <stddef.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} vector;

void vector_init(vector *v);
bool vector_append(vector *v, int num);
bool vector_pop_back(vector *v);
bool vector_get(vector *v, size_t index, int *value);
bool vector_set(vector *v, size_t index, int value);
void vector_destroy(vector *v);
#endif
