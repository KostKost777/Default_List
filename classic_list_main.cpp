#include <TXLib.h>

#include "classic_list_functions.h"
#include "classic_list_set_get_func.h"

int main()
{
    struct ListNode* node_0 = NULL;

    ListCtor(&node_0);


    printf("0 PTR: %p  DATA: %d  NEXT: %p  PREV: %p\n\n", node_0,
                                                      GetData(node_0),
                                                      GetNext(node_0),
                                                      GetPrev(node_0));

    struct ListNode* node_1 = InsertAfter(node_0, 12);

    struct ListNode* node_2 = InsertBefore(node_1, 10);

    struct ListNode* node_3 = InsertBefore(node_2, 8);

    struct ListNode* node_4 = InsertBefore(node_3, 5);

    printf("0 PTR: %p  DATA: %d  NEXT: %p  PREV: %p\n\n", node_0,
                                                      GetData(node_0),
                                                      GetNext(node_0),
                                                      GetPrev(node_0));

    printf("1 PTR: %p  DATA: %d  NEXT: %p  PREV: %p\n\n", node_1,
                                                      GetData(node_1),
                                                      GetNext(node_1),
                                                      GetPrev(node_1));

    printf("2 PTR: %p  DATA: %d  NEXT: %p  PREV: %p\n\n", node_2,
                                                      GetData(node_2),
                                                      GetNext(node_2),
                                                      GetPrev(node_2));

    printf("3 PTR: %p  DATA: %d  NEXT: %p  PREV: %p\n\n", node_3,
                                                      GetData(node_3),
                                                      GetNext(node_3),
                                                      GetPrev(node_3));

    printf("4 PTR: %p  DATA: %d  NEXT: %p  PREV: %p\n\n", node_4,
                                                      GetData(node_4),
                                                      GetNext(node_4),
                                                      GetPrev(node_4));

    for (ListNode* i = GetNext(node_0); i != node_0; i = GetNext(i)) {

        printf("DATA: %d\n", GetData(i));

    }

    printf("\n");

    ListDtor(node_0);
    printf("END");
    return 0;

}
