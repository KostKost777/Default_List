#ifndef CLASSIC_LIST_FUNC
#define CLASSIC_LIST_FUNC

const int PZN = 228;

const int CANARY= 999;

enum ReturnStatus
{
    success = 0,
    error = -1,
    fatal_error = -2,
};

struct ListNode
{
    int data;
    struct ListNode* prev;
    struct ListNode* next;
};

ReturnStatus ListCtor(struct ListNode** node_0);

struct ListNode* InsertAfter(struct ListNode* node, int value,
                             int line, const char* func,const char* file);

struct ListNode* InsertBefore(struct ListNode* node, int value,
                              int line, const char* func,const char* file);

struct ListNode* DeleteElement(struct ListNode* node,
                               int line, const char* func, const char* file);

void ListDtor(struct ListNode* node_0);

struct ListNode* Insert(struct ListNode*, int value);

#define INSERT_AFTER(node, element, label)                        \
    if ((ret_value = InsertAfter(node, element,                          \
                    __LINE__, __func__, __FILE__)) == NULL) {      \
        goto label;                                                \
    }

#define INSERT_BEFORE(node, element, label)                        \
    if ((ret_value = InsertBefore(node, element,                          \
                    __LINE__, __func__, __FILE__)) == NULL) {      \
        goto label;                                                \
    }

#define DELETE_ELEMENT(node, label)                        \
    if ((ret_value = DeleteElement(node,                          \
                    __LINE__, __func__, __FILE__)) == NULL) {      \
        goto label;                                                \
    }



#endif
