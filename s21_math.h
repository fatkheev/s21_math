#ifndef S21_MATH
#define S21_MATH

#include <float.h>
#include <stdio.h>
#include <stdlib.h>

#define pi 3.141592653589793238462643
#define e 2.71828182845904
#define norm 0.000000001

int s21_abs(int x);
long double s21_nan();
double s21_pow(double x, double y);
long double s21_sqrt(double x);
int s21_fact(int x);
double s21_deg_to_rad(int deg);
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

#endif