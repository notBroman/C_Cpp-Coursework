#include <stdio.h>
#include <stdlib.h>

void append(elem** l1, elem* l2)
{
    for(elem* p = *l1; p != NULL && p->next != NULL; p = p->next)
    {
        // do nothing just find end
    }

    if (p != NULL)
    {
        p->next = l2;
    }
    else
    {
        *l1 = l2;
    }
}
