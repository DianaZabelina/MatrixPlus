#include "test.h"

TEST(Functions, test_1) {
  int rows = 3, cols = 3;
  S21Matrix A(rows, cols);
  S21Matrix res(rows, cols);
  double input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  double output[] = {1, 4, 7, 2, 5, 8, 3, 6, 9};
  A.SetMatrix(input);
  res.SetMatrix(output);
  S21Matrix transposed = A.Transpose();
  EXPECT_TRUE(transposed.EqMatrix(res));
}

TEST(Functions, test_2) {
  int rows = 2, cols = 5;
  S21Matrix A(rows, cols);
  EXPECT_THROW(A.CalcComplements(), std::invalid_argument);
}

TEST(Functions, test_3) {
  int rows = 1, cols = 1;
  S21Matrix A(rows, cols);
  double input[] = {0};
  A.SetMatrix(input);
  S21Matrix calc_comp = A.CalcComplements();
  EXPECT_TRUE(calc_comp(0, 0) == 1);
}

TEST(Functions, test_4) {
  int rows = 3, cols = 3;
  S21Matrix A(rows, cols);
  S21Matrix res(rows, cols);
  double input[] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
  double output[] = {0, 10, -20, 4, -14, 8, -8, -2, 4};
  A.SetMatrix(input);
  res.SetMatrix(output);
  S21Matrix calc_comp = A.CalcComplements();
  EXPECT_TRUE(calc_comp.EqMatrix(res));
}

TEST(Functions, test_5) {
  int rows = 2, cols = 3;
  S21Matrix A(rows, cols);
  EXPECT_THROW(A.Determinant(), std::invalid_argument);
}

TEST(Functions, test_6) {
  int rows = 3, cols = 3;
  S21Matrix A(rows, cols);
  double input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  A.SetMatrix(input);
  EXPECT_TRUE(A.Determinant() == 0);
}

TEST(Functions, test_7) {
  int rows = 3, cols = 3;
  S21Matrix A(rows, cols);
  double input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  A.SetMatrix(input);
  EXPECT_THROW(A.InverseMatrix(), std::invalid_argument);
}

TEST(Functions, test_8) {
  int rows = 3, cols = 3;
  S21Matrix A(rows, cols);
  S21Matrix res(rows, cols);
  double input[] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
  double output[] = {1, -1, 1, -38, 41, -34, 27, -29, 24};
  A.SetMatrix(input);
  res.SetMatrix(output);
  S21Matrix inversed = A.InverseMatrix();
  EXPECT_TRUE(inversed.EqMatrix(res));
}