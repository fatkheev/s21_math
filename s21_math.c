#include "s21_math.h"

int S21_ISNAN(double x) { return x != x; }

long double s21_pow(double base, double exp1) {
  double res = 0;
  // x^y = exp(y * ln(x))
  if (exp1 == 0) {
    res = 1;
  } else if (base == 0) {
    res = 0;
  } else if (base == 0 && exp1 == 1) {
    res = 0;
  } else if (exp1 == S21_INF) {
    res = 1;
  } else if (exp1 != exp1) {
    res = 1;
  } else {
    if (exp1 >= 0) {
      res = s21_exp(exp1 * s21_log(base));
    } else {
      res = 1.0 / s21_exp(-exp1 * s21_log(base));
    }
  }

  return res;
}

long double s21_sqrt(double x) {
  // res = (res + x / res) / 2 метод Ньютона
  double res = x;

  if (x < 0) {
    res = S21_NAN;
  } else {
    while (s21_fabs((res * res - x)) > S21_EPS_10) {
      res = (res + x / res) / 2;
    }
  }
  return res;
}

long double s21_fact(double x) {
  double i = 1;
  double res = 1;
  while (i < x) {
    res = res * (i + 1);
    i++;
  }
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
  long double res = 0;
  if (x < 0) {
    res = -x;
  } else {
    res = x;
  }
  return res;
}

long double s21_sin(double x) {
  // sin(x) = x - (x^3 / 3!) + (x^5 / 5!) - (x^7 / 7!) + ...
  double res;
  if (x == 0) {
    res = 0;
  } else if (x == S21_INF) {
    res = S21_NAN;
  } else if (x != x) {
    res = S21_NAN;
  } else {
    x = x - 2 * S21_PI *
                s21_floor(x / (2 * S21_PI));  // приводим число к одному периоду
    res = x;
    double add = 0;
    int sign = 1;
    int st = 1;

    for (int i = 0; i < 50; i++) {
      st = st + 2;
      add = ((s21_pow(x, st)) / s21_fact(st));
      sign = -sign;
      res = res + sign * add;
    }
  }
  return res;
}

long double s21_cos(double x) {
  // cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + ...
  double res;
  if (x == 0) {
    res = 1;
  } else if (x == S21_INF) {
    res = S21_NAN;
  } else if (x != x) {
    res = S21_NAN;
  } else {
    int st = 0;
    double add = 0;
    res = 1.0;
    int sign = 1;

    if (x < 0) {
      x = -x;
    }
    x = x - 2 * S21_PI *
                s21_floor(x / (2 * S21_PI));  // приводим число к одному периоду

    for (int i = 1; i <= 50; i++) {
      st = st + 2;
      add = (s21_pow(x, st)) / s21_fact(st);
      sign = -sign;
      res = res + sign * add;
    }
  }

  return res;
}

long double s21_tan(double x) {
  double res = 0;
  if (x == S21_INF || x != x) {
    res = S21_NAN;
  } else if (x == 0) {
    res = 0;
  } else {
    res = s21_sin(x) / s21_cos(x);
  }
  return res;
}

long double s21_atan(double x) {
  // atan(x) = x - (x^3)/3 + (x^5)/5 - (x^7)/7 + ...
  double res;
  if (x == 1) {
    res = S21_ATAN_1;
  } else if (x == -1) {
    res = -S21_ATAN_1;
  } else if (x == S21_INF) {
    res = S21_PI / 2;
  } else {
    if (x > 1) {
      res = S21_PI / 2 - s21_atan(1 / x);
    } else if (x < -1) {
      res = -S21_PI / 2 - s21_atan(1 / x);
    } else {
      res = x;
      double add = x;
      int sign = -1;
      int znamenatel = 3;
      for (int i = 0; i < 1000; i++) {
        add = add * x * x;
        res = res + (sign * add / znamenatel);
        sign = -sign;
        znamenatel = znamenatel + 2;
      }
    }
  }

  return res;
}

long double s21_asin(double x) {
  // asin(x) = atan(x / sqrt(1 - x^2))
  long double res;
  if (x == 0) {
    res = 0;
  } else if (x == S21_INF) {
    res = S21_NAN;
  } else if (x != x) {
    res = S21_NAN;
  } else {
    if (x < 0) {
      x = -x;
      res = s21_atan(x / s21_sqrt(1 - s21_pow(x, 2)));
      res = -res;
    } else {
      res = s21_atan(x / s21_sqrt(1 - s21_pow(x, 2)));
    }
  }

  return res;
}

long double s21_acos(double x) {
  double res = 0;
  if (x == S21_INF) {
    res = S21_NAN;
  } else if (x != x) {
    res = S21_NAN;
  } else {
    res = S21_PI / 2 - s21_asin(x);
  }

  return res;
}

long double s21_exp(double x) {
  long double dev = 1, res = 1;
  int flag = 0;

  if (x == -S21_INF) {
    return 0;
  } else if (x == S21_INF) {
    return S21_INF;
  } else {
    if (x < 0) {
      x *= -1;
      flag = 1;
    }
    for (long double i = 1; s21_fabs(dev) > S21_EPS_25; i++) {
      dev *= x / i;
      res += dev;
      if (res > MAX_DOUBLE) {
        res = S21_INF;
        break;
      }
    }
    if (flag == 1) {
      if (res > MAX_DOUBLE) {
        res = 0;
      } else {
        res = 1. / res;
      }
    }

    if (res > MAX_DOUBLE) {
      res = S21_INF;
    }
  }
  return res;
}

long double s21_ceil(double x) {
  int ceil_digit = (int)x;
  double res = 0;
  if (x != x) {
    res = S21_NAN;
  } else {
    if ((double)ceil_digit == x) {
      res = x;
    } else if (x > 0) {
      res = (double)ceil_digit + 1;
    } else {
      res = (double)ceil_digit;
    }
  }

  return res;
}

long double s21_floor(double x) {
  double res;
  if (S21_ISNAN(x)) {
    res = x;
  } else {
    int ceil_digit = (int)x;
    if (x < 0 && (x - ceil_digit) != 0) {
      res = (double)ceil_digit - 1;
    } else if (x == S21_INF) {
      res = S21_INF;
    } else {
      res = (double)ceil_digit;
    }
  }

  return res;
}

long double s21_log(double x) {
  long double res;
  if (x == S21_INF) {
    res = x;
  } else if (x != x || x == -S21_INF || x < 0) {
    res = S21_NAN;
  } else if (x == 0) {
    res = -S21_INF;
  } else if (x == 1) {
    res = 0;
  } else {
    long double st = 0, count = 2, temp, result;
    while (x >= 10 || x < 1) {
      if (x < 1) {
        x = x * 10;
        st--;
      } else {
        x = x * 0.1;
        st++;
      }
    }
    x /= 10;
    x--;
    result = x;
    temp = x;
    while (s21_fabs(result) > S21_EPS_17) {
      result = result * (-x * (count - 1) / count);
      temp = temp + result;
      count = count + 1;
    }
    res = temp + (st + 1) * S21_LN10;
  }
  return res;
}

long double s21_fmod(double x, double y) {
  double res = 0;
  double summ = 0;

  if (x < 0) {
    x = -x;
    res = s21_fmod(x, y) * -1;
  } else if (x > 0 && y < 0) {
    y = -y;
    res = s21_fmod(x, y);
  } else if (x == S21_INF && y == S21_INF) {
    res = S21_NAN;
  } else if (x == 0 || x == y) {
    res = 0;
  } else if (x != 0 && y == 0) {
    res = S21_NAN;
  } else {
    while (summ < x) {
      summ = summ + y;
    }
    res = x - (summ - y);
  }

  return res;
}