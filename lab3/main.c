#include <stdio.h>
//#include "nim.h"

#define MIN_HEAPS 2
#define MAX_HEAPS 5

void print_heaps(int* heap_arr, int heaps)
{
    for(int i = 0; i < heaps; i++){
        printf("Heap [%d]: ",i);
        for(int j = 0; j < *heap_arr; j++){
            printf("o");
        }
        printf("\n");
        ++heap_arr;
    }
}

int update_total(int* heap_arr, int heaps)
{
    int total = 0;
    for(int i = 0; i < heaps; i++)
    {
        total += *heap_arr;
        ++heap_arr;
    }
    return total;
}


int main(int argc, char* argv[])
{
    int heaps = 2;
    int heap_arr[MAX_HEAPS] = {0,0,0,0,0};
    int total = 999999;
    int round = 1;
    int user[] = {0,0};
    int computer[] = {0,0};
    int decision = 0;
    int right_heap = 0;
    int nimsum = 0;

    printf("How many heaps [%d-%d]? ",MIN_HEAPS,MAX_HEAPS);
    scanf("%d",&heaps);

    for(int i = 0; i < heaps; i++)
    {
        heap_arr[i] = 1 + 2*i; // odd increasing numbers
    }

    while(total > 0)
    {
        printf("----------- round %d\n",round);
        print_heaps(&heap_arr,heaps);

        printf("Your turn: input heap, coins: ");
        scanf("%d %d", &user[0], &user[1]);
        heap_arr[user[0]] -= user[1];

        for(int i = 0; i < heaps; i++)
        {
            nimsum = nimsum ^ heap_arr[i];
        }

        if(nimsum == 0)
        {
            for(int i = 0; i < heaps; i++)
            {
                if(heap_arr[i] == 0){
                    computer[0] = i;
                    computer[1] = 1;
                }
                else
                {
                    printf("YOU LOST");
                    return 0;
                }
            }
        }
        else
        {
            for(int i = 0; i < heaps; i++)
            {
                right_heap = nimsum ^ heap_arr[i];
                if(right_heap < heap_arr[i])
                {
                    computer[0] = i;
                    computer[1] = heap_arr[i] - right_heap;
                    heap_arr[i] = right_heap;
                    break;
                }
            }
        }
        printf("My turn: heap, coins: %d, %d\n\n", computer[0], computer[1]);

        total = update_total(&heap_arr, heaps);
        round++;
        nimsum = 0;
    }

    return 0;
}
