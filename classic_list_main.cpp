#include <TXLib.h>

#include "classic_list_functions.h"
#include "classic_list_set_get_func.h"
#include "classic_list_dump_func.h"

int main()
{
    struct ListNode* ret_value = NULL;

    struct ListNode* node_0 = NULL;

    ListCtor(&node_0);


    printf("0 PTR: %p  DATA: %d  NEXT: %p  PREV: %p\n\n", node_0,
                                                      GetData(node_0),
                                                      GetNext(node_0),
                                                      GetPrev(node_0));

    INSERT_AFTER(node_0, 12, exit_label);

    INSERT_BEFORE(ret_value, 10, exit_label);

    INSERT_BEFORE(ret_value, 8, exit_label);

    INSERT_BEFORE(ret_value, 5, exit_label);

    for (ListNode* i = GetNext(node_0); i != node_0; i = GetNext(i)) {

        printf("DATA: %d\n", GetData(i));

    }

    printf("\n");

    exit_label:

        ListDtor(node_0);

        if (ret_value == NULL) {

            printf("END WITH ERROR\n");
            return 1;
        }

        printf("END SUCCESS\n");
        return 0;

}
