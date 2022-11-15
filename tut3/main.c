#include <stdio.h>
#include <time.h>
#include "stdlib.h"
/*
int isCorrect(int* arr1,int* arr2, int len)
{
    int correct = 0;
    for(int i = 0; i < len; i++)
    {
        if(*(arr1 + i*sizeof(int)) == *(arr2 + i*sizeof(int)))
        {
            correct++;
        }
    }
    printf("%d",correct);
    return correct;
}
*/

int main(){

    int code[4] = {0, 0, 0, 0};
    int guess[4] = {6, 6, 6, 6};
    srand(time(NULL));

    int length = sizeof(code)/sizeof(int);
    for(int i = 0; i < length; i++)
    {
        code[i] = rand() % 9;
    }

    int j = 1;
    int correct = 0;
    int misplaced = 0;
    while(correct != 4)
    {
        correct = 0;
        misplaced = 0;
        printf("Round %d >",j);
        scanf("%d %d %d %d", &guess[0], &guess[1], &guess[2], &guess[3]);

        for(int i = 0; i < sizeof(code)/sizeof(int); i++)
        {
            if(code[i] == guess[i])
            {
                correct++;
                continue;
            }
            for(int k = 0; k < sizeof(code)/sizeof(int); k++)
            {
                if(code[k] == guess[i] && i != k)
                {
                    misplaced++;
                }
            }
        }

        printf("correct: %d, misplaced: %d\n",correct,misplaced);
        j++;
    }

    return 0;
}
