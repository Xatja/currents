#include "linkedlist.h"

int main(int argc, char** argv) {
    List *list = build_list();
    add(list, 10);
    add(list, 20);
    add(list, 30);
    add(list, 40);
    push(list, 0);
    push(list, -10);
    insert(list, 2, 200);

    int data = value_at_index(list, 3);
    printf("Value: %d\n", data);

    print(list);
    printf("%zu\n", size(list));
    
    return 0;
}