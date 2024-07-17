CC = -Wall -Werror -Wextra -std=c++17 -pedantic
OS := $(shell uname)
FILES = ./tests/main.cc \
./tests/test_array.cc \
./tests/test_list.cc \
./tests/test_map.cc \
./tests/test_multiset.cc \
./tests/test_set.cc \
./tests/queue_tests.cc \
./tests/test_vector.cc \
./tests/stack_tests.cc

ifeq ($(OS),Linux)
FLAGS = -lgtest -lm -lpthread -lrt -fprofile-arcs -ftest-coverage
else
FLAGS = -lgtest -lm -lpthread -fprofile-arcs -ftest-coverage
endif

all: clean test

test: clean
	g++ $(CC) $(FILES) $(FLAGS) -o unit_test
	./unit_test

style:
	@cp ../materials/linters/.clang-format ./
	clang-format -n */*.cc */*.h */*.tpp
	clang-format -n *.h
	@rm -rf .clang-format

style_i:
	@cp ../materials/linters/.clang-format ./
	clang-format -i */*.cc */*.h */*.tpp
	clang-format -i *.h
	@rm -rf .clang-format


# gcov_report: test
# 	./unit_test
# 	lcov -t "./unit_test"  -o report.info  -c -d ./ --no-external
# 	genhtml -o report report.info
# 	open ./report/index.html
# 	rm -f *.gcno *.gcda *.info gсov_report.o *.gcov

gcov_report: test
	./unit_test
	lcov -t "./unit_test" -o report.info --no-external -c -d . 
	genhtml -o report report.info
	open ./report/index.html
	rm -f *.gcno *.gcda *.info gсov_report.o *.gcov
	

valgrind: test
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./unit_test

clean:
	rm -rf *.a *.o *.so *.gcda *.gcno *.gch *.info *.html *.css test *.txt test.info test.dSYM *.out report unit_test

leak:
	leaks -atExit -- ./unit_test