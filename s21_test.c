#include <check.h>
#include <stdlib.h>

#include "s21_math.h"

#define epsilon 0.000001

START_TEST(abc_test) { ck_assert_int_eq(s21_abs(-2), abs(-2)); }
END_TEST

START_TEST(test_s21_sqrt) {
  ck_assert_int_eq(s21_sqrt(4), sqrt(4));
  ck_assert_int_eq(s21_sqrt(5), sqrt(5));
  ck_assert_int_eq(s21_sqrt(5.5), sqrt(5.5));
  ck_assert_int_eq(s21_sqrt(-5.5), sqrt(-5.5));
  ck_assert_int_eq(s21_sqrt(0.0000001), sqrt(0.0000001));
}
END_TEST

START_TEST(test_s21_log) {
  ck_assert_int_eq(s21_log(1.1), log(1.1));
  for (double i = 0.00; i < 2.00; i += 0.01) {
    ck_assert_int_eq(s21_log(i), log(i));
  }
}
END_TEST

// START_TEST(test_s21_pow) {
//   ck_assert_double_eq_tol(s21_pow(2, 2), pow(2, 2), epsilon);
//   ck_assert_double_eq_tol(s21_pow(2, 2.25), pow(2, 2.25), epsilon);
//   ck_assert_double_eq_tol(s21_pow(2.25, 2), pow(2.25, 2), epsilon);
//   ck_assert_double_eq_tol(s21_pow(2.25, 2.25), pow(2.25, 2.25), epsilon);
//   ck_assert_double_eq_tol(s21_pow(0.00025, 0.00012), pow(0.00025, 0.00012),
//   epsilon);
// }
// END_TEST

// Функция для создания тестового набора.
Suite *s21_math_tests_create() {
  // Создаем набор тестов с именем "s21_math"
  Suite *s21_math = suite_create("s21_math");

  // Создаем тестовый случай с именем "s21_math_tests"
  TCase *s21_math_tests = tcase_create("s21_math_tests");

  // Добавляем тестовый случай в набор тестов
  suite_add_tcase(s21_math, s21_math_tests);

  // Добавляем функцию теста в тестовый случай
  tcase_add_test(s21_math_tests, abc_test);
  tcase_add_test(s21_math_tests, test_s21_sqrt);
  tcase_add_test(s21_math_tests, test_s21_log);
  //   tcase_add_test(s21_math_tests, test_s21_pow);

  // Возвращаем созданный набор тестов
  return s21_math;
}

int main(void) {
  // Создаем набор тестов.
  Suite *s21_math = s21_math_tests_create();

  // Создаем тестовый запускатор для набора тестов.
  SRunner *s21_math_tests_runner = srunner_create(s21_math);

  int failed_count = 0;  // Переменная для хранения числа неудачных тестов.

  // Запускаем все тесты в наборе.
  srunner_run_all(s21_math_tests_runner, CK_NORMAL);

  // Получаем количество проваленных тестов.
  failed_count = srunner_ntests_failed(s21_math_tests_runner);

  // Освобождаем память, занятую запускатором тестов.
  srunner_free(s21_math_tests_runner);

  // Если были неудачные тесты, возвращаем код ошибки.
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }

  // В противном случае возвращаем код успешного выполнения.
  return EXIT_SUCCESS;
}