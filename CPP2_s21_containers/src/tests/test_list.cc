#include <gtest/gtest.h>

#include <list>

#include "../list/s21_list.h"

TEST(list, default_constructor_int) {
  s21::list<int> list;
  std::list<int> std_list;
  ASSERT_EQ(list.empty(), std_list.empty());
  ASSERT_EQ(list.size(), std_list.size());
}

TEST(list, default_constructor_char) {
  s21::list<char> list;
  std::list<char> std_list;
  ASSERT_EQ(list.empty(), std_list.empty());
  ASSERT_EQ(list.size(), std_list.size());
}

TEST(list, default_constructor_string) {
  s21::list<std::string> list;
  std::list<std::string> std_list;
  ASSERT_EQ(list.empty(), std_list.empty());
  ASSERT_EQ(list.size(), std_list.size());
}

TEST(list, parametrized_constructor_int_1) {
  s21::list<int> list(3);
  std::list<int> std_list(3);
  ASSERT_EQ(list.empty(), std_list.empty());
  ASSERT_EQ(list.size(), std_list.size());
  s21::list<int>::iterator iter_s21 = list.begin();
  std::list<int>::iterator iter_std = std_list.begin();
  for (size_t i = 0; i < list.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, parametrized_constructor_int_2) {
  s21::list<int> list(0);
  std::list<int> std_list(0);
  ASSERT_EQ(list.empty(), std_list.empty());
  ASSERT_EQ(list.size(), std_list.size());
  s21::list<int>::iterator iter_s21 = list.begin();
  std::list<int>::iterator iter_std = std_list.begin();
  for (size_t i = 0; i < list.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, parametrized_constructor_char_1) {
  s21::list<char> list(3);
  std::list<char> std_list(3);
  ASSERT_EQ(list.empty(), std_list.empty());
  ASSERT_EQ(list.size(), std_list.size());
  s21::list<char>::iterator iter_s21 = list.begin();
  std::list<char>::iterator iter_std = std_list.begin();
  for (size_t i = 0; i < list.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, parametrized_constructor_char_2) {
  s21::list<char> list(0);
  std::list<char> std_list(0);
  ASSERT_EQ(list.empty(), std_list.empty());
  ASSERT_EQ(list.size(), std_list.size());
  s21::list<char>::iterator iter_s21 = list.begin();
  std::list<char>::iterator iter_std = std_list.begin();
  for (size_t i = 0; i < list.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, parametrized_constructor_string_1) {
  s21::list<std::string> list(3);
  std::list<std::string> std_list(3);
  ASSERT_EQ(list.empty(), std_list.empty());
  ASSERT_EQ(list.size(), std_list.size());
  s21::list<std::string>::iterator iter_s21 = list.begin();
  std::list<std::string>::iterator iter_std = std_list.begin();
  for (size_t i = 0; i < list.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, parametrized_constructor_string_2) {
  s21::list<std::string> list(0);
  std::list<std::string> std_list(0);
  ASSERT_EQ(list.empty(), std_list.empty());
  ASSERT_EQ(list.size(), std_list.size());
  s21::list<std::string>::iterator iter_s21 = list.begin();
  std::list<std::string>::iterator iter_std = std_list.begin();
  for (size_t i = 0; i < list.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, list_init_constructor_int_1) {
  s21::list<int> list{};
  std::list<int> std_list{};
  ASSERT_EQ(list.empty(), std_list.empty());
  ASSERT_EQ(list.size(), std_list.size());
  s21::list<int>::iterator iter_s21 = list.begin();
  std::list<int>::iterator iter_std = std_list.begin();
  for (size_t i = 0; i < list.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, list_init_constructor_int_2) {
  s21::list<int> list{0};
  std::list<int> std_list{0};
  ASSERT_EQ(list.empty(), std_list.empty());
  ASSERT_EQ(list.size(), std_list.size());
  s21::list<int>::iterator iter_s21 = list.begin();
  std::list<int>::iterator iter_std = std_list.begin();
  for (size_t i = 0; i < list.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, list_init_constructor_int_3) {
  s21::list<int> list{3};
  std::list<int> std_list{3};
  ASSERT_EQ(list.empty(), std_list.empty());
  ASSERT_EQ(list.size(), std_list.size());
  s21::list<int>::iterator iter_s21 = list.begin();
  std::list<int>::iterator iter_std = std_list.begin();
  for (size_t i = 0; i < list.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, list_init_constructor_int_4) {
  s21::list<int> list{1, 7, 1, 45};
  std::list<int> std_list{1, 7, 1, 45};
  ASSERT_EQ(list.empty(), std_list.empty());
  ASSERT_EQ(list.size(), std_list.size());
  s21::list<int>::iterator iter_s21 = list.begin();
  std::list<int>::iterator iter_std = std_list.begin();
  for (size_t i = 0; i < list.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, list_init_constructor_char_1) {
  s21::list<char> list{'a', 'b', 'c'};
  std::list<char> std_list{'a', 'b', 'c'};
  ASSERT_EQ(list.empty(), std_list.empty());
  ASSERT_EQ(list.size(), std_list.size());
  s21::list<char>::iterator iter_s21 = list.begin();
  std::list<char>::iterator iter_std = std_list.begin();
  for (size_t i = 0; i < list.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, list_init_constructor_string_1) {
  s21::list<std::string> list{"Hola", "amigos"};
  std::list<std::string> std_list{"Hola", "amigos"};
  ASSERT_EQ(list.empty(), std_list.empty());
  ASSERT_EQ(list.size(), std_list.size());
  s21::list<std::string>::iterator iter_s21 = list.begin();
  std::list<std::string>::iterator iter_std = std_list.begin();
  for (size_t i = 0; i < list.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, copy_constructor_int) {
  s21::list<int> list{1, 7, 700};
  s21::list<int> list2(list);
  std::list<int> std_list{1, 7, 700};
  std::list<int> std_list2(std_list);
  ASSERT_EQ(list2.size(), std_list2.size());
  s21::list<int>::iterator iter_s21 = list2.begin();
  std::list<int>::iterator iter_std = std_list2.begin();
  for (size_t i = 0; i < list.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, copy_constructor_char) {
  s21::list<char> list{'a', 'b', 'c'};
  s21::list<char> list2(list);
  std::list<char> std_list{'a', 'b', 'c'};
  std::list<char> std_list2(std_list);
  ASSERT_EQ(list2.size(), std_list2.size());
  s21::list<char>::iterator iter_s21 = list2.begin();
  std::list<char>::iterator iter_std = std_list2.begin();
  for (size_t i = 0; i < list.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, copy_constructor_string) {
  s21::list<std::string> list{"Hola", " ", "amigos"};
  s21::list<std::string> list2(list);
  std::list<std::string> std_list{"Hola", " ", "amigos"};
  std::list<std::string> std_list2(std_list);
  ASSERT_EQ(list2.size(), std_list2.size());
  s21::list<std::string>::iterator iter_s21 = list2.begin();
  std::list<std::string>::iterator iter_std = std_list2.begin();
  for (size_t i = 0; i < list.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, move_constructor_int) {
  s21::list<int> list{1, 7, 1};
  s21::list<int> list2(std::move(list));
  std::list<int> std_list{1, 7, 1};
  std::list<int> std_list2(std::move(std_list));
  ASSERT_EQ(list2.size(), std_list2.size());
  s21::list<int>::iterator iter_s21 = list2.begin();
  std::list<int>::iterator iter_std = std_list2.begin();
  for (size_t i = 0; i < list.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, move_constructor_char) {
  s21::list<char> list{'a', 'b', 'c'};
  s21::list<char> list2(std::move(list));
  std::list<char> std_list{'a', 'b', 'c'};
  std::list<char> std_list2(std::move(std_list));
  ASSERT_EQ(list2.size(), std_list2.size());
  s21::list<char>::iterator iter_s21 = list2.begin();
  std::list<char>::iterator iter_std = std_list2.begin();
  for (size_t i = 0; i < list.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, move_constructor_string) {
  s21::list<std::string> list{"Hola", " ", "amigos"};
  s21::list<std::string> list2(std::move(list));
  std::list<std::string> std_list{"Hola", " ", "amigos"};
  std::list<std::string> std_list2(std::move(std_list));
  ASSERT_EQ(list2.size(), std_list2.size());
  s21::list<std::string>::iterator iter_s21 = list2.begin();
  std::list<std::string>::iterator iter_std = std_list2.begin();
  for (size_t i = 0; i < list.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, move_operator_int) {
  s21::list<int> list{1, 7, 1};
  s21::list<int> s21_tmp(list);
  s21::list<int> result;
  result = std::move(list);
  s21::list<int>::iterator iter_1 = s21_tmp.begin();
  s21::list<int>::iterator iter_2 = result.begin();

  for (size_t i = 0; i < list.size(); i++, iter_1++, iter_2++) {
    ASSERT_EQ(*iter_1, *iter_2);
  }
  ASSERT_EQ(s21_tmp.size(), result.size());
}

TEST(list, move_operator_char) {
  s21::list<char> list{'1', '2', '3'};
  s21::list<char> s21_tmp(list);
  s21::list<char> result;
  result = std::move(list);
  s21::list<char>::iterator iter_1 = s21_tmp.begin();
  s21::list<char>::iterator iter_2 = result.begin();

  for (size_t i = 0; i < list.size(); i++, iter_1++, iter_2++) {
    ASSERT_EQ(*iter_1, *iter_2);
  }
  ASSERT_EQ(s21_tmp.size(), result.size());
}

TEST(list, move_operator_string) {
  s21::list<std::string> list{"Hola", " ", "amigos"};
  s21::list<std::string> s21_tmp(list);
  s21::list<std::string> result;
  result = std::move(list);
  s21::list<std::string>::iterator iter_1 = s21_tmp.begin();
  s21::list<std::string>::iterator iter_2 = result.begin();

  for (size_t i = 0; i < list.size(); i++, iter_1++, iter_2++) {
    ASSERT_EQ(*iter_1, *iter_2);
  }
  ASSERT_EQ(s21_tmp.size(), result.size());
}

TEST(list, copy_operator_int) {
  s21::list<int> list{1, 7, 1};
  s21::list<int> s21_tmp(list);
  s21::list<int> result;
  result = list;
  s21::list<int>::iterator iter_1 = s21_tmp.begin();
  s21::list<int>::iterator iter_2 = result.begin();

  for (size_t i = 0; i < list.size(); i++, iter_1++, iter_2++) {
    ASSERT_EQ(*iter_1, *iter_2);
  }
  ASSERT_EQ(s21_tmp.size(), result.size());
}

TEST(list, copy_operator_char) {
  s21::list<char> list{'1', '2', '3'};
  s21::list<char> s21_tmp(list);
  s21::list<char> result;
  result = list;
  s21::list<char>::iterator iter_1 = s21_tmp.begin();
  s21::list<char>::iterator iter_2 = result.begin();

  for (size_t i = 0; i < list.size(); i++, iter_1++, iter_2++) {
    ASSERT_EQ(*iter_1, *iter_2);
  }
  ASSERT_EQ(s21_tmp.size(), result.size());
}

TEST(list, copy_operator_string) {
  s21::list<std::string> list{"Hola", " ", "amigos"};
  s21::list<std::string> s21_tmp(list);
  s21::list<std::string> result;
  result = list;
  s21::list<std::string>::iterator iter_1 = s21_tmp.begin();
  s21::list<std::string>::iterator iter_2 = result.begin();

  for (size_t i = 0; i < list.size(); i++, iter_1++, iter_2++) {
    ASSERT_EQ(*iter_1, *iter_2);
  }
  ASSERT_EQ(s21_tmp.size(), result.size());
}

TEST(list, front_int_1) {
  s21::list<int> list;
  std::list<int> std_list;
  ASSERT_EQ(list.size(), std_list.size());
  ASSERT_EQ(list.front(), std_list.front());
}

TEST(list, front_int_2) {
  s21::list<int> list(2);
  std::list<int> std_list(2);
  ASSERT_EQ(list.size(), std_list.size());
  ASSERT_EQ(list.front(), std_list.front());
}

TEST(list, front_int_3) {
  s21::list<int> list{1, 7, 1};
  std::list<int> std_list{1, 7, 1};
  ASSERT_EQ(list.size(), std_list.size());
  ASSERT_EQ(list.front(), std_list.front());
}

TEST(list, front_char_1) {
  s21::list<char> list;
  std::list<char> std_list;
  ASSERT_EQ(list.size(), std_list.size());
  ASSERT_EQ(list.front(), std_list.front());
}

TEST(list, front_char_2) {
  s21::list<char> list(3);
  std::list<char> std_list(3);
  ASSERT_EQ(list.size(), std_list.size());
  ASSERT_EQ(list.front(), std_list.front());
}

TEST(list, front_char_3) {
  s21::list<char> list{'a', 'b', 'c'};
  std::list<char> std_list{'a', 'b', 'c'};
  ASSERT_EQ(list.size(), std_list.size());
  ASSERT_EQ(list.front(), std_list.front());
}

TEST(list, front_string_2) {
  s21::list<std::string> list(3);
  std::list<std::string> std_list(3);
  ASSERT_EQ(list.size(), std_list.size());
  ASSERT_EQ(list.front(), std_list.front());
}

TEST(list, front_string_3) {
  s21::list<std::string> list{"Hola", "chikas"};
  std::list<std::string> std_list{"Hola", "chikas"};
  ASSERT_EQ(list.size(), std_list.size());
  ASSERT_EQ(list.front(), std_list.front());
}

TEST(list, back_int_1) {
  s21::list<int> list;
  std::list<int> std_list;
  ASSERT_EQ(list.size(), std_list.size());
  ASSERT_EQ(list.back(), std_list.back());
}

TEST(list, back_int_2) {
  s21::list<int> list(2);
  std::list<int> std_list(2);
  ASSERT_EQ(list.size(), std_list.size());
  ASSERT_EQ(list.back(), std_list.back());
}

TEST(list, back_int_3) {
  s21::list<int> list{1, 7, 1};
  std::list<int> std_list{1, 7, 1};
  ASSERT_EQ(list.size(), std_list.size());
  ASSERT_EQ(list.back(), std_list.back());
}

TEST(list, back_char_1) {
  s21::list<char> list;
  std::list<char> std_list;
  ASSERT_EQ(list.size(), std_list.size());
  ASSERT_EQ(list.back(), std_list.back());
}

TEST(list, back_char_2) {
  s21::list<char> list(3);
  std::list<char> std_list(3);
  ASSERT_EQ(list.size(), std_list.size());
  ASSERT_EQ(list.back(), std_list.back());
}

TEST(list, back_char_3) {
  s21::list<char> list{'a', 'b', 'c'};
  std::list<char> std_list{'a', 'b', 'c'};
  ASSERT_EQ(list.size(), std_list.size());
  ASSERT_EQ(list.back(), std_list.back());
}

TEST(list, back_string_2) {
  s21::list<std::string> list(3);
  std::list<std::string> std_list(3);
  ASSERT_EQ(list.size(), std_list.size());
  ASSERT_EQ(list.back(), std_list.back());
}

TEST(list, back_string_3) {
  s21::list<std::string> list{"Hola", "chikas"};
  std::list<std::string> std_list{"Hola", "chikas"};
  ASSERT_EQ(list.size(), std_list.size());
  ASSERT_EQ(list.back(), std_list.back());
}

TEST(list, begin_int_1) {
  s21::list<int> list;
  std::list<int> std_list;
  s21::list<int>::iterator iter_s21 = list.begin();
  std::list<int>::iterator iter_std = std_list.begin();
  ASSERT_EQ(list.size(), std_list.size());
  ASSERT_EQ(*iter_s21, *iter_std);
}

TEST(list, begin_int_2) {
  s21::list<int> list(2);
  std::list<int> std_list(2);
  s21::list<int>::iterator iter_s21 = list.begin();
  std::list<int>::iterator iter_std = std_list.begin();
  ASSERT_EQ(list.size(), std_list.size());
  for (size_t i = 0; i < list.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, begin_int_3) {
  s21::list<int> list{1, 7, 1};
  std::list<int> std_list{1, 7, 1};
  s21::list<int>::iterator iter_s21 = list.begin();
  std::list<int>::iterator iter_std = std_list.begin();
  ASSERT_EQ(list.size(), std_list.size());
  for (size_t i = 0; i < list.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, begin_char_1) {
  s21::list<char> list;
  std::list<char> std_list;
  s21::list<char>::iterator iter_s21 = list.begin();
  std::list<char>::iterator iter_std = std_list.begin();
  ASSERT_EQ(list.size(), std_list.size());
  ASSERT_EQ(*iter_s21, *iter_std);
}

TEST(list, begin_char_2) {
  s21::list<char> list(2);
  std::list<char> std_list(2);
  s21::list<char>::iterator iter_s21 = list.begin();
  std::list<char>::iterator iter_std = std_list.begin();
  ASSERT_EQ(list.size(), std_list.size());
  for (size_t i = 0; i < list.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, begin_char_3) {
  s21::list<char> list{'a', 'b', 'c'};
  std::list<char> std_list{'a', 'b', 'c'};
  s21::list<char>::iterator iter_s21 = list.begin();
  std::list<char>::iterator iter_std = std_list.begin();
  ASSERT_EQ(list.size(), std_list.size());
  for (size_t i = 0; i < list.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, begin_string) {
  s21::list<std::string> list{"Hola", "wordl"};
  std::list<std::string> std_list{"Hola", "wordl"};
  s21::list<std::string>::iterator iter_s21 = list.begin();
  std::list<std::string>::iterator iter_std = std_list.begin();
  ASSERT_EQ(list.size(), std_list.size());
  for (size_t i = 0; i < list.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, end_int_1) {
  s21::list<int> list;
  std::list<int> std_list;
  s21::list<int>::iterator iter_s21 = list.end();
  std::list<int>::iterator iter_std = std_list.end();
  ASSERT_EQ(list.size(), std_list.size());
  ASSERT_EQ(*iter_s21, *iter_std);
}

TEST(list, end_int_2) {
  s21::list<int> list{1, 7, 1};
  std::list<int> std_list{1, 7, 1};
  s21::list<int>::iterator iter_s21 = list.end();
  std::list<int>::iterator iter_std = std_list.end();
  iter_s21--;
  iter_std--;
  ASSERT_EQ(list.size(), std_list.size());
  for (size_t i = list.size() - 1; i > 0; i--, iter_s21--, iter_std--) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, end_char) {
  s21::list<char> list{'a', 'b', 'c'};
  std::list<char> std_list{'a', 'b', 'c'};
  s21::list<char>::iterator iter_s21 = list.end();
  std::list<char>::iterator iter_std = std_list.end();
  iter_s21--;
  iter_std--;
  ASSERT_EQ(list.size(), std_list.size());
  for (size_t i = list.size() - 1; i > 0; i--, iter_s21--, iter_std--) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, end_string) {
  s21::list<std::string> list{"Hola", "wordl"};
  std::list<std::string> std_list{"Hola", "wordl"};
  s21::list<std::string>::iterator iter_s21 = list.end();
  std::list<std::string>::iterator iter_std = std_list.end();
  ASSERT_EQ(list.size(), std_list.size());
  for (size_t i = list.size() - 1; i > 0; i--, iter_s21--, iter_std--) {
    ASSERT_EQ(*(--iter_s21), *(--iter_std));
  }
}

TEST(list, empty_sizes_int_1) {
  s21::list<int> list;
  std::list<int> std_list;
  ASSERT_EQ(list.empty(), std_list.empty());
  ASSERT_EQ(list.size(), std_list.size());
  ASSERT_EQ(list.max_size(), std_list.max_size());
}

TEST(list, empty_sizes_int_2) {
  s21::list<int> list(2);
  std::list<int> std_list(2);
  ASSERT_EQ(list.empty(), std_list.empty());
  ASSERT_EQ(list.size(), std_list.size());
  ASSERT_EQ(list.max_size(), std_list.max_size());
}

TEST(list, empty_sizes_int_3) {
  s21::list<int> list{1, 7, 1};
  std::list<int> std_list{1, 7, 1};
  ASSERT_EQ(list.empty(), std_list.empty());
  ASSERT_EQ(list.size(), std_list.size());
  ASSERT_EQ(list.max_size(), std_list.max_size());
}

TEST(list, empty_sizes_char) {
  s21::list<char> list{'a', 'b', 'c'};
  std::list<char> std_list{'a', 'b', 'c'};
  ASSERT_EQ(list.empty(), std_list.empty());
  ASSERT_EQ(list.size(), std_list.size());
  ASSERT_EQ(list.max_size(), std_list.max_size());
}

TEST(list, empty_sizes_string) {
  s21::list<std::string> list{"Hola", "chikas"};
  std::list<std::string> std_list{"Hola", "chikas"};
  ASSERT_EQ(list.empty(), std_list.empty());
  ASSERT_EQ(list.size(), std_list.size());
  ASSERT_EQ(list.max_size(), std_list.max_size());
}

TEST(list, clear_int) {
  s21::list<int> list{1, 7, 1};
  std::list<int> std_list{1, 7, 1};
  list.clear();
  std_list.clear();
  ASSERT_EQ(list.size(), std_list.size());
}

TEST(list, clear_string) {
  s21::list<std::string> list{"Hola", "chikas"};
  std::list<std::string> std_list{"Hola", "chikas"};
  list.clear();
  std_list.clear();
  ASSERT_EQ(list.size(), std_list.size());
}

TEST(list, insert_int_1) {
  s21::list<int> list1;
  std::list<int> std_list1;
  list1.insert(list1.begin(), 100);
  std_list1.insert(std_list1.begin(), 100);
  ASSERT_EQ(list1.size(), std_list1.size());
  s21::list<int>::iterator iter_s21 = list1.begin();
  std::list<int>::iterator iter_std = std_list1.begin();
  for (size_t i = 0; i < std_list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, insert_int_2) {
  s21::list<int> list1(2);
  std::list<int> std_list1(2);
  list1.insert(list1.begin(), 100);
  std_list1.insert(std_list1.begin(), 100);
  ASSERT_EQ(list1.size(), std_list1.size());
  s21::list<int>::iterator iter_s21 = list1.begin();
  std::list<int>::iterator iter_std = std_list1.begin();
  for (size_t i = 0; i < std_list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, insert_int_3) {
  s21::list<int> list1{1, 7, 1};
  std::list<int> std_list1{1, 7, 1};
  list1.insert(list1.begin(), 100);
  std_list1.insert(std_list1.begin(), 100);
  ASSERT_EQ(list1.size(), std_list1.size());
  s21::list<int>::iterator iter_s21 = list1.begin();
  std::list<int>::iterator iter_std = std_list1.begin();
  for (size_t i = 0; i < std_list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, insert_char) {
  s21::list<char> list1{'a', 'b', 'c'};
  std::list<char> std_list1{'a', 'b', 'c'};
  list1.insert(list1.begin(), 'd');
  std_list1.insert(std_list1.begin(), 'd');
  ASSERT_EQ(list1.size(), std_list1.size());
  s21::list<char>::iterator iter_s21 = list1.begin();
  std::list<char>::iterator iter_std = std_list1.begin();
  for (size_t i = 0; i < std_list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, insert_string) {
  s21::list<std::string> list1{"new", "chikas"};
  std::list<std::string> std_list1{"new", "chikas"};
  list1.insert(list1.begin(), "Hola");
  std_list1.insert(std_list1.begin(), "Hola");
  ASSERT_EQ(list1.size(), std_list1.size());
  s21::list<std::string>::iterator iter_s21 = list1.begin();
  std::list<std::string>::iterator iter_std = std_list1.begin();
  for (size_t i = 1; i <= std_list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, erase_int) {
  s21::list<int> list1{1, 7, 1};
  std::list<int> std_list1{1, 7, 1};
  list1.erase(list1.begin());
  std_list1.erase(std_list1.begin());
  ASSERT_EQ(list1.size(), std_list1.size());
  s21::list<int>::iterator iter_s21 = list1.begin();
  std::list<int>::iterator iter_std = std_list1.begin();
  for (size_t i = 0; i < std_list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, erase_string) {
  s21::list<std::string> list1{"Hi", "dear"};
  std::list<std::string> std_list1{"Hi", "dear"};
  list1.erase(list1.begin());
  std_list1.erase(std_list1.begin());
  ASSERT_EQ(list1.size(), std_list1.size());
  s21::list<std::string>::iterator iter_s21 = list1.begin();
  std::list<std::string>::iterator iter_std = std_list1.begin();
  for (size_t i = 0; i < std_list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, erase_int_iter) {
  s21::list<int> list1{200, 100, 400};
  std::list<int> std_list1{200, 100, 400};
  list1.erase(++(++(list1.begin())));
  std_list1.erase(++(++(std_list1.begin())));
  ASSERT_EQ(list1.size(), std_list1.size());
  s21::list<int>::iterator iter_s21 = list1.begin();
  std::list<int>::iterator iter_std = std_list1.begin();
  for (size_t i = 0; i < std_list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_s21);
  }
}

TEST(list, push_back_int) {
  s21::list<int> list1;
  std::list<int> std_list1;
  list1.push_back(100);
  std_list1.push_back(100);
  ASSERT_EQ(list1.size(), std_list1.size());
  s21::list<int>::iterator iter_s21 = list1.begin();
  std::list<int>::iterator iter_std = std_list1.begin();
  for (size_t i = 0; i < std_list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, push_back_string) {
  s21::list<std::string> list1;
  std::list<std::string> std_list1;
  list1.push_back("100");
  std_list1.push_back("100");
  ASSERT_EQ(list1.size(), std_list1.size());
  s21::list<std::string>::iterator iter_s21 = list1.begin();
  std::list<std::string>::iterator iter_std = std_list1.begin();
  for (size_t i = 1; i <= std_list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, pop_back_int) {
  s21::list<int> list1{200, 100};
  std::list<int> std_list1{200, 100};
  list1.pop_back();
  std_list1.pop_back();
  ASSERT_EQ(list1.size(), std_list1.size());
  s21::list<int>::iterator iter_s21 = list1.begin();
  std::list<int>::iterator iter_std = std_list1.begin();
  for (size_t i = 0; i < std_list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, pop_back_string) {
  s21::list<std::string> list1{"200", "300"};
  std::list<std::string> std_list1{"200", "300"};
  list1.pop_back();
  std_list1.pop_back();
  ASSERT_EQ(list1.size(), std_list1.size());
  s21::list<std::string>::iterator iter_s21 = list1.begin();
  std::list<std::string>::iterator iter_std = std_list1.begin();
  for (size_t i = 1; i <= std_list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, push_front_int_1) {
  s21::list<int> list1;
  std::list<int> std_list1;
  list1.push_front(100);
  std_list1.push_front(100);
  ASSERT_EQ(list1.size(), std_list1.size());
  s21::list<int>::iterator iter_s21 = list1.begin();
  std::list<int>::iterator iter_std = std_list1.begin();
  for (size_t i = 0; i < std_list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, push_front_int_2) {
  s21::list<int> list1{1, 7};
  std::list<int> std_list1{1, 7};
  list1.push_front(100);
  std_list1.push_front(100);
  ASSERT_EQ(list1.size(), std_list1.size());
  s21::list<int>::iterator iter_s21 = list1.begin();
  std::list<int>::iterator iter_std = std_list1.begin();
  for (size_t i = 0; i < std_list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, push_front_string_1) {
  s21::list<std::string> list1;
  std::list<std::string> std_list1;
  list1.push_front("100");
  std_list1.push_front("100");
  ASSERT_EQ(list1.size(), std_list1.size());
  s21::list<std::string>::iterator iter_s21 = list1.begin();
  std::list<std::string>::iterator iter_std = std_list1.begin();
  for (size_t i = 0; i < std_list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, push_front_string_2) {
  s21::list<std::string> list1{" doolars"};
  std::list<std::string> std_list1{" doolars"};
  list1.push_front("100");
  std_list1.push_front("100");
  ASSERT_EQ(list1.size(), std_list1.size());
  s21::list<std::string>::iterator iter_s21 = list1.begin();
  std::list<std::string>::iterator iter_std = std_list1.begin();
  for (size_t i = 0; i < std_list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, pop_front_int) {
  s21::list<int> list1{200, 100};
  std::list<int> std_list1{200, 100};
  list1.pop_front();
  std_list1.pop_front();
  ASSERT_EQ(list1.size(), std_list1.size());
  s21::list<int>::iterator iter_s21 = list1.begin();
  std::list<int>::iterator iter_std = std_list1.begin();
  for (size_t i = 0; i < std_list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, pop_front_string) {
  s21::list<std::string> list1{" doolars"};
  std::list<std::string> std_list1{" doolars"};
  list1.pop_front();
  std_list1.pop_front();
  ASSERT_EQ(list1.size(), std_list1.size());
  s21::list<std::string>::iterator iter_s21 = list1.begin();
  std::list<std::string>::iterator iter_std = std_list1.begin();
  for (size_t i = 0; i < std_list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, swap_int) {
  s21::list<int> list1{200, 700};
  s21::list<int> list2{300, 100};

  std::list<int> std_list1{200, 700};
  std::list<int> std_list2{300, 100};

  list1.swap(list2);
  std_list1.swap(std_list2);

  ASSERT_EQ(list1.size(), std_list1.size());
  ASSERT_EQ(list2.size(), std_list2.size());

  s21::list<int>::iterator iter1_s21 = list1.begin();
  std::list<int>::iterator iter1_std = std_list1.begin();
  for (size_t i = 0; i < std_list1.size(); i++, iter1_s21++, iter1_std++) {
    ASSERT_EQ(*iter1_s21, *iter1_std);
  }

  s21::list<int>::iterator iter2_s21 = list2.begin();
  std::list<int>::iterator iter2_std = std_list2.begin();
  for (size_t i = 0; i < std_list2.size(); i++, iter2_s21++, iter2_std++) {
    ASSERT_EQ(*iter2_s21, *iter2_std);
  }
}

TEST(list, swap_string) {
  s21::list<std::string> list1{"200", "200"};
  s21::list<std::string> list2{"300", "300", "400"};

  std::list<std::string> std_list1{"200", "200"};
  std::list<std::string> std_list2{"300", "300", "400"};

  list1.swap(list2);
  std_list1.swap(std_list2);

  ASSERT_EQ(list1.size(), std_list1.size());
  ASSERT_EQ(list2.size(), std_list2.size());

  s21::list<std::string>::iterator iter1_s21 = list1.begin();
  std::list<std::string>::iterator iter1_std = std_list1.begin();
  for (size_t i = 0; i < std_list1.size(); i++, iter1_s21++, iter1_std++) {
    ASSERT_EQ(*iter1_s21, *iter1_std);
  }

  s21::list<std::string>::iterator iter2_s21 = list2.begin();
  std::list<std::string>::iterator iter2_std = std_list2.begin();
  for (size_t i = 0; i < std_list2.size(); i++, iter2_s21++, iter2_std++) {
    ASSERT_EQ(*iter2_s21, *iter2_std);
  }
}

TEST(list, merge_int_1) {
  s21::list<int> list1{1000, 70, 700, 1000, 100, 5007};
  s21::list<int> list2{1001, 701, 75, 100, 1005, 500};
  std::list<int> std_list1{1000, 70, 700, 1000, 100, 5007};
  std::list<int> std_list2{1001, 701, 75, 100, 1005, 500};
  list1.merge(list2);
  std_list1.merge(std_list2);
  ASSERT_EQ(list1.size(), std_list1.size());
  s21::list<int>::iterator iter_s21 = list1.begin();
  std::list<int>::iterator iter_std = std_list1.begin();
  for (size_t i = 0; i < std_list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, merge_int_2) {
  s21::list<int> list1{1, 7, 1, 4, 5, 6};
  s21::list<int> list2{6, 5, 4, 1, 7, 1};
  std::list<int> std_list1{1, 7, 1, 4, 5, 6};
  std::list<int> std_list2{6, 5, 4, 1, 7, 1};
  list1.merge(list2);
  std_list1.merge(std_list2);
  ASSERT_EQ(list1.size(), std_list1.size());
  s21::list<int>::iterator iter_s21 = list1.begin();
  std::list<int>::iterator iter_std = std_list1.begin();
  for (size_t i = 0; i < std_list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, merge_string_1) {
  s21::list<std::string> list1{"London", "is the capital", "of Great",
                               "Britain"};
  s21::list<std::string> list2{"Can You", "Repeat", "please"};
  std::list<std::string> std_list1{"London", "is the capital", "of Great",
                                   "Britain"};
  std::list<std::string> std_list2{"Can You", "Repeat", "please"};
  list1.merge(list2);
  std_list1.merge(std_list2);
  ASSERT_EQ(list1.size(), std_list1.size());
  s21::list<std::string>::iterator iter_s21 = list1.begin();
  std::list<std::string>::iterator iter_std = std_list1.begin();
  for (size_t i = 0; i < std_list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, splice_int) {
  s21::list<int> list1{100, 700, 100, 400};
  s21::list<int> list2{111, 722, 133, 444};
  std::list<int> std_list1{100, 700, 100, 400};
  std::list<int> std_list2{111, 722, 133, 444};

  s21::list<int>::const_iterator iter1_s21 = list1.cbegin();
  std::list<int>::iterator iter2_std = std_list1.begin();

  list1.splice(iter1_s21, list2);
  std_list1.splice(iter2_std, std_list2);

  ASSERT_EQ(list1.size(), std_list1.size());
  s21::list<int>::iterator iter_s21 = list1.begin();
  std::list<int>::iterator iter_std = std_list1.begin();
  for (size_t i = 0; i < std_list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, splice_string) {
  s21::list<std::string> list1{"London", "is the capital", "of Great",
                               "Britain"};
  s21::list<std::string> list2{"Can You", "Repeat", "please"};
  std::list<std::string> std_list1{"London", "is the capital", "of Great",
                                   "Britain"};
  std::list<std::string> std_list2{"Can You", "Repeat", "please"};

  s21::list<std::string>::const_iterator iter1_s21;
  iter1_s21 = list1.cbegin();
  std::list<std::string>::iterator iter2_std = std_list1.begin();

  list1.splice(iter1_s21, list2);
  std_list1.splice(iter2_std, std_list2);

  ASSERT_EQ(*iter1_s21, *iter2_std);
  ASSERT_EQ(list1.size(), std_list1.size());
  s21::list<std::string>::iterator iter_s21 = list1.begin();
  std::list<std::string>::iterator iter_std = std_list1.begin();
  for (size_t i = 0; i < std_list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, reverse_int) {
  s21::list<int> list1{1, 7, 1, 4, 5};
  std::list<int> std_list1{1, 7, 1, 4, 5};
  list1.reverse();
  std_list1.reverse();
  ASSERT_EQ(list1.size(), std_list1.size());
  s21::list<int>::iterator iter_s21 = list1.begin();
  std::list<int>::iterator iter_std = std_list1.begin();
  for (size_t i = 0; i < std_list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, reverse_string) {
  s21::list<std::string> list1{"London", "is the capital", "of Great",
                               "Britain"};
  std::list<std::string> std_list1{"London", "is the capital", "of Great",
                                   "Britain"};
  list1.reverse();
  std_list1.reverse();
  ASSERT_EQ(list1.size(), std_list1.size());
  s21::list<std::string>::iterator iter_s21 = list1.begin();
  std::list<std::string>::iterator iter_std = std_list1.begin();
  for (size_t i = 0; i < std_list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, unique_int) {
  s21::list<int> list1{100, 700, 700, 100, 100, 500};
  std::list<int> std_list1{100, 700, 700, 100, 100, 500};
  list1.unique();
  std_list1.unique();
  ASSERT_EQ(list1.size(), std_list1.size());
  s21::list<int>::iterator iter_s21 = list1.begin();
  std::list<int>::iterator iter_std = std_list1.begin();
  for (size_t i = 0; i < std_list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, unique_string) {
  s21::list<std::string> list1{"London",   "London",  "is the capital",
                               "of Great", "Britain", "London",
                               "London"};
  std::list<std::string> std_list1{"London",   "London",  "is the capital",
                                   "of Great", "Britain", "London",
                                   "London"};
  list1.unique();
  std_list1.unique();
  ASSERT_EQ(list1.size(), std_list1.size());
  s21::list<std::string>::iterator iter_s21 = list1.begin();
  std::list<std::string>::iterator iter_std = std_list1.begin();
  for (size_t i = 0; i < std_list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, sort_int) {
  s21::list<int> list1{1000, 70, 700, 1000, 100, 500};
  std::list<int> std_list1{1000, 70, 700, 1000, 100, 500};
  list1.sort();
  std_list1.sort();
  ASSERT_EQ(list1.size(), std_list1.size());
  s21::list<int>::iterator iter_s21;
  iter_s21 = list1.begin();
  std::list<int>::iterator iter_std = std_list1.begin();
  for (size_t i = 0; i < std_list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, sort_string) {
  s21::list<std::string> list1{"London",   "London",  "is the capital",
                               "of Great", "Britain", "London",
                               "London"};
  std::list<std::string> std_list1{"London",   "London",  "is the capital",
                                   "of Great", "Britain", "London",
                                   "London"};
  list1.sort();
  std_list1.sort();
  ASSERT_EQ(list1.size(), std_list1.size());
  s21::list<std::string>::iterator iter_s21 = list1.begin();
  std::list<std::string>::iterator iter_std = std_list1.begin();
  for (size_t i = 0; i < std_list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, class_list_int) {
  s21::list<int> list1;
  s21::list<s21::list<int>> list_class;
  std::list<int> std_list;
  std::list<std::list<int>> std_list_class;

  list_class.push_back(list1);
  std_list_class.push_back(std_list);
  ASSERT_EQ(list1.size(), std_list.size());
  s21::list<int>::iterator iter_s21 = list1.begin();
  std::list<int>::iterator iter_std = std_list.begin();
  for (size_t i = 0; i < list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

// ДОПОЛНИТЕЛЬНО

TEST(list, insert_many_int) {
  s21::list<int> list1;
  list1.insert_many(list1.cbegin(), 1, 7, 1);
  std::list<int> std_list;
  std_list.insert(std_list.cbegin(), {1, 7, 1});

  ASSERT_EQ(list1.size(), std_list.size());
  s21::list<int>::iterator iter_s21 = list1.begin();
  std::list<int>::iterator iter_std = std_list.begin();
  for (size_t i = 0; i < list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, insert_many_string) {
  s21::list<std::string> list1{"Hi"};
  list1.insert_many(list1.cbegin(), "Hola", "chikas");
  std::list<std::string> std_list{"Hi"};
  std_list.insert(std_list.cbegin(), {"Hola", "chikas"});

  ASSERT_EQ(list1.size(), std_list.size());
  s21::list<std::string>::iterator iter_s21 = list1.begin();
  std::list<std::string>::iterator iter_std = std_list.begin();
  for (size_t i = 0; i < list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, insert_many_back_int) {
  s21::list<int> list1{1, 7, 1};
  list1.insert_many_back(4, 5, 6);
  std::list<int> std_list{1, 7, 1};
  std_list.insert(std_list.cend(), {4, 5, 6});

  ASSERT_EQ(list1.size(), std_list.size());
  s21::list<int>::iterator iter_s21 = list1.begin();
  std::list<int>::iterator iter_std = std_list.begin();
  for (size_t i = 0; i < list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, insert_many_back_string) {
  s21::list<std::string> list1{"Hi"};
  list1.insert_many_back("Hola", "chikas");
  std::list<std::string> std_list{"Hi"};
  std_list.insert(std_list.cend(), {"Hola", "chikas"});

  ASSERT_EQ(list1.size(), std_list.size());
  s21::list<std::string>::iterator iter_s21 = list1.begin();
  std::list<std::string>::iterator iter_std = std_list.begin();
  for (size_t i = 0; i < list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, insert_many_front_int) {
  s21::list<int> list1{1, 7, 1};
  list1.insert_many_front(4, 5, 6);
  std::list<int> std_list{4, 5, 6, 1, 7, 1};

  ASSERT_EQ(list1.size(), std_list.size());
  s21::list<int>::iterator iter_s21 = list1.begin();
  std::list<int>::iterator iter_std = std_list.begin();
  for (size_t i = 0; i < list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}

TEST(list, insert_many_front_string) {
  s21::list<std::string> list1{"Hi"};
  list1.insert_many_front("Hola", "chikas");
  std::list<std::string> std_list{"Hola", "chikas", "Hi"};

  ASSERT_EQ(list1.size(), std_list.size());
  s21::list<std::string>::iterator iter_s21 = list1.begin();
  std::list<std::string>::iterator iter_std = std_list.begin();
  for (size_t i = 0; i < list1.size(); i++, iter_s21++, iter_std++) {
    ASSERT_EQ(*iter_s21, *iter_std);
  }
}