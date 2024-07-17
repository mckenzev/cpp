#include <gtest/gtest.h>

#include <map>

#include "../map/s21_map.h"

bool MapsEqual(s21::Map<int, char> M1, std::map<int, char> M2) {
  if (M1.size() != M2.size()) return false;
  s21::Map<int, char>::iterator it_M1 = M1.begin();
  std::map<int, char>::iterator it_M2 = M2.begin();
  for (; it_M2 != M2.end(); ++it_M1, ++it_M2) {
    if (*it_M1 != *it_M2) return false;
  }
  return true;
}

void PrintM1(s21::Map<int, char> M1) {
  s21::Map<int, char>::iterator it_M1 = M1.begin();
  std::cout << std::endl;
  for (; it_M1 != M1.end(); ++it_M1) {
    std::cout << (*it_M1).first << " " << (*it_M1).second << std::endl;
  }
  std::cout << std::endl;
}

void PrintM2(std::map<int, char> M2) {
  std::map<int, char>::iterator it_M2 = M2.begin();
  std::cout << std::endl;
  for (; it_M2 != M2.end(); ++it_M2) {
    std::cout << (*it_M2).first << " " << (*it_M2).second << std::endl;
  }
  std::cout << std::endl;
}

TEST(Map, default_constructor) {
  s21::Map<int, char> M1;
  std::map<int, char> M2;
  ASSERT_EQ(MapsEqual(M1, M2), true);
}

TEST(Map, list_initialized) {
  s21::Map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  ASSERT_EQ(MapsEqual(M1, M2), true);
}

TEST(Map, copy_constructor) {
  s21::Map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::Map<int, char> M2(M1);
  std::map<int, char> M3 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M4(M3);
  ASSERT_EQ(MapsEqual(M2, M4), true);
  ASSERT_EQ(MapsEqual(M1, M3), true);
}

TEST(Map, move_constructor) {
  s21::Map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::Map<int, char> M2(std::move(M1));
  std::map<int, char> M3 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M4(std::move(M3));
  ASSERT_EQ(MapsEqual(M2, M4), true);
  ASSERT_EQ(MapsEqual(M1, M3), true);
}

TEST(Map, move_operator) {
  s21::Map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::Map<int, char> M2;
  M2 = std::move(M1);
  std::map<int, char> M3 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M4;
  M4 = std::move(M3);
  ASSERT_EQ(MapsEqual(M2, M4), true);
  ASSERT_EQ(MapsEqual(M1, M3), true);
}

TEST(Map, copy_operator) {
  s21::Map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::Map<int, char> M2;
  M2 = M1;
  std::map<int, char> M3 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M4;
  M4 = M3;
  ASSERT_EQ(MapsEqual(M2, M4), true);
  ASSERT_EQ(MapsEqual(M1, M3), true);
}

TEST(Map, at1) {
  const s21::Map<int, char> M1 = {{3, 'a'}, {2, 'b'}, {1, 'c'}};
  std::map<int, char> M2 = {{3, 'a'}, {2, 'b'}, {1, 'c'}};
  ASSERT_EQ(M1.at(2), M2.at(2));
}

TEST(Map, at2) {
  s21::Map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  ASSERT_EQ(M1.at(2), M2.at(2));
}

// TEST(Map, at3) {
//   s21::Map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
//   std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
//   ASSERT_THROW(M2.at(36), std::out_of_range);
//   ASSERT_THROW(M1.at(36), std::out_of_range);
// }

TEST(Map, at4) {
  s21::Map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  M1.at(2) = 'q';
  M2.at(2) = 'q';
  ASSERT_EQ(MapsEqual(M1, M2), true);
}

// TEST(Map, at5) {
//   const s21::Map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
//   std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
//   ASSERT_THROW(M2.at(36), std::out_of_range);
//   ASSERT_THROW(M1.at(36), std::out_of_range);
// }

TEST(Map, operator_bracket1) {
  s21::Map<int, char> M1 = {{3, 'a'}, {2, 'b'}, {1, 'c'}};
  std::map<int, char> M2 = {{3, 'a'}, {2, 'b'}, {1, 'c'}};
  ASSERT_EQ(M1[2], M2[2]);
}

TEST(Map, operator_bracket2) {
  const s21::Map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  ASSERT_EQ(M1[2], M2[2]);
}

TEST(Map, operator_bracket3) {
  s21::Map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  M1[2] = 'q';
  M2[2] = 'q';
  ASSERT_EQ(MapsEqual(M1, M2), true);
}

TEST(Map, iterator_begin) {
  s21::Map<int, std::string> M1{{1, "Hi"}, {2, "Hello"}, {3, "Good"}};
  std::map<int, std::string> M2{{1, "Hi"}, {2, "Hello"}, {3, "Good"}};
  s21::Map<int, std::string>::iterator iter1 = M1.begin();
  std::map<int, std::string>::iterator iter2 = M2.begin();
  for (; iter1 != nullptr; iter1++, iter2++) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(Map, iterator_cbegin) {
  s21::Map<int, std::string> M1{{1, "Hi"}, {2, "Hello"}, {3, "Good"}};
  std::map<int, std::string> M2{{1, "Hi"}, {2, "Hello"}, {3, "Good"}};
  s21::Map<int, std::string>::const_iterator iter1 = M1.cbegin();
  std::map<int, std::string>::iterator iter2 = M2.begin();
  for (; iter1 != nullptr; iter1++, iter2++) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(Map, iterator_end) {
  s21::Map<int, std::string> M1{{1, "Hi"}, {2, "Hello"}, {3, "Good"}};
  s21::Map<int, std::string>::iterator iter1 = M1.end();
  ASSERT_EQ(iter1.unit->data.first, 0);
}

TEST(Map, iterator_cend) {
  s21::Map<int, std::string> M1{{1, "Hi"}, {2, "Hello"}, {3, "Good"}};
  s21::Map<int, std::string>::const_iterator iter1 = M1.cend();
  ASSERT_EQ(iter1.unit->data.first, 0);
}

TEST(Map, empty) {
  s21::Map<int, std::string> M1{{1, "Hi"}, {2, "Hello"}, {3, "Good"}};
  std::map<int, std::string> M2{{1, "Hi"}, {2, "Hello"}, {3, "Good"}};
  ASSERT_EQ(M1.empty(), M2.empty());
}

TEST(Map, size) {
  s21::Map<int, std::string> M1{{1, "Hi"}, {2, "Hello"}, {3, "Good"}};
  std::map<int, std::string> M2{{1, "Hi"}, {2, "Hello"}, {3, "Good"}};
  ASSERT_EQ(M1.size(), M2.size());
}

TEST(Map, clear) {
  s21::Map<int, std::string> M1{{1, "Hi"}, {2, "Hello"}, {3, "Good"}};
  std::map<int, std::string> M2{{1, "Hi"}, {2, "Hello"}, {3, "Good"}};
  M1.clear();
  M2.clear();
  ASSERT_EQ(M1.size(), M2.size());
}

TEST(Map, insert1) {
  s21::Map<int, std::string> M1{{1, "Hi"}, {2, "Hello"}, {3, "Good"}};
  std::map<int, std::string> M2{{1, "Hi"}, {2, "Hello"}, {3, "Good"}};
  std::pair<const int, std::string> pair(4, "Hi");
  M1.insert(pair);
  M2.insert(pair);
  s21::Map<int, std::string>::iterator iter1 = M1.begin();
  std::map<int, std::string>::iterator iter2 = M2.begin();
  for (; iter1 != nullptr; iter1++, iter2++) {
    ASSERT_EQ(*iter1, *iter2);
  }
  ASSERT_EQ(M1.size(), M2.size());
}

TEST(Map, insert2) {
  s21::Map<int, std::string> M1{{1, "Hi"}, {2, "Hello"}, {3, "Good"}};
  std::map<int, std::string> M2{{1, "Hi"}, {2, "Hello"}, {3, "Good"}};
  M1.insert(4, "Hi");
  M2.insert({4, "Hi"});
  s21::Map<int, std::string>::iterator iter1 = M1.begin();
  std::map<int, std::string>::iterator iter2 = M2.begin();
  for (; iter1 != nullptr; iter1++, iter2++) {
    ASSERT_EQ(*iter1, *iter2);
  }
  ASSERT_EQ(M1.size(), M2.size());
}

TEST(Map, insert_or_assign) {
  s21::Map<int, std::string> M1{{1, "Hi"}, {2, "Hello"}, {3, "Good"}};
  std::pair<s21::Map<int, std::string>::iterator, bool> iter1 =
      M1.insert_or_assign(4, "Hi");
  std::pair<s21::Map<int, std::string>::iterator, bool> iter2 =
      M1.insert_or_assign(1, "Hello");
  std::pair<const int, std::string> pair1(1, "Hello");
  std::pair<const int, std::string> pair2(2, "Hello");
  std::pair<const int, std::string> pair3(3, "Good");
  std::pair<const int, std::string> pair4(4, "Hi");
  ASSERT_EQ(M1.at(1), pair1.second);
  ASSERT_EQ(M1.at(2), pair2.second);
  ASSERT_EQ(M1.at(3), pair3.second);
  ASSERT_EQ(M1.at(4), pair4.second);
  ASSERT_EQ(iter1.second, 1);
  ASSERT_EQ(iter2.second, 0);
  ASSERT_EQ(M1.size(), 4);
}

TEST(Map, erase) {
  s21::Map<int, std::string> M1{{1, "Hi"}, {2, "Hello"}, {3, "Good"}};
  std::map<int, std::string> M2{{1, "Hi"}, {2, "Hello"}, {3, "Good"}};
  s21::Map<int, std::string>::iterator iter1 = M1.begin();
  std::map<int, std::string>::iterator iter2 = M2.begin();
  M1.erase(++iter1);
  M2.erase(++iter2);
  iter1 = M1.begin();
  iter2 = M2.begin();
  for (; iter1 != nullptr; iter1++, iter2++) {
    ASSERT_EQ(*iter1, *iter2);
  }
  ASSERT_EQ(M1.size(), M2.size());
}

TEST(Map, swap) {
  s21::Map<int, std::string> M1{{1, "Hi"}, {2, "Hello"}, {3, "Good"}};
  s21::Map<int, std::string> M2{{1, "Hi"}};
  std::map<int, std::string> M3{{1, "Hi"}, {2, "Hello"}, {3, "Good"}};
  std::map<int, std::string> M4{{1, "Hi"}};
  M1.swap(M2);
  M3.swap(M4);
  s21::Map<int, std::string>::iterator iter1 = M1.begin();
  std::map<int, std::string>::iterator iter2 = M3.begin();
  for (; iter1 != nullptr; iter1++, iter2++) {
    ASSERT_EQ(*iter1, *iter2);
  }
  s21::Map<int, std::string>::iterator iter3 = M2.begin();
  std::map<int, std::string>::iterator iter4 = M4.begin();
  for (; iter3 != nullptr; iter3++, iter4++) {
    ASSERT_EQ(*iter3, *iter4);
  }
  ASSERT_EQ(M1.size(), M3.size());
  ASSERT_EQ(M2.size(), M4.size());
}

TEST(Map, merge) {
  s21::Map<int, std::string> M1{{1, "Hi"}, {2, "Hello"}, {3, "Good"}};
  s21::Map<int, std::string> M2{{1, "Hi"}, {4, "Hello"}, {5, "Good"}};
  std::map<int, std::string> M3{{1, "Hi"}, {2, "Hello"}, {3, "Good"}};
  std::map<int, std::string> M4{{1, "Hi"}, {4, "Hello"}, {5, "Good"}};
  M1.merge(M2);
  M3.merge(M4);
  s21::Map<int, std::string>::iterator iter1 = M1.begin();
  std::map<int, std::string>::iterator iter2 = M3.begin();
  for (; iter1 != nullptr; iter1++, iter2++) {
    ASSERT_EQ(*iter1, *iter2);
  }
  s21::Map<int, std::string>::iterator iter3 = M2.begin();
  std::map<int, std::string>::iterator iter4 = M4.begin();
  for (size_t i = 0; i < M2.size(); i++, iter3++, iter4++) {
    ASSERT_EQ(*iter3, *iter4);
  }
  ASSERT_EQ(M1.size(), M3.size());
  ASSERT_EQ(M2.size(), M4.size());
}

TEST(Map, contatins) {
  s21::Map<int, std::string> M1{{1, "Hi"}, {2, "Hello"}, {3, "Good"}};
  bool b1 = M1.contains(2);
  bool b2 = M1.contains(4);

  ASSERT_EQ(b1, 1);
  ASSERT_EQ(b2, 0);
}

TEST(Map, insert_many) {
  s21::Map<int, std::string> M1{{1, "Hi"}, {2, "Hello"}, {3, "Good"}};
  std::map<int, std::string> M2{{1, "Hi"}, {2, "Hello"}, {3, "Good"}};

  M1.insert_many(std::pair<int, std::string>(3, "Bad"),
                 std::pair<int, std::string>(4, "No"),
                 std::pair<int, std::string>(5, "Yes"));

  M2.insert({{3, "Bad"}, {4, "No"}, {5, "Yes"}});
  s21::Map<int, std::string>::iterator iter1 = M1.begin();
  std::map<int, std::string>::iterator iter2 = M2.begin();
  for (; iter1 != nullptr; iter1++, iter2++) {
    ASSERT_EQ(*iter1, *iter2);
  }
  ASSERT_EQ(M1.size(), M2.size());
}
