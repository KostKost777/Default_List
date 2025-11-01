#include <TXLib.h>

#include "classic_list_functions.h"
#include "classic_list_set_get_func.h"

// GET

int GetCapacity(struct StructList* list)
{
    assert(list);

    return list->capacity;
}

int GetDataEl(struct StructList* list, int index)
{
    assert(list);

    return list->nodes[index].data;
}

struct ListNode* GetNodesEl(struct StructList* list, int index)
{
    assert(list);

    return &list->nodes[index];
}

struct ListNode* GetNextEl(struct StructList* list, int index)
{
    assert(list);

    return list->nodes[index].next;
}

struct ListNode* GetPrevEl(struct StructList* list, int index)
{
    assert(list);

    return list->nodes[index].prev;
}

struct ListNode* GetFree(struct StructList* list)
{
    assert(list);

    return list->free;
}

// SET

void SetCapacity(struct StructList* list, int value)
{
    assert(list);

    list->capacity = value;
}

void SetDataEl(struct StructList* list, int index, int value)
{
    assert(list);

    list->nodes[index].data = value;
}

void SetNodesEl(struct StructList* list, int index, struct ListNode* node_ptr)
{
    assert(list);
    assert(node_ptr);

    list->nodes[index] = *node_ptr;
}

void SetNextEl(struct StructList* list, int index, struct ListNode* node_ptr)
{
    assert(list);

    list->nodes[index].next = node_ptr;
}

void SetPrevEl(struct StructList* list, int index, struct ListNode* node_ptr)
{
    assert(list);

    list->nodes[index].prev = node_ptr;
}

void SetFree(struct StructList* list, struct ListNode* node_ptr)
{
    assert(list);

    list->free = node_ptr;
}

