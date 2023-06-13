GCC=gcc -Wall -Werror -Wextra


all: s21_math

s21_math: s21_math.o
	$(GCC) s21_math.o -o s21_math

s21_math.o: s21_math.c
	$(GCC) -c s21_math.c -o s21_math.o

s21_math.a : s21_math.c
	$(GCC) -c s21_math.c 
	ar rc  s21_math.a s21_math.o 
	ranlib s21_math.a

test: clean s21_test.c s21_math.a
	gcc -Wall -Wextra -Werror -std=c11 -c s21_test.c -o s21_test.o
	gcc s21_test.o -l check -L. s21_math.a -o test
	./test

html: test
	gcc -fprofile-arcs -ftest-coverage -o s21_test s21_math.c s21_test.c -I. -lcheck -lm -lpthread
	./s21_test
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory out
	open out/index.html

valgrind: 
	CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose --log-file=RESULT.txt ./s21_math -i test1.txt
	cat RESULT.txt
	rm -rf RESULT.txt

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