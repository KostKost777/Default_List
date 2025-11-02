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
