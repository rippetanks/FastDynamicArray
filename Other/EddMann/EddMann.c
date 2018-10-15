
#include <stdlib.h>

#include "EddMann.h"

void ed_vector_init(ed_vector *v)
{
    v->capacity = VECTOR_INIT_CAPACITY;
    v->total = 0;
    v->items = malloc(sizeof(void *) * v->capacity);
}

int ed_vector_total(ed_vector *v)
{
    return v->total;
}

static void ed_vector_resize(ed_vector *v, int capacity)
{
    void **items = realloc(v->items, sizeof(void *) * capacity);
    if (items) {
        v->items = items;
        v->capacity = capacity;
    }
}

void ed_vector_add(ed_vector *v, void *item)
{
    if (v->capacity == v->total)
        ed_vector_resize(v, v->capacity * 2);
    v->items[v->total++] = item;
}

void ed_vector_set(ed_vector *v, int index, void *item)
{
    if (index >= 0 && index < v->total)
        v->items[index] = item;
}

void *ed_vector_get(ed_vector *v, int index)
{
    if (index >= 0 && index < v->total)
        return v->items[index];
    return NULL;
}

void ed_vector_delete(ed_vector *v, int index)
{
    if (index < 0 || index >= v->total)
        return;

    v->items[index] = NULL;

    for (int i = index; i < v->total - 1; i++) {
        v->items[i] = v->items[i + 1];
        v->items[i + 1] = NULL;
    }

    v->total--;

    if (v->total > 0 && v->total == v->capacity / 4)
        ed_vector_resize(v, v->capacity / 2);
}

void ed_vector_free(ed_vector *v)
{
    free(v->items);
}
