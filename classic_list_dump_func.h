#ifndef CLASSIC_LIST_DUMP_FUNCS
#define CLASSIC_LIST_DUMP_FUNCS

extern const char* log_file_name;

extern FILE* log_file;

enum ErrorCodes
{
    list_loop_err =        1,
    list_num_of_el_err =   2,
    list_next_err =        4,
    list_prev_err =        8,
    list_canary_err =      16,
    list_NULL_err =        32,
};

int ListVerifier(struct List* list);

void PrintDumpLog(struct List* list,
                   const int line, const char* func, const char* file,
                   const char* message, ...);

void PrintError(struct List* list);

void PrintBazeEdge(FILE* graphiz_file,
                   const char* name, const char* color, struct ListNode* node);

void PrintEdge(FILE* graphiz_file,
               struct ListNode* name1, struct ListNode* name2,
               const char* color, bool is_oriented);

enum ReturnStatus ListDump(struct List* list,
                           const int line, const char* func, const char* file);

void PrintBazeNode(FILE* graphiz_file, const char* name, const char* color);

void SetNodesRanks(FILE* graphiz_file, struct List* list);

void PrintNode(FILE* graphiz_file, struct ListNode* node, const char* color,
               int data, struct ListNode* next, struct ListNode* prev);

void PrintErrorNode(FILE* graphiz_file,
                    struct ListNode* err_node,
                    const char* color, const char* err_name, struct ListNode* index);

void CreateNodes(FILE* graphiz_file, struct List* list);

void CreateEdges(FILE* graphiz_file, struct List* list);

void FillLogFile(char* image_file_name, struct List* list, int file_counter);

#define LIST_VERIFIER(list)                             \
    if (ListVerifier(list)) {          \
        printf("Ошибка %d\n", GetErrCode(list));                \
        ListDump(list, line, func, file);               \
        return NULL;                                   \
    }                                                   \

#define PRINT_DUMP_LOG(list, message, ...)                                \
        PrintDumpLog(list, line, func, file, message, ##__VA_ARGS__);     \


#endif
