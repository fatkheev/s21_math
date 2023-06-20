#include <check.h>
#include <math.h>

#include "s21_math.h"

START_TEST(abc_test) {
  ck_assert_int_eq(s21_abs(-2), abs(-2));
  ck_assert_int_eq(s21_abs(2), abs(2));
}
END_TEST

START_TEST(sqrt_test) {
  ck_assert_double_eq_tol(s21_sqrt(4), sqrt(4), S21_EPS_6);
  ck_assert_double_eq_tol(s21_sqrt(5), sqrt(5), S21_EPS_6);
  ck_assert_double_eq_tol(s21_sqrt(5.5), sqrt(5.5), S21_EPS_6);
  ck_assert_double_eq_tol(s21_sqrt(0.0000001), sqrt(0.0000001), S21_EPS_6);
  for (double i = -100; i < 10000; i += 10) {
    ck_assert_int_eq(s21_sqrt(i), sqrt(i));
  }
}
END_TEST

START_TEST(log_test) {
  ck_assert_double_eq_tol(s21_log(1.1), log(1.1), S21_EPS_6);
  ck_assert_double_eq_tol(s21_log(0.01), log(0.01), S21_EPS_6);
  for (double i = 0.01; i < 2; i = i + 0.01) {
    ck_assert_double_eq_tol(s21_log(i), log(i), S21_EPS_6);
  }

  ck_assert_double_eq_tol(s21_log(1.99), log(1.99), S21_EPS_6);
  ck_assert_double_eq_tol(s21_log(450), log(450), S21_EPS_6);
  ck_assert_double_nan(s21_log(-0.01));
}
END_TEST

START_TEST(pow_test) {
  ck_assert_double_eq_tol(s21_pow(2, 2.25), pow(2, 2.25), S21_EPS_6);
  ck_assert_double_eq_tol(s21_pow(2.25, 2), pow(2.25, 2), S21_EPS_6);
  ck_assert_double_eq_tol(s21_pow(2.25, 2.25), pow(2.25, 2.25), S21_EPS_6);
  ck_assert_double_eq_tol(s21_pow(0.00025, 0.00012), pow(0.00025, 0.00012),
                          S21_EPS_6);
  ck_assert_double_eq_tol(s21_pow(125.8, -41), pow(125.8, -41), S21_EPS_6);
  ck_assert_double_eq_tol(s21_pow(2, 2), pow(2, 2), S21_EPS_6);
  ck_assert_double_eq_tol(s21_pow(0, 0), pow(0, 0), S21_EPS_6);
  ck_assert_double_eq_tol(s21_pow(0, 1), pow(0, 1), S21_EPS_6);
}
END_TEST

START_TEST(fact_test) {
  ck_assert_double_eq_tol(s21_fact(5), 1 * 2 * 3 * 4 * 5, S21_EPS_6);
  ck_assert_double_eq_tol(s21_fact(0), 1, S21_EPS_6);
  ck_assert_double_eq_tol(s21_fact(12), 479001600, S21_EPS_6);
}
END_TEST

START_TEST(fabs_test) {
  ck_assert_double_eq_tol(s21_fabs(-234.567), fabs(-234.567), S21_EPS_6);
  ck_assert_double_infinite(s21_fabs(-S21_INF));
  ck_assert_double_infinite(s21_fabs(S21_INF));
  ck_assert_double_eq_tol(s21_fabs(0.0), fabs(0.0), S21_EPS_6);
  ck_assert_double_eq_tol(s21_fabs(234.567), fabs(234.567), S21_EPS_6);
}
END_TEST

START_TEST(exp_test) {
  ck_assert_double_eq_tol(exp(-21.8), s21_exp(-21.8), S21_EPS_6);
  ck_assert_double_eq_tol(exp(-5), s21_exp(-5), S21_EPS_6);
  ck_assert_double_eq_tol(exp(0), s21_exp(0), S21_EPS_6);
  ck_assert_double_eq_tol(exp(1), s21_exp(1), S21_EPS_6);
  ck_assert_double_eq_tol(exp(5), s21_exp(5), S21_EPS_6);
}
END_TEST

START_TEST(fmod_test) {
  ck_assert_double_nan(s21_fmod(S21_NAN, S21_NAN));
  ck_assert_float_eq_tol(fmod(-12.67536, 2.5), s21_fmod(-12.67536, 2.5),
                         S21_EPS_6);
  ck_assert_float_eq_tol(fmod(12.67536, 2.5), s21_fmod(12.67536, 2.5),
                         S21_EPS_6);
  ck_assert_double_nan(s21_fmod(12.67536, 0));
  ck_assert_float_eq_tol(fmod(12.67536, -2.5), s21_fmod(12.67536, -2.5),
                         S21_EPS_6);
  ck_assert_float_eq_tol(fmod(-1234.546373, 3.5), s21_fmod(-1234.546373, 3.5),
                         S21_EPS_6);
  ck_assert_float_eq_tol(fmod(54637872.56738, 2.5),
                         s21_fmod(54637872.56738, 2.5), S21_EPS_6);
  ck_assert_float_eq_tol(fmod(0, 3.5), s21_fmod(0, 3.5), S21_EPS_6);
  ck_assert_float_eq_tol(fmod(4.5, 4.5), s21_fmod(4.5, 4.5), S21_EPS_6);
}
END_TEST

START_TEST(floor_test) {
  ck_assert_double_eq_tol(floor(-123.65), s21_floor(-123.65), S21_EPS_6);
  ck_assert_double_eq_tol(floor(-12.2), s21_floor(-12.2), S21_EPS_6);
  ck_assert_double_eq_tol(floor(-8.8), s21_floor(-8.8), S21_EPS_6);
  ck_assert_double_eq_tol(floor(-0.546), s21_floor(-0.546), S21_EPS_6);
  ck_assert_double_eq_tol(floor(0), s21_floor(0), S21_EPS_6);
  ck_assert_double_eq_tol(floor(0.0), s21_floor(0.0), S21_EPS_6);
  ck_assert_double_eq_tol(floor(0.00001), s21_floor(0.00001), S21_EPS_6);
  ck_assert_double_eq_tol(floor(26.4567), s21_floor(26.4567), S21_EPS_6);
  ck_assert_double_eq_tol(floor(33.999), s21_floor(33.999), S21_EPS_6);
  ck_assert_double_infinite(s21_floor(S21_INF));
  ck_assert_double_nan(s21_floor(S21_NAN));
}
END_TEST

START_TEST(ceil_test) {
  ck_assert_float_eq_tol(ceil(0), s21_ceil(0), S21_EPS_6);
  ck_assert_float_eq_tol(ceil(-14.56), s21_ceil(-14.56), S21_EPS_6);
  ck_assert_float_eq_tol(ceil(14.56), s21_ceil(14.56), S21_EPS_6);
  ck_assert_float_eq_tol(ceil(1000), s21_ceil(1000), S21_EPS_6);
  ck_assert_float_eq_tol(ceil(115.0000003), s21_ceil(115.0000003), S21_EPS_6);
}
END_TEST

START_TEST(sin_test) {
  ck_assert_double_eq_tol(s21_sin(0.5), sin(0.5), S21_EPS_6);
  ck_assert_double_eq_tol(s21_sin(-0.5), sin(-0.5), S21_EPS_6);
  ck_assert_double_eq_tol(s21_sin(2.3), sin(2.3), S21_EPS_6);
  ck_assert_double_eq_tol(s21_sin(-2.3), sin(-2.3), S21_EPS_6);
  ck_assert_double_eq_tol(s21_sin(0), sin(0), S21_EPS_6);
  ck_assert_double_eq_tol(s21_sin(-0), sin(-0), S21_EPS_6);
  ck_assert_double_nan(s21_sin(S21_INF));
  ck_assert_double_nan(s21_sin(S21_NAN));
}
END_TEST

START_TEST(cos_test) {
  ck_assert_double_nan(s21_cos(S21_INF));
  ck_assert_double_nan(s21_cos(S21_NAN));
  ck_assert_double_eq_tol(s21_cos(0.8), cos(0.8), S21_EPS_6);
  ck_assert_double_eq_tol(s21_cos(-0.8), cos(-0.8), S21_EPS_6);
  ck_assert_double_eq_tol(s21_cos(1.5), cos(1.5), S21_EPS_6);
  ck_assert_double_eq_tol(s21_cos(-2.3), cos(-2.3), S21_EPS_6);
  ck_assert_double_eq_tol(s21_cos(0), cos(0), S21_EPS_6);
}
END_TEST

START_TEST(tan_test) {
  // ck_assert_double_eq_tol(s21_tan(S21_INF), tan(S21_INF), S21_EPS_6);
  ck_assert_double_nan(s21_tan(S21_NAN));
  ck_assert_double_nan(s21_tan(S21_INF));
  ck_assert_double_eq_tol(s21_tan(0.5), tan(0.5), S21_EPS_6);
  ck_assert_double_eq_tol(s21_tan(-0.5), tan(-0.5), S21_EPS_6);
  ck_assert_double_eq_tol(s21_tan(1.5), tan(1.5), S21_EPS_6);
  ck_assert_double_eq_tol(s21_tan(-2.5), tan(-2.5), S21_EPS_6);
  ck_assert_double_eq_tol(s21_tan(0), tan(0), S21_EPS_6);
}
END_TEST

START_TEST(asin_test) {
  ck_assert_double_nan(s21_asin(S21_INF));
  ck_assert_double_nan(s21_asin(S21_NAN));
  ck_assert_double_eq_tol(s21_asin(0.5), asin(0.5), S21_EPS_6);
  ck_assert_double_eq_tol(s21_asin(-0.5), asin(-0.5), S21_EPS_6);
  ck_assert_double_eq_tol(s21_asin(-1), asin(-1), S21_EPS_6);
  ck_assert_double_eq_tol(s21_asin(1), asin(1), S21_EPS_6);
  ck_assert_double_nan(s21_asin(1.5));
  ck_assert_double_eq_tol(s21_asin(0), asin(0), S21_EPS_6);
  ck_assert_double_eq_tol(s21_asin(-0), asin(-0), S21_EPS_6);
  ck_assert_double_eq_tol(s21_asin(0.00000006565545), asin(0.00000006565545),
                          S21_EPS_6);
}
END_TEST

START_TEST(atan_test) {
  ck_assert_double_nan(s21_atan(S21_NAN));
  ck_assert_double_eq_tol(s21_atan(S21_INF), atan(S21_INF), S21_EPS_6);
  ck_assert_double_eq_tol(s21_atan(0.5), atan(0.5), S21_EPS_6);
  ck_assert_double_eq_tol(s21_atan(-0.5), atan(-0.5), S21_EPS_6);
  ck_assert_double_eq_tol(s21_atan(-1), atan(-1), S21_EPS_6);
  ck_assert_double_eq_tol(s21_atan(1), atan(1), S21_EPS_6);
  ck_assert_double_eq_tol(s21_atan(1.5), atan(1.5), S21_EPS_6);
  ck_assert_double_eq_tol(s21_atan(-2.5), atan(-2.5), S21_EPS_6);
  ck_assert_double_eq_tol(s21_atan(0), atan(0), S21_EPS_6);
}
END_TEST

START_TEST(acos_test) {
  ck_assert_double_nan(s21_acos(S21_INF));
  ck_assert_double_nan(s21_acos(S21_NAN));
  ck_assert_double_eq_tol(s21_acos(0.5), acos(0.5), S21_EPS_6);
  ck_assert_double_eq_tol(s21_acos(-0.5), acos(-0.5), S21_EPS_6);
  ck_assert_double_eq_tol(s21_acos(1), acos(1), S21_EPS_6);
  ck_assert_double_nan(s21_acos(1.1));
  ck_assert_double_eq_tol(s21_acos(0.00000006565545), acos(0.00000006565545),
                          S21_EPS_6);
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
  tcase_add_test(s21_math_tests, fmod_test);
  tcase_add_test(s21_math_tests, floor_test);
  tcase_add_test(s21_math_tests, ceil_test);
  tcase_add_test(s21_math_tests, sin_test);
  tcase_add_test(s21_math_tests, cos_test);
  tcase_add_test(s21_math_tests, tan_test);
  tcase_add_test(s21_math_tests, asin_test);
  tcase_add_test(s21_math_tests, atan_test);
  tcase_add_test(s21_math_tests, acos_test);

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
