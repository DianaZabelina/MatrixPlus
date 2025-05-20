#include "s21_matrix_oop.h"

/**
 * Сложение двух матриц
 */
S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix res(*this);
  res.SumMatrix(other);
  return res;
}

/**
 * Вычитание матриц
 */
S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix res(*this);
  res.SubMatrix(other);
  return res;
}

/**
 * Умножение матрицы на число
 */
S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix res(*this);
  res.MulNumber(num);
  return res;
}

/**
 * Умножение матриц
 */
S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix res(*this);
  res.MulMatrix(other);
  return res;
}

/**
 * Сравнение матриц
 */
bool S21Matrix::operator==(const S21Matrix& other) {
  return this->EqMatrix(other);
}

/**
 * Присвоение матрице значений другой матрицы
 */
S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    delete[] matrix_;
    this->rows_ = other.rows_;
    this->cols_ = other.cols_;
    this->matrix_ = new double*[this->rows_];

    for (int i = 0; i < other.rows_; i++) {
      this->matrix_[i] = new double[other.cols_];
      for (int j = 0; j < other.cols_; j++)
        this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
  return *this;
}

/**
 * Присвоение сложения
 */
S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  this->SumMatrix(other);
  return *this;
}

/**
 * Присвоение разности
 */
S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  this->SubMatrix(other);
  return *this;
}

/**
 * Присвоение умножения матрицы на число
 */
S21Matrix& S21Matrix::operator*=(const double num) {
  this->MulNumber(num);
  return *this;
}

/**
 * Присвоение умножения матрицы
 */
S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  this->MulMatrix(other);
  return *this;
}

/**
 * Индексация по элементам матрицы
 */
double& S21Matrix::operator()(int i, int j) {
  if (i < 0 || j < 0 || i >= this->rows_ || j >= this->cols_)
    throw invalid_argument("Index outside the matrix");

  return this->matrix_[i][j];
}