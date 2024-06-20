#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"

#define MAX_INPUT_LENGTH 100

void randomNumber(int *code);
void checkCode(int *numbers, int *code);
void intArrayToString(int *scode, char *scode_str);

void intArrayToString(int *scode, char *scode_str){
    for (int i = 0; i < 4; i++) {
        scode_str[i] = scode[i] + '0'; 
        scode_str[4] = '\0'; 
    }
}

void checkCode(int *numbers, int *code){
    int misplacedPieces = 0;
    int correct = 0;

    for (int i = 0; i < 4; i++) 
    {
        if (numbers[i] == code[i])
        {
            correct++;
            code[i] = -1;
            numbers[i] = -2;
        }
    }

    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 4; j++) {
            if (numbers[i] == code[j]) {
                misplacedPieces++;
                code[j] = -1;
                break;
            }
        }
    }    
    printf("Well placed pieces: %d\nMisplaced pieces: %d\n", correct, misplacedPieces); 
}


int main(int argc, char **argv) {
    char input[MAX_INPUT_LENGTH]; 
    int scode[4] = {0};
    char scode_str[5]; 
    int max_attempts = 10;
    int attempt_count = 0;
    int code = 1;

    for (int index = 1; index < argc; index++) {
        if (strcmp(argv[index], "-t") == 0 && index + 1 < argc) {
            max_attempts = atoi(argv[index + 1]);
            break;
        } else if (strcmp(argv[index], "-c") == 0 && index + 1 < argc) {
            char *secret = argv[index + 1];
            if (strlen(secret) == 4 && isdigit(secret[0]) && isdigit(secret[1])
                && isdigit(secret[2]) && isdigit(secret[3])) {
                for (int i = 0; i < 4; i++) {
                    scode[i] = secret[i] - '0'; 
                }
                intArrayToString(scode, scode_str);
                code = 0;
                break;
            } 
        }
    }

   if (code) {
     randomNumber(scode); 
     intArrayToString(scode, scode_str);
    }

    printf("Will you find the secret code?\n");
    printf("Please enter a valid guess\n");

    while (attempt_count < max_attempts) {
        int i = 0;
        char c;
        while (i < 4) {
            ssize_t bytes_read = read(STDIN_FILENO, &c, 1);
            if (bytes_read == 0 || c == '\n') {
                break;
            } else if (!isdigit(c)) { 
                printf("Wrong input!\n");
                break; 
            } else {
                input[i++] = c;
            } 
        }
        intArrayToString(scode, scode_str);
        input[i] = '\0'; 

        if (strcmp(input, scode_str) == 0) {
            printf("Congratz! You did it!\n");
            return 0; 
        } else {
            int numbers[4];
            for (int i = 0; i < 4; i++) {
                numbers[i] = input[i] - '0';
            }
            checkCode(numbers, scode);
        }
        attempt_count++;
    }
    return 0;
}
