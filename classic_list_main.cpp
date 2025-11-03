#include <TXLib.h>

#include "classic_list_functions.h"
#include "classic_list_set_get_func.h"
#include "classic_list_dump_func.h"

int main()
{
    atexit(CloseLogFile);

    struct ListNode* ret_value = NULL;

    struct List list = {};

    if (OpenLogFile())
        goto exit_label;

    if (ListCtor(&list))
        goto exit_label;


    printf("0 PTR: %p  DATA: %d  NEXT: %p  PREV: %p\n\n", GetNode_0(&list),
                                                      GetData(GetNode_0(&list)),
                                                      GetNext(GetNode_0(&list)),
                                                      GetPrev(GetNode_0(&list)));

    INSERT_AFTER(&list, GetNode_0(&list), 12, exit_label);

    INSERT_BEFORE(&list, ret_value, 10, exit_label);

    ret_value->next = NULL;

    INSERT_BEFORE(&list, ret_value, 8, exit_label);

    INSERT_BEFORE(&list, ret_value, 5, exit_label);

    DELETE_ELEMENT(&list, ret_value, exit_label);

    for (ListNode* i = GetNext(GetNode_0(&list)); i != GetNode_0(&list); i = GetNext(i)) {

        printf("DATA: %d\n", GetData(i));

    }

    printf("\n");

    exit_label:

        ListDtor(&list);

        if (ret_value == NULL) {

            printf("END WITH ERROR\n");
            return 1;
        }

        printf("END SUCCESS\n");
        return 0;

}
