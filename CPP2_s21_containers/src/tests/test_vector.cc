#include <gtest/gtest.h>

#include "../vector/s21_vector.h"

TEST(vector, default_constructor_int) {
  s21::vector<int> vector;
  std::vector<int> std_vector;

  ASSERT_EQ(vector.empty(), std_vector.empty());
  ASSERT_EQ(vector.size(), std_vector.size());
  ASSERT_EQ(vector.capacity(), std_vector.capacity());
}

TEST(vector, default_constructor_char) {
  s21::vector<char> vector;
  std::vector<char> std_vector;

  ASSERT_EQ(vector.empty(), std_vector.empty());
  ASSERT_EQ(vector.size(), std_vector.size());
  ASSERT_EQ(vector.capacity(), std_vector.capacity());
}

TEST(vector, parameterized_constructor) {
  s21::vector<int> vector(6);
  std::vector<int> std_vector(6);

  ASSERT_EQ(vector.empty(), std_vector.empty());
  ASSERT_EQ(vector.size(), std_vector.size());
  ASSERT_EQ(vector.capacity(), std_vector.capacity());
}

TEST(vector, initializer_list_constructor_int) {
  s21::vector<int> vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};

  ASSERT_EQ(vector.empty(), std_vector.empty());
  ASSERT_EQ(vector.size(), std_vector.size());
  ASSERT_EQ(vector.capacity(), std_vector.capacity());
}

TEST(vector, initializer_list_constructor_char) {
  s21::vector<int> vector{'a', 'b', 'c'};
  std::vector<int> std_vector{'a', 'b', 'c'};

  ASSERT_EQ(vector.empty(), std_vector.empty());
  ASSERT_EQ(vector.size(), std_vector.size());
  ASSERT_EQ(vector.capacity(), std_vector.capacity());
}

TEST(vector, initializer_list_constructor_string_1) {
  s21::vector<std::string> vector{"Hi"};
  std::vector<std::string> std_vector{"Hi"};

  ASSERT_EQ(vector.empty(), std_vector.empty());
  ASSERT_EQ(vector.size(), std_vector.size());
  ASSERT_EQ(vector.capacity(), std_vector.capacity());
}

TEST(vector, initializer_list_constructor_string_2) {
  s21::vector<std::string> vector{"Hi", "my", "friend"};
  std::vector<std::string> std_vector{"Hi", "my", "friend"};

  ASSERT_EQ(vector.empty(), std_vector.empty());
  ASSERT_EQ(vector.size(), std_vector.size());
  ASSERT_EQ(vector.capacity(), std_vector.capacity());
}

TEST(vector, copy_constructor_int) {
  s21::vector<int> vector{1, 2, 3};
  s21::vector<int> s21_tmp(vector);
  std::vector<int> std_vector{1, 2, 3};
  std::vector<int> std_tmp(std_vector);

  ASSERT_EQ(vector.size(), std_vector.size());
  ASSERT_EQ(s21_tmp.size(), std_tmp.size());
  ASSERT_EQ(vector.capacity(), std_vector.capacity());
  ASSERT_EQ(s21_tmp.capacity(), std_tmp.capacity());
}

TEST(vector, copy_constructor_char) {
  s21::vector<char> vector{'a', 'b', 'c'};
  s21::vector<char> s21_tmp(vector);
  std::vector<char> std_vector{'a', 'b', 'c'};
  std::vector<char> std_tmp(std_vector);

  ASSERT_EQ(vector.size(), std_vector.size());
  ASSERT_EQ(s21_tmp.size(), std_tmp.size());
  ASSERT_EQ(vector.capacity(), std_vector.capacity());
  ASSERT_EQ(s21_tmp.capacity(), std_tmp.capacity());
}

TEST(vector, copy_constructor_string) {
  s21::vector<std::string> vector{"Hi", "my", "friend"};
  s21::vector<std::string> s21_tmp(vector);
  std::vector<std::string> std_vector{"Hi", "my", "friend"};
  std::vector<std::string> std_tmp(std_vector);

  ASSERT_EQ(vector.size(), std_vector.size());
  ASSERT_EQ(s21_tmp.size(), std_tmp.size());
  ASSERT_EQ(vector.capacity(), std_vector.capacity());
  ASSERT_EQ(s21_tmp.capacity(), std_tmp.capacity());
}

TEST(vector, move_constructor_int) {
  s21::vector<int> vector{1, 2, 3};
  s21::vector<int> s21_tmp = vector;
  std::vector<int> std_vector{1, 2, 3};
  std::vector<int> std_tmp = std_vector;

  ASSERT_EQ(vector.size(), std_vector.size());
  ASSERT_EQ(s21_tmp.size(), std_tmp.size());
  ASSERT_EQ(vector.capacity(), std_vector.capacity());
  ASSERT_EQ(s21_tmp.capacity(), std_tmp.capacity());
}

TEST(vector, move_constructor_char) {
  s21::vector<char> vector{'a', 'b', 'c'};
  s21::vector<char> s21_tmp(std::move(vector));
  std::vector<char> std_vector{'a', 'b', 'c'};
  std::vector<char> std_tmp(std::move(std_vector));

  ASSERT_EQ(vector.size(), std_vector.size());
  ASSERT_EQ(s21_tmp.size(), std_tmp.size());
  ASSERT_EQ(vector.capacity(), std_vector.capacity());
  ASSERT_EQ(s21_tmp.capacity(), std_tmp.capacity());
}

TEST(vector, move_constructor_string) {
  s21::vector<std::string> vector{"Hi", "my", "friend"};
  s21::vector<std::string> s21_tmp(std::move(vector));
  std::vector<std::string> std_vector{"Hi", "my", "friend"};
  std::vector<std::string> std_tmp(std::move(std_vector));

  ASSERT_EQ(vector.size(), std_vector.size());
  ASSERT_EQ(s21_tmp.size(), std_tmp.size());
  ASSERT_EQ(vector.capacity(), std_vector.capacity());
  ASSERT_EQ(s21_tmp.capacity(), std_tmp.capacity());
}

TEST(vector, destructor_int) {
  s21::vector<int> vector{1, 2, 3};
  vector.~vector();

  ASSERT_EQ(0, vector.size());
  ASSERT_EQ(0, vector.capacity());
  ASSERT_EQ(0, vector.data());
}

TEST(vector, destructor_char) {
  s21::vector<char> vector{'a', 'b', 'c'};
  vector.~vector();

  ASSERT_EQ(0, vector.size());
  ASSERT_EQ(0, vector.capacity());
  ASSERT_EQ(0, vector.data());
}

TEST(vector, destructor_string) {
  s21::vector<std::string> vector{"Hi", "my", "friend"};
  vector.~vector();

  ASSERT_EQ(0, vector.size());
  ASSERT_EQ(0, vector.capacity());
  ASSERT_EQ(0, vector.data());
}

TEST(vector, move_operator_char) {
  s21::vector<char> vector{'a', 'b', 'c'};
  s21::vector<char> s21_tmp = std::move(vector);
  s21::vector<char> result;
  result = std::move(vector);

  EXPECT_TRUE(vector.size() == result.size());
  EXPECT_TRUE(vector.capacity() == result.capacity());
}

TEST(vector, move_operator_string) {
  s21::vector<std::string> vector{"Hi", "my", "friend"};
  s21::vector<std::string> s21_tmp = std::move(vector);
  s21::vector<std::string> result;
  result = std::move(vector);

  EXPECT_TRUE(vector.size() == result.size());
  EXPECT_TRUE(vector.capacity() == result.capacity());
}

TEST(vector, at_int) {
  s21::vector<int> vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  vector.at(0) = 3;
  vector.at(1) = 2;
  vector.at(2) = 1;

  std_vector.at(0) = 3;
  std_vector.at(1) = 2;
  std_vector.at(2) = 1;

  ASSERT_EQ(vector.at(0), std_vector.at(0));
  ASSERT_EQ(vector.at(1), std_vector.at(1));
  ASSERT_EQ(vector.at(2), std_vector.at(2));
  ASSERT_EQ(vector.size(), std_vector.size());
  ASSERT_EQ(vector.capacity(), std_vector.capacity());
}

TEST(vector, at_char) {
  s21::vector<char> vector{'a', 'b', 'c'};
  std::vector<char> std_vector{'a', 'b', 'c'};
  vector.at(0) = '3';
  vector.at(1) = '2';
  vector.at(2) = '1';

  std_vector.at(0) = '3';
  std_vector.at(1) = '2';
  std_vector.at(2) = '1';

  ASSERT_EQ(vector.at(0), std_vector.at(0));
  ASSERT_EQ(vector.at(1), std_vector.at(1));
  ASSERT_EQ(vector.at(2), std_vector.at(2));
  ASSERT_EQ(vector.size(), std_vector.size());
  ASSERT_EQ(vector.capacity(), std_vector.capacity());
}

TEST(vector, at_string) {
  s21::vector<std::string> vector{"Hi", "my", "frinebd"};
  std::vector<std::string> std_vector{"Hi", "my", "frinebd"};
  vector.at(0) = "Am";
  vector.at(1) = "is";
  vector.at(2) = "are";

  std_vector.at(0) = "Am";
  std_vector.at(1) = "is";
  std_vector.at(2) = "are";

  ASSERT_EQ(vector.at(0), std_vector.at(0));
  ASSERT_EQ(vector.at(1), std_vector.at(1));
  ASSERT_EQ(vector.at(2), std_vector.at(2));
  ASSERT_EQ(vector.size(), std_vector.size());
  ASSERT_EQ(vector.capacity(), std_vector.capacity());
}

TEST(vector, operator_br) {
  s21::vector<int> vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  vector[0] = 100;
  std_vector[0] = 100;

  ASSERT_EQ(vector.at(0), std_vector.at(0));
  ASSERT_EQ(vector.at(1), std_vector.at(1));
  ASSERT_EQ(vector.at(2), std_vector.at(2));
  ASSERT_EQ(vector.size(), std_vector.size());
  ASSERT_EQ(vector.capacity(), std_vector.capacity());
}

TEST(vector, operator_br_const) {
  const s21::vector<int> vector{1, 2, 3};
  const std::vector<int> std_vector{1, 2, 3};

  ASSERT_EQ(vector[0], std_vector[0]);
  ASSERT_EQ(vector[1], std_vector[1]);
  ASSERT_EQ(vector[2], std_vector[2]);
  ASSERT_EQ(vector.size(), std_vector.size());
  ASSERT_EQ(vector.capacity(), std_vector.capacity());
}

TEST(vector, test_front) {
  s21::vector<int> vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};

  ASSERT_EQ(vector.front(), std_vector.front());
}

TEST(vector, test_back) {
  s21::vector<int> vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};

  ASSERT_EQ(vector.back(), std_vector.back());
}

TEST(vector, test_begin) {
  s21::vector<int> vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  vector.insert(vector.begin() + 1, 100);
  std_vector.insert(std_vector.begin() + 1, 100);

  ASSERT_EQ(vector.at(0), std_vector.at(0));
  ASSERT_EQ(vector.at(1), std_vector.at(1));
  ASSERT_EQ(vector.at(2), std_vector.at(2));
  ASSERT_EQ(vector.at(3), std_vector.at(3));
}

TEST(vector, test_begin_const) {
  const s21::vector<int> vector{1, 2, 3};
  const std::vector<int> std_vector{1, 2, 3};

  for (size_t i = 0; i < 3; i++) {
    ASSERT_EQ(*(vector.cbegin() + i), *(std_vector.begin() + i));
  }
}

TEST(vector, test_end_const) {
  const s21::vector<int> vector{1, 2, 3};
  const std::vector<int> std_vector{1, 2, 3};

  for (size_t i = 0; i < 3; i++) {
    ASSERT_EQ(*(vector.cend() - i - 1), *(std_vector.end() - i - 1));
  }
}

TEST(vector, test_reserve) {
  s21::vector<int> vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  vector.reserve(15);
  std_vector.reserve(15);

  ASSERT_EQ(vector.empty(), std_vector.empty());
  ASSERT_EQ(vector.size(), std_vector.size());
  ASSERT_EQ(vector.capacity(), std_vector.capacity());
}

TEST(vector, test_shrink_to_fit) {
  s21::vector<int> vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  vector.reserve(15);
  std_vector.reserve(15);
  vector.shrink_to_fit();
  std_vector.shrink_to_fit();

  ASSERT_EQ(vector.empty(), std_vector.empty());
  ASSERT_EQ(vector.size(), std_vector.size());
  ASSERT_EQ(vector.capacity(), std_vector.capacity());
}

TEST(vector, test_clear) {
  s21::vector<int> vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  vector.reserve(15);
  std_vector.reserve(15);
  vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  vector.clear();
  std_vector.clear();

  ASSERT_EQ(vector.empty(), std_vector.empty());
  ASSERT_EQ(vector.size(), std_vector.size());
  ASSERT_EQ(vector.capacity(), std_vector.capacity());
}

TEST(vector, test_insert) {
  s21::vector<int> vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  vector.insert(vector.begin() + 1, 50);
  std_vector.insert(std_vector.begin() + 1, 50);

  ASSERT_EQ(vector.at(0), std_vector.at(0));
  ASSERT_EQ(vector.at(1), std_vector.at(1));
  ASSERT_EQ(vector.at(2), std_vector.at(2));
  ASSERT_EQ(vector.at(3), std_vector.at(3));
}

TEST(vector, test_erase) {
  s21::vector<int> vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  vector.erase(vector.begin() + 1);
  std_vector.erase(std_vector.begin() + 1);

  ASSERT_EQ(vector.at(0), std_vector.at(0));
  ASSERT_EQ(vector.at(1), std_vector.at(1));
}

TEST(vector, test_push_back_1) {
  s21::vector<int> vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  vector.push_back(100);
  std_vector.push_back(100);

  ASSERT_EQ(vector.at(0), std_vector.at(0));
  ASSERT_EQ(vector.at(1), std_vector.at(1));
  ASSERT_EQ(vector.at(2), std_vector.at(2));
  ASSERT_EQ(vector.at(3), std_vector.at(3));
}

TEST(vector, test_push_back_2) {
  s21::vector<int> vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  vector.push_back(50);
  std_vector.push_back(50);
  vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  vector.push_back(100);
  std_vector.push_back(100);

  ASSERT_EQ(vector.at(0), std_vector.at(0));
  ASSERT_EQ(vector.at(1), std_vector.at(1));
  ASSERT_EQ(vector.at(2), std_vector.at(2));
  ASSERT_EQ(vector.at(3), std_vector.at(3));
  ASSERT_EQ(vector.at(4), std_vector.at(4));

  ASSERT_EQ(vector.empty(), std_vector.empty());
  ASSERT_EQ(vector.size(), std_vector.size());
  ASSERT_EQ(vector.capacity(), std_vector.capacity());
}

TEST(vector, test_push_back_3) {
  s21::vector<int> vector;
  std::vector<int> std_vector;
  vector.push_back(50);
  std_vector.push_back(50);
  vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  vector.push_back(100);
  std_vector.push_back(100);

  ASSERT_EQ(vector.at(0), std_vector.at(0));

  ASSERT_EQ(vector.empty(), std_vector.empty());
  ASSERT_EQ(vector.size(), std_vector.size());
  ASSERT_EQ(vector.capacity(), std_vector.capacity());
}

TEST(vector, test_pop_back) {
  s21::vector<int> vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  vector.pop_back();
  std_vector.pop_back();

  ASSERT_EQ(vector.at(0), std_vector.at(0));
  ASSERT_EQ(vector.at(1), std_vector.at(1));

  ASSERT_EQ(vector.empty(), std_vector.empty());
  ASSERT_EQ(vector.size(), std_vector.size());
  ASSERT_EQ(vector.capacity(), std_vector.capacity());
}

TEST(vector, test_swap) {
  s21::vector<int> vector{1, 2, 3};
  s21::vector<int> vector_tmp;
  std::vector<int> std_vector{1, 2, 3};
  std::vector<int> std_vector_tmp;
  vector_tmp.swap(vector);
  std_vector_tmp.swap(std_vector);

  ASSERT_EQ(vector.empty(), std_vector.empty());
  ASSERT_EQ(vector.size(), std_vector.size());
  ASSERT_EQ(vector.capacity(), std_vector.capacity());

  ASSERT_EQ(vector_tmp.empty(), std_vector_tmp.empty());
  ASSERT_EQ(vector_tmp.size(), std_vector_tmp.size());
  ASSERT_EQ(vector_tmp.capacity(), std_vector_tmp.capacity());
}

// ДОПКА

TEST(vector, insert_many_one) {
  s21::vector<int> vector{1, 2, 3, 5, 6};
  std::vector<int> std_vector{1, 2, 3, 5, 6};

  vector.insert_many(vector.begin() + 3, 8);
  std_vector.insert(std_vector.begin() + 3, 8);

  for (size_t i = 0; i < vector.size(); i++) {
    ASSERT_EQ(vector[i], std_vector[i]);
  }
}

TEST(vector, insert_many_much) {
  s21::vector<int> vector{1, 2, 3, 5, 6};
  std::vector<int> std_vector{1, 2, 3, 5, 6};

  vector.insert_many(vector.begin() + 3, 8, 9);
  std_vector.insert(std_vector.begin() + 3, {8, 9});

  for (size_t i = 0; i < vector.size(); i++) {
    ASSERT_EQ(vector[i], std_vector[i]);
  }
}

TEST(vector, insert_many_back) {
  s21::vector<int> vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};

  vector.insert_many_back(4, 5, 6);
  std_vector.insert(std_vector.end(), {4, 5, 6});

  for (size_t i = 0; i < vector.size(); i++) {
    ASSERT_EQ(vector[i], std_vector[i]);
  }
}

TEST(vector, insert_many_back_1) {
  s21::vector<char> vector{'1', '2', '3'};
  std::vector<char> std_vector{'1', '2', '3'};

  vector.insert_many_back('4', '$', '&');
  std_vector.insert(std_vector.end(), {'4', '$', '&'});

  for (size_t i = 0; i < vector.size(); i++) {
    ASSERT_EQ(vector[i], std_vector[i]);
  }

  ASSERT_EQ(vector.empty(), std_vector.empty());
  ASSERT_EQ(vector.size(), std_vector.size());
  ASSERT_EQ(vector.capacity(), std_vector.capacity());
}
