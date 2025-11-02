#ifndef CLASSIC_LIST_DUMP_FUNCS
#define CLASSIC_LIST_DUMP_FUNCS

enum ErrorCodes
{
    list_loop_err =        1,
    list_num_of_el_err =   2,
    list_next_err =        4,
    list_prev_err =        8,
    list_canary_err =      16,
    list_NULL_err =        32,
};

int ListVerifier(struct ListNode* node);

#define LIST_VERIFIER(node)                             \
    if (ListVerifier(node)) {          \
        printf("Ошибка \n");                \
                       \
        return NULL;                                   \
    }                                                   \

#define PRINT_DUMP_LOG(list, message, ...)                                \
        PrintDumpLog(list, line, func, file, message, ##__VA_ARGS__);     \


#endif
