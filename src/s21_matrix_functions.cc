#include "s21_matrix_oop.h"

/**
 * Сравнение матриц
 */
bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool state = true;
  if (!this->S21MatrixSizesAreEqual(other)) state = false;

  if (state)
    for (int i = 0; i < this->rows_ && state; i++)
      for (int j = 0; j < this->cols_ && state; j++)
        if (abs(this->matrix_[i][j] - other.matrix_[i][j]) > ACCURACY)
          state = false;

  return state;
}

/**
 * Сложение матриц
 */
void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (!this->S21MatrixSizesAreEqual(other))
    throw invalid_argument("Matrices of different sizes");

  double** new_matrix = new double*[this->rows_];
  for (int i = 0; i < this->rows_; i++) {
    new_matrix[i] = new double[this->cols_];
    for (int j = 0; j < this->cols_; j++)
      new_matrix[i][j] = this->matrix_[i][j] + other.matrix_[i][j];
  }

  this->ResetMatrix();
  matrix_ = new_matrix;
}

/**
 * Вычитание матриц
 */
void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (!this->S21MatrixSizesAreEqual(other))
    throw invalid_argument("Matrices of different sizes");

  double** new_matrix = new double*[this->rows_];
  for (int i = 0; i < this->rows_; i++) {
    new_matrix[i] = new double[this->cols_];
    for (int j = 0; j < this->cols_; j++)
      new_matrix[i][j] = this->matrix_[i][j] - other.matrix_[i][j];
  }

  this->ResetMatrix();
  matrix_ = new_matrix;
}

/**
 * Умножение матрицы на число
 */
void S21Matrix::MulNumber(const double num) {
  double** new_matrix = new double*[this->rows_];
  for (int i = 0; i < this->rows_; i++) {
    new_matrix[i] = new double[this->cols_];
    for (int j = 0; j < this->cols_; j++)
      new_matrix[i][j] = this->matrix_[i][j] * num;
  }

  this->ResetMatrix();
  matrix_ = new_matrix;
}

/**
 * Умножение матриц
 */
void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (this->rows_ != other.cols_ || this->cols_ != other.rows_)
    throw invalid_argument(
        "The number of columns of the first matrix is ​​not equal to the "
        "number of rows of the second matrix");

  double** new_matrix = new double*[this->rows_];
  for (int i = 0; i < this->rows_; i++) {
    new_matrix[i] = new double[other.cols_];
    for (int j = 0; j < other.cols_; j++)
      for (int k = 0; k < this->cols_; k++)
        new_matrix[i][j] += this->matrix_[i][k] * other.matrix_[k][j];
  }

  this->ResetMatrix();
  this->cols_ = other.cols_;
  this->matrix_ = new_matrix;
}

/**
 * Транспонирование матрицы
 */
S21Matrix S21Matrix::Transpose() {
  int new_rows = this->cols_;
  int new_cols = this->rows_;

  S21Matrix transposed_matrix(new_rows, new_cols);
  for (int i = 0; i < cols_; i++)
    for (int j = 0; j < rows_; j++)
      transposed_matrix.matrix_[i][j] = matrix_[j][i];

  return transposed_matrix;
}

/**
 * Матрица алгебраических дополнений
 */
S21Matrix S21Matrix::CalcComplements() {
  if (!this->S21MatrixIsSquare())
    throw invalid_argument("Matrix is not square");

  S21Matrix calc_comp(this->rows_, this->cols_);
  if (this->rows_ == 1)
    calc_comp.matrix_[0][0] = 1;
  else {
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < this->cols_; j++) {
        S21Matrix* minor = new S21Matrix(this->rows_ - 1, this->cols_ - 1);
        this->ExcludeRowCol(*minor, i, j);
        calc_comp.matrix_[i][j] = minor->DetRec() * ((i + j) % 2 == 0 ? 1 : -1);
        delete minor;
      }
    }
  }

  return calc_comp;
}

/**
 * Определитель матрицы
 */
double S21Matrix::Determinant() {
  if (!this->S21MatrixIsSquare())
    throw invalid_argument("Matrix is not square");

  return this->DetRec();
}

/**
 * Обратная матрица
 */
S21Matrix S21Matrix::InverseMatrix() {
  double det = this->Determinant();
  if (det == 0)
    throw invalid_argument("The determinant of the matrix is ​​0");

  S21Matrix temp_matrix(this->rows_, this->cols_);
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++)
      temp_matrix.matrix_[i][j] = this->matrix_[i][j];
  }

  S21Matrix calc_comp = temp_matrix.CalcComplements();
  S21Matrix result = calc_comp.Transpose();
  result.MulNumber(1 / det);

  return result;
}