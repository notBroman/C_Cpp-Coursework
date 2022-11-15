#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct letter{
    char letter;
    int count;
} letter;

/*
letter* merge(letter slice1[], letter slice2[])
{
    int total_chars = (sizeof(slice1) + sizeof(slice2))/sizeof(slice1[0]);
    letter res[total_chars];
    int j = 0;
    int k = 0;
    for(int i = 0; i< total_chars; i++)
    {
        while(j < sizeof(slice1) && k < sizeof(slice2))
        {
            if(slice1[j].count >= slice2[k].count){
                res[i] = slice1[j];
                j++;
            }
            else
            {
                res[i] = slice2[k];
                k++;
            }
        }
        while(j < sizeof(slice1))
        {
            res[i] = slice1[j];
            j++;
        }

        while(k < sizeof(slice2))
        {
            res[i] = slice2[k];
            k++;
        }
    }

    return res;
}

letter* mergeSort(letter arr[])
{
    int mid = (sizeof(arr)/sizeof(letter))/2;
    letter left[];
    memcpy(left, arr, mid * sizeof(letter)); // copy left half to left
    letter right[];
    for(int i = mid + 1; i < sizeof(arr)/sizeof(letter);i++)
    {
        right[i - mid - 1] = arr[i];
    }

    arr = merge(mergeSort(left),mergeSort(right));

    return arr;
}
*/

int main(int argv, char *argc[])
{
    FILE *fp;
    char buf = '\0';
    fp = fopen(argc[1],"r");
    letter l[26];
    int num_char = 0;
    int j = 0;

    for(int c = 'a'; c <= 'z'; c++)
    {
        l[j].letter = c;
        l[j].count = 0;
        j++;
    }

    while((buf = fgetc(fp)) != EOF)
    {

        if(buf >= 'A' && buf <= 'Z')
        {
            l[buf-'A'].count++;
            num_char++;
        }
        else if(buf >= 'a' && buf <= 'z')
        {
            l[buf-'a'].count++;
            num_char++;
        }
        else
        {
        }

    }

    fclose(fp);

//    l = mergeSort(l);

    for(int i = 0; i < 26; i++){
        printf("%c: %.6f \%\n",l[i].letter, (((float)(l[i].count))/((float)(num_char))));
    }
    return 0;
}
