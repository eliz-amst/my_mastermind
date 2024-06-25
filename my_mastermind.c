#include "my_mastermind.h"

void initialize();
int checkSpec(char* argv, char* argv1, int * code);
char* my_strcpy(char* param_1, char* param_2);
void checkCode(char *tempCode, int *code);
void randomNumber(int *code);
int attempCheck(int * code);
void checkAttempts(int *attempts, int *rounds);
int checkBuffer(int* numbers);
int checkPieces(int *numbers, int *code);

int attempts = 10;
int rounds = 0;

int main(int argc, char **argv) {
    int code[CODE_LEN] = {0};
    initialize();
    if(argc == 0) return 0;
    for (int i = 1; argv[i] != 0; i+=2) 
       if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "-t") == 0) {
            checkSpec(argv[i], argv[i+1], code);
        } else {
            printf("Wrong instructions provided!");
            return 0;
        }
    attempCheck(code);

    return 0;
}

void initialize(){
    printf("Will you find the secret code?\n");
    printf("Please enter a valid guess\n");
}

int checkSpec(char* argv, char* argv1, int * code) {
    char tempCode[CODE_LEN];

    if(strcmp(argv, "-c") == 0) 
    {
        my_strcpy(tempCode, argv1); 
        checkCode(tempCode, code); 
        return 0;
    } else if (strcmp(argv, "-t") == 0) 
        attempts = atoi(argv1);
    else
        randomNumber(code);
    return 1;
}

char* my_strcpy(char* param_1, char* param_2){
    int i = 0;
    int len = strlen(param_2);

    while (i < len) 
    {
        param_1[i] = param_2[i];
        i++;
    }

    return param_1;
}

void checkCode(char *tempCode, int *code){    
    for (int i = 0; i < CODE_LEN; i++)
    {
        if (tempCode[i] >= '0' && tempCode[i] <= '8') 
        { 
            if (tempCode[i] != '0') 
                code[i] = tempCode[i] - '0'; 
            else 
                code[i] = 0;   
        } 
        else 
            break;
    }
}

void randomNumber(int *code){
    srand(time(NULL));
    for (int i = 0; i < CODE_LEN; i++) 
        code[i] =  rand() % 9;
}

int attempCheck(int * code){
    int numbers[CODE_LEN] = {0}; 

    while (attempts) 
    {
        printf("Round %d\n", rounds);

        checkAttempts(&attempts, &rounds);

        int check = checkBuffer(numbers);
        if(check == -1){
            printf("Wrong input!\n");
            char c;
            while (read(STDIN_FILENO, &c, 1) > 0 && c != '\n');  
            continue;
        } else if(checkPieces(numbers, code) == 1) {
            return 0;  
        }
    }
    return 1;
}

void checkAttempts(int *attempts, int *rounds){
    *attempts -= 1; 
    *rounds += 1; 
}

int checkBuffer(int* numbers){
    char c;
    int i = 0, ptr;

    while ((ptr = read(STDIN_FILENO, &c, 1)) == 1 && c != '\n')
    {
        if (c >= '0' && c <= '8')
        {        
            if (c != '0') 
                numbers[i++] =  c - '0'; 
            else 
                numbers[i++] = 0;
        }
        else 
            return -1;
    }

    if (i > 4 || i < 4)             
        return -1;

    return 1;
}

int checkPieces(int *numbers, int *code){
    int misplacedPieces = 0;
    int correct = 0;

    for (int i = 0; i < 4; i++) 
    {
        if (numbers[i] == code[i]) 
            correct++;
        else if (numbers[i] != code[i] && (numbers[i] == code[(i+1)%4] || numbers[i] == code[(i+2)%4] || numbers[i] == code[(i+3)%4]))
            misplacedPieces++;
    }
    
    if (correct == 4) 
    {
        printf("Congratz! You did it!\n");
        return 1;
    } else 
        printf("Well placed pieces: %d\nMisplaced pieces: %d\n", correct, misplacedPieces); 

    return 0;
}
