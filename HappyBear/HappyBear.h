/**
 *
 * \see https://www.happybearsoftware.com/implementing-a-dynamic-array
 */

#ifndef DYNAMIC_ARRAY_HAPPYBEAR_H
#define DYNAMIC_ARRAY_HAPPYBEAR_H

#define VECTOR_INITIAL_CAPACITY 100

// Define a vector type
typedef struct {
    int size;      // slots used so far
    int capacity;  // total available slots
    int *data;     // array of integers we're storing
} hb_Vector;

void hb_vector_init(hb_Vector *vector);

void hb_vector_append(hb_Vector *vector, int value);

int hb_vector_get(hb_Vector *vector, int index);

void hb_vector_set(hb_Vector *vector, int index, int value);

void hb_vector_double_capacity_if_full(hb_Vector *vector);

void hb_vector_free(hb_Vector *vector);

#endif //DYNAMIC_ARRAY_HAPPYBEAR_H
