#include "s21_matrix_oop.h"

#include <cmath>
#include <iostream>

S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(int rows, int cols)
    : rows_(rows), cols_(cols), matrix_(nullptr) {
  if (rows < 1 || cols < 1) {
    throw std::invalid_argument("Invalid number of columns or rows");
  }
  matrix_ = createMatrix(rows, cols);
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  matrix_ = createMatrix(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.rows_ = other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() { removeMatrix(); }

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool result = true;
  if (this != &other) {
    if (rows_ == other.rows_ && cols_ == other.cols_) {
      for (int i = 0; i < rows_ && result == true; i++) {
        for (int j = 0; j < cols_; j++) {
          if (fabs(matrix_[i][j] - other.matrix_[i][j]) > fabs(epsilon)) {
            result = false;
            break;
          }
        }
      }
    } else {
      result = false;
    }
  }
  return result;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::logic_error("The matrices differ in size");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::logic_error("The matrices differ in size");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::logic_error("Incorrect matrix");
  }
  S21Matrix tmp(rows_, other.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      tmp.matrix_[i][j] = 0;
      for (int k = 0; k < cols_; k++) {
        tmp.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  std::swap(*this, tmp);
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix tmp(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      tmp.matrix_[j][i] = matrix_[i][j];
    }
  }
  return tmp;
}

S21Matrix S21Matrix::CalcComplements() {
  if (cols_ != rows_) {
    throw std::logic_error("Rows are not equal to columns");
  }
  if (cols_ < 2) {
    throw std::logic_error("The number of rows in the matrix is less than 2");
  }
  S21Matrix res(rows_, cols_);
  for (int i = 0; i < cols_; i++) {
    for (int j = 0; j < cols_; j++) {
      S21Matrix tmp(rows_ - 1, cols_ - 1);
      int sign = (i + j) % 2 ? -1 : 1;
      for (int k = 0; k < rows_ - 1; k++) {
        for (int l = 0; l < rows_ - 1; l++) {
          int onePlus = k >= i ? 1 : 0;
          int secPlus = l >= j ? 1 : 0;
          tmp.matrix_[k][l] = matrix_[k + onePlus][l + secPlus];
        }
      }
      res.matrix_[i][j] = sign * tmp.Determinant();
    }
  }
  return res;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_) {
    throw std::logic_error("Rows are not equal to columns");
  }
  if (rows_ == 1) return matrix_[0][0];
  if (rows_ == 2) {
    return matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  }
  double result = 0;
  for (int i = 0; i < rows_; i++) {
    S21Matrix tmp(rows_ - 1, cols_ - 1);
    for (int j = 0; j < rows_ - 1; j++) {
      for (int k = 0; k < cols_ - 1; k++) {
        int plus = k >= i ? 1 : 0;
        tmp.matrix_[j][k] = matrix_[j + 1][k + plus];
      }
    }
    double det = tmp.Determinant();
    int sign = i % 2 ? -1 : 1;
    result += matrix_[0][i] * det * sign;
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  double det = Determinant();
  if (fabs(det) < epsilon) {
    throw std::invalid_argument("The matrix cannot be inverted");
  }
  S21Matrix res(rows_, cols_);
  if (cols_ == 1) {
    res.matrix_[0][0] = 1 / matrix_[0][0];
  } else {
    res = CalcComplements();
    res = res.Transpose();
    res.MulNumber(1 / det);
  }
  return res;
}

int S21Matrix::GetRows() const { return rows_; }

int S21Matrix::GetCols() const { return cols_; }

void S21Matrix::SetRows(int new_rows) {
  if (new_rows < 1) {
    throw std::invalid_argument("Invalid value");
  }
  S21Matrix res(new_rows, cols_);
  int minRows = new_rows < rows_ ? new_rows : rows_;
  for (int i = 0; i < minRows; i++) {
    for (int j = 0; j < cols_; j++) {
      res.matrix_[i][j] = matrix_[i][j];
    }
  }
  std::swap(*this, res);
}

void S21Matrix::SetCols(int new_cols) {
  if (new_cols < 1) {
    throw std::invalid_argument("Invalid value");
  }
  S21Matrix res(rows_, new_cols);
  int minCols = new_cols < cols_ ? new_cols : cols_;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < minCols; j++) {
      res.matrix_[i][j] = matrix_[i][j];
    }
  }
  std::swap(*this, res);
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix newMatrix(*this);
  newMatrix.SumMatrix(other);
  return newMatrix;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix newMatrix(*this);
  newMatrix.SubMatrix(other);
  return newMatrix;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix newMatrix(*this);
  newMatrix.MulMatrix(other);
  return newMatrix;
}

S21Matrix S21Matrix::operator*(const double num) const {
  S21Matrix newMatrix(*this);
  newMatrix.MulNumber(num);
  return newMatrix;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

bool S21Matrix::operator==(const S21Matrix& other) { return EqMatrix(other); }

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    *this = other;
    // S21Matrix temp(other);
    // std::swap(*this, temp);
  }
  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) noexcept {
  if (this != &other) {
    removeMatrix();
    rows_ = cols_ = 0;
    std::swap(rows_, other.rows_);
    std::swap(cols_, other.cols_);
    std::swap(matrix_, other.matrix_);
  }
  return *this;
}

S21Matrix operator*(double number, S21Matrix& other) {
  S21Matrix tmp(other);
  tmp *= number;
  return tmp;
}

double S21Matrix::operator()(int row, int col) const {
  if ((row >= rows_) || (col >= cols_) || (row < 0) || (col < 0))
    throw std::out_of_range("Beyond the matrix.");
  return matrix_[row][col];
}

double& S21Matrix::operator()(int row, int col) {
  if ((row >= rows_) || (col >= cols_) || (row < 0) || (col < 0))
    throw std::out_of_range("Beyond the matrix.");
  return matrix_[row][col];
}

double** S21Matrix::createMatrix(int rows, int cols) const {
  double** matrix = new double*[rows]();
  for (int i = 0; i < rows; i++) matrix[i] = new double[cols]();
  return matrix;
}

void S21Matrix::removeMatrix() {
  for (int i = 0; i < rows_; i++) delete[] matrix_[i];
  delete[] matrix_;
  matrix_ = nullptr;
}
