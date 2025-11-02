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

ReturnStatus ListCtor(struct ListNode** node);

struct ListNode* InsertAfter(struct ListNode* node, int value);

struct ListNode* InsertBefore(struct ListNode* node, int value);

void DeleteElement(struct ListNode* node);

void ListDtor(struct ListNode* node_0);

#define INSERT_AFTER(node, element, label)                        \
    if ((out_index = InsertAfter(node, element,                          \
                    __LINE__, __func__, __FILE__)) == -1) {      \
        goto label;                                                \
    }

#define INSERT_BEFORE(node, element, label)                        \
    if ((out_index = InsertBefore(node, element,                          \
                    __LINE__, __func__, __FILE__)) == -1) {      \
        goto label;                                                \
    }

#define DELETE_ELEMENT(node, label)                        \
    if ((out_index = DeleteElement(node,                          \
                    __LINE__, __func__, __FILE__)) == -1) {      \
        goto label;                                                \
    }



#endif
