OS := $(shell uname -s)
CXX = g++
FLAGS = -Werror -Wextra -Wall -std=c++17 -lstdc++
MODEL = model
CONTROLLER = controller
VIEW = view
UTILS = include
TESTS = tests
SOURCE = $(MODEL)/*.cc $(CONTROLLER)/*.cc $(VIEW)/*.cc $(UTILS)/*.cc $(TESTS)/*.cc main.cc
HEADERS = $(MODEL)/*.h $(CONTROLLER)/*.h $(VIEW)/*.h $(UTILS)/*.h
CHECK_FLAGS = -lpthread -lcheck -pthread -lm
ifeq ($(OS), Linux)
CHECK_FLAGS += -lrt -lsubunit
endif
DIST_FILES = $(SOURCE) $(HEADERS) Makefile dvi.md SmartCalc.pro
TEST_FLAGS = -lgtest -lgtest_main

ifeq ($(OS), Darwin)
INSTALL = mkdir -p ~/app && \
	mkdir -p build && \
	cd build && \
	qmake ../SmartCalc.pro && \
	make && \
	mv SmartCalc.app/Contents/MacOS/SmartCalc ~/app/SmartCalc_v2 && \
	cd .. && \
	rm -rf build
endif

ifeq ($(OS), Linux)
INSTALL = mkdir -p ~/app && \
	mkdir -p build && \
	cd build && \
	qmake6 ../SmartCalc.pro && \
	make && \
	mv SmartCalc ~/app/SmartCalc_v2 && \
	cd .. && \
	rm -rf build
endif

clean:
	rm -rf *.o *.a *.out report/ *.info *.gcda *.gcno *.tar.gz build

all: gcov_report install dist

style:
	clang-format -style=Google -n $(SOURCE) $(HEADERS) main.cc

s21_calc.a: s21_calc.o 
	ar rcs s21_calc.a *.o
	ranlib *.a

s21_calc.o:
	$(CXX) -c $(FLAGS) $(UTILS)/utils.cc $(MODEL)/*.cc $(CONTROLLER)/*.cc

test: clean s21_calc.a
	$(CXX) $(FLAGS) $(TESTS)/*.cc s21_calc.a -o test.out $(TEST_FLAGS)
	./test.out

gcov_report:
	$(CXX) $(FLAGS) -fprofile-arcs -ftest-coverage $(TESTS)/*.cc $(MODEL)/*.cc $(CONTROLLER)/*.cc $(UTILS)/utils.cc $(CHECK_FLAGS) $(TEST_FLAGS) -o test.out
	./test.out
	lcov -t "test" --ignore-errors inconsistent -o test.info --no-external -c -d  ./
	genhtml test.info -o report
	open report/index.html

valgrind: test
	valgrind -s --leak-check=full ./test.out

uninstall:
	rm -rf ~/app/SmartCalc_v2

install: uninstall
	$(INSTALL)

dvi:
	open dvi.md

dist: install
	cp ~/app/SmartCalc_v2 ./SmartCalc_v2
	tar czvf SmartCalc_v2.0.tar.gz $(DIST_FILES) SmartCalc_v2
	rm -rf SmartCalc_v2

open:
	~/app/SmartCalc_v2