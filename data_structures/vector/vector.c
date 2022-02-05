//
// Created by PC on 05.02.2022.
//

#include "vector.h"

// memory usage of vector

vector createVector(size_t n){
    vector result;
    result.size = 0;
    result.capacity = n;
    if (n) {
        result.data = malloc(n * sizeof(int));

        if (result.data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
    } else
        result.data = NULL;

    return result;
}

void reserve(vector *v, size_t newCapacity) {
    if (v->data == NULL) {
        *v = createVector(newCapacity);
        return;
    }
    if (newCapacity == 0) {
        deleteVector(v);
        return;
    }

    void *new = realloc(v->data,
                        newCapacity * sizeof(int));

    if (new == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    v->data = (int *) new;
    if (v->size > newCapacity) v->size = newCapacity;
    v->capacity = newCapacity;

}

void clear(vector *v){
    v->size = 0;
}

void shrinkToFit(vector *v){
    reserve(v, v->size);
}

void deleteVector(vector *v){
    free(v->data);
    v->data = NULL;
    v->capacity = 0;
    v->size = 0;
}
