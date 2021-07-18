#include "linkedlist.h"

int main(int argc, char** argv) {
    List *list = build_list();
    add(list, 10);
    add(list, 20);
    add(list, 30);
    add(list, 40);
    push(list, 0);
    push(list, -10);

    print(list);
    printf("%zu\n", size(list));
    return 0;
}