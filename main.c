#include <stdio.h>
#include <malloc.h>

#include "data_structures/vector/vectorVoid.h"

int main() {
    vectorVoid vv = (vectorVoid){
            malloc(5 * sizeof(int)),
            0,
            5,
            sizeof(int)
    };

    return 0;
}
