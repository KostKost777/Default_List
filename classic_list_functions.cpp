#include <TXLib.h>

#include "classic_list_functions.h"
#include "classic_list_set_get_func.h"

ReturnStatus ListCtor(struct ListNode** node_0)
{

    *node_0 =(ListNode*)calloc(1, sizeof(struct ListNode));

    if (node_0 == NULL){
        printf("Not allocate memory\n");
        return error;
    }

    SetNext(*node_0, *node_0);
    SetPrev(*node_0, *node_0);
    SetData(*node_0, PZN);

    return success;
}

void ListDtor(struct ListNode* node_0)
{
    assert(node_0);

    for (ListNode* i = GetNext(node_0); i != node_0; i = GetNext(i)) {

        //printf("PTR: %p  NEXT_PTR: %p\n", i, GetNext(i));
        free(i);
    }
}

struct ListNode* InsertAfter(struct ListNode* node, int value)
{
    assert(node != NULL);

    ListNode* new_node =(ListNode*)calloc(1, sizeof(struct ListNode));

    assert(new_node != NULL);

    SetPrev(new_node, node);
    SetNext(new_node, GetNext(node));

    SetData(new_node, value);

    SetPrev(GetNext(node), new_node);

    SetNext(node, new_node);

    return new_node;
}

struct ListNode* InsertBefore(struct ListNode* node, int value)
{
    assert(node != NULL);

    return InsertAfter(GetPrev(node), value);
}

void DeleteElement(struct ListNode* node)
{
    assert(node != NULL);

    SetNext(GetPrev(node), GetNext(node));
    SetPrev(GetNext(node), GetPrev(node));

}




