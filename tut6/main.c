#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct elem {
    int data;
    struct elem* next;
}elem;


void remove_tail(elem** plist)
{
    elem* head = *plist;

    for(head; head != NULL && head->next != NULL && head->next->next != NULL; head = head->next)
    {
        //move to the second to last element in list
    }

    // conditions for there is 1 and 0 elements in the list
    if(head == NULL)
    {
        // 0 elements in the list
        // do nothing already empty
        *plist = NULL;
    }
    else if(head->next == NULL)
    {
        // 1 element in the list
        free(head);
        *plist = NULL;
    }
    else if(head->next->next == NULL)
    {
        // 2 elements in list
        free(head->next);
        head->next = NULL;
    }
    else
    {
        free(head->next->next);
        head->next->next = NULL;
    }
}

elem* get_elem(int n, elem* plist)
{
    int i = 1;

    while(plist != NULL && plist->next != NULL)
    {
        if(i == n)
        {
            return plist;
        }
        plist = plist->next;
        i++;
    }

    return NULL;
}

elem* make_list(int* array, int len)
{
    elem* new_list = NULL;
    elem* new_elem = NULL;

    for(int i = 0; i < len; i++)
    {
        new_elem = (elem *)malloc(sizeof(elem));
        int a = array[i];
        new_elem->data = a;

            new_elem->next = new_list;
            new_list = new_elem;
    }

    return new_list;
}



void printLinked(elem* h)
{
    while(h != NULL)
    {
        printf("%d -> ",h->data);
        h = h->next;
    }
    printf("NULL\n");
}


void split_list(elem* h, elem** front, elem** back)
{
    elem* itr = h;
    elem* hed_ref = h;
    int i = 1;
    while(itr != NULL && itr->next != NULL)
    {
        i++;
        itr = itr->next;
    }
    *back = get_elem(i/2 + 1,h);

    itr = h;
    while(itr != NULL && itr->next != NULL && itr->next != *back)
    {
        itr = itr->next;
    }

    itr->next = NULL;
    *front = h;

}

int main(int argv, char* argc[])
{
    elem* tmp = NULL; // cleanup var
    int list[] = {1,23,54,100,111};
    elem* a = make_list(list,5);
    elem* f_half = NULL;
    elem* b_half = NULL;

    printLinked(a);
    // elem* b = get_elem(3,a);

    //printLinked(b);


    split_list(a, &f_half, &b_half);

    printLinked(f_half);
    printLinked(b_half);


    // issue become pointer has been freed already
    //printLinked(a);
    /*
    while(a != NULL)
    {
        tmp = a;
        a = a->next;
        free(tmp);
    }
    */
    return 0;
}
