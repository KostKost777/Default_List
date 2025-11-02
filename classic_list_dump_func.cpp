#include <TXLib.h>

#include "classic_list_functions.h"
#include "classic_list_set_get_func.h"
#include "classic_list_dump_func.h"

int ListVerifier(struct ListNode* node)
{
    assert(node != NULL);

    int err_code = 0;

    int counter = 0;

    for (struct ListNode* i = GetNext(node); i != node; i = GetNext(i)) {

        if (i == NULL) {
            err_code |= list_NULL_err;
            return err_code;
        }

        if (GetNext(i) == NULL) {
            err_code |= list_next_err;
            return err_code;
        }

        if (GetPrev(i) == NULL) {
            err_code |= list_prev_err;
            return err_code;
        }

        if (GetPrev(GetNext(i)) != i)
            err_code |= list_loop_err;

        if (GetNext(GetPrev(i)) != i)
            err_code |= list_loop_err;

        counter++;
    }

    return err_code;
}





