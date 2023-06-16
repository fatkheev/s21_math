#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

int test_ints[] = {0, -21, 21, 11, (int)-INFINITY, (int)NAN};
double test_acos_asin_atan[] = {-1, 0, 1, 0.1234, -0.424, -0.5};
double test_doubles[] = {-21.21, 11.21, 1.02, 0, -1, 11.12};
double test_positive_doubles[] = {1.323, 21, 12, 1, 14, 2.21};
double test_nans[] = {S21_NAN, -S21_NAN};

Suite *s21_math_tests();

int main() {
  int number_failed = 0;
  Suite *s;
  SRunner *sr;
  s = s21_math_tests();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (!number_failed) ? EXIT_SUCCESS : EXIT_FAILURE;
}

START_TEST(test_abs) {
  ck_assert_int_eq(s21_abs(test_ints[_i]), abs(test_ints[_i]));
}
END_TEST

START_TEST(test_acos) {
  ck_assert_double_eq_tol(s21_acos(test_acos_asin_atan[_i]),
                          acos(test_acos_asin_atan[_i]), S21_EPS_6);
}
END_TEST

START_TEST(test_asin) {
  ck_assert_double_eq_tol(s21_asin(test_acos_asin_atan[_i]),
                          asin(test_acos_asin_atan[_i]), S21_EPS_6);
}
END_TEST

START_TEST(test_atan) {
  ck_assert_double_eq_tol(s21_atan(test_acos_asin_atan[_i]),
                          atan(test_acos_asin_atan[_i]), S21_EPS_6);
}
END_TEST

START_TEST(test_ceil) {
  ck_assert_double_eq_tol(s21_ceil(test_doubles[_i]), ceil(test_doubles[_i]),
                          S21_EPS_6);
}
END_TEST

START_TEST(test_cos) {
  ck_assert_double_eq_tol(s21_cos(test_doubles[_i]), cos(test_doubles[_i]),
                          S21_EPS_6);
}
END_TEST

START_TEST(test_exp) {
  ck_assert_double_eq_tol(s21_exp(test_doubles[_i]), exp(test_doubles[_i]),
                          S21_EPS_6);
}
END_TEST

START_TEST(test_fabs) {
  ck_assert_double_eq_tol(s21_fabs(test_doubles[_i]), fabs(test_doubles[_i]),
                          S21_EPS_6);
}
END_TEST

START_TEST(test_floor) {
  ck_assert_double_eq_tol(s21_floor(test_doubles[_i]), floor(test_doubles[_i]),
                          S21_EPS_6);
}
END_TEST

START_TEST(test_fmod) {
  ck_assert_double_eq_tol(s21_fmod(test_doubles[_i], test_positive_doubles[_i]),
                          fmod(test_doubles[_i], test_positive_doubles[_i]),
                          S21_EPS_6);
}
END_TEST

START_TEST(test_log) {
  ck_assert_double_eq_tol(s21_log(test_positive_doubles[_i]),
                          log(test_positive_doubles[_i]), S21_EPS_6);
}
END_TEST

START_TEST(test_pow) {
  ck_assert_double_eq_tol(s21_pow(test_doubles[_i], test_ints[_i]),
                          pow(test_doubles[_i], test_ints[_i]), S21_EPS_6);
}
END_TEST

START_TEST(test_sin) {
  ck_assert_double_eq_tol(s21_sin(test_doubles[_i]), sin(test_doubles[_i]),
                          S21_EPS_6);
}
END_TEST

START_TEST(test_sqrt) {
  ck_assert_double_eq_tol(s21_sqrt(test_positive_doubles[_i]),
                          sqrt(test_positive_doubles[_i]), S21_EPS_6);
}
END_TEST

START_TEST(test_tan) {
  ck_assert_double_eq_tol(s21_tan(test_doubles[_i]), tan(test_doubles[_i]),
                          S21_EPS_6);
}
END_TEST

START_TEST(test_nan) {
  ck_assert_double_nan(s21_acos(test_nans[_i]));
  ck_assert_double_nan(acos(test_nans[_i]));
  ck_assert_double_nan(s21_asin(test_nans[_i]));
  ck_assert_double_nan(asin(test_nans[_i]));
  ck_assert_double_nan(s21_atan(test_nans[_i]));
  ck_assert_double_nan(atan(test_nans[_i]));
  ck_assert_double_nan(s21_ceil(test_nans[_i]));
  ck_assert_double_nan(ceil(test_nans[_i]));
  ck_assert_double_nan(s21_cos(test_nans[_i]));
  ck_assert_double_nan(cos(test_nans[_i]));
  ck_assert_double_nan(s21_exp(test_nans[_i]));
  ck_assert_double_nan(exp(test_nans[_i]));
  ck_assert_double_nan(s21_fabs(test_nans[_i]));
  ck_assert_double_nan(fabs(test_nans[_i]));
  ck_assert_double_nan(s21_floor(test_nans[_i]));
  ck_assert_double_nan(floor(test_nans[_i]));
  ck_assert_double_nan(s21_fmod(test_nans[_i], test_nans[_i]));
  ck_assert_double_nan(fmod(test_nans[_i], test_nans[_i]));
  ck_assert_double_nan(s21_log(test_nans[_i]));
  ck_assert_double_nan(log(test_nans[_i]));
  ck_assert_double_nan(s21_pow(test_nans[_i], test_nans[_i]));
  ck_assert_double_nan(pow(test_nans[_i], test_nans[_i]));
  ck_assert_double_nan(s21_sin(test_nans[_i]));
  ck_assert_double_nan(sin(test_nans[_i]));
  ck_assert_double_nan(s21_sqrt(test_nans[_i]));
  ck_assert_double_nan(sqrt(test_nans[_i]));
  ck_assert_double_nan(s21_tan(test_nans[_i]));
  ck_assert_double_nan(tan(test_nans[_i]));
}

START_TEST(cover_all) {
  ck_assert_double_nan(s21_acos(2.3223));
  ck_assert_double_nan(acos(2.3223));
  ck_assert_double_nan(s21_asin(2.3223));
  ck_assert_double_nan(asin(2.3223));
  ck_assert_double_nan(s21_log(-2.3223));
  ck_assert_double_nan(log(-2.3223));
  ck_assert_double_eq(s21_pow(-INFINITY, INFINITY), pow(-INFINITY, INFINITY));
  ck_assert_double_eq(s21_pow(-INFINITY, -INFINITY), pow(-INFINITY, -INFINITY));
  ck_assert_double_eq(s21_pow(0, 0), pow(0, 0));
  ck_assert_double_nan(s21_pow(-1, 1.2));
  ck_assert_double_nan(pow(-1, 1.2));
  ck_assert_double_nan(s21_sqrt(-1));
  ck_assert_double_nan(sqrt(-1));
  ck_assert_double_nan(s21_acos(INFINITY));
  ck_assert_double_nan(acos(INFINITY));
  ck_assert_double_nan(s21_fmod(INFINITY, INFINITY));
  ck_assert_double_nan(fmod(INFINITY, INFINITY));
  ck_assert_double_eq(s21_fmod(23, INFINITY), fmod(23, INFINITY));
}
Suite *s21_math_tests() {
  int test_ints_size = sizeof(test_ints) / sizeof(int),
      test_doubles_size = sizeof(test_doubles) / sizeof(double),
      test_positive_doubles_size =
          sizeof(test_positive_doubles) / sizeof(double),
      test_nans_size = sizeof(test_nans) / sizeof(double);
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_math");
  tc_core = tcase_create("Core");
  tcase_add_loop_test(tc_core, test_abs, 0, test_ints_size);
  tcase_add_loop_test(tc_core, test_acos, 0, test_doubles_size);
  tcase_add_loop_test(tc_core, test_asin, 0, test_doubles_size);
  tcase_add_loop_test(tc_core, test_atan, 0, test_doubles_size);
  tcase_add_loop_test(tc_core, test_ceil, 0, test_doubles_size);
  tcase_add_loop_test(tc_core, test_cos, 0, test_doubles_size);
  tcase_add_loop_test(tc_core, test_exp, 0, test_doubles_size);
  tcase_add_loop_test(tc_core, test_fabs, 0, test_doubles_size);
  tcase_add_loop_test(tc_core, test_floor, 0, test_doubles_size);
  tcase_add_loop_test(tc_core, test_fmod, 0, test_doubles_size);
  tcase_add_loop_test(tc_core, test_log, 0, test_positive_doubles_size);
  tcase_add_loop_test(tc_core, test_pow, 0, test_doubles_size);
  tcase_add_loop_test(tc_core, test_sin, 0, test_doubles_size);
  tcase_add_loop_test(tc_core, test_sqrt, 0, test_positive_doubles_size);
  tcase_add_loop_test(tc_core, test_tan, 0, test_doubles_size);
  tcase_add_loop_test(tc_core, test_nan, 0, test_nans_size);
  tcase_add_test(tc_core, cover_all);
  suite_add_tcase(s, tc_core);
  return s;
}