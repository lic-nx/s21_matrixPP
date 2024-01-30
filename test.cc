
#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

TEST(mull, HanglesInitedEqualMatrices) {
  // TestS21Matrix A, B;
  S21Matrix A(3, 3);
  A(0, 0) = 7, A(0, 1) = 8, A(0, 2) = 3;
  A(1, 0) = 5, A(1, 1) = 9, A(1, 2) = 1;
  A(2, 0) = 9, A(2, 1) = 4, A(2, 2) = 2;
  // TestS21Matrix B(4);
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 14, matrix(0, 1) = 16, matrix(0, 2) = 6;
  matrix(1, 0) = 10, matrix(1, 1) = 18, matrix(1, 2) = 2;
  matrix(2, 0) = 18, matrix(2, 1) = 8, matrix(2, 2) = 4;
  A = 2 * A;
  ASSERT_EQ(true, A.EqMatrix(matrix));
}
TEST(mull1, HanglesInitedEqualMatrices) {
  // TestS21Matrix A, B;
  S21Matrix A(3, 3);
  A(0, 0) = 7, A(0, 1) = 8, A(0, 2) = 3;
  A(1, 0) = 5, A(1, 1) = 9, A(1, 2) = 1;
  A(2, 0) = 9, A(2, 1) = 4, A(2, 2) = 2;
  // TestS21Matrix B(4);
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 14, matrix(0, 1) = 16, matrix(0, 2) = 6;
  matrix(1, 0) = 10, matrix(1, 1) = 18, matrix(1, 2) = 2;
  matrix(2, 0) = 18, matrix(2, 1) = 8, matrix(2, 2) = 4;
  A = 2.0 * A;
  ASSERT_EQ(true, A.EqMatrix(matrix));
}

TEST(mull2, HanglesInitedEqualMatrices) {
  // TestS21Matrix A, B;
  S21Matrix A(3, 3);
  A(0, 0) = 7, A(0, 1) = 8, A(0, 2) = 3;
  A(1, 0) = 5, A(1, 1) = 9, A(1, 2) = 1;
  A(2, 0) = 9, A(2, 1) = 4, A(2, 2) = 2;
  // TestS21Matrix B(4);
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 14, matrix(0, 1) = 16, matrix(0, 2) = 6;
  matrix(1, 0) = 10, matrix(1, 1) = 18, matrix(1, 2) = 2;
  matrix(2, 0) = 18, matrix(2, 1) = 8, matrix(2, 2) = 4;

  ASSERT_ANY_THROW(2.0 *= A;);
}

TEST(mull3, HanglesInitedEqualMatrices) {
  // TestS21Matrix A, B;
  S21Matrix A(3, 3);
  A(0, 0) = 7, A(0, 1) = 8, A(0, 2) = 3;
  A(1, 0) = 5, A(1, 1) = 9, A(1, 2) = 1;
  A(2, 0) = 9, A(2, 1) = 4, A(2, 2) = 2;
  // TestS21Matrix B(4);
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 14, matrix(0, 1) = 16, matrix(0, 2) = 6;
  matrix(1, 0) = 10, matrix(1, 1) = 18, matrix(1, 2) = 2;
  matrix(2, 0) = 18, matrix(2, 1) = 8, matrix(2, 2) = 4;
  ASSERT_ANY_THROW(2 *= A;);
}

TEST(EqMatrixTest, HanglesInitedEqualMatrices) {
  // TestS21Matrix A, B;
  S21Matrix A(2, 2), B(2, 2);
  A(0, 0) = 1;
  A(0, 1) = 1;
  A(1, 0) = 1;
  A(1, 1) = 1;
  B(0, 0) = 1;
  B(0, 1) = 1;
  B(1, 0) = 1;
  B(1, 1) = 1;
  ASSERT_EQ(true, A.EqMatrix(B));
}

TEST(EqMatrixTest, HanglesInitedUnEqualMatrices) {
  S21Matrix A(2, 2), B(2, 2);
  A(0, 0) = 1;
  A(0, 1) = 1;
  A(1, 0) = 1;
  A(1, 1) = 1;
  B(0, 0) = A(0, 0) - 1;
  B(0, 1) = 1;
  B(1, 0) = 1;
  B(1, 1) = 1;
  // B.matrix(0, 0) = A.matrix(0, 0) - 1;
  ASSERT_EQ(false, A.EqMatrix(B));
}

TEST(SumMatrixTest, HanglesInitedMatrices) {
  S21Matrix A(3, 3);
  A(0, 0) = 7, A(0, 1) = 8, A(0, 2) = 3;
  A(1, 0) = 5, A(1, 1) = 9, A(1, 2) = 1;
  A(2, 0) = 9, A(2, 1) = 4, A(2, 2) = 2;
  // TestS21Matrix B(4);
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 14, matrix(0, 1) = 16, matrix(0, 2) = 6;
  matrix(1, 0) = 10, matrix(1, 1) = 18, matrix(1, 2) = 2;
  matrix(2, 0) = 18, matrix(2, 1) = 8, matrix(2, 2) = 4;
  A.SumMatrix(A);
  ASSERT_EQ(true, A.EqMatrix(matrix));
}

TEST(SumMatrixTest2, HanglesInitedMatrices) {
  S21Matrix A(3, 3);
  A(0, 0) = 7, A(0, 1) = 8, A(0, 2) = 3;
  A(1, 0) = 5, A(1, 1) = 9, A(1, 2) = 1;
  A(2, 0) = 9, A(2, 1) = 4, A(2, 2) = 2;
  // TestS21Matrix B(4);
  S21Matrix matrix(3, 4);
  matrix(0, 0) = 14, matrix(0, 1) = 16, matrix(0, 2) = 6;
  matrix(1, 0) = 10, matrix(1, 1) = 18, matrix(1, 2) = 2;
  matrix(2, 0) = 18, matrix(2, 1) = 8, matrix(2, 2) = 4;

  ASSERT_ANY_THROW(A.SumMatrix(matrix););
}

TEST(SubMatrixTest2, HanglesInitedMatrices) {
  S21Matrix A(3, 3);
  A(0, 0) = 7, A(0, 1) = 8, A(0, 2) = 3;
  A(1, 0) = 5, A(1, 1) = 9, A(1, 2) = 1;
  A(2, 0) = 9, A(2, 1) = 4, A(2, 2) = 2;
  // TestS21Matrix B(4);
  S21Matrix matrix(3, 4);
  matrix(0, 0) = 14, matrix(0, 1) = 16, matrix(0, 2) = 6;
  matrix(1, 0) = 10, matrix(1, 1) = 18, matrix(1, 2) = 2;
  matrix(2, 0) = 18, matrix(2, 1) = 8, matrix(2, 2) = 4;

  ASSERT_ANY_THROW(A.SubMatrix(matrix););
}
TEST(SubMatrixTest, HanglesInitedMatrices) {
  S21Matrix A(3, 3);
  A(0, 0) = 7, A(0, 1) = 8, A(0, 2) = 3;
  A(1, 0) = 5, A(1, 1) = 9, A(1, 2) = 1;
  A(2, 0) = 9, A(2, 1) = 4, A(2, 2) = 2;
  // TestS21Matrix B(4);
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 0, matrix(0, 1) = 0, matrix(0, 2) = 0;
  matrix(1, 0) = 0, matrix(1, 1) = 0, matrix(1, 2) = 0;
  matrix(2, 0) = 0, matrix(2, 1) = 0, matrix(2, 2) = 0;
  A.SubMatrix(A);
  ASSERT_EQ(true, A.EqMatrix(matrix));
}

TEST(MulMatrixTest, HanglesInitedMatrices) {
  S21Matrix A(3, 3);
  A(0, 0) = 7, A(0, 1) = 8, A(0, 2) = 3;
  A(1, 0) = 5, A(1, 1) = 9, A(1, 2) = 1;
  A(2, 0) = 9, A(2, 1) = 4, A(2, 2) = 2;
  // TestS21Matrix B(4);
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 116, matrix(0, 1) = 140, matrix(0, 2) = 35;
  matrix(1, 0) = 89, matrix(1, 1) = 125, matrix(1, 2) = 26;
  matrix(2, 0) = 101, matrix(2, 1) = 116, matrix(2, 2) = 35;

  A.MulMatrix(A);
  ASSERT_EQ(true, A.EqMatrix(matrix));
}

TEST(MulNumberTest, HanglesInitedMatrices) {
  S21Matrix A(3, 3);
  A(0, 0) = 7, A(0, 1) = 8, A(0, 2) = 3;
  A(1, 0) = 5, A(1, 1) = 9, A(1, 2) = 1;
  A(2, 0) = 9, A(2, 1) = 4, A(2, 2) = 2;
  // TestS21Matrix B(4);
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 14, matrix(0, 1) = 16, matrix(0, 2) = 6;
  matrix(1, 0) = 10, matrix(1, 1) = 18, matrix(1, 2) = 2;
  matrix(2, 0) = 18, matrix(2, 1) = 8, matrix(2, 2) = 4;
  A.MulNumber(2);
  ASSERT_EQ(true, A.EqMatrix(matrix));
}

TEST(TransposeTest, HanglesInitedMatrices) {
  S21Matrix A(3, 4);
  A.operator()(0, 0) = 1;
  A.operator()(0, 1) = 2;
  A.operator()(0, 2) = 3;
  A.operator()(0, 3) = 4;
  A.operator()(1, 0) = 5;
  A.operator()(1, 1) = 6;
  A.operator()(1, 2) = 7;
  A.operator()(1, 3) = 8;
  A.operator()(2, 0) = 9;
  A.operator()(2, 1) = 10;
  A.operator()(2, 2) = 11;
  A.operator()(2, 3) = 12;
  S21Matrix B(3, 4);
  B = A.Transpose();
  EXPECT_EQ(4, B.GetRow());
  EXPECT_EQ(3, B.GetCol());
}

TEST(CalcComplementsTest, HanglesInitedMatrices) {
  S21Matrix A;
  A.SetCol(3);
  A.SetRow(3);
  A(0, 0) = 7, A(0, 1) = 8, A(0, 2) = 3;
  A(1, 0) = 5, A(1, 1) = 9, A(1, 2) = 1;
  A(2, 0) = 9, A(2, 1) = 4, A(2, 2) = 2;
  S21Matrix C;
  C.SetCol(3);
  C.SetRow(3);
  C(0, 0) = 14, C(0, 1) = -1, C(0, 2) = -61;
  C(1, 0) = -4, C(1, 1) = -13, C(1, 2) = 44;
  C(2, 0) = -19, C(2, 1) = 8, C(2, 2) = 23;

  S21Matrix B = A.CalcComplements();
  ASSERT_EQ(true, B.EqMatrix(C));
}

TEST(DeterminantTest, HanglesInitedMatrices3x3) {
  S21Matrix A;
  A.SetCol(3);
  A.SetRow(3);
  A(0, 0) = 116, A(0, 1) = 140, A(0, 2) = 35;
  A(1, 0) = 89, A(1, 1) = 125, A(1, 2) = 26;
  A(2, 0) = 101, A(2, 1) = 116, A(2, 2) = 35;
  double determinant = A.Determinant();
  ASSERT_DOUBLE_EQ(determinant, 8649.0);
}

TEST(DeterminantTest1, HanglesInitedMatrices3x3) {
  S21Matrix A;
  A.SetCol(3);
  A.SetRow(4);
  A(0, 0) = 116, A(0, 1) = 140, A(0, 2) = 35;
  A(1, 0) = 89, A(1, 1) = 125, A(1, 2) = 26;
  A(2, 0) = 101, A(2, 1) = 116, A(2, 2) = 35;
  // double determinant = A.Determinant();
  ASSERT_ANY_THROW(A.Determinant());
}

TEST(MoveConstructor, HanglesInitedMatrices) {
  S21Matrix A(1, 1);
  A(0, 0) = 7;
  S21Matrix B(A);
  ASSERT_EQ(true, B(0, 0) == 7);
}
TEST(MoveConstructors, HanglesInitedMatrices) {
  S21Matrix A(2, 1);
  A(0, 0) = 7;
  A(1, 0) = 0.3;
  S21Matrix B(A);
  ASSERT_EQ(true, B(0, 0) == 7);
  ASSERT_EQ(true, B(1, 0) == 0.3);
}

TEST(DeterminantTest, HanglesInitedMatrices4x4) {
  S21Matrix A(1, 1);
  A(0, 0) = 1;
  double determinant = A.Determinant();
  ASSERT_DOUBLE_EQ(determinant, 1);
  S21Matrix B(3, 3);
  B(0, 0) = 4, B(0, 1) = 15, B(0, 2) = 1;
  B(1, 0) = 2, B(1, 1) = 3, B(1, 2) = 4;
  B(2, 0) = 5, B(2, 1) = 4, B(2, 2) = 3;
  determinant = B.Determinant();

  ASSERT_DOUBLE_EQ(determinant, 175);
}

TEST(InverseMatrixTest, HanglesInitedMatrices3x3) {
  S21Matrix A;
  A.SetCol(3);
  A.SetRow(3);
  A(0, 0) = 7, A(0, 1) = 8, A(0, 2) = 3;
  A(1, 0) = 5, A(1, 1) = 9, A(1, 2) = 1;
  A(2, 0) = 9, A(2, 1) = 4, A(2, 2) = 2;
  S21Matrix i_matrix;
  i_matrix.SetCol(3);
  i_matrix.SetRow(3);
  i_matrix(0, 0) = -0.150538, i_matrix(0, 1) = 0.0430108;
  i_matrix(0, 2) = 0.204301, i_matrix(1, 0) = 0.0107527;
  i_matrix(1, 1) = 0.139785, i_matrix(1, 2) = -0.0860215;
  i_matrix(2, 0) = 0.655914, i_matrix(2, 1) = -0.473118;
  i_matrix(2, 2) = -0.247312;
  S21Matrix C = A.InverseMatrix();
  ASSERT_EQ(false, C.EqMatrix(i_matrix));
}

TEST(InverseMatrixTest1, HanglesInitedMatrices3x3) {
  S21Matrix A;
  A.SetCol(1);
  A.SetRow(1);
  A(0, 0) = 0;
  ASSERT_ANY_THROW(A.InverseMatrix());
}

TEST(OperatorEqual, HanglesInitedMatrices) {
  S21Matrix A(3, 3), B(3, 3);
  A(0, 0) = 7, A(0, 1) = 8, A(0, 2) = 3;
  A(1, 0) = 5, A(1, 1) = 9, A(1, 2) = 1;
  A(2, 0) = 9, A(2, 1) = 4, A(2, 2) = 2;

  B(0, 0) = 7, B(0, 1) = 8, B(0, 2) = 3;
  B(1, 0) = 5, B(1, 1) = 9, B(1, 2) = 1;
  B(2, 0) = 9, B(2, 1) = 4, B(2, 2) = 2;
  bool status = false;
  if (A == B) {
    status = true;
  }
  ASSERT_EQ(true, status);
}

TEST(OpetatorCopy, HanglesInitedMatrices) {
  S21Matrix A(3, 3), B(2, 1);
  A(0, 0) = 7, A(0, 1) = 8, A(0, 2) = 3;
  A(1, 0) = 5, A(1, 1) = 9, A(1, 2) = 1;
  A(2, 0) = 9, A(2, 1) = 4, A(2, 2) = 2;

  B(0, 0) = 1, B(1, 0) = 12;
  B = A;
  ASSERT_EQ(true, B.EqMatrix(A));
}

TEST(OpetatorSum, HanglesInitedMatrices) {
  S21Matrix A(3, 3), B(3, 3);
  A(0, 0) = 7, A(0, 1) = 8, A(0, 2) = 3;
  A(1, 0) = 5, A(1, 1) = 9, A(1, 2) = 1;
  A(2, 0) = 9, A(2, 1) = 4, A(2, 2) = 2;

  B(0, 0) = 7, B(0, 1) = 8, B(0, 2) = 3;
  B(1, 0) = 5, B(1, 1) = 9, B(1, 2) = 1;
  B(2, 0) = 9, B(2, 1) = 4, B(2, 2) = 2;
  A += B;
  B *= 2;
  ASSERT_EQ(true, B.EqMatrix(A));
}

TEST(OpetatorSub, HanglesInitedMatrices) {
  S21Matrix A(3, 3), B(3, 3);
  A(0, 0) = 7, A(0, 1) = 8, A(0, 2) = 3;
  A(1, 0) = 5, A(1, 1) = 9, A(1, 2) = 1;
  A(2, 0) = 9, A(2, 1) = 4, A(2, 2) = 2;

  B(0, 0) = 0, B(0, 1) = 0, B(0, 2) = 0;
  B(1, 0) = 0, B(1, 1) = 0, B(1, 2) = 0;
  B(2, 0) = 0, B(2, 1) = 0, B(2, 2) = 0;
  A -= A;
  ASSERT_EQ(true, B.EqMatrix(A));
}

TEST(OpetatorPlus, HanglesInitedMatrices) {
  S21Matrix A(3, 3), B(3, 3);
  A(0, 0) = 7, A(0, 1) = 8, A(0, 2) = 3;
  A(1, 0) = 5, A(1, 1) = 9, A(1, 2) = 1;
  A(2, 0) = 9, A(2, 1) = 4, A(2, 2) = 2;

  B(0, 0) = 7, B(0, 1) = 8, B(0, 2) = 3;
  B(1, 0) = 5, B(1, 1) = 9, B(1, 2) = 1;
  B(2, 0) = 9, B(2, 1) = 4, B(2, 2) = 2;
  A = A + A;
  B *= 2;
  ASSERT_EQ(true, B.EqMatrix(A));
}

TEST(OpetatorMinus, HanglesInitedMatrices) {
  S21Matrix A(3, 3), B(3, 3);
  A(0, 0) = 7, A(0, 1) = 8, A(0, 2) = 3;
  A(1, 0) = 5, A(1, 1) = 9, A(1, 2) = 1;
  A(2, 0) = 9, A(2, 1) = 4, A(2, 2) = 2;

  B(0, 0) = 14, B(0, 1) = 16, B(0, 2) = 6;
  B(1, 0) = 10, B(1, 1) = 18, B(1, 2) = 2;
  B(2, 0) = 18, B(2, 1) = 8, B(2, 2) = 4;
  B = B - A;
  ASSERT_EQ(true, B.EqMatrix(A));
}
TEST(OpetatorMulMatrices, HanglesInitedMatrices) {
  S21Matrix A(3, 3), B(3, 3);
  A(0, 0) = 7, A(0, 1) = 8, A(0, 2) = 3;
  A(1, 0) = 5, A(1, 1) = 9, A(1, 2) = 1;
  A(2, 0) = 9, A(2, 1) = 4, A(2, 2) = 2;

  B(0, 0) = 116, B(0, 1) = 140, B(0, 2) = 35;
  B(1, 0) = 89, B(1, 1) = 125, B(1, 2) = 26;
  B(2, 0) = 101, B(2, 1) = 116, B(2, 2) = 35;
  A *= A;
  ASSERT_EQ(true, A.EqMatrix(B));
}

TEST(OpetatorStar, HanglesInitedMatrices) {
  S21Matrix A(3, 3), B(3, 3);
  A(0, 0) = 7, A(0, 1) = 8, A(0, 2) = 3;
  A(1, 0) = 5, A(1, 1) = 9, A(1, 2) = 1;
  A(2, 0) = 9, A(2, 1) = 4, A(2, 2) = 2;

  B(0, 0) = 116, B(0, 1) = 140, B(0, 2) = 35;
  B(1, 0) = 89, B(1, 1) = 125, B(1, 2) = 26;
  B(2, 0) = 101, B(2, 1) = 116, B(2, 2) = 35;
  A = A * A;
  ASSERT_EQ(true, A.EqMatrix(B));
}

TEST(OperatorStar2, HanglesInitedMatrices) {
  S21Matrix A(3, 3), B(3, 3);
  A(0, 0) = 7, A(0, 1) = 8, A(0, 2) = 3;
  A(1, 0) = 5, A(1, 1) = 9, A(1, 2) = 1;
  A(2, 0) = 9, A(2, 1) = 4, A(2, 2) = 2;
  B(0, 0) = 14, B(0, 1) = 16, B(0, 2) = 6;
  B(1, 0) = 10, B(1, 1) = 18, B(1, 2) = 2;
  B(2, 0) = 18, B(2, 1) = 8, B(2, 2) = 4;
  A = A * 2;
  ASSERT_EQ(true, A.EqMatrix(B));
}

TEST(OpetatorMulNum, HanglesInitedMatrices) {
  S21Matrix A(3, 3), B(3, 3);
  A(0, 0) = 7, A(0, 1) = 8, A(0, 2) = 3;
  A(1, 0) = 5, A(1, 1) = 9, A(1, 2) = 1;
  A(2, 0) = 9, A(2, 1) = 4, A(2, 2) = 2;
  B(0, 0) = 14, B(0, 1) = 16, B(0, 2) = 6;
  B(1, 0) = 10, B(1, 1) = 18, B(1, 2) = 2;
  B(2, 0) = 18, B(2, 1) = 8, B(2, 2) = 4;
  A *= 2;
  ASSERT_EQ(true, A.EqMatrix(B));
}

TEST(SetColRow, HanglesInitedMatrices) {
  S21Matrix A(3, 3), B(3, 3);
  A(0, 0) = 7, A(0, 1) = 8, A(0, 2) = 3;
  A(1, 0) = 5, A(1, 1) = 9, A(1, 2) = 1;
  A(2, 0) = 9, A(2, 1) = 4, A(2, 2) = 2;
  B.SetCol(2);
  B.SetRow(2);
  B(0, 0) = 7, B(0, 1) = 8;
  B(1, 0) = 5, B(1, 1) = 9;
  A.SetCol(2);
  A.SetRow(2);
  ASSERT_EQ(true, A == B);
}

TEST(SetColRow1, HanglesInitedMatrices) {
  S21Matrix A(1, 1), B(2, 2), C(2, 2);
  A(0, 0) = 7;
  B(0, 0) = 7, B(0, 1) = 8;
  B(1, 0) = 5, B(1, 1) = 9;
  A = std::move(B);
  C(0, 0) = 7, C(0, 1) = 8;
  C(1, 0) = 5, C(1, 1) = 9;
  ASSERT_EQ(true, A == C);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
