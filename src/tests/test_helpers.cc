#include "test.h"

TEST(Helpers, test_1) {
  int rows = -1, cols = -1;
  S21Matrix A;
  EXPECT_THROW(A.setRows(rows), std::invalid_argument);
  EXPECT_THROW(A.setCols(cols), std::invalid_argument);
  EXPECT_EQ(A.getMatrix(), nullptr);
}

TEST(Helpers, test_2) {
  int rows = 0, cols = 0;
  S21Matrix A;
  A.setRows(rows);
  A.setCols(cols);
  EXPECT_EQ(A.getRows(), 0);
  EXPECT_EQ(A.getCols(), 0);
  EXPECT_NE(A.getMatrix(), nullptr);
}

TEST(Helpers, test_3) {
  int old_rows = 1, old_cols = 1, new_rows = 2, new_cols = 2;
  S21Matrix* A = new S21Matrix(old_rows, old_cols);
  S21Matrix* res = new S21Matrix(new_rows, new_cols);
  double input[] = {1};
  double output[] = {1, 0, 0, 0};
  A->SetMatrix(input);
  res->SetMatrix(output);
  A->setRows(new_rows);
  A->setCols(new_cols);
  EXPECT_TRUE(A->EqMatrix(*res));
  delete A;
  delete res;
}

TEST(Helpers, test_4) {
  int old_rows = 2, old_cols = 2, new_rows = 1, new_cols = 1;
  S21Matrix* A = new S21Matrix(old_rows, old_cols);
  S21Matrix* res = new S21Matrix(new_rows, new_cols);
  double input[] = {1, 0, 0, 0};
  double output[] = {1};
  A->SetMatrix(input);
  res->SetMatrix(output);
  A->setRows(new_rows);
  A->setCols(new_cols);
  EXPECT_TRUE(A->EqMatrix(*res));
  delete A;
  delete res;
}

TEST(Helpers, test_5) {
  int rows = 3, cols = 3;
  S21Matrix A(rows, cols);
  S21Matrix B;
  EXPECT_TRUE(A.S21MatrixIsCorrect());
}

TEST(Helpers, test_6) {
  int rows = 3, cols = 3;
  S21Matrix A(rows, cols);
  EXPECT_TRUE(A.S21MatrixIsSquare());
}

TEST(Helpers, test_7) {
  int rows = 3, cols = 3;
  S21Matrix A(rows, cols);
  S21Matrix B(rows, cols);
  EXPECT_TRUE(A.S21MatrixSizesAreEqual(B));
}

TEST(Helpers, test_8) {
  int A_rows = 3, A_cols = 3, B_rows = 2, B_cols = 2;
  S21Matrix A(A_rows, A_cols);
  S21Matrix B(B_rows, B_cols);
  S21Matrix res(B_rows, B_cols);
  double input[] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
  double output[] = {4, 2, 2, 1};
  A.SetMatrix(input);
  res.SetMatrix(output);
  A.ExcludeRowCol(B, 0, 0);
  EXPECT_TRUE(B.EqMatrix(res));
}

TEST(Helpers, test_9) {
  int rows = 2, cols = 2;
  S21Matrix A(rows, cols);
  double input[] = {4, 2, 2, 1};
  A.SetMatrix(input);
  EXPECT_TRUE(A.DetRec() == 0);
}