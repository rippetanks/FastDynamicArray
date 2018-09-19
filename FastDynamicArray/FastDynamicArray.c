/*
    Copyright 2018 Simone Martelli

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <stdlib.h>
#include <math.h>

#include "FastDynamicArray.h"

void dyvec_init(DynamicVector *const v) {
    v->vectors = malloc(sizeof(struct _ItemDynamicVector*));
    v->vectors[0] = malloc(sizeof(struct _ItemDynamicVector));
    v->size = 0;
    v->capacity = DYNAMIC_ARRAY_BLOCK_SIZE;
    v->block = 1;
}

void dyvec_add(DynamicVector *const v, void *const obj) {
    long int block = (v->size >> _DYNAMIC_SHIFT);
    // if the allocated space is not sufficient, a block is added
    if(v->size == v->capacity) {
        v->block++;
        v->vectors = realloc(v->vectors, v->block * sizeof(_ItemDynamicVector*));
        v->vectors[block] = malloc(sizeof(_ItemDynamicVector));
        v->capacity += DYNAMIC_ARRAY_BLOCK_SIZE;
    }
    v->vectors[block]->item[v->size & _DYNAMIC_MOD] = obj;
    v->size++;
}

void* dyvec_get(DynamicVector *const v, const long int index) {
    if(index >= 0 && index < v->size)
        return v->vectors[index >> _DYNAMIC_SHIFT]->item[index & _DYNAMIC_MOD];
    return NULL;
}

void dyvec_set(DynamicVector *const v, const long int index, void *const obj) {
    if(index >= 0 && index < v->size)
        v->vectors[index >> _DYNAMIC_SHIFT]->item[index & _DYNAMIC_MOD] = obj;
}

void dyvec_resize(DynamicVector *const v, const long int newSize) {
    long int i, block;
    // the size can not be reduced below the block unit
    if(newSize < DYNAMIC_ARRAY_BLOCK_SIZE)
        return;
    block = (int)ceil((double)newSize / DYNAMIC_ARRAY_BLOCK_SIZE);
    if(v->block > block) {
        for(i = block; i < v->block; i++)
            free(v->vectors[i]);
    }
    v->vectors = realloc(v->vectors, block * sizeof(_ItemDynamicVector*));
    v->capacity = block * DYNAMIC_ARRAY_BLOCK_SIZE;
    if(v->size > newSize)
        v->size = newSize;
    v->block = block;
}

void dyvec_erase(DynamicVector *const v, const long int index) {
    long int i, j;
    if(index < 0 || index >= v->size)
        return;
    j = 0;
    for(i = index; i < v->size - 1; i++) {
        j = i + 1;
        v->vectors[i >> _DYNAMIC_SHIFT]->item[i & _DYNAMIC_MOD] = v->vectors[j >> _DYNAMIC_SHIFT]->item[j & _DYNAMIC_MOD];
    }
    v->vectors[j >> _DYNAMIC_SHIFT]->item[j & _DYNAMIC_MOD] = NULL;
    v->size--;
    // the size can not be reduced below the block unit
    if(v->size >= DYNAMIC_ARRAY_BLOCK_SIZE && v->size <= v->capacity - DYNAMIC_ARRAY_BLOCK_SIZE)
        dyvec_resize(v, v->capacity - DYNAMIC_ARRAY_BLOCK_SIZE);
}

void dyvec_erase_interval(DynamicVector *const v, const long int start, const long int end) {
    long int i, j;
    if(start >= 0 && start < v->size &&
        end >= 0 && end < v->size &&
        start <= end)
    {
        j = 0;
        for(i = start; i <= end; i++) {
            j = i + 1;
            v->vectors[i >> _DYNAMIC_SHIFT]->item[i & _DYNAMIC_MOD] = v->vectors[j >> _DYNAMIC_SHIFT]->item[j & _DYNAMIC_MOD];
        }
        v->vectors[j >> _DYNAMIC_SHIFT]->item[j & _DYNAMIC_MOD] = NULL;
        v->size = v->size - (end - start);
        // the size can not be reduced below the block unit
        if(v->size > DYNAMIC_ARRAY_BLOCK_SIZE && v->size < v->capacity - DYNAMIC_ARRAY_BLOCK_SIZE)
            dyvec_resize(v, v->capacity - DYNAMIC_ARRAY_BLOCK_SIZE);
    }
}

void* dyvec_pop(DynamicVector *const v) {
    if(v->size == 0)
        return NULL;

    v->size--;
    void *p = v->vectors[v->size >> _DYNAMIC_SHIFT]->item[v->size & _DYNAMIC_MOD];

    if(v->size >= DYNAMIC_ARRAY_BLOCK_SIZE && v->size <= v->capacity - DYNAMIC_ARRAY_BLOCK_SIZE)
        dyvec_resize(v, v->capacity - DYNAMIC_ARRAY_BLOCK_SIZE);
    return p;
}

void dyvec_push(DynamicVector *const v, void *const obj) {
    dyvec_add(v, obj);
}

void dyvec_free(DynamicVector *v) {
    long int i;
    for(i = 0; i < v->block; i++)
        free(v->vectors[i]);
    free(v->vectors);
    v->vectors = NULL;
    v->size = 0;
    v->block = 0;
    v->capacity = 0;
}
