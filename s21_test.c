#include <check.h>
#include "s21_math.h"

#define epsilon 0.000001

START_TEST(abs_test)
{
  ck_assert_int_eq(s21_abs(2), abs(2));
  ck_assert_int_eq(s21_abs(-2), abs(-2));
  ck_assert_int_eq(s21_abs(-2147483647), abs(-2147483647));

}
END_TEST

START_TEST(log_test) {
  ck_assert_double_eq(s21_log(1.1), log(1.1));
  ck_assert_double_eq_tol(s21_log(0.01), log(0.01), epsilon);
  for (double i = 0.01; i < 2; i = i + 0.01)
  {
    ck_assert_double_eq_tol(s21_log(i), log(i), epsilon);
  }
  
  ck_assert_double_eq_tol(s21_log(1.99), log(1.99), epsilon);
  //ck_assert_double_eq_tol(s21_log(450), log(450), epsilon);
//   ck_assert_double_eq_tol(s21_log(-0.01), log(-0.01), epsilon);
}
END_TEST

START_TEST(fact_test)
{
  ck_assert_int_eq(s21_fact(5), 1*2*3*4*5);
  ck_assert_int_eq(s21_fact(0), 1);
  ck_assert_int_eq(s21_fact(12), 479001600);
}
END_TEST

START_TEST(fabs_test)
{
  ck_assert_double_eq(s21_fabs(-234.567), fabs(-234.567));
  ck_assert_double_eq(s21_fabs(-inf), fabs(-inf));
  ck_assert_double_eq(s21_fabs(inf), fabs(inf));
  ck_assert_double_eq(s21_fabs(0.0), fabs(0.0));
  ck_assert_double_eq(s21_fabs(234.567), fabs(234.567));
}
END_TEST

START_TEST(sqrt_test)
{
  ck_assert_double_eq(s21_sqrt(-234.567), sqrt(-234.567));
}
END_TEST

Suite *s21_math_tests_create()
{
    Suite *s21_math = suite_create("s21_math");
    TCase *s21_math_tests = tcase_create("s21_math_tests");
    suite_add_tcase(s21_math, s21_math_tests);
    tcase_add_test(s21_math_tests, abs_test);
    tcase_add_test(s21_math_tests, log_test);
    tcase_add_test(s21_math_tests, fact_test);
    tcase_add_test(s21_math_tests, fabs_test);
    tcase_add_test(s21_math_tests, sqrt_test);
    return s21_math;
}

int main(void)
{
    Suite *s21_math = s21_math_tests_create();  
    SRunner *s21_math_tests_runner = srunner_create(s21_math);
    int failed_count = 0;
    srunner_run_all(s21_math_tests_runner, CK_NORMAL);
    failed_count = srunner_ntests_failed(s21_math_tests_runner);
    srunner_free(s21_math_tests_runner);
    
    if (failed_count != 0) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}