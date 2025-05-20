#include "s21_matrix_oop.h"

/**
 * Доступ к количеству строк
 */
int S21Matrix::getRows() { return rows_; }

/**
 * Доступ к количеству столбцов
 */
int S21Matrix::getCols() { return cols_; }

/**
 * Доступ к указателю
 */
double** S21Matrix::getMatrix() { return matrix_; }

/**
 * Изменение количества строк
 * При увеличении размера matrix дополняется нулевыми элементами, при
 * уменьшении - лишнее просто отбрасывается.
 */
void S21Matrix::setRows(int rows) {
  if (rows < 0) throw invalid_argument("Invalid rows_ value");

  int old_rows = rows_;
  double** new_matrix = new double*[rows];
  for (int i = 0; i < rows; i++) {
    new_matrix[i] = new double[cols_];
    for (int j = 0; j < cols_; j++)
      new_matrix[i][j] = (i < rows_) ? matrix_[i][j] : 0;
  }

  for (int i = 0; i < old_rows; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;

  rows_ = rows;
  matrix_ = new_matrix;
}

/**
 * Изменение количества столбцов
 * При увеличении размера matrix дополняется нулевыми элементами, при
 * уменьшении - лишнее просто отбрасывается.
 */
void S21Matrix::setCols(int cols) {
  if (cols < 0) throw invalid_argument("Invalid cols_ value");

  for (int i = 0; i < rows_; i++) {
    double* new_row = new double[cols];
    for (int j = 0; j < cols; j++) new_row[j] = (j < cols_) ? matrix_[i][j] : 0;
    delete[] matrix_[i];
    matrix_[i] = new_row;
  }

  cols_ = cols;
}

/**
 * Проверка корректности матрицы
 * @return  true - матрица корректна
 * false - матрица не корректна
 */
bool S21Matrix::S21MatrixIsCorrect() {
  return (matrix_ != nullptr && rows_ > 0 && cols_ > 0);
}

/**
 * Проверка квадратной матрицы
 * @return  true - матрица квадратная
 * false - матрица не квадратная
 */
bool S21Matrix::S21MatrixIsSquare() {
  return (rows_ > 0 && cols_ > 0 && rows_ == cols_);
}

/**
 * Проверка размеров матриц
 * @return  true - матрицы одного размера
 * false - матрицы разного размера
 */
bool S21Matrix::S21MatrixSizesAreEqual(const S21Matrix& other) {
  return (this->rows_ == other.rows_ && this->cols_ == other.cols_);
}

/**
 * Очищение матрицы
 */
void S21Matrix::ResetMatrix() {
  for (int i = 0; i < this->rows_; i++) {
    delete[] this->matrix_[i];
  }
  delete[] this->matrix_;
}

/**
 * Вычеркивание из матрицы i-й строки и j-го столбца
 */
void S21Matrix::ExcludeRowCol(const S21Matrix& minor, int ex_row, int ex_col) {
  int minor_row = 0, minor_col = 0;
  for (int i = 0; i < this->rows_; i++) {
    if (i != ex_row) {
      for (int j = 0; j < this->cols_; j++) {
        if (j != ex_col) {
          minor.matrix_[minor_row][minor_col] = this->matrix_[i][j];
          minor_col++;
        }
      }
      minor_col = 0;
      minor_row++;
    }
  }
}

/**
 * Рекурсивное вычисление определителя матрицы
 */
double S21Matrix::DetRec() {
  if (this->rows_ == 1) return this->matrix_[0][0];

  double det = 0;
  int sign = 1;
  S21Matrix* minor = new S21Matrix(this->rows_ - 1, this->cols_ - 1);
  for (int i = 0; i < this->rows_; i++) {
    this->ExcludeRowCol(*minor, 0, i);
    det += sign * this->matrix_[0][i] * minor->DetRec();
    sign = -sign;
  }
  delete minor;

  return det;
}

/**
 * Заполнение матрицы заданным массивом
 */
void S21Matrix::SetMatrix(double* array) {
  for (int i = 0; i < this->rows_; i++)
    for (int j = 0; j < this->cols_; j++)
      matrix_[i][j] = array[i * this->cols_ + j];
}

/**
 * Вывод матрицы
 */
// void S21Matrix::PrintMatrix() {
//   for (int i = 0; i < this->rows_; i++) {
//     for (int j = 0; j < this->cols_; j++) cout << matrix_[i][j] << " ";
//     cout << endl;
//   }
//   cout << endl;
// }