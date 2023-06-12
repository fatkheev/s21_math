#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define pi 3.141592653589793238462643
#define e 2.71828182845904
#define norm 0.000000001
#define EPS 1e-17

long double s21_nan();
double s21_pow(double x, double y);
long double s21_sqrt(double x);
int s21_fact(int x);
double s21_deg_to_rad(int deg);
int s21_abs(int x);
long double s21_fabs(double x);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_atan(double x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_exp(double x);
long double s21_log(double x);
long double s21_fmod(double x, double y);

int main() {
  double x;
  printf("Введите число: ");
  scanf("%lf", &x);
  printf("%.15Lf\n", s21_log(x));
  printf("%.15f", log(x));
  return 0;
}

long double s21_nan() {
  double zero = 0.0;
  return zero / zero;
}

double s21_pow(double base, double exp) {
  // x^y = exp(y * ln(x))
  double res = s21_exp(exp * s21_log(base));
  return res;
}

long double s21_sqrt(double x) {
  double res = x;

  if (x < 0) {
    res = s21_nan();
  } else {
    while (s21_fabs((res * res - x)) > norm) {
      res = (res + x / res) / 2;
    }
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

long double s21_fabs(double x) {
  double res = 0;
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
    add = (s21_pow(x, st) / s21_fact(st));
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
    add = (s21_pow(x, st)) / s21_fact(st);
    sign = -sign;
    res = res + sign * add;
  }

  return res;
}

long double s21_tan(double x) {
  double res = 0;
  return res = s21_sin(x) / s21_cos(x);
}

long double s21_atan(double x) {
  double res;

  if (x > 1) {
    res = pi / 2 - s21_atan(1 / x);
  } else if (x < -1) {
    res = -pi / 2 - s21_atan(1 / x);
  } else {
    res = x;
    double add = 0;
    int sign = -1;
    int st = 3;
    for (int i = 0; i < 200; i++) {
      add = sign * s21_pow(x, st) / st;
      res = res + add;
      sign = -sign;
      st = st + 2;
    }
  }

  return res;
}

long double s21_asin(double x) {
  long double res;
  if (x < 1) {
    res = s21_atan(x / s21_sqrt(1 - s21_pow(x, 2)));

  } else {
    res = s21_nan();
  }

  return res;
}

long double s21_acos(double x) {
  double res = 0;
  res = pi / 2 - s21_asin(x);
  return res;
}

long double s21_ceil(double x) {
  int ceil_digit = (int)x;
  double res = 0;
  if ((double)ceil_digit == x) {
    res = x;
  } else {
    res = (double)ceil_digit + 1;
  }
  return res;
}

long double s21_floor(double x) {
  int ceil_digit = (int)x;
  double res = (double)ceil_digit;
  return res;
}

long double s21_exp(double x) {
  long double res = 1.0;
  long double term = 1.0;

  for (int i = 1; i <= 300; i++) {
    term = term * (x / i);
    res = res + term;
  }

  return res;
}

long double s21_log(double x) {
  double y = (x - 1) / (x + 1);
  int st = 1;
  double add = y;
  double res = y;

  for (int i = 1; i < 10000; i++) {
    add = y;
    st = st + 2;
    for (int j = 1; j < st; j++) {
      add = add * y;
    }
    res = res + add / st;
  }

  return 2 * res;
}

long double s21_fmod(double x, double y) {
  double res = 0;
  int del = (int)x / (int)y;

  res = x - (double)del * y;
  return res;
}