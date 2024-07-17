#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <limits>

namespace s21 {

template <class T>
class VectorIterator;

template <class T>
class VectorConstIterator;

template <class T>
class vector {
 private:
  size_t sz_;
  size_t cap_;
  T *data_;

 public:
  using iterator = VectorIterator<T>;
  using const_iterator = VectorConstIterator<T>;
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;
  using pointer = T *;

  vector();
  vector(size_t value);
  vector(size_t size, T value);
  vector(const vector &other);
  vector(std::initializer_list<T> const &items);
  vector(vector &&other) noexcept;
  ~vector();

  bool empty();

  vector &operator=(vector &&other) noexcept;
  reference operator[](size_t x);
  const_reference operator[](size_t x) const;

  iterator insert(iterator pos, const_reference value);
  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args);
  template <typename... Args>
  void insert_many_back(Args &&...args);

  reference at(size_t n);
  const_reference at(size_t n) const { return this->at(n); }
  const_reference front();
  const_reference back();
  pointer data() { return data_; };

  size_type size() const { return sz_; }
  size_type max_size() const {
    return std::numeric_limits<std::size_t>::max() / sizeof(value_type);
  }
  size_type capacity() const { return cap_; }

  void erase(iterator pos);
  void clear();
  void push_back(const_reference value);
  void pop_back();
  void shrink_to_fit();
  void reserve(size_t new_cap);
  void resize(size_t new_size);
  void swap(vector<T> &other);

  iterator begin();
  iterator end();

  const_iterator cbegin() const;
  const_iterator cend() const;

  void zero();
};

template <class T>
class VectorIterator {
  friend class vector<T>;
  friend class VectorConstIterator<T>;

  using value_type = T;
  using pointer = T *;
  using reference = T &;

 public:
  VectorIterator() { ptr_ = nullptr; }
  VectorIterator(pointer ptr) { ptr_ = ptr; }

  value_type &operator*() const { return (*ptr_); }
  pointer operator->() { return ptr_; }

  VectorIterator &operator++() {
    ptr_++;
    return *this;
  }

  VectorIterator &operator--() {
    ptr_--;
    return *this;
  }

  VectorIterator operator++(int) {
    VectorIterator tmp = *this;
    ++(*this);
    return tmp;
  }

  VectorIterator operator--(int) {
    VectorIterator tmp = *this;
    --(*this);
    return tmp;
  }

  VectorIterator operator+(int value) const {
    VectorIterator tmp(*this);
    for (int i = 0; i < value; i++) {
      tmp++;
    }

    return tmp;
  }

  VectorIterator operator-(int value) const {
    VectorIterator tmp(*this);
    for (int i = 0; i < value; i++) {
      tmp--;
    }

    return tmp;
  }

  ptrdiff_t operator-(const VectorIterator &other) const {
    return ptr_ - other.ptr_;
  }

  bool operator==(const VectorIterator &other) { return ptr_ == other.ptr_; }

  bool operator!=(const VectorIterator &other) { return ptr_ != other.ptr_; }

  operator VectorConstIterator<T>() const {
    return VectorConstIterator<T>(ptr_);
  }

 private:
  pointer ptr_;
};

template <class T>
class VectorConstIterator {
  friend class vector<T>;
  friend class VectorIterator<T>;

  using value_type = T;
  using pointer = T *;
  using reference = T &;

 public:
  VectorConstIterator() { ptr_ = nullptr; };
  VectorConstIterator(pointer ptr) { ptr_ = ptr; };
  value_type operator*() const { return (*ptr_); }
  pointer operator->() { return ptr_; }

  VectorConstIterator &operator++() {
    ptr_++;
    return *this;
  }

  VectorConstIterator &operator--() {
    ptr_--;
    return *this;
  }

  VectorConstIterator operator++(int) {
    VectorConstIterator tmp = *this;
    ++(*this);
    return tmp;
  }

  VectorConstIterator operator--(int) {
    VectorConstIterator tmp = *this;
    --(*this);
    return tmp;
  }

  bool operator==(const VectorConstIterator &other) {
    return ptr_ == other.ptr_;
  }

  bool operator!=(const VectorConstIterator &other) {
    return ptr_ != other.ptr_;
  }

  VectorConstIterator operator+(int value) const {
    VectorConstIterator tmp(*this);
    for (int i = 0; i < value; i++) {
      tmp++;
    };

    return tmp;
  }

  VectorConstIterator operator-(int value) const {
    VectorConstIterator tmp(*this);
    for (int i = 0; i < value; i++) {
      tmp--;
    };
    return tmp;
  }

  ptrdiff_t operator-(const VectorConstIterator &other) const {
    return ptr_ - other.ptr_;
  }

  operator VectorIterator<T>() const { return VectorIterator<T>(ptr_); }

 private:
  pointer ptr_;
};

}  // namespace s21

#include "s21_vector.cpp"

#endif  // VECTOR_H