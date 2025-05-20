#include "s21_matrix_oop.h"

/**
 * Базовый конструктор, инициализирующий матрицу некоторой заранее заданной
 * размерностью
 */
S21Matrix::S21Matrix() {
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

/**
 * Параметризированный конструктор с количеством строк и столбцов
 */
S21Matrix::S21Matrix(int rows, int cols) {
  if (rows < 0 || cols < 0)
    throw invalid_argument("Invalid rows_ or cols_ value");

  rows_ = rows;
  cols_ = cols;
  matrix_ = new double*[rows_];

  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
    for (int j = 0; j < cols_; j++) matrix_[i][j] = 0;
  }
}

/**
 * Конструктор копирования
 */
S21Matrix::S21Matrix(const S21Matrix& other) {
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  this->matrix_ = new double*[rows_];

  for (int i = 0; i < other.rows_; i++) {
    this->matrix_[i] = new double[other.cols_];
    for (int j = 0; j < other.cols_; j++)
      this->matrix_[i][j] = other.matrix_[i][j];
  }
}

/**
 * Конструктор переноса
 */
S21Matrix::S21Matrix(S21Matrix&& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;

  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

/**
 * Деструктор
 */
S21Matrix::~S21Matrix() {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;

  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}