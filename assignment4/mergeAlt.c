#include <stdio.h>
#include <stdlib.h>
#include "llio.h"

 node* joinAlt( node *list1,  node *list2){
    
    node *newlist = NULL,*tmp;

    if (list1 == NULL && list2 == NULL)
    	return NULL;
    
    if(list1 == NULL)
        return list2;
 
    if(list2 == NULL)
        return list1;

    newlist = list1;
    tmp = list1;
    list1 = list1->next;
    int i = 0;

    while(1)
    {
        if(i%2 != 0 && list1 != NULL)
        {
            tmp->next = list1;
            list1 = list1->next;
        }
        else if(list2 != NULL)
        {
            tmp->next = list2;
            list2 = list2->next;
        }
        else
        {
            break;
        }
        tmp = tmp->next;
        i++;
    }

    return newlist;
}
int main()
{
    //intializing lists
    node *list1 = createList(), *list2 = createList();
    printf("\nlist1 was\n");
    display(list1);
    printf("\nlist2 was\n");
    display(list2);

    //merging list
    node *newlist = joinAlt(list1,list2);
    printf("\nafter merging lists:");
    display(newlist);
    return 0;
}
