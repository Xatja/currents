#include <stdio.h>
#include "linkedlist.h"

int main(int argc, char* argv[]) {
    list_t_int *integer_list = build_list_int();
    list_t_float *float_list = build_list_float();

    int integer1 = 10;
    int integer2 = 20;
    float float1 = 10.0;
    float float2 = 20.0;

    push_int(integer_list, &integer1);
    add_int(integer_list, &integer2);

    push_float(float_list, &float1);
    push_float(float_list, &float1);
    add_float(float_list, &float2);

    printf("Size: %zu\n", size_int(integer_list));
    printf("Size: %zu\n", size_float(float_list));

    clear_int(integer_list);
    clear_float(float_list);

    printf("Size: %zu\n", size_int(integer_list));
    printf("Size: %zu\n", size_float(float_list));

    destroy_float(float_list);
    destroy_int(integer_list);

    return 0;
}