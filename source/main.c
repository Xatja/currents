#include "linkedlist.h"

int main(int argc, char* argv[]) {
    List *list = build_list();

    int item1 = 10;
    float item2 = 20.0;

    add(list, &item1, INTEGER);
    add(list, &item2, FLOAT);

    delete_at_index(list, 0);
    clear(list);

    printf("Size of list: %zu\n", size(list));

    destroy(list);

    return 0;
}