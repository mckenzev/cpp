#ifndef S21_QUEUE_H
#define S21_QUEUE_H

#include <cstddef>
#include <iostream>
#include <utility>

namespace s21 {

template <class T>
struct QueueNode {
  QueueNode<T> *pPrev;
  QueueNode<T> *pNext;
  T key;
  QueueNode() : pPrev(nullptr), pNext(nullptr) {}
  // QueueNode(T i) : pPrev(nullptr), pNext(nullptr), key(i) {}
  QueueNode(T i, QueueNode<T> *p, QueueNode<T> *n)
      : pPrev(p), pNext(n), key(i) {}
};

template <class T>
class queue {
 public:
  queue() : pFront(nullptr), pBack(nullptr), size_cont(0) {}

  queue(std::initializer_list<T> const &items)
      : pFront(nullptr), pBack(nullptr), size_cont(0) {
    for (auto i : items) {
      this->push(i);
      // size_cont++;
      // QueueNode<T> *n = new QueueNode<T>(i, pBack, nullptr);
      // if (pBack != nullptr) {
      //   pBack->pNext = n;
      // } else {
      //   pFront = n;
      // }
      // pBack = n;
    }
  }

  queue(const queue &q) {
    pFront = nullptr;
    pBack = nullptr;
    size_cont = 0;
    QueueNode<T> *n = q.pFront;
    while (n != nullptr) {
      push(n->key);
      n = n->pNext;
      // size_cont++;
      // QueueNode<T> *n1 = new QueueNode<T>(n->key, pBack, nullptr);
      // if (pBack != nullptr) {
      //   pBack->pNext = n1;
      // } else {
      //   pFront = n1;
      // }
      // pBack = n1;
      // n = n->pNext;
    }
  }

  queue(queue &&q) noexcept {
    pFront = q.pFront;
    pBack = q.pBack;
    size_cont = q.size_cont;
    q.pFront = nullptr;
    q.pBack = nullptr;
    q.size_cont = 0;
  }

  ~queue() {
    while (pFront != nullptr) {
      this->pop();
    }
  }

  queue &operator=(queue &&q) noexcept {
    if (pFront != nullptr) {
      while (pFront != nullptr) {
        this->pop();
      }
    }
    pFront = q.pFront;
    pBack = q.pBack;
    size_cont = q.size_cont;
    q.pFront = nullptr;
    q.pBack = nullptr;
    q.size_cont = 0;
    return *this;
  }

  queue &operator=(const queue &q) {
    if (this == &q) {
      return *this;
    }
    while (pFront != nullptr) {
      this->pop();
    }
    pBack = nullptr;
    QueueNode<T> *n = q.pFront;
    while (n != nullptr) {
      push(n->key);
      n = n->pNext;
    }
    return *this;
  }

  const T &front() { return pFront->key; }
  const T &back() { return pBack->key; }

  bool empty() const {
    if (size_cont == 0) {
      return true;
    }
    return false;
  }

  size_t size() const { return size_cont; }

  void push(const T &value) {
    size_cont++;
    QueueNode<T> *n = new QueueNode<T>(value, pBack, nullptr);
    if (pBack != nullptr) {
      pBack->pNext = n;
    } else {
      pFront = n;
    }
    pBack = n;
  }

  void pop() {
    if (pFront != nullptr) {
      size_cont--;
      QueueNode<T> *temp = pFront;
      pFront = pFront->pNext;
      if (pFront == nullptr) {
        pBack = nullptr;
      }
      delete temp;
    }
  }

  void swap(queue &rotate) {
    queue tmp = rotate;
    rotate = *this;
    *this = tmp;
  }

  template <class... Args>
  void emplace_back(Args &&...args) {
    for (auto data : {args...}) {
      push(data);
    }
  }

  const T &get_start_element() { return this->front(); }

 private:
  QueueNode<T> *pFront;
  QueueNode<T> *pBack;
  size_t size_cont;
};

}  // namespace s21

#endif