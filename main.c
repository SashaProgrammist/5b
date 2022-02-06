#include <stdio.h>
#include <assert.h>

#include "data_structures/vector/vectorVoid.h"

void test_pushBack_int(){
    int n = 8;

    vectorVoid v = createVectorV(0, sizeof(int));
    for (int i = 0; i < n; i++) {
        int x = i ^ n;

        pushBackV(&v, &x);
    }

    for (int i = 0; i < n; i++) {
        int x;
        getVectorValueV(&v, i, &x);

        assert(x == (i ^ n));
    }

    deleteVectorV(&v);
}

void test_pushBack_float(){
    int n = 8;

    vectorVoid v = createVectorV(0, sizeof(float));
    for (int i = 0; i < n; i++) {
        float x = (float)i * 3.14f;

        pushBackV(&v, &x);
    }

    for (int i = 0; i < n; i++) {
        float x;
        getVectorValueV(&v, i, &x);

        assert(x == ((float)i * 3.14f));
    }

    deleteVectorV(&v);
}

int main() {
    test_pushBack_int();
    test_pushBack_float();
    printf("OK\n");

    return 0;
}
