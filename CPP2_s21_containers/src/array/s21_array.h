#ifndef CPP2_S21_CONTAINER_2_SRC_ARRYA_ARRAY_H_
#define CPP2_S21_CONTAINER_2_SRC_ARRYA_ARRAY_H_

#include <initializer_list>
#include <iostream>
#include <stdexcept>

namespace s21 {

template <typename T, size_t N>
class Array {
 public:
  using value_type = T;
  using reference = value_type&;
  using const_reference = const T&;
  using iterator = T*;
  using const_iterator = const T*;
  using size_type = size_t;

  Array() = default;

  Array(std::initializer_list<T> const& items) {
    if (items.size() > N) throw std::out_of_range("Error size");

    const_iterator cit = items.begin();

    for (size_type i = 0; i < items.size(); ++i) {
      data_[i] = *(cit + i);
    }
  }

  Array(const Array& a) {
    for (size_type i = 0; i < N; ++i) {
      data_[i] = a.data_[i];
    }
  }

  Array(Array&& a) {
    for (size_type i = 0; i < N; ++i) {
      data_[i] = std::move(a.data_[i]);
    }
  }

  ~Array() = default;

  Array& operator=(Array&& a) {
    for (size_type i = 0; i < N; ++i) {
      data_[i] = std::move(a.data_[i]);
    }
    return *this;
  }

  reference operator[](size_type pos) { return data_[pos]; }
  constexpr const_reference operator[](size_type pos) const {
    return data_[pos];
  }

  reference at(size_type pos) {
    if (pos >= N) throw std::out_of_range("Index out of range");
    return data_[pos];
  }

  constexpr const_reference at(size_type pos) const {
    if (pos >= N) throw std::out_of_range("Index out of range");
    return data_[pos];
  }

  const_reference front() const { return data_[0]; }
  const_reference back() const { return data_[N - 1]; }

  iterator data() { return data_; }
  constexpr const_iterator data() const { return data_; }

  iterator begin() { return data_; }
  constexpr const_iterator begin() const { return data_; }

  iterator end() { return data_ + N; }
  constexpr const_iterator end() const { return data_ + N; }

  size_type size() const { return N; }
  size_type max_size() const { return N; }

  bool empty() { return N == 0; }

  void fill(const_reference value) {
    for (size_type i = 0; i < N; ++i) {
      data_[i] = value;
    }
  }

  void swap(Array& other) {
    for (size_type i = 0; i < N; ++i) {
      T temp = data_[i];
      data_[i] = other.data_[i];
      other.data_[i] = temp;
    }
  }

 private:
  T data_[N];
};

}  // namespace s21
#endif  // CPP2_S21_CONTAINER_2_SRC_ARRYA_ARRAY_H_