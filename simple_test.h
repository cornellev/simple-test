/*
 * simple_test.h : Extremely bare-bones testing framework for C.
 * @author Ethan Uppal
 * @copyright Copyright (C) 2024 Ethan Uppal. All rights reserved.
 */

#pragma once

#include <stdio.h>
#include <stdlib.h>

#ifdef TEST
void test_main(void);

int main() {
    test_main();
    fprintf(stderr, "All test passed!\n");
    return 0;
}
#endif

#define assert_equal(exp, act)                                                 \
    test_assert_equal((exp) == (act), #exp, #act, __FILE__, __FUNCTION__,      \
        __LINE__)

#define assert_true(val)                                                       \
    test_assert_true(val, #val, "true", __FILE__, __FUNCTION__, __LINE__)

#define assert_false(val)                                                      \
    test_assert_true(!(val), #val, "false", __FILE__, __FUNCTION__, __LINE__)

static void test_assert_equal(bool result, const char* exp, const char* act,
    const char* file, const char* func, int line) {
    if (!result) {
        fprintf(stderr,
            "%s: assert_equal failed %s:%d: %s is not equal to %s\n", func,
            file, line, act, exp);
        exit(1);
    }
}

static void test_assert_true(bool result, const char* expr, const char* type,
    const char* file, const char* func, int line) {
    if (!result) {
        fprintf(stderr, "%s: assert_%s failed at %s:%d: %s is not %s\n", func,
            type, file, line, expr, type);
        exit(1);
    }
}
