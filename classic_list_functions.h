#ifndef CLASSIC_LIST_FUNC
#define CLASSIC_LIST_FUNC

const int CANARY= 999;

const int MAX_SIZE = 10E6;

enum ReturnStatus
{
    success = 0,
    error = -1,
    fatal_error = -2,
};

struct List
{
    int num_of_el;
    int err_code;
    struct ListNode* node_0;
};

struct ListNode
{
    int data;
    struct ListNode* prev;
    struct ListNode* next;
};

ReturnStatus ListCtor(struct List* list);

enum ReturnStatus OpenLogFile();

void CloseLogFile();

struct ListNode* InsertAfter(struct List* list, struct ListNode* node,
                             int value,
                             int line, const char* func, const char* file);

struct ListNode* InsertBefore(struct List* list, struct ListNode* node,
                              int value,
                              int line, const char* func, const char* file);

struct ListNode* DeleteElement(struct List* list, struct ListNode* node,
                               int line, const char* func, const char* file);

void ListDtor(struct List* list);

struct ListNode* Insert(struct List* list, struct ListNode* node, int value);

#define INSERT_AFTER(list, node, element, label)                        \
    if ((ret_value = InsertAfter(list, node, element,                          \
                    __LINE__, __func__, __FILE__)) == NULL) {      \
        goto label;                                                \
    }

#define INSERT_BEFORE(list, node, element, label)                        \
    if ((ret_value = InsertBefore(list, node, element,                          \
                    __LINE__, __func__, __FILE__)) == NULL) {      \
        goto label;                                                \
    }

#define DELETE_ELEMENT(list, node, label)                        \
    if ((ret_value = DeleteElement(list, node,                          \
                    __LINE__, __func__, __FILE__)) == NULL) {      \
        goto label;                                                \
    }



#endif
