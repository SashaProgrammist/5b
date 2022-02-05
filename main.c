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
void test_pushBack_emptyVector(){
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
void test_pushBack_fullVector(){
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

void test_atVector_standardWork(){
    int n = 6;
    vector v = createVector(n);
    v.size = n;

    for (int i = 0; i < n; ++i) {
        assert(atVector(&v, i) == v.data + i);
    }

    deleteVector(&v);
}
void test_atVector_notEmptyVector(){
    vector v = createVector(4);
    v.size = 4;

    assert(atVector(&v, 2) == v.data + 2);
    assert(atVector(&v, 1) == v.data + 1);

    deleteVector(&v);
}
void test_atVector_requestToLastElement(){
    vector v = createVector(7);
    v.size = 7;

    assert(atVector(&v, 6) == v.data + 6);

    deleteVector(&v);
}

void test_back_oneElementInVector(){
    vector v = createVector(1);
    v.size = 1;

    assert(back(&v) == v.data);

    deleteVector(&v);
}

void test_front_oneElementInVector(){
    vector v = createVector(1);
    v.size = 1;

    assert(front(&v) == v.data);

    deleteVector(&v);
}

void test(){
    test_pushBack_standardWork();
    test_pushBack_emptyVector();
    test_pushBack_fullVector();

    test_popBack_standardWork();

    test_atVector_standardWork();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();

    test_back_oneElementInVector();

    test_front_oneElementInVector();
}

int main() {
    test();

    return 0;
}
