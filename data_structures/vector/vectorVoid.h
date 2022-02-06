//
// Created by PC on 05.02.2022.
//

#ifndef INC_5B_VECTORVOID_H
#define INC_5B_VECTORVOID_H

#include <limits.h>
#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>
#include <memory.h>

typedef struct vectorVoid {
     void * data ;         // указатель на нулевой элемент вектора
     size_t size ;         // размер вектора
     size_t capacity ;     // вместимость вектора
     size_t baseTypeSize ; // размер базового типа:
} vectorVoid ;

// memory usage of vector

vectorVoid createVectorV(size_t n, size_t baseTypeSize);

void reserveV(vectorVoid *v, size_t newCapacity);

void shrinkToFitV(vectorVoid *v);

void clearV(vectorVoid *v);

void deleteVectorV(vectorVoid *v);

// boolean functions

bool isEmptyV(vectorVoid *v);

bool isFullV(vectorVoid *v);

// the simplest interaction with the structure

void getVectorValueV(vectorVoid *v, size_t index, void *destination);

void setVectorValueV(vectorVoid *v, size_t index, void *source);

void popBackV(vectorVoid *v);

void pushBackV(vectorVoid *v, void *source);

#endif //INC_5B_VECTORVOID_H
