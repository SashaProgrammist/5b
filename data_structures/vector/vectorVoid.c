//
// Created by PC on 05.02.2022.
//

#include "vectorVoid.h"

// memory usage of vector

vectorVoid createVectorV(size_t n, size_t baseTypeSize){
    vectorVoid self = (vectorVoid){
        NULL, 0, n, baseTypeSize
    };

    if (n) {
        self.data = malloc(n * baseTypeSize);

        if (self.data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
    }

    return self;
}

void reserveV(vectorVoid *v, size_t newCapacity){
    if (isEmptyV(v))
        *v = createVectorV(newCapacity, v->baseTypeSize);
    else if (newCapacity == 0)
        deleteVectorV(v);
    else {
        v->data = realloc(v->data,
                          newCapacity * v->baseTypeSize);
        if (v->size > newCapacity) v->size = newCapacity;
        v->capacity = newCapacity;

        if (v->data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
    }
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
    void *source = v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(vectorVoid *v, size_t index, void *source){
    void *destination = v->data + index * v->baseTypeSize;
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
