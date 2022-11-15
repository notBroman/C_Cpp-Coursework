#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

typedef struct event
{
    time_t time;
    char* desc;
    struct event* next;
} event;

event* head = NULL;

void add_event(time_t t, char* ed)
{
    event* itr = head;

    event* new = (event *)malloc(sizeof(event));
    new->time = t;
    new->desc = (char *)malloc(sizeof(strlen(ed)+1));
    strcpy(new->desc,ed);

    for(itr; itr != NULL;itr = itr->next)
    {
        if(itr->time < t && (itr->next == NULL || itr->next->time > t))
        { // insert at this point
            new->next = itr->next;

            itr->next = new;
            return;
        }
    }

    if(itr == NULL)
    {
        new->next = NULL;

        itr->next = new;
    }
    return;
}

void print_diary()
{
    event* h = head;
    while(h != NULL)
    {
        printf("%s\n%s\n\n",ctime(&h->time),h->desc);
        h = h->next;
    }
}


void save_diary(char* fname)
{

}

void load_diary(char* fname)
{

}

void delete(int k)
{

}

int main(int argv,char* argc[])
{
    time_t t1 = time(&t1);

    char* a = "abc";
    char* b = "def";
    add_event(t1,a);



    while(head != NULL)
    {
        event* tmp = head;
        head = head->next;

        print_diary();

        free(tmp);
    }
    return 0;
}
