/**
 *
 * \see https://stackoverflow.com/questions/3536153/c-dynamically-growing-array
 */

#include <stdlib.h>

#ifndef DYNAMIC_ARRAY_STACKOVERFLOW1_H
#define DYNAMIC_ARRAY_STACKOVERFLOW1_H

typedef struct {
    int *array;
    size_t used;
    size_t size;
} so_Array;

void so_initArray(so_Array *a, size_t initialSize) {
    a->array = (int *)malloc(initialSize * sizeof(int));
    a->used = 0;
    a->size = initialSize;
}

void so_insertArray(so_Array *a, int element) {
    // a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
    // Therefore a->used can go up to a->size
    if (a->used == a->size) {
        a->size *= 2;
        a->array = (int *)realloc(a->array, a->size * sizeof(int));
    }
    a->array[a->used++] = element;
}

void so_freeArray(so_Array *a) {
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

#endif //DYNAMIC_ARRAY_STACKOVERFLOW1_H
