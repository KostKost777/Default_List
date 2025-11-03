#include <TXLib.h>

#include "classic_list_functions.h"
#include "classic_list_set_get_func.h"

// GET

int GetData(struct ListNode* node)
{
    assert(node != NULL);

    return node->data;
}

struct ListNode* GetNext(struct ListNode* node)
{
    assert(node != NULL);

    return node->next;
}

struct ListNode* GetPrev(struct ListNode* node)
{
    assert(node != NULL);

    return node->prev;
}

struct ListNode* GetNode_0(struct List* list)
{
    assert(list != NULL);

    return list->node_0;
}

int GetNumOfEl(struct List* list)
{
    assert(list != NULL);

    return list->num_of_el;
}

int GetErrCode(struct List* list)
{
    assert(list != NULL);

    return list->err_code;
}

struct ListNode* GetHead(struct List* list)
{
    assert(list != NULL);
    assert(list->node_0 != NULL);

    return GetNext(list->node_0);
}

struct ListNode* GetTail(struct List* list)
{
    assert(list != NULL);
    assert(list->node_0 != NULL);

    return GetPrev(list->node_0);
}

// SET

void SetData(struct ListNode* node, int value)
{
    assert(node!= NULL);

    node->data = value;
}

void SetNext(struct ListNode* node, struct ListNode* new_node)
{
    assert(node != NULL);
    assert(new_node != NULL);

    node->next = new_node;
}

void SetPrev(struct ListNode* node, struct ListNode* new_node)
{
    assert(node != NULL);

    node->prev = new_node;
}

void SetNumOfEl(struct List* list, int value)
{
    assert(list != NULL);

    list->num_of_el = value;
}
