#ifndef S21_MATRIX_OOP_H_
#define S21_MATRIX_OOP_H_

#include <algorithm>
#include <cmath>
#include <vector>
class S21Matrix {
  // Pointer to the memory where the matrix is allocated

 public:
  S21Matrix();                             // Default constructor // done
  S21Matrix(int rows, int cols);           // done
  S21Matrix(const S21Matrix &other);       // done
  S21Matrix(S21Matrix &&other);            // done
  ~S21Matrix();                            // Destructor // done
  void SumMatrix(const S21Matrix &other);  // done
  bool EqMatrix(const S21Matrix &other);   // done
  void SubMatrix(const S21Matrix &other);  // done
  void MulNumber(const double num);        // done
  void MulMatrix(const S21Matrix &other);  // done
  S21Matrix Transpose();                   // done
  S21Matrix CalcComplements();
  double Determinant();  // look like done
  S21Matrix InverseMatrix();
  double &operator()(int row, int col) const;         // done
  S21Matrix &operator=(const S21Matrix &other);       // done
  S21Matrix &operator=(S21Matrix &&other);            // done
  bool operator==(S21Matrix other);                   // done
  S21Matrix operator*(const double &value) const;     // done
  S21Matrix operator*(const S21Matrix &other) const;  // done
  void operator*=(const S21Matrix &other);            // done
  void operator*=(const double &value);               // done

  // friend S21Matrix operator*(double value, S21Matrix &matrix);
  //  friend S21Matrix operator*(int value, S21Matrix& matrix);
  // friend void operator*=(double value, S21Matrix &matrix);
  //  friend void operator*=(int value, S21Matrix& matrix);
  //  friend Matrix operator*(Matrix&, double);

  S21Matrix operator-(const S21Matrix &other) const;  // done
  void operator-=(const S21Matrix &other);            // done
  S21Matrix operator+(const S21Matrix &other) const;  // done
  void operator+=(const S21Matrix &other);            // done
  int GetRow();                                       // done
  int GetCol();                                       // done
  void SetRow(int rows);                              // done
  void SetCol(int cols);                              // done

 private:
  int rows_, cols_;  // Rows and columns
  double **matrix_;
  // look like done
  double Determinant_recursive(S21Matrix &tmp);  // look like done
  void CopyMatrix(const S21Matrix &other);
  void DelMatrix();                       // done
  void CreateMatrix(int rows, int cols);  // done
  S21Matrix Minor(int i, int j);
};

S21Matrix operator*(double,
                    S21Matrix &);  // думашь что друзья не нужны? как бы не так
void operator*=(double, S21Matrix &);

#endif  // S21_MATRIX_OOP_H
