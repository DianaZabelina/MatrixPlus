#include "test.h"

TEST(Operators, test_1) {
  int rows = 3, cols = 3;
  S21Matrix* A = new S21Matrix(rows, cols);
  S21Matrix* B = new S21Matrix(rows, cols);
  S21Matrix* res = new S21Matrix(rows, cols);
  double input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  double output[] = {2, 4, 6, 8, 10, 12, 14, 16, 18};
  A->SetMatrix(input);
  B->SetMatrix(input);
  res->SetMatrix(output);
  S21Matrix sum = *A + *B;
  EXPECT_TRUE(sum.EqMatrix(*res));
  delete A;
  delete B;
  delete res;
}

TEST(Operators, test_2) {
  int rows = 3, cols = 3;
  S21Matrix* A = new S21Matrix(rows, cols);
  S21Matrix* B = new S21Matrix(rows, cols);
  S21Matrix* res = new S21Matrix(rows, cols);
  double input_1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  double input_2[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9};
  double output[] = {2, 4, 6, 8, 10, 12, 14, 16, 18};
  A->SetMatrix(input_1);
  B->SetMatrix(input_2);
  res->SetMatrix(output);
  S21Matrix sub = *A - *B;
  EXPECT_TRUE(sub.EqMatrix(*res));
  delete A;
  delete B;
  delete res;
}

TEST(Operators, test_3) {
  int rows = 3, cols = 3;
  S21Matrix* A = new S21Matrix(rows, cols);
  S21Matrix* res = new S21Matrix(rows, cols);
  double input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  double output[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
  A->SetMatrix(input);
  res->SetMatrix(output);
  S21Matrix mul_num = *A * 1.1;
  EXPECT_TRUE(mul_num.EqMatrix(*res));
  delete A;
  delete res;
}

TEST(Operators, test_4) {
  int A_rows = 2, A_cols = 3, B_rows = 3, B_cols = 2;
  S21Matrix* A = new S21Matrix(A_rows, A_cols);
  S21Matrix* B = new S21Matrix(B_rows, B_cols);
  S21Matrix* res = new S21Matrix(A_rows, B_cols);
  double input_1[] = {1, 2, 3, 4, 5, 6};
  double input_2[] = {6, 5, 4, 3, 2, 1};
  double output[] = {20, 14, 56, 41};
  A->SetMatrix(input_1);
  B->SetMatrix(input_2);
  res->SetMatrix(output);
  S21Matrix mul = *A * *B;
  EXPECT_TRUE(mul.EqMatrix(*res));
  delete A;
  delete B;
  delete res;
}

TEST(Operators, test_5) {
  int rows = 3, cols = 3;
  S21Matrix* A = new S21Matrix(rows, cols);
  S21Matrix* B = new S21Matrix(rows, cols);
  double input_1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9.1234567};
  double input_2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9.1234560};
  A->SetMatrix(input_1);
  B->SetMatrix(input_2);
  EXPECT_FALSE(*A == *B);
  delete A;
  delete B;
}

TEST(Operators, test_6) {
  int rows = 3, cols = 3;
  S21Matrix* A = new S21Matrix(rows, cols);
  S21Matrix* B = new S21Matrix(rows, cols);
  double input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  A->SetMatrix(input);
  *B = *A;
  EXPECT_TRUE(B->EqMatrix(*A));
  delete A;
  delete B;
}

TEST(Operators, test_7) {
  int A_rows = 3, A_cols = 3, B_rows = 2, B_cols = 5;
  S21Matrix* A = new S21Matrix(A_rows, A_cols);
  S21Matrix* B = new S21Matrix(B_rows, B_cols);
  EXPECT_THROW(*A += *B, std::invalid_argument);
  delete A;
  delete B;
}

TEST(Operators, test_8) {
  int rows = 3, cols = 3;
  S21Matrix* A = new S21Matrix(rows, cols);
  S21Matrix* B = new S21Matrix(rows, cols);
  S21Matrix* res = new S21Matrix(rows, cols);
  double input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  double output[] = {2, 4, 6, 8, 10, 12, 14, 16, 18};
  A->SetMatrix(input);
  B->SetMatrix(input);
  res->SetMatrix(output);
  *A += *B;
  EXPECT_TRUE(A->EqMatrix(*res));
  delete A;
  delete B;
  delete res;
}

TEST(Operators, test_9) {
  int A_rows = 3, A_cols = 3, B_rows = 2, B_cols = 5;
  S21Matrix* A = new S21Matrix(A_rows, A_cols);
  S21Matrix* B = new S21Matrix(B_rows, B_cols);
  EXPECT_THROW(*A -= *B, std::invalid_argument);
  delete A;
  delete B;
}

TEST(Operators, test_10) {
  int rows = 3, cols = 3;
  S21Matrix* A = new S21Matrix(rows, cols);
  S21Matrix* B = new S21Matrix(rows, cols);
  S21Matrix* res = new S21Matrix(rows, cols);
  double input_1[] = {2, 4, 6, 8, 10, 12, 14, 16, 18};
  double input_2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  double output[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  A->SetMatrix(input_1);
  B->SetMatrix(input_2);
  res->SetMatrix(output);
  *A -= *B;
  EXPECT_TRUE(A->EqMatrix(*res));
  delete A;
  delete B;
  delete res;
}

TEST(Operators, test_11) {
  int rows = 3, cols = 3;
  S21Matrix* A = new S21Matrix(rows, cols);
  S21Matrix* res = new S21Matrix(rows, cols);
  double input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  double output[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
  A->SetMatrix(input);
  res->SetMatrix(output);
  *A *= 1.1;
  EXPECT_TRUE(A->EqMatrix(*res));
  delete A;
  delete res;
}

TEST(Operators, test_12) {
  int A_rows = 3, A_cols = 3, B_rows = 2, B_cols = 5;
  S21Matrix* A = new S21Matrix(A_rows, A_cols);
  S21Matrix* B = new S21Matrix(B_rows, B_cols);
  EXPECT_THROW(*A *= *B, std::invalid_argument);
  delete A;
  delete B;
}

TEST(Operators, test_13) {
  int A_rows = 2, A_cols = 3, B_rows = 3, B_cols = 2;
  S21Matrix* A = new S21Matrix(A_rows, A_cols);
  S21Matrix* B = new S21Matrix(B_rows, B_cols);
  S21Matrix* res = new S21Matrix(A_rows, B_cols);
  double input_1[] = {1, 2, 3, 4, 5, 6};
  double input_2[] = {6, 5, 4, 3, 2, 1};
  double output[] = {20, 14, 56, 41};
  A->SetMatrix(input_1);
  B->SetMatrix(input_2);
  res->SetMatrix(output);
  *A *= *B;
  EXPECT_TRUE(A->EqMatrix(*res));
  delete A;
  delete B;
  delete res;
}

TEST(Operators, test_14) {
  int rows = 3, cols = 3;
  S21Matrix A(rows, cols);
  double value = A(0, 0);
  EXPECT_TRUE(value == 0);
  EXPECT_THROW(A(-1, 0), std::invalid_argument);
  EXPECT_THROW(A(0, -1), std::invalid_argument);
  EXPECT_THROW(A(3, 0), std::invalid_argument);
  EXPECT_THROW(A(0, 3), std::invalid_argument);
}