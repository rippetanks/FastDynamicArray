/**
 *
 * \see https://eddmann.com/posts/implementing-a-dynamic-vector-array-in-c/
 */

#ifndef VECTOR_H
#define VECTOR_H

#define VECTOR_INIT_CAPACITY 4

#define VECTOR_INIT(vec) ed_vector vec; ed_vector_init(&vec)
#define VECTOR_ADD(vec, item) ed_vector_add(&vec, (void *) item)
#define VECTOR_SET(vec, id, item) ed_vector_set(&vec, id, (void *) item)
#define VECTOR_GET(vec, type, id) (type) ed_vector_get(&vec, id)
#define VECTOR_DELETE(vec, id) ed_vector_delete(&vec, id)
#define VECTOR_TOTAL(vec) ed_vector_total(&vec)
#define VECTOR_FREE(vec) ed_vector_free(&vec)

typedef struct vector {
    void **items;
    int capacity;
    int total;
} ed_vector;

void ed_vector_init(ed_vector *);
int ed_vector_total(ed_vector *);
static void ed_vector_resize(ed_vector *, int);
void ed_vector_add(ed_vector *, void *);
void ed_vector_set(ed_vector *, int, void *);
void *ed_vector_get(ed_vector *, int);
void ed_vector_delete(ed_vector *, int);
void ed_vector_free(ed_vector *);

#endif
