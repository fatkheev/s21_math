GCC=gcc -Wall -Werror -Wextra

all: test gcov_report

s21_math.a : s21_math.c
	$(GCC) -c s21_math.c 
	ar rc  s21_math.a s21_math.o 
	ranlib s21_math.a

test: clean s21_test.c s21_math.a
	gcc -I /opt/homebrew/Cellar/check/0.15.2/include -Wall -Wextra -Werror -std=c11 -c s21_test.c -o s21_test.o
	gcc s21_test.o -L /opt/homebrew/Cellar/check/0.15.2/lib -lcheck -L. s21_math.a -o test
	./test

gcov_report: test
	gcc -fprofile-arcs -ftest-coverage -o s21_test s21_math.c s21_test.c -I/opt/homebrew/Cellar/check/0.15.2/include -L/opt/homebrew/Cellar/check/0.15.2/lib -lcheck -lm -lpthread
	./s21_test
	lcov --capture --directory . --output-file coverage.info
	lcov --remove coverage.info '/usr/*' --output-file coverage.info
	genhtml coverage.info --output-directory out
	open out/index.html

rebuild: clean all

clean:
	rm -rf s21_math
	rm -rf s21_test
	rm -rf test
	rm -rf out
	rm -rf *.o
	rm -rf *.a
	rm -rf *.out
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info