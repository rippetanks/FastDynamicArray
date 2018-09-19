
#include "Matugm.h"
#include <stdlib.h>

struct ArrayData *ma_initArray() {
    struct ArrayData *newArray = malloc(sizeof(struct ArrayData));
    newArray->pointer = calloc(1000, sizeof(int));
    newArray->size = 1000;
    newArray->counter = 0;
    return newArray;
}

void ma_resizeArray(struct ArrayData* array) {
    int newSize = (array->size * sizeof(int)) * 2;
    array->pointer = realloc(array->pointer, newSize);
    array->size *= 2;  // This is the number of elements, don't multiply by sizeof
}

int ma_addElement(struct ArrayData *array, int number) {
    if (array->counter >= array->size) {
        ma_resizeArray(array);
    }

    *(array->pointer + array->counter) = number;  // Pointer arithmetic
    array->counter += 1;

    return 0;
}

int ma_getElement(struct ArrayData *array, int index) {
    if (array->counter >= array->size) {
        return -1;
    }

    int *data = array->pointer + index;
    return *data;
}

