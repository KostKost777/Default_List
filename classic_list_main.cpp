#include <TXLib.h>

#include "classic_list_functions.h"
#include "classic_list_set_get_func.h"

int main()
{
    struct StructList list = {};

    if (ListCtor(&list, 10))
        goto exit_label;

    //INSERT_AFTER(&list, 0, 100, exit_label);

    exit_label:

        ListDtor(&list);
        printf("END");
        return 0;

    return 0;

}
