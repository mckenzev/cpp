#include "s21_vector.h"
using namespace std;

namespace s21 {

template <class T>
vector<T>::vector() {
  sz_ = 0;
  cap_ = 0;
  this->data_ = nullptr;
}

template <class T>
vector<T>::vector(size_t value) {
  if (this->max_size() < value) {
    throw std::out_of_range("Incorrect size");
  }
  sz_ = value;
  cap_ = sz_;
  this->data_ = new T[cap_]();
}

template <class T>
vector<T>::vector(size_t size, T value) {
  if (this->max_size() < value) {
    throw std::out_of_range("Incorrect size");
  }
  sz_ = size;
  cap_ = sz_;
  this->data_ = new T[cap_]();
  for (size_t i = 0; i < sz_; i++) {
    data_[i] = value;
  }
}

template <class T>
vector<T>::vector(std::initializer_list<T> const& items) {
  sz_ = items.size();
  cap_ = sz_;
  data_ = new T[items.size() * 2];
  std::copy(items.begin(), items.end(), this->data_);
}

template <class T>
vector<T>::vector(const vector& other) {
  sz_ = other.sz_;
  cap_ = other.cap_;
  data_ = new T[cap_]();
  for (size_t i = 0; i < sz_; i++) {
    data_[i] = other.data_[i];
  }
}

template <class T>
vector<T>::vector(vector&& other) noexcept {
  sz_ = std::exchange(other.sz_, 0);
  cap_ = std::exchange(other.cap_, 0);
  data_ = std::exchange(other.data_, nullptr);
}

template <class T>
vector<T> &vector<T>::operator=(vector&& other) noexcept {
  if (this != &other) {
    this->sz_ = other.sz_;
    cap_ = other.cap_;
    data_ = other.data_;

    delete[] other.data_;
    other.sz_ = 0;
    other.cap_ = 0;
    other.data_ = nullptr;
  }

  return *this;
}

template <class value_type>
typename vector<value_type>::iterator vector<value_type>::begin() {
  return iterator(data_);
}

template <class value_type>
typename vector<value_type>::iterator vector<value_type>::end() {
  return iterator(data_ + sz_);
}

template <class value_type>
typename vector<value_type>::const_iterator vector<value_type>::cbegin() const {
  return const_iterator(data_);
}

template <class value_type>
typename vector<value_type>::const_iterator vector<value_type>::cend() const {
  return const_iterator(data_ + sz_);
}

template <class value_type>
typename vector<value_type>::reference vector<value_type>::at(size_t n) {
  if (n >= sz_) {
    throw std::out_of_range("AtError: Index out of range");
  }
  return data_[n];
}

template <class value_type>
typename vector<value_type>::const_reference vector<value_type>::front() {
  if (this->empty()) {
    throw std::out_of_range("Out of range");
  }
  return *data_;
}

template <class value_type>
typename vector<value_type>::const_reference vector<value_type>::back() {
  if (this->empty()) {
    throw std::out_of_range("Out of range");
  }
  return data_[sz_ - 1];
}

template <class value_type>
typename vector<value_type>::reference vector<value_type>::operator[](
    size_t x) {
  if (this->size() < x) {
    throw std::out_of_range("Index out of range");
  }
  return data_[x];
}

template <class value_type>
typename vector<value_type>::const_reference vector<value_type>::operator[](
    size_t x) const {
  if (this->size() < x) {
    throw std::out_of_range("Index out of range");
  }
  return data_[x];
}   

template <class T>
vector<T>::~vector() {
  sz_ = 0;
  cap_ = 0;
  delete[] data_;
  data_ = nullptr;
}

template <class T>
void vector<T>::clear() {
  sz_ = 0;
}

template <class T>
bool vector<T>::empty() {
  return sz_ == 0;
}

template <class T>
void vector<T>::push_back(const_reference value) {
  if (sz_ >= cap_) {
    reserve(sz_ * 2);
  }
  if (sz_ == 0) {
    resize(1);
    data_[sz_--] = value;
  }
  data_[sz_++] = value;
}

template <class T>
void vector<T>::pop_back() {
  this->sz_ > 0 ? this->sz_-- : 0;
}

template <class T>
void vector<T>::reserve(size_t new_cap) {
  if (new_cap < sz_) {
    new_cap = sz_;
  }
  cap_ = new_cap;
  T* ptr = new T[cap_];
  for (size_t i = 0; i < this->sz_; ++i) {
    ptr[i] = data_[i];
  }
  delete[] data_;
  data_ = ptr;
}

template <class T>
void vector<T>::shrink_to_fit() {
  reserve(sz_);
}

template <class T>
void vector<T>::resize(size_t new_size) {
  if (new_size < 1) throw std::out_of_range("Invalid size");
  if (new_size > cap_) {
    reserve(new_size * 2);
  }

  sz_ = new_size;
}

template <class T>
void vector<T>::erase(iterator pos) {
  size_type position = &(*pos) - data_;
  size_type zero = 0;
  if (zero > position || position > sz_) {
    throw std::out_of_range("Index out ot range");
  }
  for (size_type i = position + 1; i < sz_; i++) {
    data_[i - 1] = data_[i];
  }
  sz_--;
}

template <typename T>
void vector<T>::swap(vector<T>& other) {
  std::swap(data_, other.data_);
  std::swap(sz_, other.sz_);
  std::swap(cap_, other.cap_);
}

template <class T>
typename vector<T>::iterator vector<T>::insert(iterator pos,
                                               const_reference value) {
  size_type position = &(*pos) - data_;
  size_type zero = 0;
  if (zero > position || position > sz_) {
    throw std::out_of_range("Index out ot range");
  }

  if (sz_ == cap_) {
    reserve(cap_ ? cap_ * 2 : 1);
  }

  value_type replace = data_[position];
  sz_++;
  data_[position] = value;
  for (size_type i = position + 1; i < sz_; ++i) {
    value_type next = data_[i];
    data_[i] = replace;
    replace = next;
  }
  return data_ + position;
}

template <class T>
template <typename... Args>
typename vector<T>::iterator vector<T>::insert_many(const_iterator pos,
                                                    Args&&... args) {
  vector<value_type> tmp{args...};
  iterator cur_pos = begin() + (pos - cbegin());
  for (size_t i = 0; i < tmp.size(); ++i) {
    cur_pos = insert(cur_pos, tmp[i]);
    ++cur_pos;
  }
  return cur_pos;
}

template <typename T>
template <typename... Args>
void vector<T>::insert_many_back(Args&&... args) {
  insert_many(cend(), args...);
}

template <typename T>
void vector<T>::zero() {
  cap_ = 0;
  sz_ = 0;
  data_ = nullptr;
}

}  // namespace s21