#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>

#include "../source/linkedlist.h"

static void list_add_node(void **state) {
    List *sut = build_list();
    int expected = 10;
    
    add(sut, expected);
    int result = value_at_index(sut, 0);

    assert_int_equal(expected, result);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(list_add_node),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}