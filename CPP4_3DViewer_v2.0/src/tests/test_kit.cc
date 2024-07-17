#include <iostream>

#include "test_core.h"

bool isEqual(std::vector<double>& S1, std::vector<double>& S2) {
  auto it_S1 = S1.begin();
  auto it_S2 = S2.begin();
  for (; it_S2 != S2.end(); ++it_S1, ++it_S2) {
    if (*it_S1 != *it_S2) return false;
  }
  return true;
}

TEST(Parse, Vertices) {
  std::vector<double> vertices, coordinates, result = {0.0, 0.25};
  std::string filename = "tests/test.obj";
  s21::Controller c(coordinates, vertices, filename);
  c.Parse();
  ASSERT_EQ(isEqual(vertices, result), true);
}

TEST(Parse, Coordinates) {
  std::vector<double> vertices, coordinates, result = {0.0, 0.25};
  std::string filename = "tests/test.obj";
  s21::Controller c(coordinates, vertices, filename);
  c.Parse();
  ASSERT_EQ(isEqual(coordinates, result), true);
}

TEST(Move, X) {
  std::vector<double> vertices, coordinates, result = {0.0, 0.25};
  std::string filename = "tests/test.obj";
  s21::Controller c(coordinates, vertices, filename);
  c.Parse();
  c.Move(0.1, s21::X);
  ASSERT_EQ(isEqual(coordinates, result), true);
}

TEST(Rotate, X) {
  std::vector<double> vertices, coordinates, result = {0.0, 0.25};
  std::string filename = "tests/test.obj";
  s21::Controller c(coordinates, vertices, filename);
  c.Parse();
  c.Rotate(0.1, s21::X);
  ASSERT_EQ(isEqual(coordinates, result), true);
}

TEST(Rotate, Y) {
  std::vector<double> vertices, coordinates, result = {0.0, 0.25};
  std::string filename = "tests/test.obj";
  s21::Controller c(coordinates, vertices, filename);
  c.Parse();
  c.Rotate(0.1, s21::Y);
  ASSERT_EQ(isEqual(coordinates, result), true);
}

TEST(Rotate, Z) {
  std::vector<double> vertices, coordinates, result = {0.0, 0.25};
  std::string filename = "tests/test.obj";
  s21::Controller c(coordinates, vertices, filename);
  c.Parse();
  c.Rotate(0.1, s21::Z);
  ASSERT_EQ(isEqual(coordinates, result), true);
}

TEST(Normalization, 1) {
  std::vector<double> vertices, coordinates, result = {0.0, 0.25};
  std::string filename = "tests/test.obj";
  s21::Controller c(coordinates, vertices, filename);
  c.Parse();
  c.Normalization();
  ASSERT_EQ(isEqual(coordinates, result), true);
}

TEST(Scale, 1) {
  std::vector<double> vertices, coordinates, result = {0.0, 0.25};
  std::string filename = "tests/test.obj";
  s21::Controller c(coordinates, vertices, filename);
  c.Parse();
  c.Scale(0.1);
  ASSERT_EQ(isEqual(coordinates, result), true);
}

TEST(FillingCoords, 1) {
  std::vector<double> vertices, coordinates, result = {0.0, 0.25};
  std::string filename = "tests/test.obj";
  s21::Controller c(coordinates, vertices, filename);
  c.Parse();
  c.FillingCoords();
  ASSERT_EQ(isEqual(coordinates, result), true);
}