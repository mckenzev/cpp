#include <gtest/gtest.h>

#include "../array/s21_array.h"

TEST(Array, default_constructor_int) {
  s21::Array<int, 1> Array;
  std::array<int, 1> std_array;

  ASSERT_EQ(Array.empty(), std_array.empty());
  ASSERT_EQ(Array.size(), std_array.size());
}

TEST(Array, default_constructor_char) {
  s21::Array<char, 5> Array;
  std::array<char, 5> std_array;

  ASSERT_EQ(Array.empty(), std_array.empty());
  ASSERT_EQ(Array.size(), std_array.size());
}

TEST(Array, default_constructor_string) {
  s21::Array<std::string, 5> Array;
  std::array<std::string, 5> std_array;

  ASSERT_EQ(Array.empty(), std_array.empty());
  ASSERT_EQ(Array.size(), std_array.size());
}

TEST(Array, initializer_list_constructor_int) {
  s21::Array<int, 3> Array{1, 2, 7};
  std::array<int, 3> std_array{1, 2, 7};

  for (size_t i = 0; i < Array.size(); i++) {
    ASSERT_EQ(Array[i], std_array[i]);
  }
  ASSERT_EQ(Array.empty(), std_array.empty());
  ASSERT_EQ(Array.size(), std_array.size());
}

TEST(Array, initializer_list_constructor_char_1) {
  s21::Array<char, 3> Array{'1', '2', '3'};
  std::array<char, 3> std_array{'1', '2', '3'};

  for (size_t i = 0; i < Array.size(); i++) {
    ASSERT_EQ(Array[i], std_array[i]);
  }
  ASSERT_EQ(Array.empty(), std_array.empty());
  ASSERT_EQ(Array.size(), std_array.size());
}

TEST(Array, initializer_list_constructor_char_2) {
  s21::Array<char, 3> Array{};
  std::array<char, 3> std_array{};

  for (size_t i = 0; i < Array.size(); i++) {
    ASSERT_EQ(Array[i], std_array[i]);
  }
  ASSERT_EQ(Array.empty(), std_array.empty());
  ASSERT_EQ(Array.size(), std_array.size());
}

TEST(Array, initializer_list_constructor_string_1) {
  s21::Array<std::string, 1> Array{"Hi"};
  std::array<std::string, 1> std_array{"Hi"};

  for (size_t i = 0; i < Array.size(); i++) {
    ASSERT_EQ(Array[i], std_array[i]);
  }

  ASSERT_EQ(Array.empty(), std_array.empty());
  ASSERT_EQ(Array.size(), std_array.size());
}

TEST(Array, initializer_list_constructor_string_2) {
  s21::Array<std::string, 3> Array{"Hi", "my", "friend"};
  std::array<std::string, 3> std_array{"Hi", "my", "friend"};

  for (size_t i = 0; i < Array.size(); i++) {
    ASSERT_EQ(Array[i], std_array[i]);
  }
  ASSERT_EQ(Array.empty(), std_array.empty());
  ASSERT_EQ(Array.size(), std_array.size());
}

TEST(Array, copy_constructor_int) {
  s21::Array<int, 3> Array{1, 2, 7};
  s21::Array<int, 3> s21_tmp(Array);
  std::array<int, 3> std_array{1, 2, 7};
  std::array<int, 3> std_tmp(std_array);

  for (size_t i = 0; i < Array.size(); i++) {
    ASSERT_EQ(Array[i], std_array[i]);
    ASSERT_EQ(s21_tmp[i], std_tmp[i]);
  }
  ASSERT_EQ(Array.empty(), std_array.empty());
  ASSERT_EQ(s21_tmp.empty(), s21_tmp.empty());
  ASSERT_EQ(Array.size(), std_array.size());
  ASSERT_EQ(s21_tmp.size(), std_tmp.size());
}

TEST(Array, copy_constructor_char) {
  s21::Array<char, 3> Array{'1', '2', '3'};
  s21::Array<char, 3> s21_tmp(Array);
  std::array<char, 3> std_array{'1', '2', '3'};
  std::array<char, 3> std_tmp(std_array);

  for (size_t i = 0; i < Array.size(); i++) {
    ASSERT_EQ(Array[i], std_array[i]);
    ASSERT_EQ(s21_tmp[i], std_tmp[i]);
  }
  ASSERT_EQ(Array.empty(), std_array.empty());
  ASSERT_EQ(s21_tmp.empty(), s21_tmp.empty());
  ASSERT_EQ(Array.size(), std_array.size());
  ASSERT_EQ(s21_tmp.size(), std_tmp.size());
}

TEST(Array, copy_constructor_string) {
  s21::Array<std::string, 3> Array{"Hi", "my", "friend"};
  s21::Array<std::string, 3> s21_tmp(Array);
  std::array<std::string, 3> std_array{"Hi", "my", "friend"};
  std::array<std::string, 3> std_tmp(std_array);

  for (size_t i = 0; i < Array.size(); i++) {
    ASSERT_EQ(Array[i], std_array[i]);
    ASSERT_EQ(s21_tmp[i], std_tmp[i]);
  }
  ASSERT_EQ(Array.empty(), std_array.empty());
  ASSERT_EQ(s21_tmp.empty(), s21_tmp.empty());
  ASSERT_EQ(Array.size(), std_array.size());
  ASSERT_EQ(s21_tmp.size(), std_tmp.size());
}

TEST(Array, move_constructor_int) {
  s21::Array<int, 3> Array{1, 2, 7};
  s21::Array<int, 3> s21_tmp(std::move(Array));
  std::array<int, 3> std_array{1, 2, 7};
  std::array<int, 3> std_tmp(std::move(std_array));

  for (size_t i = 0; i < Array.size(); i++) {
    ASSERT_EQ(Array[i], std_array[i]);
    ASSERT_EQ(s21_tmp[i], std_tmp[i]);
  }
  ASSERT_EQ(Array.empty(), std_array.empty());
  ASSERT_EQ(s21_tmp.empty(), s21_tmp.empty());
  ASSERT_EQ(Array.size(), std_array.size());
  ASSERT_EQ(s21_tmp.size(), std_tmp.size());
}

TEST(Array, move_constructor_char) {
  s21::Array<char, 3> Array{'1', '2', '3'};
  s21::Array<char, 3> s21_tmp(std::move(Array));
  std::array<char, 3> std_array{'1', '2', '3'};
  std::array<char, 3> std_tmp(std::move(std_array));

  for (size_t i = 0; i < Array.size(); i++) {
    ASSERT_EQ(Array[i], std_array[i]);
    ASSERT_EQ(s21_tmp[i], std_tmp[i]);
  }
  ASSERT_EQ(Array.empty(), std_array.empty());
  ASSERT_EQ(s21_tmp.empty(), s21_tmp.empty());
  ASSERT_EQ(Array.size(), std_array.size());
  ASSERT_EQ(s21_tmp.size(), std_tmp.size());
}

TEST(Array, move_constructor_string) {
  s21::Array<std::string, 3> Array{"Hi", "dear"};
  s21::Array<std::string, 3> s21_tmp(std::move(Array));
  std::array<std::string, 3> std_array{"Hi", "dear"};
  std::array<std::string, 3> std_tmp(std::move(std_array));

  for (size_t i = 0; i < Array.size(); i++) {
    ASSERT_EQ(Array[i], std_array[i]);
    ASSERT_EQ(s21_tmp[i], std_tmp[i]);
  }
  ASSERT_EQ(Array.empty(), std_array.empty());
  ASSERT_EQ(s21_tmp.empty(), s21_tmp.empty());
  ASSERT_EQ(Array.size(), std_array.size());
  ASSERT_EQ(s21_tmp.size(), std_tmp.size());
}

TEST(Array, move_operator_int) {
  s21::Array<int, 3> Array{1, 2, 7};
  s21::Array<int, 3> s21_tmp(Array);
  s21::Array<int, 3> result;
  result = std::move(Array);

  for (size_t i = 0; i < Array.size(); i++) {
    ASSERT_EQ(s21_tmp[i], result[i]);
  }
  EXPECT_TRUE(Array.size() == result.size());
}

TEST(Array, move_operator_char) {
  s21::Array<char, 3> Array{'1', '2', '3'};
  s21::Array<char, 3> s21_tmp(Array);
  s21::Array<char, 3> result;
  result = std::move(Array);

  for (size_t i = 0; i < Array.size(); i++) {
    ASSERT_EQ(s21_tmp[i], result[i]);
  }
  EXPECT_TRUE(Array.size() == result.size());
}

TEST(Array, move_operator_string) {
  s21::Array<std::string, 3> Array{"Hi", "dear"};
  s21::Array<std::string, 3> s21_tmp(Array);
  s21::Array<std::string, 3> result;
  result = std::move(Array);

  for (size_t i = 0; i < Array.size(); i++) {
    ASSERT_EQ(s21_tmp[i], result[i]);
  }
  EXPECT_TRUE(Array.size() == result.size());
}

TEST(Array, at_int) {
  s21::Array<int, 3> Array{1, 2, 7};
  std::array<int, 3> std_array{1, 2, 7};
  Array.at(0) = 3;
  Array.at(1) = 2;
  Array.at(2) = 1;

  std_array.at(0) = 3;
  std_array.at(1) = 2;
  std_array.at(2) = 1;

  ASSERT_EQ(Array.at(0), std_array.at(0));
  ASSERT_EQ(Array.at(1), std_array.at(1));
  ASSERT_EQ(Array.at(2), std_array.at(2));
  ASSERT_EQ(Array.size(), std_array.size());
}

TEST(Array, at_int_const) {
  const s21::Array<int, 3> Array{1, 2, 7};
  const std::array<int, 3> std_array{1, 2, 7};

  for (size_t i = 0; i < Array.size(); i++) {
    ASSERT_EQ(Array.at(i), std_array.at(i));
  }
  ASSERT_EQ(Array.size(), std_array.size());
}

TEST(Array, at_char) {
  s21::Array<char, 3> Array{'1', '2', '3'};
  std::array<char, 3> std_array{'1', '2', '3'};
  Array.at(0) = '3';
  Array.at(1) = '2';
  Array.at(2) = '1';

  std_array.at(0) = '3';
  std_array.at(1) = '2';
  std_array.at(2) = '1';

  ASSERT_EQ(Array.at(0), std_array.at(0));
  ASSERT_EQ(Array.at(1), std_array.at(1));
  ASSERT_EQ(Array.at(2), std_array.at(2));
  ASSERT_EQ(Array.size(), std_array.size());
}

TEST(Array, at_string) {
  s21::Array<std::string, 3> Array{"Hi", "my", "dear"};
  std::array<std::string, 3> std_array{"Hi", "my", "dear"};
  Array.at(0) = "dear";
  Array.at(1) = "my";
  Array.at(2) = "Hi";

  std_array.at(0) = "dear";
  std_array.at(1) = "my";
  std_array.at(2) = "Hi";

  ASSERT_EQ(Array.at(0), std_array.at(0));
  ASSERT_EQ(Array.at(1), std_array.at(1));
  ASSERT_EQ(Array.at(2), std_array.at(2));
  ASSERT_EQ(Array.size(), std_array.size());
}

TEST(Array, operator_br) {
  s21::Array<int, 3> Array{1, 2, 7};
  std::array<int, 3> std_array{1, 2, 7};
  Array[0] = 100;
  std_array[0] = 100;

  for (size_t i = 0; i < Array.size(); i++) {
    ASSERT_EQ(Array.at(i), std_array.at(i));
  }
  ASSERT_EQ(Array.size(), std_array.size());
}

TEST(Array, operator_br_const) {
  const s21::Array<int, 3> Array{1, 2, 7};
  const std::array<int, 3> std_array{1, 2, 7};

  for (size_t i = 0; i < Array.size(); i++) {
    ASSERT_EQ(Array[i], std_array[i]);
  }
  ASSERT_EQ(Array.size(), std_array.size());
}

TEST(Array, test_throw) {
  s21::Array<int, 3> Array{1, 2, 7};
  std::array<int, 3> std_array{1, 2, 7};

  ASSERT_ANY_THROW(Array.at(5));
  ASSERT_ANY_THROW(std_array.at(5));
}

TEST(Array, test_front) {
  s21::Array<int, 3> Array{1, 2, 7};
  std::array<int, 3> std_array{1, 2, 7};

  ASSERT_EQ(Array.front(), std_array.front());
}

TEST(Array, test_back) {
  s21::Array<int, 3> Array{1, 2, 7};
  std::array<int, 3> std_array{1, 2, 7};

  ASSERT_EQ(Array.back(), std_array.back());
}

TEST(Array, test_data) {
  s21::Array<int, 3> Array{1, 2, 7};
  std::array<int, 3> std_array{1, 2, 7};
  int *tmp_s21 = Array.data();
  int *tmp_std = std_array.data();

  for (size_t i = 0; i < Array.size(); i++) {
    ASSERT_EQ(tmp_s21[i], tmp_std[i]);
  }
}

TEST(Array, test_data_const) {
  const s21::Array<int, 3> Array{1, 2, 7};
  const std::array<int, 3> std_array{1, 2, 7};
  const int *tmp_s21 = Array.data();
  const int *tmp_std = std_array.data();

  for (size_t i = 0; i < Array.size(); i++) {
    ASSERT_EQ(tmp_s21[i], tmp_std[i]);
  }
}

TEST(Array, test_begin) {
  s21::Array<int, 3> Array{1, 2, 7};
  std::array<int, 3> std_array{1, 2, 7};
  int *tmp_s21 = Array.begin() + 2;
  int *tmp_std = std_array.begin() + 2;

  for (size_t i = Array.size() - 1; i > 0; i--) {
    ASSERT_EQ(*(tmp_s21 - i), *(tmp_std - i));
  }
  ASSERT_EQ(Array.size(), std_array.size());
}

TEST(Array, test_begin_const) {
  const s21::Array<int, 3> Array{1, 2, 7};
  const std::array<int, 3> std_array{1, 2, 7};
  const int *tmp_s21 = Array.begin() + 2;
  const int *tmp_std = std_array.begin() + 2;

  for (size_t i = Array.size() - 1; i > 0; i--) {
    ASSERT_EQ(*(tmp_s21 - i), *(tmp_std - i));
  }
  ASSERT_EQ(Array.size(), std_array.size());
}

TEST(Array, test_end) {
  s21::Array<int, 3> Array{1, 2, 7};
  std::array<int, 3> std_array{1, 2, 7};
  int *tmp_s21 = Array.end() - 1;
  int *tmp_std = std_array.end() - 1;

  for (size_t i = Array.size() - 1; i > 0; i--) {
    ASSERT_EQ(*(tmp_s21 - i), *(tmp_std - i));
  }
  ASSERT_EQ(Array.size(), std_array.size());
}

TEST(Array, test_end_const) {
  const s21::Array<int, 3> Array{1, 2, 7};
  const std::array<int, 3> std_array{1, 2, 7};
  const int *tmp_s21 = Array.end() - 1;
  const int *tmp_std = std_array.end() - 1;

  for (size_t i = Array.size() - 1; i > 0; i--) {
    ASSERT_EQ(*(tmp_s21 - i), *(tmp_std - i));
  }
  ASSERT_EQ(Array.size(), std_array.size());
}

TEST(Array, test_max_size) {
  s21::Array<int, 3> Array{1, 2, 7};
  std::array<int, 3> std_array{1, 2, 7};

  ASSERT_EQ(Array.max_size(), std_array.max_size());
}

TEST(Array, test_swap) {
  s21::Array<int, 3> Array{1, 2, 7};
  s21::Array<int, 3> Array_tmp;
  std::array<int, 3> std_array{1, 2, 7};
  std::array<int, 3> std_array_tmp;
  Array_tmp.swap(Array);
  std_array_tmp.swap(std_array);

  ASSERT_EQ(Array.empty(), std_array.empty());
  ASSERT_EQ(Array.size(), std_array.size());
  for (size_t i = 0; i < Array.size(); i++) {
    ASSERT_EQ(Array_tmp[i], Array_tmp[i]);
  }
  ASSERT_EQ(Array_tmp.empty(), std_array_tmp.empty());
  ASSERT_EQ(Array_tmp.size(), std_array_tmp.size());
}

TEST(Array, def_fill) {
  s21::Array<char, 3> Array{'1', '2', '3'};
  std::array<char, 3> std_array{'1', '2', '3'};
  Array.fill('w');
  std_array.fill('w');

  for (size_t i = 0; i < Array.size(); i++) {
    ASSERT_EQ(Array[i], std_array[i]);
  }

  ASSERT_EQ(Array.size(), std_array.size());
  ASSERT_EQ(Array.empty(), std_array.empty());
}