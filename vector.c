#include "vector.h"
#include <stdint.h>
#include <stdlib.h>

void vector_init(vector *v) {
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

bool vector_append(vector *v, int num) {
    if (v->size == v->capacity) {
        size_t new_capacity;
        if (v->capacity == 0) {
            new_capacity = 1;
        } else {
            if (v->capacity > SIZE_MAX / 2) {
                return false;
            }
            new_capacity = 2 * v->capacity;
        }

        if (new_capacity > SIZE_MAX / sizeof(*v->data)) {
            return false;
        }

        int *temp = realloc(v->data, new_capacity * sizeof(*v->data));
        if (temp == NULL) {
            return false;
        }
        v->data = temp;
        v->capacity = new_capacity;
    }
    *(v->data + v->size) = num;
    v->size++;
    return true;
}

void vector_destroy(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

bool vector_pop_back(vector *v) {
    if (!v->size) {
        return false;
    } else {
        v->size--;
        return true;
    }
}
bool vector_get(vector *v, size_t index, int *value) {
    if (index >= v->size || value == NULL) {
        return false;
    }
    *value = *(v->data + index);
    return true;
}

bool vector_set(vector *v, size_t index, int value) {
    if (index >= v->size) {
        return false;
    }
    *(v->data + index) = value;
    return true;
}
