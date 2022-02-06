//
// Created by PC on 05.02.2022.
//

#include "vectorVoid.h"

// memory usage of vector

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
    if (isEmptyV(v)) {
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

// boolean functions

bool isEmptyV(vectorVoid *v){
    return v->data == NULL;
}

bool isFullV(vectorVoid *v){
    return v->size == v->capacity;
}

// the simplest interaction with the structure

void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(vectorVoid *v, size_t index, void *source){
    char *destination = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void popBackV(vectorVoid *v){
    if (v->size == 0){
        fprintf(stderr, "vector = NULL");
        exit(1);
    }

    v->size--;
}

void pushBackV(vectorVoid *v, void *source){
    if (isEmptyV(v))
        *v = createVectorV(1, v->baseTypeSize);

    if (isFullV(v))
        reserveV(v, v->capacity * 2);

    setVectorValueV(v, v->size++, source);
}
