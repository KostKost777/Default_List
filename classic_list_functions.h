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

struct StructList
{
    int capacity;
    struct ListNode* free;
    struct ListNode* nodes;
};

void SetDefaultNodes(struct StructList* list);

ReturnStatus ListCtor(struct StructList* list, int capacity);

void ListDtor(struct StructList* list);




#endif
