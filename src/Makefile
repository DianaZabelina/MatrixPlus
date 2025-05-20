CFLAGS = -std=c++17 -Wall -Werror -Wextra
TFLAGS = -lgtest -lgmock -lpthread
GCOVFLAGS = -fprofile-arcs -ftest-coverage -lgcov

SRC = *.cc
OBJECTS = $(SRC:.cc=.o)
TESTS_SRC = tests/*.cc

all: clean s21_matrix_oop.a

s21_matrix_oop.a:
	g++ $(CFLAGS) $(SRC) -c
	ar rc s21_matrix_oop.a $(OBJECTS)
	rm -rf *.o

test: clean s21_matrix_oop.a
	g++ $(CFLAGS) $(TESTS_SRC) $(SRC) s21_matrix_oop.a $(TFLAGS) -o test
	./test

gcov_report: clean s21_matrix_oop.a
	g++ $(CFLAGS) $(TESTS_SRC) $(SRC) s21_matrix_oop.a $(TFLAGS) $(GCOVFLAGS) -o s21_matrix_oop
	./s21_matrix_oop
	lcov -t "s21_matrix_oop" -o s21_report.info -q --no-external -c -d . --ignore-errors usage,inconsistent
	genhtml -o report s21_report.info
	open ./report/index.html
	rm -rf *.gcno *.gcda *.info s21_matrix_oop

clang:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -i *.cc *.h tests/*.cc tests/*.h
	rm -rf .clang-format

clang_review:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n *.cc *.h tests/*.cc tests/*.h
	rm -rf .clang-format

leaks: clean test
	leaks -atExit -- test

rebuild: clean all

clean:
	rm -rf *.a *.o *.gcno *.gcda *.info s21_matrix_oop.a test s21_matrix_oop report