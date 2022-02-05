//
// Created by PC on 05.02.2022.
//

#ifndef INC_5B_VECTOR_H
#define INC_5B_VECTOR_H

#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct vector {
    int *data;         // указатель на элементы вектора
    size_t size;       // размер вектора
    size_t capacity;   // вместимость вектора
} vector;

// memory usage of vector

vector createVector(size_t n);

void reserve(vector *v, size_t newCapacity);

void clear(vector *v);

void shrinkToFit(vector *v);

void deleteVector(vector *v);

// boolean functions

bool isEmpty(vector *v);

bool isFull(vector *v);

// the simplest interaction with the structure

int getVectorValue(vector *v, size_t i);

void pushBack(vector *v, int x);

void popBack(vector *v);

// access functions

int* atVector(vector *v, size_t index);

int* back(vector *v);

int* front(vector *v);

#endif //INC_5B_VECTOR_H
