#include "llio.h"

void shiftFirstElement( node **list1,  node **list2)
{	
    if(*list2 == NULL) return;
    node *tmp = *list2;
    *list2 = tmp->next;
    tmp->next = *list1;
    *list1 = tmp;
}

int main()
{
    node *list1 = createList(), *list2 = createList();
    shiftFirstElement(&list1,&list2);
    printf("\nList1 is: ");
    display(list1);
    printf("\nList2 is ");
    display(list2);
}
 