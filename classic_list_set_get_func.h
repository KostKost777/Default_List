#ifndef SET_GET_CLASSIC_LIST_FUNC
#define SET_GET_CLASSIC_LIST_FUNC

int GetData(struct ListNode* node);

struct ListNode* GetNext(struct ListNode* node);

struct ListNode* GetPrev(struct ListNode* node);

// SET

void SetData(struct ListNode* node, int value);

void SetNext(struct ListNode* node, struct ListNode* new_node);

void SetPrev(struct ListNode* node, struct ListNode* new_node);

#endif
