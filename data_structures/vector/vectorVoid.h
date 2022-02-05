//
// Created by PC on 05.02.2022.
//

#ifndef INC_5B_VECTORVOID_H
#define INC_5B_VECTORVOID_H

# include <limits.h>

typedef struct vectorVoid {
     void * data ;         // указатель на нулевой элемент вектора
     size_t size ;         // размер вектора
     size_t capacity ;     // вместимость вектора
     size_t baseTypeSize ; // размер базового типа:
} vectorVoid ;

#endif //INC_5B_VECTORVOID_H
