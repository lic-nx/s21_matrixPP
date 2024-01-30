#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {  // создаем пустой объект
  CreateMatrix(1, 1);
  //  matrix_ = nullptr;
}

S21Matrix::S21Matrix(int rows,
                     int cols) {  // создаем матрицу размером rows cols
  CreateMatrix(rows, cols);
}

S21Matrix::S21Matrix(const S21Matrix &other) {  // создаем дубликат матрицы
  CreateMatrix(other.rows_, other.cols_);
  CopyMatrix(other);
}

S21Matrix::S21Matrix(S21Matrix &&other)
    : rows_(other.rows_), cols_(other.cols_) {  // Конструктор переноса
  std::swap(matrix_, other.matrix_);
  other.cols_ = 0;
  other.rows_ = 0;
}

S21Matrix::~S21Matrix() { DelMatrix(); }

void S21Matrix::DelMatrix() {
  for (int i = 0; i < rows_; ++i) {
    delete[] matrix_[i];  // delete each row
  }
  if (rows_ > 0) delete[] matrix_;
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

int S21Matrix::GetRow() { return rows_; }
int S21Matrix::GetCol() { return cols_; }

void S21Matrix::SetRow(int rows) {
  if (rows <= 0) throw "count rows need be more then 0";
  S21Matrix other(rows, cols_);
  for (int i = 0; i < rows && i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      other.matrix_[i][j] = matrix_[i][j];
    }
  }
  DelMatrix();
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

void S21Matrix::SetCol(int cols) {
  if (cols <= 0) throw "count rows need be more then 0";
  S21Matrix other(rows_, cols);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_ && j < cols; j++) {
      other.matrix_[i][j] = matrix_[i][j];
    }
  }
  rows_ = other.rows_;
  cols_ = other.cols_;
  std::swap(matrix_, other.matrix_);
}

void S21Matrix::CopyMatrix(const S21Matrix &other) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

void S21Matrix::CreateMatrix(int rows, int cols) {
  rows_ = rows;
  cols_ = cols;
  matrix_ = new double *[rows_]();
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
}

bool S21Matrix::EqMatrix(const S21Matrix &other) {
  bool ret = true;
  if (other.cols_ == cols_ && other.rows_ == rows_) {
    for (int i = 0; i < rows_ && ret == true; i++) {
      for (int j = 0; j < cols_ && ret == true; j++) {
        if (fabs(matrix_[i][j] - other.matrix_[i][j]) > 1e-07) {
          ret = false;
        }
      }
    }
  } else
    ret = false;
  return ret;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (other.cols_ != cols_ || other.rows_ != rows_)
    throw "different matrix dimensions";
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += other(i, j);
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (other.cols_ != cols_ || other.rows_ != rows_)
    throw "different matrix dimensions";

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] -= other(i, j);
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
S21Matrix operator*(double value, S21Matrix &matrix) {
  S21Matrix res(matrix);
  res.MulNumber(value);
  return res;
}

void operator*=(double value, S21Matrix &matrix) { throw "cant mull"; }

// void operator*=(int value, S21Matrix& matrix){
//   throw "cant mull";
// }

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (other.rows_ != cols_) {
    throw "different matrix dimensions";
  }
  S21Matrix tmp(rows_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      tmp(i, j) = 0;
      for (int k = 0; k < cols_; k++) {
        tmp(i, j) += matrix_[i][k] * other(k, j);
      }
    }
  }
  *this = tmp;
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix tmp(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      tmp(j, i) = matrix_[i][j];
    }
  }
  return (tmp);
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_)
    throw("The matrix is not square to calculate the complements");
  S21Matrix tmp(rows_, cols_);
  double determ = 0;
  if (cols_ > 1 && rows_ > 1) {
    int Pow = 1;
    S21Matrix minor(rows_ - 1, cols_ - 1);
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        Pow = pow((-1), i + j);
        minor = Minor(i, j);

        determ = minor.Determinant();

        tmp(i, j) = determ;

        tmp(i, j) *= Pow;
      }
    }
  }

  return tmp;
}

double S21Matrix::Determinant() {  // look like done
  double determinant;
  if (rows_ != cols_ || rows_ < 0) throw "in Determinant: wrong size in matrix";

  determinant = matrix_[0][0];
  if (rows_ > 1) {
    determinant = Determinant_recursive(*this);
  }
  return determinant;
}

S21Matrix S21Matrix::Minor(int i, int j) {  // i dont know work it or not
  S21Matrix minor(rows_ - 1, cols_ - 1);
  for (int rows = 0, m = 0; rows < rows_; rows++, m++) {
    for (int columns = 0, n = 0; columns < rows_; columns++, n++) {
      if (columns == j) columns++;
      if (rows == i) rows++;
      if (rows != i && columns != j && columns < rows_ && rows < rows_) {
        minor.matrix_[m][n] = matrix_[rows][columns];
      }
    }
  }
  return minor;
}

double S21Matrix::Determinant_recursive(S21Matrix &tmp) {
  double result = 0;
  if (tmp.rows_ == 2) {
    result = tmp.matrix_[0][0] * tmp.matrix_[1][1] -
             tmp.matrix_[0][1] * tmp.matrix_[1][0];
  } else {
    S21Matrix minor(tmp.rows_ - 1,
                    tmp.cols_ - 1);  // создаем матрицу на размер меньше

    for (int i = 0; i < tmp.rows_; i++) {
      minor = tmp.Minor(0, i);
      result += pow((-1), i) * tmp.matrix_[0][i] * Determinant_recursive(minor);
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  S21Matrix Atrans;
  double determ = Determinant();
  if (determ == 0.0 || rows_ < 1) {
    throw("determ = 0");
  }
  S21Matrix minor = CalcComplements();
  Atrans = minor.Transpose();
  Atrans.MulNumber(1 / determ);
  return Atrans;
}

double &S21Matrix::operator()(int row, int col) const {
  if (row >= rows_ || col >= cols_ || row < 0 || col < 0)
    throw("Incorrect input, index is out of range");
  return matrix_[row][col];
}

bool S21Matrix::operator==(S21Matrix other) { return EqMatrix(other); }

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (*this == other) return *this;
  DelMatrix();
  CreateMatrix(other.rows_, other.cols_);
  CopyMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator=(S21Matrix &&other) {
  if (*this == other) return *this;
  DelMatrix();
  rows_ = other.rows_;
  cols_ = other.cols_;
  std::swap(matrix_, other.matrix_);
  other.cols_ = 0;
  other.rows_ = 0;
  return *this;
}

S21Matrix S21Matrix::operator*(const double &value) const {
  S21Matrix res{*this};
  res.MulNumber(value);
  return res;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) const {
  S21Matrix res{*this};
  res.MulMatrix(other);
  return res;
}

void S21Matrix::operator*=(const S21Matrix &other) { MulMatrix(other); }
void S21Matrix::operator*=(const double &value) { MulNumber(value); }

S21Matrix S21Matrix::operator-(const S21Matrix &other) const {
  S21Matrix res{*this};
  res.SubMatrix(other);
  return res;
}

void S21Matrix::operator-=(const S21Matrix &other) { SubMatrix(other); }

S21Matrix S21Matrix::operator+(const S21Matrix &other) const {
  S21Matrix res{*this};
  res.SumMatrix(other);
  return res;
}

void S21Matrix::operator+=(const S21Matrix &other) { SumMatrix(other); }
