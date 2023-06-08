GC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
OB=s21_test
LIB=s21_math
GCOV=--coverage

all : test

rebuild : clean all

test: $(LIB).a
	$(GC)  $(CFLAGS) -c $(OB).c
	$(GC) $(CFLAGS) $(OB).o -l check -L. $(LIB).a -o test
	./test

gcov_report : clean lcov $(OB).gcov g$(LIB).a 
	$(GC) $(GCOV) $(OB).o -l check -L. $(LIB).a  -o gcov
	./gcov
	gcov s21_math.c
	/opt/goinfre/*/homebrew/bin/lcov -t "test" -o test.info -c -d .
	/opt/goinfre/*/homebrew/bin/genhtml -o report test.info
	open report/index.html

	
$(LIB).a : $(LIB).c
	$(GC) -c $(LIB).c 
	ar rc  $(LIB).a $(LIB).o 
	ranlib $(LIB).a  #
# библиотека для теста

g$(LIB).a : $(LIB).c
	$(GC) $(GCOV) -c $(LIB).c 
	ar rc  $(LIB).a $(LIB).o 
	ranlib $(LIB).a
# библиотека для отчета

clean :
	rm -rf *.o
	rm -rf *.a
	rm -rf *.g*
	rm -rf report
	rm -rf test.info

lcov:
ifeq ("", "$(wildcard /opt/goinfre/*/homebrew/bin/lcov)")
	$(error Need to install lcov)
# (\_/)
# (*.*)
# />100%
endif



# lcov_instal :
# 	cd /opt/goinfre/
# 	git clone https://github.com/Homebrew/brew homebrew
# 	cd ${HOME}/goinfre/homebrew/bin
# 	USERNAME=$(whoami)
# 	echo $(USERNAME)
# 	eval "$(/opt/goinfre/USERNAME/homebrew/bin/brew shellenv)"
# 	brew update --force --quiet
# 	chmod -R go-w "$(brew --prefix)/share/zsh"
# 	brew install lcov 
# Лан, забей, сам установишь


f : $(LIB).a f.o 
	$(GC) f.o -L. $(LIB).a -o f
	make clean

f.o : f.c
	$(GC) $(CFLAGS) -c f.c