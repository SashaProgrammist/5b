//
// Created by PC on 05.02.2022.
//

#include "vectorVoid.h"

vectorVoid createVectorV(size_t n, size_t baseTypeSize){
    vectorVoid result;
    result.size = 0;
    result.capacity = n;
    result.baseTypeSize = baseTypeSize;
    if (n) {
        result.data = malloc(n * baseTypeSize);

        if (result.data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
    } else
        result.data = NULL;

    return result;
}

void reserveV(vectorVoid *v, size_t newCapacity){
    if (v->data == NULL) {
        *v = createVectorV(newCapacity, v->baseTypeSize);
        return;
    }
    if (newCapacity == 0) {
        deleteVectorV(v);
        return;
    }

    void *new = realloc(v->data,
                        newCapacity * v->baseTypeSize);

    if (new == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    v->data = (int *) new;
    if (v->size > newCapacity) v->size = newCapacity;
    v->capacity = newCapacity;
}

void shrinkToFitV(vectorVoid *v){
    reserveV(v, v->size);
}

void clearV(vectorVoid *v){
    v->size = 0;
}

void deleteVectorV(vectorVoid *v){
    free(v->data);
    v->data = NULL;
    v->capacity = 0;
    v->size = 0;
}
