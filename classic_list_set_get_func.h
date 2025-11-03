#ifndef SET_GET_CLASSIC_LIST_FUNC
#define SET_GET_CLASSIC_LIST_FUNC

int GetData(struct ListNode* node);

struct ListNode* GetNext(struct ListNode* node);

struct ListNode* GetPrev(struct ListNode* node);

struct ListNode* GetNode_0(struct List* list);

int GetErrCode(struct List* list);

int GetNumOfEl(struct List* list);

struct ListNode* GetHead(struct List* list);

struct ListNode* GetTail(struct List* list);


// SET

void SetData(struct ListNode* node, int value);

void SetNext(struct ListNode* node, struct ListNode* new_node);

void SetPrev(struct ListNode* node, struct ListNode* new_node);

void SetNumOfEl(struct List* list, int value);

#endif
