GCC=gcc -Wall -Werror -Wextra


all: s21_math

s21_math: s21_math.o
	$(GCC) s21_math.o -o s21_math

s21_math.o: s21_math.c
	$(GCC) -c s21_math.c -o s21_math.o

test: s21_math test_func_cat.sh
	sh test_func_cat.sh

valgrind: 
	CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose --log-file=RESULT.txt ./s21_math -i test1.txt
	cat RESULT.txt
	rm -rf RESULT.txt

rebuild: clean all

clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf *.out
	rm -rf s21_math