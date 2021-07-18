#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>

#include "../source/linkedlist.h"

static void list_int_add_node(void **state) {
    (void**) state;

    list_t_int *sut = build_list_int();
    int item = 100;
    add_int(sut, &item);
    assert_int_equal(size_int(sut), 1);
    destroy_int(sut);
}

static void list_float_add_node(void **state) {
    (void**) state;

    list_t_float *sut = build_list_float();
    float item = 100.0f;
    add_float(sut, &item);
    assert_int_equal(size_float(sut), 1);
    destroy_float(sut);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(list_int_add_node),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}