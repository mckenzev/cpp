#include <gtest/gtest.h>

#include <iostream>

#include "s21_matrix_oop.h"

TEST(Constructors, SizeIndex) {
  S21Matrix matrix(3, 4);

  EXPECT_EQ(matrix.GetRows(), 3);
  EXPECT_EQ(matrix.GetCols(), 4);
}

TEST(Constructors, SizeFail1) { EXPECT_ANY_THROW(S21Matrix matrix(0, 1)); }

TEST(Constructors, SizeFail2) { EXPECT_ANY_THROW(S21Matrix matrix(1, 0)); }

TEST(Constructors, Default) {
  S21Matrix matrix;

  EXPECT_GE(matrix.GetRows(), 0);
  EXPECT_GE(matrix.GetCols(), 0);
}

TEST(Constructors, Copy) {
  S21Matrix matrix_1(2, 1);
  S21Matrix matrix_2(matrix_1);

  EXPECT_EQ(matrix_2.GetRows(), 2);
  EXPECT_EQ(matrix_2.GetCols(), 1);
  EXPECT_EQ(matrix_2.EqMatrix(matrix_1), true);
}

TEST(Constructors, Move) {
  S21Matrix matrix_1(2, 1);
  S21Matrix matrix_2(std::move(matrix_1));

  EXPECT_EQ(matrix_2.GetRows(), 2);
  EXPECT_EQ(matrix_2.GetCols(), 1);
  EXPECT_EQ(matrix_1.GetRows(), 0);
  EXPECT_EQ(matrix_1.GetCols(), 0);
}

TEST(Indexing, Success) {
  S21Matrix matrix_1(2, 2);

  EXPECT_NO_THROW(matrix_1(1, 1));
  EXPECT_NO_THROW(matrix_1(1, 1) = 23.0);
  EXPECT_DOUBLE_EQ(matrix_1(1, 1), 23.0);
}

TEST(Indexing, OutOfMatrix) {
  S21Matrix matrix_1(2, 2);

  ASSERT_ANY_THROW(matrix_1(3, 3));
}

TEST(EqMatrix, Success) {
  S21Matrix matrix_1(3, 2);
  S21Matrix matrix_2(3, 2);

  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;
  matrix_1(2, 0) = 5.0;
  matrix_1(2, 1) = 6.0;

  matrix_2(0, 0) = 1.0;
  matrix_2(0, 1) = 2.0;
  matrix_2(1, 0) = 3.0;
  matrix_2(1, 1) = 4.0;
  matrix_2(2, 0) = 5.0;
  matrix_2(2, 1) = 6.0;

  EXPECT_EQ(matrix_1.EqMatrix(matrix_2), true);
}

TEST(EqMatrix, NoOne) {
  S21Matrix matrix_1(3, 2);
  S21Matrix matrix_2(3, 2);

  matrix_2(0, 0) = 21;

  EXPECT_EQ(matrix_1.EqMatrix(matrix_2), false);
}

TEST(EqMatrix, SizeFail) {
  S21Matrix matrix_1(2, 1);
  matrix_1(0, 0) = 1.0;
  matrix_1(1, 0) = 2.0;
  S21Matrix matrix_2(1, 2);
  matrix_2(0, 0) = 1.0;
  matrix_2(0, 1) = 2.0;

  EXPECT_EQ(matrix_1.EqMatrix(matrix_2), false);
}

TEST(EqMatrix, OperatorSuccess) {
  S21Matrix matrix_1(3, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;
  S21Matrix matrix_2(3, 2);
  matrix_2(0, 0) = 1.0;
  matrix_2(0, 1) = 2.0;
  matrix_2(1, 0) = 3.0;
  matrix_2(1, 1) = 4.0;

  EXPECT_EQ(matrix_1 == matrix_2, true);
}

TEST(EqMatrix, OperatorFail) {
  S21Matrix matrix_1(2, 1);
  S21Matrix matrix_2(1, 1);

  EXPECT_EQ(matrix_1 == matrix_2, false);
}

TEST(EqMatrix, OperatorMove) {
  S21Matrix matrix_1(2, 1);
  S21Matrix matrix_2 = std::move(matrix_1);

  EXPECT_EQ(matrix_2.GetRows(), 2);
  EXPECT_EQ(matrix_2.GetCols(), 1);
  EXPECT_EQ(matrix_1.GetRows(), 0);
  EXPECT_EQ(matrix_1.GetCols(), 0);
}

TEST(SumMatrix, Sum) {
  S21Matrix matrix_1(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;
  S21Matrix matrix_2(2, 2);
  matrix_2(0, 0) = 1.0;
  matrix_2(0, 1) = 2.0;
  matrix_2(1, 0) = 3.0;
  matrix_2(1, 1) = 4.0;

  matrix_1.SumMatrix(matrix_2);

  EXPECT_DOUBLE_EQ(matrix_1(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(matrix_1(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(matrix_1(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(matrix_1(1, 1), 8.0);
}

TEST(SumMatrix, SumSizeFail) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(1, 1);

  EXPECT_ANY_THROW(matrix_1.SumMatrix(matrix_2));
}

TEST(SumMatrix, OrderTwo) {
  S21Matrix matrix_1(2, 2);
  matrix_1(0, 0) = 2.0;
  matrix_1(0, 1) = 0.0;
  matrix_1(1, 0) = 2.0;
  matrix_1(1, 1) = 3.0;
  S21Matrix matrix_2(2, 2);
  matrix_2(0, 0) = 3.0;
  matrix_2(0, 1) = 2.0;
  matrix_2(1, 0) = 0.0;
  matrix_2(1, 1) = 2.0;
  S21Matrix result;

  result = matrix_1 + matrix_2;

  EXPECT_DOUBLE_EQ(result(0, 0), 5.0);
  EXPECT_DOUBLE_EQ(result(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(result(1, 0), 2.0);
  EXPECT_DOUBLE_EQ(result(1, 1), 5.0);
}

TEST(SumMatrix, SumSelf) {
  S21Matrix matrix_1(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 8.0;
  matrix_1(1, 0) = 2.0;
  matrix_1(1, 1) = 6.0;
  S21Matrix matrix_2(2, 2);
  matrix_2(0, 0) = 1.0;
  matrix_2(0, 1) = 8.0;
  matrix_2(1, 0) = 2.0;
  matrix_2(1, 1) = 6.0;

  matrix_1 += matrix_2;

  EXPECT_DOUBLE_EQ(matrix_1(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(matrix_1(0, 1), 16.0);
  EXPECT_DOUBLE_EQ(matrix_1(1, 0), 4.0);
  EXPECT_DOUBLE_EQ(matrix_1(1, 1), 12.0);
}

TEST(SubMatrix, Sub) {
  S21Matrix matrix_1(2, 2);
  matrix_1(0, 0) = 4.0;
  matrix_1(0, 1) = 3.0;
  matrix_1(1, 0) = 2.0;
  matrix_1(1, 1) = 1.0;
  S21Matrix matrix_2(2, 2);
  matrix_2(0, 0) = 1.0;
  matrix_2(0, 1) = 2.0;
  matrix_2(1, 0) = 3.0;
  matrix_2(1, 1) = 4.0;

  matrix_1.SubMatrix(matrix_2);

  EXPECT_DOUBLE_EQ(matrix_1(0, 0), 3.0);
  EXPECT_DOUBLE_EQ(matrix_1(0, 1), 1.0);
  EXPECT_DOUBLE_EQ(matrix_1(1, 0), -1.0);
  EXPECT_DOUBLE_EQ(matrix_1(1, 1), -3.0);
}

TEST(SubMatrix, SizeFail) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(1, 1);

  EXPECT_ANY_THROW(matrix_1.SubMatrix(matrix_2));
}

TEST(SubMatrix, OrderTwo) {
  S21Matrix matrix_1(2, 2);
  matrix_1(0, 0) = 4.0;
  matrix_1(0, 1) = 3.0;
  matrix_1(1, 0) = 2.0;
  matrix_1(1, 1) = 1.0;
  S21Matrix matrix_2(2, 2);
  matrix_2(0, 0) = 1.0;
  matrix_2(0, 1) = 2.0;
  matrix_2(1, 0) = 3.0;
  matrix_2(1, 1) = 4.0;
  S21Matrix result;

  result = matrix_1 - matrix_2;

  EXPECT_DOUBLE_EQ(result(0, 0), 3.0);
  EXPECT_DOUBLE_EQ(result(0, 1), 1.0);
  EXPECT_DOUBLE_EQ(result(1, 0), -1.0);
  EXPECT_DOUBLE_EQ(result(1, 1), -3.0);
}

TEST(SubMatrix, SubSelf) {
  S21Matrix matrix_1(2, 2);
  matrix_1(0, 0) = -1.0;
  matrix_1(0, 1) = -1.0;
  matrix_1(1, 0) = -1.0;
  matrix_1(1, 1) = -1.0;
  S21Matrix matrix_2(2, 2);
  matrix_2(0, 0) = 1.0;
  matrix_2(0, 1) = 2.0;
  matrix_2(1, 0) = 3.0;
  matrix_2(1, 1) = 4.0;

  matrix_1 -= matrix_2;

  EXPECT_DOUBLE_EQ(matrix_1(0, 0), -2.0);
  EXPECT_DOUBLE_EQ(matrix_1(0, 1), -3.0);
  EXPECT_DOUBLE_EQ(matrix_1(1, 0), -4.0);
  EXPECT_DOUBLE_EQ(matrix_1(1, 1), -5.0);
}

TEST(MultNumber, MultNumber) {
  S21Matrix matrix_1(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;

  matrix_1.MulNumber(2.0);

  EXPECT_DOUBLE_EQ(matrix_1(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(matrix_1(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(matrix_1(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(matrix_1(1, 1), 8.0);
}

TEST(MultNumber, PreNumber) {
  S21Matrix matrix_1(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;

  S21Matrix matrix_result;
  matrix_result = 6 * matrix_1;

  EXPECT_DOUBLE_EQ(matrix_result(0, 0), 6.0);
  EXPECT_DOUBLE_EQ(matrix_result(0, 1), 12.0);
  EXPECT_DOUBLE_EQ(matrix_result(1, 0), 18.0);
  EXPECT_DOUBLE_EQ(matrix_result(1, 1), 24.0);
}

TEST(MultNumber, PostNumber) {
  S21Matrix matrix_1(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;

  S21Matrix matrix_result;
  matrix_result = matrix_1 * 6;

  EXPECT_DOUBLE_EQ(matrix_result(0, 0), 6.0);
  EXPECT_DOUBLE_EQ(matrix_result(0, 1), 12.0);
  EXPECT_DOUBLE_EQ(matrix_result(1, 0), 18.0);
  EXPECT_DOUBLE_EQ(matrix_result(1, 1), 24.0);
}

TEST(MultNumber, MultiplicationSelf) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 7.0;
  matrix(0, 1) = 44.0;
  matrix(1, 0) = 2.0;
  matrix(1, 1) = 10.0;

  matrix *= 2.0;

  EXPECT_DOUBLE_EQ(matrix(0, 0), 14.0);
  EXPECT_DOUBLE_EQ(matrix(0, 1), 88.0);
  EXPECT_DOUBLE_EQ(matrix(1, 0), 4.0);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 20.0);
}

TEST(MultMatrix, MultiplicationTwoMatrix) {
  S21Matrix matrix_1(1, 2);
  matrix_1(0, 0) = 4;
  matrix_1(0, 1) = 8;
  S21Matrix matrix_2(2, 1);
  matrix_2(0, 0) = 15;
  matrix_2(1, 0) = 16;
  S21Matrix result;

  result = matrix_1 * matrix_2;

  EXPECT_DOUBLE_EQ(result(0, 0), 188.0);
}

TEST(MultMatrix, MultiplicationSelf) {
  S21Matrix matrix_1(1, 2);
  matrix_1(0, 0) = 5.0;
  matrix_1(0, 1) = 5.0;
  S21Matrix matrix_2(2, 1);
  matrix_2(0, 0) = 12.0;
  matrix_2(1, 0) = 14.0;

  matrix_1 *= matrix_2;

  EXPECT_DOUBLE_EQ(matrix_1(0, 0), 130.0);
}

TEST(MultMatrix, OrderResultThree) {
  S21Matrix matrix_1(3, 1);
  matrix_1(0, 0) = 23.0;
  matrix_1(1, 0) = 34.0;
  matrix_1(2, 0) = 45.0;
  S21Matrix matrix_2(1, 3);
  matrix_2(0, 0) = 56.0;
  matrix_2(0, 1) = 67.0;
  matrix_2(0, 2) = 78.0;

  matrix_1.MulMatrix(matrix_2);

  EXPECT_DOUBLE_EQ(matrix_1(0, 0), 1288.0);
  EXPECT_DOUBLE_EQ(matrix_1(0, 1), 1541.0);
  EXPECT_DOUBLE_EQ(matrix_1(0, 2), 1794.0);
  EXPECT_DOUBLE_EQ(matrix_1(1, 0), 1904.0);
  EXPECT_DOUBLE_EQ(matrix_1(1, 1), 2278.0);
  EXPECT_DOUBLE_EQ(matrix_1(1, 2), 2652.0);
  EXPECT_DOUBLE_EQ(matrix_1(2, 0), 2520.0);
  EXPECT_DOUBLE_EQ(matrix_1(2, 1), 3015.0);
  EXPECT_DOUBLE_EQ(matrix_1(2, 2), 3510.0);
}

TEST(MultMatrix, SidesMismatch) {
  S21Matrix matrix_1(2, 1);
  matrix_1(0, 0) = 6;
  matrix_1(1, 0) = 6;
  S21Matrix matrix_2(2, 1);
  matrix_2(0, 0) = 6;

  EXPECT_ANY_THROW(matrix_1.MulMatrix(matrix_2));
}

TEST(Transpose, NoSquareSuccess) {
  S21Matrix matrix(2, 3);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(0, 2) = 3.0;
  matrix(1, 0) = 4.0;
  matrix(1, 1) = 5.0;
  matrix(1, 2) = 6.0;
  S21Matrix result = matrix.Transpose();

  EXPECT_EQ(result.GetRows(), 3);
  EXPECT_EQ(result.GetCols(), 2);
  EXPECT_DOUBLE_EQ(result(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(result(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(result(1, 0), 2.0);
  EXPECT_DOUBLE_EQ(result(1, 1), 5.0);
  EXPECT_DOUBLE_EQ(result(2, 0), 3.0);
  EXPECT_DOUBLE_EQ(result(2, 1), 6.0);
}

TEST(Determinant, OrderFour) {
  S21Matrix matrix(4, 4);
  matrix(0, 0) = -4.0;
  matrix(0, 1) = -2.0;
  matrix(0, 2) = -7.0;
  matrix(0, 3) = 8.0;
  matrix(1, 0) = 2.0;
  matrix(1, 1) = 7.0;
  matrix(1, 2) = 4.0;
  matrix(1, 3) = 9.0;
  matrix(2, 0) = 2.0;
  matrix(2, 1) = 0.0;
  matrix(2, 2) = 6.0;
  matrix(2, 3) = -3.0;
  matrix(3, 0) = 6.0;
  matrix(3, 1) = 4.0;
  matrix(3, 2) = -10.0;
  matrix(3, 3) = -4.0;
  double result = 0.0;

  result = matrix.Determinant();

  EXPECT_DOUBLE_EQ(result, -1926);
}

TEST(Determinant, OrderThree) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 7.0;
  matrix(0, 1) = 4.0;
  matrix(0, 2) = 9.0;
  matrix(1, 0) = 0.0;
  matrix(1, 1) = 6.0;
  matrix(1, 2) = -3.0;
  matrix(2, 0) = 4.0;
  matrix(2, 1) = -10.0;
  matrix(2, 2) = -4.0;
  double result = 0.0;

  result = matrix.Determinant();

  EXPECT_DOUBLE_EQ(result, -642);
}

TEST(Determinant, OrderTwo) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = -6.0;
  matrix(0, 1) = -3.0;
  matrix(1, 0) = -10.0;
  matrix(1, 1) = -4.0;
  double result = 0.0;

  result = matrix.Determinant();

  EXPECT_DOUBLE_EQ(result, -6.0);
}

TEST(Determinant, OrderOne) {
  S21Matrix matrix(1, 1);
  matrix(0, 0) = 15.9;
  double result = 0.0;

  result = matrix.Determinant();

  EXPECT_DOUBLE_EQ(result, 15.9);
}

TEST(Determinant, NoSquareFail) {
  S21Matrix matrix(1, 2);
  EXPECT_ANY_THROW(matrix.Determinant());
}

TEST(CalcComplements, OrderFour) {
  S21Matrix matrix(4, 4);
  matrix(0, 0) = 2.0;
  matrix(0, 1) = 1.0;
  matrix(0, 2) = 0.0;
  matrix(0, 3) = 0.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 2.0;
  matrix(1, 2) = 0.0;
  matrix(1, 3) = 0.0;
  matrix(2, 0) = 1.0;
  matrix(2, 1) = 1.0;
  matrix(2, 2) = 3.0;
  matrix(2, 3) = 4.0;
  matrix(3, 0) = 2.0;
  matrix(3, 1) = -1.0;
  matrix(3, 2) = 2.0;
  matrix(3, 3) = 3.0;

  S21Matrix result = matrix.CalcComplements();

  EXPECT_DOUBLE_EQ(result(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(result(0, 1), -3.0);
  EXPECT_DOUBLE_EQ(result(0, 2), 31.0);
  EXPECT_DOUBLE_EQ(result(0, 3), -23.0);
  EXPECT_DOUBLE_EQ(result(1, 0), -1.0);
  EXPECT_DOUBLE_EQ(result(1, 1), 2.0);
  EXPECT_DOUBLE_EQ(result(1, 2), -19.0);
  EXPECT_DOUBLE_EQ(result(1, 3), 14.0);
  EXPECT_DOUBLE_EQ(result(2, 0), 0.0);
  EXPECT_DOUBLE_EQ(result(2, 1), 0.0);
  EXPECT_DOUBLE_EQ(result(2, 2), 3.0);
  EXPECT_DOUBLE_EQ(result(2, 3), -2.0);
  EXPECT_DOUBLE_EQ(result(3, 0), 0.0);
  EXPECT_DOUBLE_EQ(result(3, 1), 0.0);
  EXPECT_DOUBLE_EQ(result(3, 2), -4.0);
  EXPECT_DOUBLE_EQ(result(3, 3), 3.0);
}

TEST(CalcComplements, OrderThree) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 2.0;
  matrix(0, 1) = 5.0;
  matrix(0, 2) = 7.0;
  matrix(1, 0) = 6.0;
  matrix(1, 1) = 3.0;
  matrix(1, 2) = 4.0;
  matrix(2, 0) = 5.0;
  matrix(2, 1) = -2.0;
  matrix(2, 2) = -3.0;

  S21Matrix result = matrix.CalcComplements();

  EXPECT_DOUBLE_EQ(result(0, 0), -1.0);
  EXPECT_DOUBLE_EQ(result(0, 1), 38.0);
  EXPECT_DOUBLE_EQ(result(0, 2), -27.0);
  EXPECT_DOUBLE_EQ(result(1, 0), 1.0);
  EXPECT_DOUBLE_EQ(result(1, 1), -41.0);
  EXPECT_DOUBLE_EQ(result(1, 2), 29.0);
  EXPECT_DOUBLE_EQ(result(2, 0), -1.0);
  EXPECT_DOUBLE_EQ(result(2, 1), 34.0);
  EXPECT_DOUBLE_EQ(result(2, 2), -24.0);
}

TEST(CalcComplements, OrderTwo) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 3.0;
  matrix(0, 1) = 4.0;
  matrix(1, 0) = 5.0;
  matrix(1, 1) = 7.0;

  S21Matrix result = matrix.CalcComplements();

  EXPECT_DOUBLE_EQ(result(0, 0), 7.0);
  EXPECT_DOUBLE_EQ(result(0, 1), -5.0);
  EXPECT_DOUBLE_EQ(result(1, 0), -4.0);
  EXPECT_DOUBLE_EQ(result(1, 1), 3.0);
}

TEST(CalcComplements, NoSquareFail) {
  S21Matrix matrix(2, 1);

  EXPECT_ANY_THROW(matrix.CalcComplements());
}

TEST(CalcComplements, OrderOneFail) {
  S21Matrix matrix(1, 1);

  EXPECT_ANY_THROW(matrix.CalcComplements());
}

TEST(InverseMatrix, OrderFour) {
  S21Matrix matrix(4, 4);
  matrix(0, 0) = 2.0;
  matrix(0, 1) = 1.0;
  matrix(0, 2) = 0.0;
  matrix(0, 3) = 0.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 2.0;
  matrix(1, 2) = 0.0;
  matrix(1, 3) = 0.0;
  matrix(2, 0) = 1.0;
  matrix(2, 1) = 1.0;
  matrix(2, 2) = 3.0;
  matrix(2, 3) = 4.0;
  matrix(3, 0) = 2.0;
  matrix(3, 1) = -1.0;
  matrix(3, 2) = 2.0;
  matrix(3, 3) = 3.0;

  S21Matrix result = matrix.InverseMatrix();

  EXPECT_DOUBLE_EQ(result(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(result(0, 1), -1.0);
  EXPECT_DOUBLE_EQ(result(0, 2), 0.0);
  EXPECT_DOUBLE_EQ(result(0, 3), 0.0);
  EXPECT_DOUBLE_EQ(result(1, 0), -3.0);
  EXPECT_DOUBLE_EQ(result(1, 1), 2.0);
  EXPECT_DOUBLE_EQ(result(1, 2), 0.0);
  EXPECT_DOUBLE_EQ(result(1, 3), 0.0);
  EXPECT_DOUBLE_EQ(result(2, 0), 31.0);
  EXPECT_DOUBLE_EQ(result(2, 1), -19.0);
  EXPECT_DOUBLE_EQ(result(2, 2), 3.0);
  EXPECT_DOUBLE_EQ(result(2, 3), -4.0);
  EXPECT_DOUBLE_EQ(result(3, 0), -23.0);
  EXPECT_DOUBLE_EQ(result(3, 1), 14.0);
  EXPECT_DOUBLE_EQ(result(3, 2), -2.0);
  EXPECT_DOUBLE_EQ(result(3, 3), 3.0);
}

TEST(InverseMatrix, OrderThree) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 2.0;
  matrix(0, 1) = 5.0;
  matrix(0, 2) = 7.0;
  matrix(1, 0) = 6.0;
  matrix(1, 1) = 3.0;
  matrix(1, 2) = 4.0;
  matrix(2, 0) = 5.0;
  matrix(2, 1) = -2.0;
  matrix(2, 2) = -3.0;

  S21Matrix result = matrix.InverseMatrix();

  EXPECT_DOUBLE_EQ(result(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(result(0, 1), -1.0);
  EXPECT_DOUBLE_EQ(result(0, 2), 1.0);
  EXPECT_DOUBLE_EQ(result(1, 0), -38.0);
  EXPECT_DOUBLE_EQ(result(1, 1), 41.0);
  EXPECT_DOUBLE_EQ(result(1, 2), -34.0);
  EXPECT_DOUBLE_EQ(result(2, 0), 27.0);
  EXPECT_DOUBLE_EQ(result(2, 1), -29.0);
  EXPECT_DOUBLE_EQ(result(2, 2), 24.0);
}

TEST(InverseMatrix, OrderTwo) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 3.0;
  matrix(0, 1) = 4.0;
  matrix(1, 0) = 5.0;
  matrix(1, 1) = 7.0;

  S21Matrix result = matrix.InverseMatrix();

  EXPECT_DOUBLE_EQ(result(0, 0), 7.0);
  EXPECT_DOUBLE_EQ(result(0, 1), -4.0);
  EXPECT_DOUBLE_EQ(result(1, 0), -5.0);
  EXPECT_DOUBLE_EQ(result(1, 1), 3.0);
}

TEST(InverseMatrix, OrderOne) {
  S21Matrix matrix(1, 1);
  matrix(0, 0) = 5.0;

  S21Matrix result = matrix.InverseMatrix();

  EXPECT_DOUBLE_EQ(result(0, 0), 0.2);
}

TEST(InverseMatrix, DetZero) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 0.0;
  matrix(0, 1) = 1.0;
  matrix(0, 2) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;
  matrix(1, 2) = 5.0;
  matrix(2, 0) = 6.0;
  matrix(2, 1) = 7.0;
  matrix(2, 2) = 8.0;

  EXPECT_ANY_THROW(matrix.InverseMatrix());
}

TEST(AccessorMutator, GetRowsGetCols) {
  S21Matrix matrix(3, 2);

  EXPECT_EQ(matrix.GetRows(), 3);
  EXPECT_EQ(matrix.GetCols(), 2);
}

TEST(AccessorMutator, SetRow1) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  matrix.SetRows(1);

  EXPECT_EQ(matrix.GetRows(), 1);
  EXPECT_EQ(matrix.GetCols(), 2);
}

TEST(AccessorMutator, SetRow2) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  matrix.SetRows(3);

  EXPECT_EQ(matrix.GetRows(), 3);
  EXPECT_EQ(matrix.GetCols(), 2);
  EXPECT_DOUBLE_EQ(matrix(2, 0), 0.0);
  EXPECT_DOUBLE_EQ(matrix(2, 1), 0.0);
}

TEST(AccessorMutator, SetRow3) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  EXPECT_ANY_THROW(matrix.SetRows(-3));
}

TEST(AccessorMutator, SetCol1) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  matrix.SetCols(1);

  EXPECT_EQ(matrix.GetRows(), 2);
  EXPECT_EQ(matrix.GetCols(), 1);
}

TEST(AccessorMutator, SetCol2) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  matrix.SetCols(3);

  EXPECT_EQ(matrix.GetRows(), 2);
  EXPECT_EQ(matrix.GetCols(), 3);
  EXPECT_DOUBLE_EQ(matrix(0, 2), 0.0);
  EXPECT_DOUBLE_EQ(matrix(1, 2), 0.0);
}

TEST(AccessorMutator, SetCol3) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  EXPECT_ANY_THROW(matrix.SetCols(-1));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
