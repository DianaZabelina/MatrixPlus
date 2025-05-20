#include "test.h"

TEST(Constructors, test_1) {
  S21Matrix A;
  EXPECT_EQ(A.getRows(), 0);
  EXPECT_EQ(A.getCols(), 0);
  EXPECT_EQ(A.getMatrix(), nullptr);
}

TEST(Constructors, test_2) {
  int rows = -1, cols = 1;
  EXPECT_THROW(S21Matrix A(rows, cols), std::invalid_argument);
}

TEST(Constructors, test_3) {
  int rows = 1, cols = -1;
  EXPECT_THROW(S21Matrix A(rows, cols), std::invalid_argument);
}

TEST(Constructors, test_4) {
  int rows = 1, cols = 1;
  S21Matrix A(rows, cols);
  EXPECT_EQ(A.getRows(), rows);
  EXPECT_EQ(A.getCols(), cols);
  EXPECT_NE(A.getMatrix(), nullptr);
}

TEST(Constructors, test_5) {
  int rows = 3, cols = 3;
  S21Matrix A(rows, cols);
  S21Matrix B(A);
  EXPECT_EQ(B.getRows(), A.getRows());
  EXPECT_EQ(B.getCols(), A.getCols());
  EXPECT_NE(B.getMatrix(), A.getMatrix());
  for (int i = 0; i < B.getRows(); i++)
    for (int j = 0; j < B.getCols(); j++) EXPECT_DOUBLE_EQ(B(i, j), 0);
}

TEST(Constructors, test_6) {
  int rows = 3, cols = 3;
  S21Matrix* A = new S21Matrix(rows, cols);
  S21Matrix res(rows, cols);
  double input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  double output[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  double** A_ptr = A->getMatrix();
  A->SetMatrix(input);
  res.SetMatrix(output);
  S21Matrix B = std::move(*A);
  EXPECT_EQ(B.getMatrix(), A_ptr);
  EXPECT_TRUE(B.EqMatrix(res));
  EXPECT_EQ(A->getRows(), 0);
  EXPECT_EQ(A->getCols(), 0);
  EXPECT_EQ(A->getMatrix(), nullptr);
  delete A;
}

TEST(Constructors, test_7) {
  int rows = 1, cols = 1;
  S21Matrix* A = new S21Matrix(rows, cols);
  EXPECT_EQ(A->getRows(), rows);
  EXPECT_EQ(A->getCols(), cols);
  EXPECT_NE(A->getMatrix(), nullptr);
  delete A;
  EXPECT_EQ(A->getRows(), 0);
  EXPECT_EQ(A->getCols(), 0);
  EXPECT_EQ(A->getMatrix(), nullptr);
}