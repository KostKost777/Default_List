#include <TXLib.h>

#include "classic_list_functions.h"
#include "classic_list_set_get_func.h"
#include "classic_list_dump_func.h"

const char* log_file_name = "";
FILE* log_file = NULL;

static char* GetNewDotCmd(int file_counter)
{
    char str_command[100] = "";

    snprintf(str_command, sizeof(str_command),
            "dot -Tpng image%d.txt -o image%d.png",
             file_counter, file_counter);

    return strdup(str_command);
}

static char* GetNewImageFileName(int file_counter)
{
    char str_file_counter[100] = "";

    snprintf(str_file_counter, sizeof(str_file_counter),
             "image%d.txt", file_counter);

    return strdup(str_file_counter);
}

void PrintNode(FILE* graphiz_file, struct ListNode* node, const char* color,
               int data, struct ListNode* next, struct ListNode* prev)
{
    assert(color != NULL);
    assert(graphiz_file != NULL);

    fprintf(graphiz_file, "node%p "
                          "[shape = Mrecord; "
                          "style = filled; "
                          "fillcolor = \"%s\"; "
                          "color = \"#00000\"; "
                          "label = \"{PTR = %p |"
                          "DATA = %d | "
                          "NEXT = %p | "
                          "PREV = %p }\"; ]\n",
                           node, color, node, data, next, prev);
}

void PrintBazeNode(FILE* graphiz_file, const char* name, const char* color)
{
    assert(name != NULL);
    assert(color != NULL);
    assert(graphiz_file != NULL);

    fprintf(graphiz_file, "%s "
                          "[shape = Mrecord; "
                          "style = filled; "
                          "fillcolor = \"%s\"; "
                          "color = \"#00000\"; "
                          "label = \"%s\"; ]\n",
                          name, color, name);
}

void SetNodesRanks(FILE* graphiz_file, struct List* list)
{
    assert(graphiz_file != NULL);
    assert(list != NULL);
    assert(list->node_0 != NULL);

    fprintf(graphiz_file, "{ rank = same; ");

    fprintf(graphiz_file, "node%p; ", GetNode_0(list));

    for (struct ListNode* i = GetNext(GetNode_0(list));
         i != NULL && i != GetNode_0(list); i = GetNext(i))

        fprintf(graphiz_file, "node%p; ", i);

    fprintf(graphiz_file, "}\n");

    fprintf(graphiz_file, "{ rank = same; HEAD; TAIL}\n");

    for (struct ListNode* i = GetNext(GetNode_0(list));
         i != NULL && i != GetPrev(GetNode_0(list)); i = GetNext(i))

        fprintf(graphiz_file, "node%p -> node%p "
                              "[color = \"transparent\";"
                              " weight=10]\n", i, GetNext(i));

    fprintf(graphiz_file, "node%p -> node%p "
                              "[color = \"transparent\";"
                              " weight=10]\n", GetNode_0(list), GetHead(list));
}

void CreateNodes(FILE* graphiz_file, struct List* list)
{
    assert(graphiz_file != NULL);
    assert(list != NULL);
    assert(list->node_0 != NULL);

    PrintBazeNode(graphiz_file, "HEAD", "#F2B138");
    PrintBazeNode(graphiz_file, "TAIL", "#B2A4F0");

    PrintNode(graphiz_file, GetNode_0(list), "#F984E5", GetData(GetNode_0(list)),
                                                        GetNext(GetNode_0(list)),
                                                        GetPrev(GetNode_0(list)));

    const char* color = NULL;

    //Создание вершин

    for (struct ListNode* i = GetNext(GetNode_0(list));
         i != NULL && i != GetNode_0(list); i = GetNext(i)) {

        if(i == GetHead(list))

            color = "#F2B138";

        else if (i == GetTail(list))

            color = "#B2A4F0";

        else

            color = "#87CEEB";

        PrintNode(graphiz_file, i, color, GetData(i),
                                          GetNext(i),
                                          GetPrev(i));
    }

}

void PrintBazeEdge(FILE* graphiz_file,
                   const char* name, const char* color, struct ListNode* node)
{
    assert(name != NULL);
    assert(color != NULL);
    assert(graphiz_file != NULL);
    assert(node != NULL);

    fprintf(graphiz_file, "%s -> node%p "
                          "[color = \"%s\","
                          " weight=10]\n", name, node, color);
}

void PrintEdge(FILE* graphiz_file,
               struct ListNode* name1, struct ListNode* name2,
               const char* color, bool is_oriented)
{
    assert(name1 != NULL);
    assert(name2 != NULL);
    assert(color != NULL);
    assert(graphiz_file != NULL);

    if (is_oriented)

        fprintf(graphiz_file, "node%p -> node%p "
                              "[color = \"%s\", "
                              " penwidth = 1.0, "
                              " weight=0]\n", name1, name2, color);

    else

        fprintf(graphiz_file, "node%p -> node%p "
                              "[color = \"%s\", "
                              " penwidth = 1.0, "
                              " dir = both, "
                              " weight=0]\n", name1, name2, color);

}

void PrintErrorNode(FILE* graphiz_file,
                    struct ListNode* err_node,
                    const char* color, const char* err_name, struct ListNode* index)
{
    assert(color != NULL);
    assert(err_name != NULL);
    assert(graphiz_file != NULL);

    static int name = 0;

    fprintf(graphiz_file, "error%d "
                          "[shape = Mrecord; "
                          "style = filled; "
                          "fillcolor = \"%s\"; "
                          "color = \"#00000\"; "
                          "label = \"{ %s: %p }\"]\n",
                           name, color, err_name, err_node);

    fprintf(graphiz_file, "node%p -> error%d "
                          "[color = \"black\", "
                          " penwidth = 2.0, "
                          " fillcolor = \"red\", "
                          " style = \"filled\", "
                          " arrowsize = 1.5, "
                          " weight=0]\n", index, name);

    name++;
}

void CreateEdges(FILE* graphiz_file, struct List* list)
{
    assert(graphiz_file != NULL);
    assert(list != NULL);
    assert(list->node_0 != NULL);

    PrintBazeEdge(graphiz_file, "HEAD", "#F2B138", GetHead(list));
    PrintBazeEdge(graphiz_file, "TAIL", "#B2A4F0", GetTail(list));

    for (struct ListNode* i = GetNext(GetNode_0(list));
         i != NULL && i != GetNode_0(list); i = GetNext(i)) {

        //Если индекс валидный

        if (GetNext(i) != NULL && GetPrev(i) != NULL) {

            if ( i != GetNext(GetPrev(i)) )

                PrintEdge(graphiz_file, i, GetPrev(i), "black", true);

            if ( i != GetPrev(GetNext(i)) )

                PrintEdge(graphiz_file, i, GetNext(i), "black", true);

            if (   i == GetPrev(GetNext(i))
                && i == GetNext(GetPrev(i)) )

                PrintEdge(graphiz_file, i, GetPrev(i), "black", false);

            continue;

        }

        //Если индекс не валидный

        if (GetNext(i) == NULL)

            PrintErrorNode(graphiz_file, GetNext(i), "#FF0000", "NEXT_ERR", i);

        if (GetPrev(i) == NULL)

            PrintErrorNode(graphiz_file, GetPrev(i), "#FF0000", "PREV_ERR", i);

    }
}

int ListVerifier(struct List* list)
{
    assert(list != NULL);

    if (GetNode_0(list) == NULL) {
        list->err_code |= list_NULL_err;
        return list->err_code;
    }

    if (GetData(GetNode_0(list)) != CANARY)
        list->err_code |= list_canary_err;

    if (GetNumOfEl(list) < 0 || GetNumOfEl(list) >= MAX_SIZE)
        list->err_code |= list_num_of_el_err;

    int counter = 0;

    for (struct ListNode* i = GetNext(GetNode_0(list));
         i != GetNode_0(list); i = GetNext(i)) {

        if (i == NULL) {
            list->err_code |= list_NULL_err;
            return list->err_code;
        }

        if (GetNext(i) == NULL) {
            list->err_code |= list_next_err;
            return list->err_code;
        }

        if (GetPrev(i) == NULL) {
            list->err_code |= list_prev_err;
            return list->err_code;
        }

        if (GetPrev(GetNext(i)) != i) {
            list->err_code |= list_loop_err;
            //printf("I: %p   GP_GN_I: %p\n", i, GetPrev(GetNext(i)));
        }

        if (GetNext(GetPrev(i)) != i) {
            list->err_code |= list_loop_err;
            //printf("I: %p   GN_GP_I: %p\n", i, GetPrev(GetNext(i)));
        }

        counter++;
    }

    if (counter != GetNumOfEl(list))
        list->err_code |= list_loop_err;

    //printf("NUMOFEL: %d  COUNTER: %d\n", GetNumOfEl(list), counter);

    //printf("ERR_CODE: %d\n", list->err_code);
    return list->err_code;
}

void PrintDumpLog(struct List* list,
                   const int line, const char* func, const char* file,
                   const char* message, ...)
{
    assert(list != NULL);
    assert(func != NULL);
    assert(file != NULL);
    assert(message != NULL);

    va_list args;
    va_start(args, message);

    vfprintf(log_file, message, args);
    fflush(log_file);

    va_end(args);

    ListDump(list, line, func, file);
}

void PrintError(struct List* list)
{
    assert(list != NULL);

    if (GetErrCode(list) & list_loop_err)
        fprintf(log_file, "BAD_LIST_LOOP - [%d]\n", list_loop_err);;

    if (GetErrCode(list) & list_next_err)
        fprintf(log_file, "BAD_NEXT - [%d]\n", list_next_err);

    if (GetErrCode(list) & list_prev_err)
        fprintf(log_file, "BAD_PREV - [%d]\n", list_loop_err);

    if (GetErrCode(list) & list_canary_err)
        fprintf(log_file, "BAD_CANARY - [%d]\n", list_canary_err);

    if (GetErrCode(list) & list_num_of_el_err)
        fprintf(log_file, "BAD_NUM_OF_ELEMENT - [%d]\n", list_num_of_el_err);

    if (GetErrCode(list) & list_NULL_err)
        fprintf(log_file, "BAD_NULL_PTR - [%d]\n", list_NULL_err);
}

enum ReturnStatus ListDump(struct List* list,
                           const int line, const char* func, const char* file)
{
    assert(list);
    assert(func);
    assert(file);

    fprintf(log_file, "<h4>CLASSIC_LIST { %s %s:%d }</h4>", func, file, line);

    if (GetErrCode(list) != 0)
        PrintError(list);

    static int file_counter = 0;

    char* image_file_name = GetNewImageFileName(file_counter);

    FILE* graphiz_file = fopen(image_file_name, "w");

    fprintf(graphiz_file, "digraph {\n"
                          "rankdir = HR;\n"
                          "splines = ortho\n"
                          "ranksep = 1.0\n"
                          "nodesep = 0.5\n");

    //Создание вершин

    CreateNodes(graphiz_file, list);

    //Установка ранков

    SetNodesRanks(graphiz_file, list);

    //Создание ребер

    CreateEdges(graphiz_file, list);

    fprintf(graphiz_file, "}");

    fclose(graphiz_file);
    free(image_file_name);

    char* command = GetNewDotCmd(file_counter);

    system(command);
    free(command);

    FillLogFile(image_file_name, list, file_counter);

    file_counter++;

    return success;

}

void FillLogFile(char* image_file_name, struct List* list, int file_counter)
{
    assert(image_file_name != NULL);
    assert(list != NULL);

    fprintf(log_file, "\nHEAD: %p\n", GetHead(list));
    fprintf(log_file, "TAIL: %p\n", GetTail(list));
    fprintf(log_file, "NUMBER OF ELEMENTS: %d\n\n", GetNumOfEl(list));

    fprintf(log_file, "PTR: ");

    for (struct ListNode* i = GetNext(GetNode_0(list));
         i != NULL && i != GetNode_0(list); i = GetNext(i)) {

        fprintf(log_file, "|%10p| ", i);
    }

    fprintf(log_file, "\nDATA: ");

    for (struct ListNode* i = GetNext(GetNode_0(list));
         i != NULL && i != GetNode_0(list); i = GetNext(i)) {

        fprintf(log_file, "|%10d| ", GetData(i));
    }

    fprintf(log_file, "\nNEXT: ");

    for (struct ListNode* i = GetNext(GetNode_0(list));
         i != NULL && i != GetNode_0(list); i = GetNext(i)) {

        fprintf(log_file, "|%10p| ", GetNext(i));
    }

    fprintf(log_file, "\nPREV: ");

    for (struct ListNode* i = GetNext(GetNode_0(list));
         i != NULL && i != GetNode_0(list); i = GetNext(i)) {

        fprintf(log_file, "|%10p| ", GetPrev(i));
    }

    fprintf(log_file, "\n\n<img src=image%d.png width=%dpx>\n\n",
                                                    file_counter,
                                                    (GetNumOfEl(list) + 1) * 150);

    fprintf(log_file, "-------------------------------------------------------\n\n");

    fflush(log_file);
}







