#ifndef SET_GET_CLASSIC_LIST_FUNC
#define SET_GET_CLASSIC_LIST_FUNC

// GET

int GetCapacity(struct StructList* list);

int GetDataEl(struct StructList* list, int index);

struct ListNode* GetNextEl(struct StructList* list, int index);

struct ListNode* GetPrevEl(struct StructList* list, int index);

struct ListNode* GetFree(struct StructList* list);

struct ListNode* GetNodesEl(struct StructList* list, int index);

// SET

void SetCapacity(struct StructList* list, int value);

void SetDataEl(struct StructList* list, int index, int value);

void SetNodesEl(struct StructList* list, int index, struct ListNode* node_ptr);

void SetNextEl(struct StructList* list, int index, struct ListNode* node_ptr);

void SetPrevEl(struct StructList* list, int index, struct ListNode* node_ptr);

void SetFree(struct StructList* list, struct ListNode* node_ptr);


#endif
