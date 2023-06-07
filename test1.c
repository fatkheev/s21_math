#include <stdlib.h> 
#include <check.h>
#include "s21_math.h"

START_TEST(abc_test)
{
  ck_assert_int_eq(s21_abs(-2), abs(-2));
}
END_TEST

Suite *s21_math_tests_create()
{
    Suite *s21_math = suite_create("s21_math");
    TCase *s21_math_tests = tcase_create("s21_math_tests");
    suite_add_tcase(s21_math, s21_math_tests);
    tcase_add_test(s21_math_tests, abc_test);
    
    
    return s21_math;
}

int main(void)
{
    Suite *s21_math = s21_math_tests_create();
    SRunner *s21_math_tests_runner = srunner_create(s21_math);
    int failed_count = 0;
    srunner_run_all(s21_math_tests_runner, CK_NORMAL);
    // Получаем количество проваленных тестов.
    failed_count = srunner_ntests_failed(s21_math_tests_runner);
    srunner_free(s21_math_tests_runner);
    
    if (failed_count != 0) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}