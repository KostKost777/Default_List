#include <TXLib.h>

#include "classic_list_functions.h"
#include "classic_list_set_get_func.h"
#include "classic_list_dump_func.h"

ReturnStatus ListCtor(struct List* list)
{

    list->node_0 =(ListNode*)calloc(1, sizeof(struct ListNode));

    if (list->node_0 == NULL){
        printf("Not allocate memory\n");
        return error;
    }

    SetData(GetNode_0(list), CANARY);
    SetNumOfEl(list, 0);

    SetNext(list->node_0, list->node_0);
    SetPrev(list->node_0, list->node_0);
    SetData(list->node_0, CANARY);

    return success;
}

void ListDtor(struct List* list)
{
    assert(list);
    assert(GetNode_0(list));

    for (ListNode* i = GetNext(GetNode_0(list));
         i != NULL && i != GetNode_0(list); i = GetNext(i)) {

        //printf("PTR: %p  NEXT_PTR: %p\n", i, GetNext(i));
        free(i);
    }

    free(GetNode_0(list));
}

struct ListNode* Insert(struct List* list, struct ListNode* node, int value)
{
    assert(node != NULL);

    ListNode* new_node =(ListNode*)calloc(1, sizeof(struct ListNode));

    assert(new_node != NULL);

    SetPrev(new_node, node);
    SetNext(new_node, GetNext(node));

    SetData(new_node, value);

    SetPrev(GetNext(node), new_node);

    SetNext(node, new_node);

    SetNumOfEl(list, GetNumOfEl(list) + 1);

    return new_node;
}

struct ListNode* InsertAfter(struct List* list, struct ListNode* node,
                             int value,
                             int line, const char* func, const char* file)
{
    assert(node != NULL);
    assert(list != NULL);
    assert(func != NULL);
    assert(file != NULL);

    LIST_VERIFIER(list);

    PRINT_DUMP_LOG(list, "\n<h3>\nDUMP: Before InsertAfter(%p, %d)</h3>\n",
                                                           node, value);
    struct ListNode* new_node = Insert(list, node, value);

    LIST_VERIFIER(list);

    PRINT_DUMP_LOG(list, "\n<h3>\nDUMP: After InsertAfter(%p, %d)</h3>\n",
                                                           node, value);
    return new_node;
}

struct ListNode* InsertBefore(struct List* list, struct ListNode* node,
                              int value,
                              int line, const char* func, const char* file)
{
    assert(node != NULL);
    assert(list != NULL);
    assert(func != NULL);
    assert(file != NULL);

    LIST_VERIFIER(list);

    PRINT_DUMP_LOG(list, "\n<h3>\nDUMP: Before InsertBefore(%p, %d)</h3>\n",
                                                           node, value);

    struct ListNode* new_node = Insert(list, GetPrev(node), value);

    LIST_VERIFIER(list);

    PRINT_DUMP_LOG(list, "\n<h3>\nDUMP: After InsertBefore(%p, %d)</h3>\n",
                                                           node, value);

    return new_node;

}

struct ListNode* DeleteElement(struct List* list, struct ListNode* node,
                               int line, const char* func, const char* file)
{
    assert(node != NULL);
    assert(list != NULL);
    assert(func != NULL);
    assert(file != NULL);

    LIST_VERIFIER(list);

    PRINT_DUMP_LOG(list, "\n<h3>\nDUMP: Before Delete(%p)</h3>\n", node);

    struct ListNode* ret_val = GetPrev(node);

    SetNext(GetPrev(node), GetNext(node));
    SetPrev(GetNext(node), GetPrev(node));
    SetNumOfEl(list, GetNumOfEl(list) - 1);

    LIST_VERIFIER(list);

    PRINT_DUMP_LOG(list, "\n<h3>\nDUMP: After Delete(%p)</h3>\n", node);

    free(node);
    node = NULL;

    return ret_val;
}

void CloseLogFile()
{
    fclose(log_file);
    printf("Logfile close\n");
}

enum ReturnStatus OpenLogFile()
{
    log_file_name = "classic_list_logs.html";

    log_file = fopen(log_file_name, "w");

    if (log_file == NULL) {
        printf("Logfile open error\n");
        return error;
    }

    printf("Logfile open success\n");

    fprintf(log_file, "<pre>\n");

    return success;
}




