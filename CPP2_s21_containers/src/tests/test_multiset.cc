#include <gtest/gtest.h>

#include <set>

#include "../multiset/s21_multiset.h"

bool MultisetsEqual(s21::Multiset<int> S1, std::multiset<int> S2) {
  if (S1.size() != S2.size()) return false;
  auto it_S1 = S1.begin();
  auto it_S2 = S2.begin();
  for (; it_S2 != S2.end(); ++it_S1, ++it_S2) {
    if (*it_S1 != *it_S2) return false;
  }
  return true;
}

TEST(Multiset, default_constructor) {
  s21::Multiset<int> S1;
  std::multiset<int> S2;
  ASSERT_EQ(MultisetsEqual(S1, S2), true);
  ASSERT_EQ(S1.size(), S2.size());
}

TEST(Multiset, list_initialized) {
  s21::Multiset<int> S1 = {1, 2, 3};
  std::multiset<int> S2 = {1, 2, 3};
  ASSERT_EQ(MultisetsEqual(S1, S2), true);
  ASSERT_EQ(S1.size(), S2.size());
}

TEST(Multiset, copy_constructor) {
  s21::Multiset<int> S1 = {1, 2, 3};
  s21::Multiset<int> S2(S1);
  std::multiset<int> S3 = {1, 2, 3};
  std::multiset<int> S4(S3);
  ASSERT_EQ(MultisetsEqual(S2, S4), true);
  ASSERT_EQ(MultisetsEqual(S1, S3), true);
  ASSERT_EQ(S1.size(), S3.size());
  ASSERT_EQ(S2.size(), S4.size());
}

TEST(Multiset, move_constructor) {
  s21::Multiset<int> S1 = {1, 2, 3};
  s21::Multiset<int> S2(std::move(S1));
  std::multiset<int> S3 = {1, 2, 3};
  std::multiset<int> S4(std::move(S3));
  ASSERT_EQ(MultisetsEqual(S2, S4), true);
  ASSERT_EQ(MultisetsEqual(S1, S3), true);
  ASSERT_EQ(S1.size(), S3.size());
  ASSERT_EQ(S2.size(), S4.size());
}

TEST(Multiset, move_operator) {
  s21::Multiset<int> S1 = {1, 2, 3};
  s21::Multiset<int> S2;
  S2 = std::move(S1);
  std::multiset<int> S3 = {1, 2, 3};
  std::multiset<int> S4;
  S4 = std::move(S3);
  ASSERT_EQ(MultisetsEqual(S2, S4), true);
  ASSERT_EQ(MultisetsEqual(S1, S3), true);
  ASSERT_EQ(S1.size(), S3.size());
  ASSERT_EQ(S2.size(), S4.size());
}

TEST(Multiset, copy_operator) {
  s21::Multiset<int> S1 = {1, 2, 3};
  s21::Multiset<int> S2;
  S2 = S1;
  std::multiset<int> S3 = {1, 2, 3};
  std::multiset<int> S4;
  S4 = S3;
  ASSERT_EQ(MultisetsEqual(S2, S4), true);
  ASSERT_EQ(MultisetsEqual(S1, S3), true);
  ASSERT_EQ(S1.size(), S3.size());
  ASSERT_EQ(S2.size(), S4.size());
}

TEST(Multiset, iterator_begin) {
  s21::Multiset<int> S1{1, 2, 3};
  std::multiset<int> S2{1, 2, 3};
  s21::Multiset<int>::iterator iter1 = S1.begin();
  std::multiset<int>::iterator iter2 = S2.begin();
  for (; iter1 != nullptr; iter1++, iter2++) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(Multiset, iterator_cbegin) {
  s21::Multiset<int> S1{1, 2, 3};
  std::multiset<int> S2{1, 2, 3};
  s21::Multiset<int>::const_iterator iter1 = S1.cbegin();
  std::multiset<int>::iterator iter2 = S2.cbegin();
  for (; iter1 != nullptr; iter1++, iter2++) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(Multiset, iterator_end) {
  s21::Multiset<int> S1{1, 2, 3};
  s21::Multiset<int>::iterator iter1 = S1.end();
  ASSERT_EQ(*iter1, 0);
}

TEST(Multiset, iterator_cend) {
  s21::Multiset<int> S1{1, 2, 3};
  s21::Multiset<int>::const_iterator iter1 = S1.cend();
  ASSERT_EQ(*iter1, 0);
}

TEST(Multiset, empty) {
  s21::Multiset<int> S1{1, 2, 3};
  std::multiset<int> S2{1, 2, 3};
  ASSERT_EQ(S1.empty(), S2.empty());
}

TEST(Multiset, size) {
  s21::Multiset<int> S1{1, 2, 3};
  std::multiset<int> S2{1, 2, 3};
  ASSERT_EQ(S1.size(), S2.size());
}

TEST(Multiset, clear) {
  s21::Multiset<int> S1{1, 2, 3};
  std::multiset<int> S2{1, 2, 3};
  S1.clear();
  S2.clear();
  ASSERT_EQ(S1.size(), S2.size());
}

TEST(Multiset, insert) {
  s21::Multiset<int> S1{1, 2, 3};
  std::multiset<int> S2{1, 2, 3};
  S1.insert(5);
  S2.insert(5);
  s21::Multiset<int>::iterator iter1 = S1.begin();
  std::multiset<int>::iterator iter2 = S2.begin();
  for (; iter1 != nullptr; iter1++, iter2++) {
    ASSERT_EQ(*iter1, *iter2);
  }
  ASSERT_EQ(S1.size(), S2.size());
}

TEST(Multiset, erase) {
  s21::Multiset<int> S1{1, 2, 3};
  std::multiset<int> S2{1, 2, 3};
  s21::Multiset<int>::iterator iter1 = S1.begin();
  std::multiset<int>::iterator iter2 = S2.begin();
  S1.erase(++iter1);
  S2.erase(++iter2);
  iter1 = S1.begin();
  iter2 = S2.begin();
  for (; iter1 != nullptr; iter1++, iter2++) {
    ASSERT_EQ(*iter1, *iter2);
  }
  ASSERT_EQ(S1.size(), S2.size());
}

TEST(Multiset, swap) {
  s21::Multiset<int> S1{1, 2, 3};
  s21::Multiset<int> S2{1};
  std::multiset<int> S3{1, 2, 3};
  std::multiset<int> S4{1};
  S1.swap(S2);
  S3.swap(S4);
  s21::Multiset<int>::iterator iter1 = S1.begin();
  std::multiset<int>::iterator iter2 = S3.begin();
  for (; iter1 != nullptr; iter1++, iter2++) {
    ASSERT_EQ(*iter1, *iter2);
  }
  s21::Multiset<int>::iterator iter3 = S2.begin();
  std::multiset<int>::iterator iter4 = S4.begin();
  for (; iter3 != nullptr; iter3++, iter4++) {
    ASSERT_EQ(*iter3, *iter4);
  }
  ASSERT_EQ(S1.size(), S3.size());
  ASSERT_EQ(S2.size(), S4.size());
}

TEST(Multiset, merge) {
  s21::Multiset<int> S1{1, 2, 3};
  s21::Multiset<int> S2{1, 4, 5};
  std::multiset<int> S3{1, 2, 3};
  std::multiset<int> S4{1, 4, 5};
  S1.merge(S2);
  S3.merge(S4);
  s21::Multiset<int>::iterator iter1 = S1.begin();
  std::multiset<int>::iterator iter2 = S3.begin();
  for (; iter1 != nullptr; iter1++, iter2++) {
    ASSERT_EQ(*iter1, *iter2);
  }
  s21::Multiset<int>::iterator iter3 = S2.begin();
  std::multiset<int>::iterator iter4 = S4.begin();
  for (size_t i = 0; i < S2.size(); i++, iter3++, iter4++) {
    ASSERT_EQ(*iter3, *iter4);
  }
  ASSERT_EQ(S1.size(), S3.size());
  ASSERT_EQ(S2.size(), S4.size());
}

TEST(Multiset, find) {
  s21::Multiset<int> S1{1, 2, 3};
  std::multiset<int> S2{1, 2, 3};
  s21::Multiset<int>::const_iterator iter1 = S1.find(2);
  std::multiset<int>::iterator iter2 = S2.find(2);

  ASSERT_EQ(*iter1, *iter2);
  ASSERT_EQ(S1.size(), S2.size());
}

TEST(Multiset, contatins) {
  s21::Multiset<int> S1{1, 2, 3};
  bool b1 = S1.contains(2);
  bool b2 = S1.contains(4);

  ASSERT_EQ(b1, 1);
  ASSERT_EQ(b2, 0);
}

TEST(Multiset, insert_many) {
  s21::Multiset<int> S1{1, 2, 3};
  std::multiset<int> S2{1, 2, 3};
  S1.insert_many(3, 4, 5);
  S2.insert({3, 4, 5});
  s21::Multiset<int>::iterator iter1 = S1.begin();
  std::multiset<int>::iterator iter2 = S2.begin();
  for (; iter1 != nullptr; iter1++, iter2++) {
    ASSERT_EQ(*iter1, *iter2);
  }
  ASSERT_EQ(S1.size(), S2.size());
}

TEST(Multiset, max_size) {
  s21::Multiset<int> S1 = {1, 2, 3};
  std::multiset<int> S2 = {1, 2, 3};
  EXPECT_NEAR(S1.max_size() / S2.max_size(), 1, 1);
}
