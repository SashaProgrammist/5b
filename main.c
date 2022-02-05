#include <stdio.h>
#include <assert.h>

#include "data_structures/vector/vector.h"

void test_pushBack_standardWork(){
    vector v = createVector(5);
    v.size = 2;

    pushBack(&v, 12);

    assert(v.data[2] == 12);
    assert(v.size == 3);
    assert(v.capacity == 5);

    deleteVector(&v);
}
void test_pushBack_EmptyVector(){
    vector v = createVector(0);

    pushBack(&v, 2);
    assert(v.capacity == 1);
    pushBack(&v, 3);
    assert(v.capacity == 2);
    pushBack(&v, 4);

    assert(v.data[0] == 2);
    assert(v.data[1] == 3);
    assert(v.data[2] == 4);
    assert(v.size == 3);
    assert(v.capacity == 4);

    deleteVector(&v);
}
void test_pushBack_FullVector(){
    vector v = createVector(5);
    v.size = 5;

    pushBack(&v, 1);
    assert(v.capacity == 10);
    v.size = 10;

    pushBack(&v, 1);
    assert(v.capacity == 20);
    v.size = 20;

    pushBack(&v, 1);
    assert(v.capacity == 40);
    v.size = 40;

    deleteVector(&v);
}

void test_popBack_standardWork(){
    vector v = createVector(5);
    v.size = 4;

    popBack(&v);
    assert(v.size == 3);

    popBack(&v);
    assert(v.size == 2);

    assert(v.capacity == 5);

    deleteVector(&v);
}

void test(){
    test_pushBack_standardWork();
    test_pushBack_EmptyVector();
    test_pushBack_FullVector();

    test_popBack_standardWork();
}

int main() {
    test();

    return 0;
}
