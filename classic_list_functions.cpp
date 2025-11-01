#include <TXLib.h>

#include "classic_list_functions.h"
#include "classic_list_set_get_func.h"

ReturnStatus ListCtor(struct StructList* list, int capacity)
{
    assert(list != NULL);

    SetCapacity(list, capacity);

    list->nodes = (ListNode*)calloc(GetCapacity(list), sizeof(ListNode));

    if (list->nodes == NULL) {
        printf("Memory was not allocated");
        return error;
    }

    SetDefaultNodes(list);

    SetFree(list, GetNodesEl(list, 1));

    return success;

}

void SetDefaultNodes(struct StructList* list)
{
    SetNextEl(list, 0, NULL);
    SetPrevEl(list, 0, NULL);
    SetDataEl(list, 0, CANARY);

    for (int i = 1; i < GetCapacity(list); ++i) {

        SetDataEl(list, i, PZN);

        if (i < GetCapacity(list) - 1) {
            SetNextEl(list, i, GetNodesEl(list, i + 1));
        }

        SetPrevEl(list, i, NULL);

    }

    SetNextEl(list, GetCapacity(list) - 1, GetNodesEl(list, 0));

}

void ListDtor(struct StructList* list)
{
    assert(list);

    free(list->nodes);

    list->nodes = NULL;
}




