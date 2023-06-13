FLAGS = -Wall -Werror -Wextra -std=c11
FUNC = s21_math.c
FUNC_LIB = s21_math.o

all:  test gcov_report

s21_math:
	gcc $(FLAGS) s21_math.c

s21_math.o:
	gcc $(FLAGS) -c s21_math.c

s21_math.a: s21_math.o
	ar rc s21_math.a s21_math.o
	ranlib s21_math.a

test: clean s21_math.a 
	gcc $(FLAGS) -fprofile-arcs -ftest-coverage -o test s21_math.c s21_test.c -lcheck -lm -lpthread
	./test

gcov_report: s21_math.a
	gcov s21_test.c
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory out
	open out/index.html

clean:
	rm -rf *.o out *.info *.gcda *.gcno *.gcov *.gch *.out *.a test

rebuild: clean all