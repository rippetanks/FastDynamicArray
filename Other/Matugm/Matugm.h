/**
 *
 * \see https://gist.github.com/matugm/4708222
 */

#ifndef DYNAMIC_ARRAY_MATUGM_H
#define DYNAMIC_ARRAY_MATUGM_H

#ifndef ARRAY_H_
#define ARRAY_H_

struct ArrayData *ma_initArray();
int ma_addElement(struct ArrayData *array, int number);
int ma_getElement(struct ArrayData *array, int index);

typedef struct ArrayData {
    int *pointer;
    int counter;
    int size;
} ma_ArrayData;

#endif /* ARRAY_H_ */

#endif //DYNAMIC_ARRAY_MATUGM_H
