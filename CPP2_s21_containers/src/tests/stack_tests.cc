#include <gtest/gtest.h>

#include <stack>

#include "../stack/s21_stack.h"

TEST(Stack_test, DefaultConstructor) {
  s21::stack<int> q;
  EXPECT_TRUE(q.empty());
  EXPECT_EQ(0, q.size());
}

TEST(Stack_test, DefaultConstructor_1) {
  s21::stack<int> q1;
  s21::stack<int> q2;
  EXPECT_EQ(q1.empty(), q2.empty());
  EXPECT_EQ(0, q1.size());
  EXPECT_EQ(0, q2.size());
}

TEST(Stack_test, Initializator_List) {
  s21::stack<int> q1{1, 2, 3, 4};
  s21::stack<int> q2;
  s21::stack<double> q3{1.1, 2.1, 3.1, 4.1};
  s21::stack<std::string> q4{"Hello", ",", "world", "!", "!"};
  q2.push(1);
  q2.push(2);
  q2.push(3);
  q2.push(4);
  EXPECT_EQ(q1.size(), q2.size());
  EXPECT_EQ(q1.size(), 4U);
  EXPECT_EQ(q2.size(), 4U);
  EXPECT_EQ(q3.size(), 4U);
  EXPECT_EQ(q4.size(), 5U);
  while (!q2.empty()) {
    EXPECT_EQ(q1.top(), q2.top());
    q1.pop();
    q2.pop();
  }
}

TEST(Stack_test, CopyConstructor) {
  std::initializer_list<int> a = {1, 2, 3};

  s21::stack<int> s21_stack{a};
  s21::stack<int> s21_stack_copy{s21_stack};

  std::stack<int> std_stack{a};
  std::stack<int> std_stack_copy{std_stack};
  EXPECT_EQ(s21_stack_copy.size(), std_stack_copy.size());
  EXPECT_EQ(s21_stack_copy.top(), std_stack_copy.top());
}

TEST(Stack_test, MoveConstructor) {
  std::initializer_list<int> a = {1, 2, 3};

  s21::stack<int> s21_stack{a};
  s21::stack<int> s21_stack_move{s21_stack};
  std::stack<int> std_stack{a};
  std::stack<int> std_stack_move{std_stack};
  EXPECT_EQ(s21_stack_move.size(), std_stack_move.size());
  EXPECT_EQ(s21_stack_move.top(), std_stack_move.top());
}

TEST(Stack_test, MoveConstructor_1) {
  std::initializer_list<int> a1 = {1, 2, 3};
  std::initializer_list<int> a2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{a1};
  s21::stack<int> s21_stack_move{a2};
  s21_stack = std::move(s21_stack_move);

  std::stack<int> std_stack{a1};
  std::stack<int> std_stack_move{a2};
  std_stack = std::move(std_stack_move);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(Stack_test, MoveConstructor_2) {
  std::initializer_list<int> a1;
  std::initializer_list<int> a2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{a1};
  s21::stack<int> s21_stack_move{a2};
  s21_stack = std::move(s21_stack_move);

  std::stack<int> std_stack{a1};
  std::stack<int> std_stack_move{a2};
  std_stack = std::move(std_stack_move);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

// тест с утечкой на exception
TEST(Stack_test, top_exception) {
  std::initializer_list<int> a1;

  s21::stack<int> s21_stack{a1};

  EXPECT_THROW(s21_stack.top(), std::out_of_range);
}

TEST(Stack_test, push_1) {
  std::initializer_list<int> a1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{a1};
  std::stack<int> std_stack{a1};
  s21_stack.push(1);
  std_stack.push(1);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(Stack_test, push_2) {
  std::initializer_list<int> a1;

  s21::stack<int> s21_stack{a1};
  std::stack<int> std_stack{a1};
  s21_stack.push(1);
  std_stack.push(1);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(Stack_test, pop_1) {
  std::initializer_list<int> a1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{a1};
  std::stack<int> std_stack{a1};
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(Stack_test, swap) {
  std::initializer_list<int> a1 = {4, 5, 6, 7};
  std::initializer_list<int> a2 = {1, 2, 3};

  s21::stack<int> s21_stack{a1};
  s21::stack<int> s21_stack_swap{a2};
  std::stack<int> std_stack{a1};
  std::stack<int> std_stack_swap{a2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
  EXPECT_EQ(s21_stack_swap.top(), std_stack_swap.top());
}

TEST(Stack_test, swap_1) {
  std::initializer_list<int> a1 = {1, 2, 3};
  std::initializer_list<int> a2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{a1};
  s21::stack<int> s21_stack_swap{a2};
  std::stack<int> std_stack{a1};
  std::stack<int> std_stack_swap{a2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
  EXPECT_EQ(s21_stack_swap.top(), std_stack_swap.top());
}

TEST(Stack_test, swap_2) {
  std::initializer_list<int> a1 = {4, 5, 6, 7};
  std::initializer_list<int> a2;

  s21::stack<int> s21_stack{a1};
  s21::stack<int> s21_stack_swap{a2};
  std::stack<int> std_stack{a1};
  std::stack<int> std_stack_swap{a2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
}

TEST(Stack_test, swap_3) {
  std::initializer_list<int> a1;
  std::initializer_list<int> a2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{a1};
  s21::stack<int> s21_stack_swap{a2};
  std::stack<int> std_stack{a1};
  std::stack<int> std_stack_swap{a2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
}

TEST(Stack_test, emplace_back) {
  s21::stack<int> q1{1, 2, 3};
  s21::stack<int> q2{1, 2, 3, 7, 8};
  q1.emplace_front(7, 8);
  for (size_t i = 0; i <= q2.size(); i++) {
    ASSERT_EQ(q1.top(), q2.top());
    q1.pop();
    q2.pop();
  }
}