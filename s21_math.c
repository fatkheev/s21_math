#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define pi 3.141592653589793238462643

double s21_stepen(double x, double y);
long double s21_sqrt(double x);
int s21_fact(int x);
double s21_deg_to_rad(int deg);
int s21_abs(int x);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);

int main() {
  double x;
  printf("Введите число: ");
  scanf("%lf", &x);
  printf("%Lf\n", s21_sqrt(x));
  printf("%f", sqrt(x));

  return 0;
}

double s21_stepen(double x, double y) {
  double digit = x;
  double st = y;
  double temp = x;

  for (int i = 1; i < st; i++) {
    temp = temp * digit;
  }
  return temp;
}

long double s21_sqrt(double x) {
  double res = x;

  while ((res * res - x) > 0) {
    res = (res + x / res) / 2;
  }

  return res;
}

int s21_fact(int x) {
  int i = 1;
  int res = 1;
  while (i < x) {
    res = res * (i + 1);
    i++;
  }
  return res;
}

double s21_deg_to_rad(int deg) {
  double res = deg * (pi / 180.0);
  return res;
}

int s21_abs(int x) {
  int res = 0;
  if (x < 0) {
    res = -x;
  } else {
    res = x;
  }
  return res;
}

long double s21_sin(double x) {
  double res = x;
  double add = 0;
  int sign = 1;
  int st = 1;

  for (int i = 0; i < 10; i++) {
    st = st + 2;
    add = (s21_stepen(x, st) / s21_fact(st));
    sign = -sign;
    res = res + sign * add;
  }

  return res;
}

long double s21_cos(double x) {
  int st = 0;
  double add = 0;
  double res = 1.0;
  int sign = 1;

  for (int i = 1; i <= 10; i++) {
    st = st + 2;
    add = (s21_stepen(x, st)) / s21_fact(st);
    sign = -sign;
    res = res + sign * add;
  }

  return res;
}

long double s21_tan(double x) {
  double res = 0;
  return res = s21_sin(x) / s21_cos(x);
}

// long double atan(double x) {
//   double res = 0;
//   double add = 0;
//   int sign = 1;
// }
//atan(x) = x - (x^3)/3 + (x^5)/5 - (x^7)/7 + ...


//arcsin(x) = atan(x / sqrt(1 - x^2))
//arccos(x) = π/2 - arcsin(x)