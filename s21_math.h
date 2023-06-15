#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define S21_PI 3.141592653589793238462643
#define S21_EIL 2.71828182845904
#define S21_EPS_6 1e-6
#define S21_EPS_10 1e-10
#define S21_EPS_17 1e-17
#define S21_NAN 0.0 / 0.0
#define S21_INF 1.0 / 0.0
#define S21_LN_2 0.69314718056

long double s21_pow(double x, double y);
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