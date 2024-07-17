#include <gtest/gtest.h>

#include <set>

#include "../set/s21_set.h"

bool SetsEqual(s21::Set<int> S1, std::set<int> S2) {
  if (S1.size() != S2.size()) return false;
  auto it_S1 = S1.begin();
  auto it_S2 = S2.begin();
  for (; it_S2 != S2.end(); ++it_S1, ++it_S2) {
    if (*it_S1 != *it_S2) return false;
  }
  return true;
}

TEST(Set, default_constructor) {
  s21::Set<int> S1;
  std::set<int> S2;
  ASSERT_EQ(SetsEqual(S1, S2), true);
  ASSERT_EQ(S1.size(), S2.size());
}

TEST(Set, list_initialized) {
  s21::Set<int> S1 = {1, 2, 3};
  std::set<int> S2 = {1, 2, 3};
  ASSERT_EQ(SetsEqual(S1, S2), true);
  ASSERT_EQ(S1.size(), S2.size());
}

TEST(Set, copy_constructor) {
  s21::Set<int> S1 = {1, 2, 3};
  s21::Set<int> S2(S1);
  std::set<int> S3 = {1, 2, 3};
  std::set<int> S4(S3);
  ASSERT_EQ(SetsEqual(S2, S4), true);
  ASSERT_EQ(SetsEqual(S1, S3), true);
  ASSERT_EQ(S1.size(), S3.size());
  ASSERT_EQ(S2.size(), S4.size());
}

TEST(Set, move_constructor) {
  s21::Set<int> S1 = {1, 2, 3};
  s21::Set<int> S2(std::move(S1));
  std::set<int> S3 = {1, 2, 3};
  std::set<int> S4(std::move(S3));
  ASSERT_EQ(SetsEqual(S2, S4), true);
  ASSERT_EQ(SetsEqual(S1, S3), true);
  ASSERT_EQ(S1.size(), S3.size());
  ASSERT_EQ(S2.size(), S4.size());
}

TEST(Set, move_operator) {
  s21::Set<int> S1 = {1, 2, 3};
  s21::Set<int> S2;
  S2 = std::move(S1);
  std::set<int> S3 = {1, 2, 3};
  std::set<int> S4;
  S4 = std::move(S3);
  ASSERT_EQ(SetsEqual(S2, S4), true);
  ASSERT_EQ(SetsEqual(S1, S3), true);
  ASSERT_EQ(S1.size(), S3.size());
  ASSERT_EQ(S2.size(), S4.size());
}

TEST(Set, copy_operator) {
  s21::Set<int> S1 = {1, 2, 3};
  s21::Set<int> S2;
  S2 = S1;
  std::set<int> S3 = {1, 2, 3};
  std::set<int> S4;
  S4 = S3;
  ASSERT_EQ(SetsEqual(S2, S4), true);
  ASSERT_EQ(SetsEqual(S1, S3), true);
  ASSERT_EQ(S1.size(), S3.size());
  ASSERT_EQ(S2.size(), S4.size());
}

TEST(Set, iterator_begin) {
  s21::Set<int> S1{1, 2, 3};
  std::set<int> S2{1, 2, 3};
  s21::Set<int>::iterator iter1 = S1.begin();
  std::set<int>::iterator iter2 = S2.begin();
  for (; iter1 != nullptr; iter1++, iter2++) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(Set, iterator_cbegin) {
  s21::Set<int> S1{1, 2, 3};
  std::set<int> S2{1, 2, 3};
  s21::Set<int>::const_iterator iter1 = S1.cbegin();
  std::set<int>::iterator iter2 = S2.cbegin();
  for (; iter1 != nullptr; iter1++, iter2++) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(Set, iterator_end) {
  s21::Set<int> S1{1, 2, 3};
  s21::Set<int>::iterator iter1 = S1.end();
  ASSERT_EQ(*iter1, 0);
}

TEST(Set, iterator_cend) {
  s21::Set<int> S1{1, 2, 3};
  s21::Set<int>::const_iterator iter1 = S1.cend();
  ASSERT_EQ(*iter1, 0);
}

TEST(Set, empty) {
  s21::Set<int> S1{1, 2, 3};
  std::set<int> S2{1, 2, 3};
  ASSERT_EQ(S1.empty(), S2.empty());
}

TEST(Set, size) {
  s21::Set<int> S1{1, 2, 3};
  std::set<int> S2{1, 2, 3};
  ASSERT_EQ(S1.size(), S2.size());
}

TEST(Set, clear) {
  s21::Set<int> S1{1, 2, 3};
  std::set<int> S2{1, 2, 3};
  S1.clear();
  S2.clear();
  ASSERT_EQ(S1.size(), S2.size());
}

TEST(Set, insert) {
  s21::Set<int> S1{1, 2, 3};
  std::set<int> S2{1, 2, 3};
  S1.insert(5);
  S2.insert(5);
  s21::Set<int>::iterator iter1 = S1.begin();
  std::set<int>::iterator iter2 = S2.begin();
  for (; iter1 != nullptr; iter1++, iter2++) {
    ASSERT_EQ(*iter1, *iter2);
  }
  ASSERT_EQ(S1.size(), S2.size());
}

TEST(Set, erase) {
  s21::Set<int> S1{1, 2, 3};
  std::set<int> S2{1, 2, 3};
  s21::Set<int>::iterator iter1 = S1.begin();
  std::set<int>::iterator iter2 = S2.begin();
  S1.erase(++iter1);
  S2.erase(++iter2);
  iter1 = S1.begin();
  iter2 = S2.begin();
  for (; iter1 != nullptr; iter1++, iter2++) {
    ASSERT_EQ(*iter1, *iter2);
  }
  ASSERT_EQ(S1.size(), S2.size());
}

TEST(Set, swap) {
  s21::Set<int> S1{1, 2, 3};
  s21::Set<int> S2{1};
  std::set<int> S3{1, 2, 3};
  std::set<int> S4{1};
  S1.swap(S2);
  S3.swap(S4);
  s21::Set<int>::iterator iter1 = S1.begin();
  std::set<int>::iterator iter2 = S3.begin();
  for (; iter1 != nullptr; iter1++, iter2++) {
    ASSERT_EQ(*iter1, *iter2);
  }
  s21::Set<int>::iterator iter3 = S2.begin();
  std::set<int>::iterator iter4 = S4.begin();
  for (; iter3 != nullptr; iter3++, iter4++) {
    ASSERT_EQ(*iter3, *iter4);
  }
  ASSERT_EQ(S1.size(), S3.size());
  ASSERT_EQ(S2.size(), S4.size());
}

TEST(Set, merge) {
  s21::Set<int> S1{1, 2, 3};
  s21::Set<int> S2{1, 4, 5};
  std::set<int> S3{1, 2, 3};
  std::set<int> S4{1, 4, 5};
  S1.merge(S2);
  S3.merge(S4);
  s21::Set<int>::iterator iter1 = S1.begin();
  std::set<int>::iterator iter2 = S3.begin();
  for (; iter1 != nullptr; iter1++, iter2++) {
    ASSERT_EQ(*iter1, *iter2);
  }
  s21::Set<int>::iterator iter3 = S2.begin();
  std::set<int>::iterator iter4 = S4.begin();
  for (size_t i = 0; i < S2.size(); i++, iter3++, iter4++) {
    ASSERT_EQ(*iter3, *iter4);
  }
  ASSERT_EQ(S1.size(), S3.size());
  ASSERT_EQ(S2.size(), S4.size());
}

TEST(Set, find) {
  s21::Set<int> S1{1, 2, 3};
  std::set<int> S2{1, 2, 3};
  s21::Set<int>::const_iterator iter1 = S1.find(2);
  std::set<int>::iterator iter2 = S2.find(2);

  ASSERT_EQ(*iter1, *iter2);
  ASSERT_EQ(S1.size(), S2.size());
}

TEST(Set, contatins) {
  s21::Set<int> S1{1, 2, 3};
  bool b1 = S1.contains(2);
  bool b2 = S1.contains(4);

  ASSERT_EQ(b1, 1);
  ASSERT_EQ(b2, 0);
}

TEST(Set, insert_many) {
  s21::Set<int> S1{1, 2, 3};
  std::set<int> S2{1, 2, 3};
  S1.insert_many(3, 4, 5);
  S2.insert({3, 4, 5});
  s21::Set<int>::iterator iter1 = S1.begin();
  std::set<int>::iterator iter2 = S2.begin();
  for (; iter1 != nullptr; iter1++, iter2++) {
    ASSERT_EQ(*iter1, *iter2);
  }
  ASSERT_EQ(S1.size(), S2.size());
}

TEST(Set, max_size) {
  s21::Set<int> S1 = {1, 2, 3};
  std::set<int> S2 = {1, 2, 3};
  EXPECT_NEAR(S1.max_size() / S2.max_size(), 1, 1);
}
