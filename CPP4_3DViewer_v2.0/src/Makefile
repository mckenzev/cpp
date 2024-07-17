CC = g++ -std=c++17
CCFLAGS = -Wall -Werror -Wextra
TEST_LIBS = -lgtest
TESTS = tests/*.cc model/*.cc controller/*.cc
VIEW = view/*cc
TARGET = 3DViewer_v2_0

ifeq ($(OS),Darwin)
	FLAGS += -ftest-coverage
	OPEN_CMD = open
	OPEN_APP = $(OPEN_CMD) 
	APP = 3dViewer.app
else
	FLAGS += -lm -lrt -lsubunit -ftest-coverage
	OPEN_CMD = xdg-open
	OPEN_APP = ./
	APP = 3dViewer
endif

all: tests clean

clean:
	rm -rf test &&\
	rm -rf *.o *.a *.out *.log *.gcda *.gcno *.info gcov_report test report .pro &&\
	rm -rf test_report

tests: clean
	$(CC) $(CCFLAGS) $(TESTS) -o test $(TEST_LIBS)
	./test

install:
	mkdir -p Executables
	cd Executables &&\
	qmake6 ../view/$(TARGET).pro &&\
	make -j6

uninstall:
	rm -r Executables
	
leaks: clean
	$(CC) $(CCFLAGS) tests/*.cpp $(TEST_LIBS) -o test
	leaks --atExit -- ./test

valgrind: clean tests
	valgrind --track-origins=yes --leak-check=full --log-file="valgrind.log" --leak-resolution=med --show-leak-kinds=all -s ./test
	
open:
	./Executables/$(TARGET)

dvi:
	$(OPEN_CMD) README.html

dist: 
	cd .. && tar -czf $(TARGET).tgz src &&\
	mv 3DViewer_v2_0.tgz src

check_style:
	clang-format -style=google -n controller/*
	clang-format -style=google -n model/*
	clang-format -style=google -n tests/*.cc tests/*.h
	clang-format -style=google -n view/*.cc view/*.h
	clang-format -style=google -n main.cc
	clang-format -style=google -n utils.h
gcov_report: clean
	${CC} ${TESTS} -o test_report ${TEST_LIBS} --coverage -fno-elide-constructors
	@./test_report
	@mkdir report
	@gcovr -r . --html --html-details -o ./report/coverage_report.html
	@open ./report/coverage_report.html

rebuild: clean all