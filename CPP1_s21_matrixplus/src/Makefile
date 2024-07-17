LIB_NAME	= s21_matrix_oop.a
CC = gcc
STD_FLAG = -lstdc++
CPP_FLAGS = -std=c++17 -pedantic -Wall -Werror -Wextra
GTEST_FLAGS = -lgtest
OS := $(shell uname -s)
LINUX_FLAG =
ifeq ($(OS), Linux)
	LINUX_FLAG += -lm
endif
SRC = s21_matrix_oop.cc
TEST_NAME = s21_matrix_oop_unit_test
SRC_TEST	= s21_matrix_oop_unit_test.cc

.PHONY: all test clean iclang clang leaks
 
all: test

s21_matrix_oop.a:
	$(CC) $(STD_FLAG) $(CPP_FLAGS) -c s21_*.cc
	ar rc s21_matrix_oop.a s21_*.o
	ranlib s21_matrix_oop.a
	rm *.o

test: $(SRC_TEST) $(LIB_NAME)
	$(CC) $(CPP_FLAGS) $(SRC_TEST) $(GTEST_FLAGS) $(LIB_NAME) $(STD_FLAG) $(LINUX_FLAG) -o $(TEST_NAME).out
	./$(TEST_NAME).out

clean:
	rm -rf $(OBJS) $(TEST).out $(TEST_NAME).out *.gcda *.gcno $(TEST_NAME).out.dSYM report *.a $(REPORT) GcovReport.info


iclang:
	clang-format -i -style=Google *.h *.cc

clang:
	clang-format -n -style=Google *.h *.cc

leaks: test
	CK_FORK=no leaks --atExit -- ./$(TEST_NAME).out



