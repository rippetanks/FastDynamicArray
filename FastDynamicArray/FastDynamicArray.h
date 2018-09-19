/*
    Copyright 2018 Simone Martelli

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#ifndef DYNAMIC_ARRAY_FASTDYNAMICARRAY_H
/**
 *
 * \author S. Martelli
 * \date 2018-09-08
 * \brief High performance dynamic vector with minimal memory waste
 * \see https://github.com/rippetanks
 *
 *  This implementation manages a high-performance variable-size vector minimizing waste of memory.
 */
#define DYNAMIC_ARRAY_FASTDYNAMICARRAY_H

/**
 *
 * DYNAMIC_ARRAY_BLOCK_SIZE must be a power of 2
 * <br>
 * DYNAMIC_ARRAY_BLOCK_SIZE = 2 ^ DYNAMIC_SHIFT
 */
#define DYNAMIC_ARRAY_BLOCK_SIZE 1024
#define _DYNAMIC_MOD DYNAMIC_ARRAY_BLOCK_SIZE - 1
#define _DYNAMIC_SHIFT 10

/**
 *
 * \struct DynamicVector
 * \brief Object that manages and contain the elements of the vector
 */
typedef struct DynamicVector {
    struct _ItemDynamicVector **vectors; /** Dynamic vector of basic element */
    long int block; /** Number of blocks of basic elements */
    long int capacity; /** Size of allocated storage capacity */
    long int size; /** Occupied spaces */
} DynamicVector;

/**
 *
 * \struct ItemDynamicVector
 * \brief Basic element of the vector
 */
typedef struct _ItemDynamicVector {
    void* item[DYNAMIC_ARRAY_BLOCK_SIZE]; /** Block that contains the elements */
} _ItemDynamicVector;

/**
 *
 * \brief Initialization DynamicVector
 * \param vector to initialize
 */
void dyvec_init(DynamicVector*);

/**
 *
 * \brief Add an element to the array
 * \param vector
 * \param pointer to the item to be added
 *
 * Adds an element at the end of the vector, if there is not enough space it allocates a new block.
 */
void dyvec_add(DynamicVector*, void*);

/**
 *
 * \brief Get a value from the array
 * \param vector
 * \param index
 * \return pointer to the stored item, in out of bound return NULL
 */
void* dyvec_get(DynamicVector*, long int);

/**
 *
 * \brief Set a value in the array
 * \param vector
 * \param index
 * \param pointer to the new value
 */
void dyvec_set(DynamicVector*, long int, void*);

/**
 *
 * \brief Changes the capacity of the array
 * \param vector
 * \param new capacity
 *
 * If the size is smaller than the previous some elements may be deleted.
 */
void dyvec_resize(DynamicVector*, long int);

/**
 *
 * \brief Delete an element from the array
 * \param vector
 * \param index
 */
void dyvec_erase(DynamicVector*, long int);

/**
 *
 * \brief Deletes a range of elements from the array, the interval is closed
 * \param vector
 * \param start index
 * \param end index
 */
void dyvec_erase_interval(DynamicVector*, long int, long int);

/**
 *
 * \brief Get the last item and delete it
 * \param vector
 * \return pointer to the last element, if the vector is empty returns null
 */
void* dyvec_pop(DynamicVector*);

/**
 *
 * \brief Add element at the end, alias for dyvec_push
 * \param vector
 * \param pointer to the element to be added
 */
void dyvec_push(DynamicVector*, void*);

/**
 *
 * \brief Free the acquired resources
 * \param vector
 */
void dyvec_free(DynamicVector*);

#endif //DYNAMIC_ARRAY_FASTDYNAMICARRAY_H
