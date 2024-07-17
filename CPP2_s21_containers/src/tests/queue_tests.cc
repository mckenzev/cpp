#include <gtest/gtest.h>

#include <queue>

#include "../queue/s21_queue.h"

TEST(Queue_test, DefaultConstructor) {
  s21::queue<int> q;
  EXPECT_TRUE(q.empty());
  EXPECT_EQ(0, q.size());
}

TEST(Queue_test, DefaultConstructor_1) {
  s21::queue<int> q1;
  s21::queue<int> q2;
  EXPECT_EQ(q1.empty(), q2.empty());
  EXPECT_EQ(0, q1.size());
  EXPECT_EQ(0, q2.size());
}

TEST(Queue_test, Initializator_List) {
  s21::queue<int> q1{1, 2, 3, 4};
  s21::queue<int> q2;
  q2.push(1);
  q2.push(2);
  q2.push(3);
  q2.push(4);
  EXPECT_EQ(q1.size(), q2.size());
  while (!q1.empty()) {
    EXPECT_EQ(q1.front(), q2.front());
    q1.pop();
    q2.pop();
  }
}

TEST(Queue_test, CopyConstructor) {
  s21::queue<int> q1{1, 2, 3, 4};
  s21::queue<int> q2(q1);
  s21::queue<int> q3;
  q3.push(1);
  q3.push(2);
  q3.push(3);
  q3.push(4);
  s21::queue<int> q4(q3);
  EXPECT_EQ(q1.size(), q3.size());
  EXPECT_EQ(q2.size(), q4.size());
  while (!q2.empty()) {
    EXPECT_EQ(q2.front(), q4.front());
    q2.pop();
    q4.pop();
  }
}

TEST(Queue_test, MoveConstructor) {
  s21::queue<int> q1{1, 2, 3, 4};
  s21::queue<int> q2(std::move(q1));
  s21::queue<int> q3;
  q3.push(1);
  q3.push(2);
  q3.push(3);
  q3.push(4);
  s21::queue<int> q4(std::move(q3));
  EXPECT_EQ(q2.size(), q4.size());
  while (!q2.empty()) {
    EXPECT_EQ(q2.front(), q4.front());
    q2.pop();
    q4.pop();
  }
}

TEST(Queue_test, Push_TEST) {
  s21::queue<int> q1;
  std::queue<int> q2;

  q1.push(1);
  q2.push(1);
  EXPECT_EQ(q1.front(), q2.front());
  EXPECT_EQ(q1.back(), q2.back());

  q1.push(2);
  q2.push(2);
  EXPECT_EQ(q1.front(), q2.front());
  EXPECT_EQ(q1.back(), q2.back());

  q1.push(3);
  q2.push(3);
  EXPECT_EQ(q1.front(), q2.front());
  EXPECT_EQ(q1.back(), q2.back());
}

TEST(Queue_test, Move_Assignment) {
  s21::queue<int> q1{1, 2, 3, 4};
  s21::queue<int> q2;
  q2 = std::move(q1);
  s21::queue<int> q3;
  q3.push(1);
  q3.push(2);
  q3.push(3);
  q3.push(4);
  s21::queue<int> q4;
  q4 = std::move(q3);
  EXPECT_EQ(q2.size(), q4.size());
  while (!q2.empty()) {
    EXPECT_EQ(q2.front(), q4.front());
    q2.pop();
    q4.pop();
  }
}

TEST(Queue_test, Swap_Test) {
  s21::queue<int> q1{1, 2, 3, 4};
  s21::queue<int> q2{5, 6, 7, 8};
  s21::queue<int> q1_copy(q1);
  s21::queue<int> q2_copy(q2);

  q1.swap(q2);

  EXPECT_EQ(q1.size(), q2_copy.size());
  EXPECT_EQ(q2.size(), q1_copy.size());
  EXPECT_EQ(q1.front(), 5);
  EXPECT_EQ(q1.back(), 8);

  q2.swap(q1);

  EXPECT_EQ(q2.size(), q1_copy.size());
  EXPECT_EQ(q1.size(), q2_copy.size());
  EXPECT_EQ(q2.front(), 5);
  EXPECT_EQ(q2.back(), 8);
  EXPECT_EQ(q1.front(), 1);
  EXPECT_EQ(q1.back(), 4);
}

TEST(Queue_test, emplace_back) {
  s21::queue<int> q1{1, 2, 3};
  s21::queue<int> q2{1, 2, 3, 7, 8};
  q1.emplace_back(7, 8);
  for (size_t i = 0; i <= q2.size(); i++) {
    ASSERT_EQ(q1.back(), q2.back());
    q1.pop();
    q2.pop();
  }
}
