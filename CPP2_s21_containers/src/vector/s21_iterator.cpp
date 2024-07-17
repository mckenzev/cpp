//#include "s21_vector.h"

namespace s21 {

//         VectorIterator

template <typename T>
typename vector<T>::reference vector<T>::IteratorVec::operator*() {
  return *ptr_;
}

template <typename T>
typename vector<T>::IteratorVec vector<T>::IteratorVec::operator++(int) {
  IteratorVec tmp(*this);
  ++ptr_;
  return tmp;
}

template <typename T>
typename vector<T>::IteratorVec vector<T>::IteratorVec::operator--(int) {
  IteratorVec tmp(*this);
  --ptr_;
  return tmp;
}

template <typename T>
typename vector<T>::IteratorVec &vector<T>::IteratorVec::operator++() {
  ++ptr_;
  return *this;
}

template <typename T>
typename vector<T>::IteratorVec &vector<T>::IteratorVec::operator--() {
  --ptr_;
  return *this;
}

template <typename T>
typename vector<T>::IteratorVec vector<T>::IteratorVec::operator+(int n) const {
  IteratorVec tmp(*this);
  for (int i = 0; i < n; i++) {
    tmp++;
  };

  return tmp;
}

template <typename T>
typename vector<T>::IteratorVec vector<T>::IteratorVec::operator-(int n) const {
  IteratorVec tmp(*this);
  for (int i = 0; i < n; i++) {
    tmp--;
  };

  return tmp;
}

template <typename T>
typename vector<T>::ConstIteratorVec vector<T>::ConstIteratorVec::operator++(
    int) {
  ConstIteratorVec tmp(*this);
  ++ptr_;
  return tmp;
}

template <typename T>
typename vector<T>::ConstIteratorVec vector<T>::ConstIteratorVec::operator--(
    int) {
  ConstIteratorVec tmp(*this);
  --ptr_;
  return tmp;
}

template <typename T>
typename vector<T>::ConstIteratorVec &
vector<T>::ConstIteratorVec::operator++() {
  ++ptr_;
  return *this;
}

template <typename T>
typename vector<T>::ConstIteratorVec &
vector<T>::ConstIteratorVec::operator--() {
  --ptr_;
  return *this;
}

template <typename T>
bool vector<T>::ConstIteratorVec::operator==(
    const ConstIteratorVec &other) const {
  return ptr_ == other.ptr_;
}

template <typename T>
bool vector<T>::ConstIteratorVec::operator!=(
    const ConstIteratorVec &other) const {
  return ptr_ != other.ptr_;
}

template <typename T>
typename vector<T>::ConstIteratorVec vector<T>::ConstIteratorVec::operator+(
    int n) const {
  ConstIteratorVec tmp(*this);
  for (int i = 0; i < n; i++) {
    tmp++;
  };

  return tmp;
}

template <typename T>
typename vector<T>::ConstIteratorVec vector<T>::ConstIteratorVec::operator-(
    int n) const {
  ConstIteratorVec tmp(*this);
  for (int i = 0; i < n; i++) {
    tmp--;
  };

  return tmp;
}

}  // namespace s21