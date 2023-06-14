#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

#define epsilon 0.000001

START_TEST(abc_test) { ck_assert_int_eq(s21_abs(-2), abs(-2)); }
END_TEST

START_TEST(sqrt_test) {
  ck_assert_double_eq_tol(s21_sqrt(4), sqrt(4), epsilon);
  ck_assert_double_eq_tol(s21_sqrt(5), sqrt(5), epsilon);
  ck_assert_double_eq_tol(s21_sqrt(5.5), sqrt(5.5), epsilon);
  ck_assert_double_eq_tol(s21_sqrt(0.0000001), sqrt(0.0000001), epsilon);
  for (double i = -100; i < 10000; i += 10) {
    ck_assert_int_eq(s21_sqrt(i), sqrt(i));
  }
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
  ck_assert_double_eq_tol(s21_log(450), log(450), epsilon);
  ck_assert_double_nan(s21_log(-0.01));
}
END_TEST

START_TEST(pow_test) {
  ck_assert_double_eq_tol(s21_pow(2, 2.25), pow(2, 2.25), epsilon);
  ck_assert_double_eq_tol(s21_pow(2.25, 2), pow(2.25, 2), epsilon);
  ck_assert_double_eq_tol(s21_pow(2.25, 2.25), pow(2.25, 2.25), epsilon);
  ck_assert_double_eq_tol(s21_pow(0.00025, 0.00012), pow(0.00025, 0.00012),
  epsilon);
  ck_assert_double_eq_tol(s21_pow(125.8, -41), pow(125.8, -41),
  epsilon);
  ck_assert_double_eq_tol(s21_pow(2, 2), pow(2, 2), epsilon);
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

START_TEST(exp_test)
{
  ck_assert_double_eq_tol(s21_exp(24.67), exp(24.67), epsilon);
}
END_TEST

Suite *s21_math_tests_create() {
  Suite *s21_math = suite_create("s21_math");

  TCase *s21_math_tests = tcase_create("s21_math_tests");

  suite_add_tcase(s21_math, s21_math_tests);

  tcase_add_test(s21_math_tests, abc_test);
  tcase_add_test(s21_math_tests, sqrt_test);
  tcase_add_test(s21_math_tests, log_test);
  tcase_add_test(s21_math_tests, pow_test);
  tcase_add_test(s21_math_tests, fact_test);
  tcase_add_test(s21_math_tests, fabs_test);
  tcase_add_test(s21_math_tests, exp_test);

  return s21_math;
}

int main(void) {
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