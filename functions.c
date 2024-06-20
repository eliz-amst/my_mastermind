#include "functions.h"
#include <stdlib.h>
#include <time.h>

void randomNumber(int *code) {
    srand(time(NULL));
    for (int i = 0; i < 4; i++) {
        code[i] = rand() % 9;
    }
}