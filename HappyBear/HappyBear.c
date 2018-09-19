
#include <stdlib.h>

#include "HappyBear.h"

void hb_vector_init(hb_Vector *vector) {
    // initialize size and capacity
    vector->size = 0;
    vector->capacity = VECTOR_INITIAL_CAPACITY;

    // allocate memory for vector->data
    vector->data = malloc(sizeof(int) * vector->capacity);
}

void hb_vector_append(hb_Vector *vector, int value) {
    // make sure there's room to expand into
    hb_vector_double_capacity_if_full(vector);

    // append the value and increment vector->size
    vector->data[vector->size++] = value;
}

int hb_vector_get(hb_Vector *vector, int index) {
    if (index >= vector->size || index < 0) {
        exit(1);
    }
    return vector->data[index];
}

void hb_vector_set(hb_Vector *vector, int index, int value) {
    // zero fill the vector up to the desired index
    while (index >= vector->size) {
        hb_vector_append(vector, 0);
    }

    // set the value at the desired index
    vector->data[index] = value;
}

void hb_vector_double_capacity_if_full(hb_Vector *vector) {
    if (vector->size >= vector->capacity) {
        // double vector->capacity and resize the allocated memory accordingly
        vector->capacity *= 2;
        vector->data = realloc(vector->data, sizeof(int) * vector->capacity);
    }
}

void hb_vector_free(hb_Vector *vector) {
    free(vector->data);
}

