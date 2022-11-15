#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

typedef struct entry
{
    char* word;
    int qnt;
    struct entry* next;
} entry;

entry* insert(char* s, entry* dict)
{
    entry* itr = dict;
    entry* insert = NULL;

    if(strlen(s) <= 3){
        return dict;
    }

    for(itr;itr != NULL;itr = itr->next) //iterate over dict to see if entry with word s exists
    {
        if(strcmp(itr->word, s) == 0)
        { //if s is found in dict
            itr->qnt++;    //increment quantity
            return dict; //exit function and return the head of the dict
        }
        if(itr->next == NULL || strcmp(itr->next->word, s) > 0)
        { //if the next entry appears after s in lex order
            break;
        }
    }
    insert = (entry *)malloc(sizeof(entry));
    insert->word = s;
    insert->qnt = 1;

    if(itr == NULL)
    {
        insert->next = NULL;
        dict = insert;
    }
    else if(itr->next == NULL || strcmp(itr->next->word, s) > 0) //if the next entry appears after s in lex order
    {
        insert->next = itr->next; // link next entry after insert
        itr->next = insert; // link prev entry to insert
    }

    return dict;
}

void printLinked(entry* h)
{
    while(h != NULL)
    {
        printf("%s : %d -> ",h->word,h->qnt);
        h = h->next;
    }
    printf("\n");
}

char* readWord(FILE *fileptr)
{
    char str[60];
    char buf[2];
    while((fgets(buf,2,fileptr)) != NULL && isalpha(buf[0]) != 0 && buf[0] != '@' && feof(fileptr) == 0)
    {
        if(!islower(buf[0]))
        {
            buf[0] = tolower(buf[0]);
        }
        strcat(str,buf);
    }
    if(feof(fileptr) > 0)
    {
        return (void*)NULL;
    }

    char* out = (char*)malloc(sizeof(str));
    strcpy(out,str);
    return out;
}

int main(int argv, char *argc[])
{
    FILE *fp;
    char buf = '\0';
    fp = fopen(argc[1],"r");

    entry* tmp = NULL; //allocate var for cleanup
    entry* head = NULL; // init head of linked list

    char* a = NULL;
    while(1){
        a = readWord(fp);

        if(a == NULL)
        {
            break;
        }
        head = insert(a,head);
    }

    char* input;
    printf("Please input a search term: ");
    scanf("%s\n",&input);

    while(head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    return 0;
}
