#include "s21_math.h"

// int main()
// {
//   double x, y;
//   printf("Введите число: ");
//   scanf("%lf %lf", &x, &y);
//   printf("%.16Lf\n", s21_fmod(x, y));
//   printf("%.16f", fmod(x, y));
//   return 0;
// }

long double s21_pow(double base, double exp)
{
  double res;
  // x^y = exp(y * ln(x))
  if (exp >= 0)
  {
    res = s21_exp(exp * s21_log(base));
  }
  else
  {
    res = 1.0 / s21_exp(-exp * s21_log(base));
  }
  return res;
}

long double s21_sqrt(double x)
{
  double res = x;

  if (x < 0)
  {
    res = S21_NAN;
  }
  else
  {
    while (s21_fabs((res * res - x)) > S21_EPS_10)
    {
      res = (res + x / res) / 2;
    }
  }
  return res;
}

int s21_fact(int x)
{
  int i = 1;
  int res = 1;
  while (i < x)
  {
    res = res * (i + 1);
    i++;
  }
  return res;
}

double s21_deg_to_rad(int deg)
{
  double res = deg * (S21_PI / 180.0);
  return res;
}

int s21_abs(int x)
{
  int res = 0;
  if (x < 0)
  {
    res = -x;
  }
  else
  {
    res = x;
  }
  return res;
}

long double s21_fabs(double x)
{
  double res = 0;
  if (x < 0)
  {
    res = -x;
  }
  else
  {
    res = x;
  }
  return res;
}

long double s21_sin(double x)
{
  double res = x;
  double add = 0;
  int sign = 1;
  int st = 1;

  for (int i = 0; i < 10; i++)
  {
    st = st + 2;
    add = (s21_pow(x, st) / s21_fact(st));
    sign = -sign;
    res = res + sign * add;
  }

  return res;
}

long double s21_cos(double x)
{
  int st = 0;
  double add = 0;
  double res = 1.0;
  int sign = 1;

  for (int i = 1; i <= 10; i++)
  {
    st = st + 2;
    add = (s21_pow(x, st)) / s21_fact(st);
    sign = -sign;
    res = res + sign * add;
  }

  return res;
}

long double s21_tan(double x)
{
  double res = 0;
  return res = s21_sin(x) / s21_cos(x);
}

long double s21_atan(double x)
{
  double res;

  if (x > 1)
  {
    res = S21_PI / 2 - s21_atan(1 / x);
  }
  else if (x < -1)
  {
    res = -S21_PI / 2 - s21_atan(1 / x);
  }
  else
  {
    res = x;
    double add = 0;
    int sign = -1;
    int st = 3;
    for (int i = 0; i < 200; i++)
    {
      add = sign * s21_pow(x, st) / st;
      res = res + add;
      sign = -sign;
      st = st + 2;
    }
  }

  return res;
}

long double s21_asin(double x)
{
  long double res;
  if (x < 1)
  {
    res = s21_atan(x / s21_sqrt(1 - s21_pow(x, 2)));
  }
  else
  {
    res = S21_NAN;
  }

  return res;
}

long double s21_acos(double x)
{
  double res = 0;
  res = S21_PI / 2 - s21_asin(x);
  return res;
}

long double s21_ceil(double x)
{
  int ceil_digit = (int)x;
  double res = 0;
  if ((double)ceil_digit == x)
  {
    res = x;
  }
  else
  {
    res = (double)ceil_digit + 1;
  }
  return res;
}

long double s21_floor(double x)
{
  int ceil_digit = (int)x;
  double res = (double)ceil_digit;
  return res;
}

long double s21_exp(double x)
{
  // exp(x) = 1 + x/1! + x^2/2! + x^3/3! + x^4/4! + ...
  if (x < 100)
  {
    long double res = 1.0;
    long double add = 1.0;

    for (int i = 1; i <= 300; i++)
    {

      add = add * (x / i);
      res = res + add;
    }

    return res;
  }
  else
  {
    long double tmp = s21_exp(x / 2);
    return tmp * tmp;
  }
}

long double s21_log(double x)
{
  if (x < S21_EPS_17)
  {
    return S21_NAN;
  }
  double res;

  // для больших чисел используем свойство ln(a*b) = ln(a) + ln(b)
  if (x > 2)
  {
    int count = 0;
    while (x > 2)
    {
      x /= 2;
      count++;
    }
    res = s21_log(x) + count * S21_LN_2;
  }
  else
  {
    double y = (x - 1) / (x + 1);
    int st = 1;
    double add = y;
    res = y;

    for (int i = 1; i < 5000; i++)
    {
      add = y;
      st = st + 2;
      for (int j = 1; j < st; j++)
      {
        add = add * y;
      }
      res = res + add / st;
      if (s21_fabs(add / st) < S21_EPS_17)
      {
        break;
      }
    }
    res = res * 2;
  }
  return res;
}

long double s21_fmod(double x, double y)
{
  double res = 0;
  double summ = 0;

  if (x < 0)
  {
    x = -x;
    res = s21_fmod(x, y) * -1;
  }
  else if (x > 0 && y < 0)
  {
    y = -y;
    res = s21_fmod(x, y);
  }
  else if (x == 0 || x == y)
  {
    res = 0;
  }
    else if (y == 0)
  {
    res = S21_NAN;
  }
  else
  {
    while (summ < x)
    {
      summ = summ + y;
    }
    res = x - (summ - y);
  }

  return res;
}