#ifndef CPP2_S21_CONTAINERS_S21_Set_H_
#define CPP2_S21_CONTAINERS_S21_Set_H_

#include "../tree/s21_tree.h"
#include "../vector/s21_vector.h"

namespace s21 {

template <typename Key, typename Container = tree<Key, Key>>
class Set {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = TreeIterator<Key, Key>;
  using const_iterator = TreeConstIterator<Key, Key>;
  using size_type = size_t;

  Set() : tree_(){};
  Set(std::initializer_list<value_type> const& items) : tree_() {
    size_type n = items.size();
    if (n > max_size()) throw "Error max limit";
    for (size_type i = 0; i < n; i++) {
      insert(*(items.begin() + i));
    }
  };

  Set(const Set& other) : tree_(other.tree_){};
  Set(Set&& other) : tree_(std::move(other.tree_)){};
  ~Set() {}

  Set& operator=(Set&& other) {
    tree_ = std::move(other.tree_);
    return *this;
  }

  Set& operator=(const Set& other) {
    tree_ = other.tree_;
    return *this;
  }

  iterator begin() { return tree_.begin(); }

  iterator end() { return tree_.end(); }

  const_iterator cbegin() { return tree_.cbegin(); }

  const_iterator cend() { return tree_.cend(); }

  bool empty() { return tree_.empty(); }

  size_type size() { return tree_.size(); }

  size_type max_size() { return tree_.max_size(); }

  void clear() { tree_.clear(); }

  std::pair<iterator, bool> insert(const value_type& value) {
    bool flag = false;
    std::pair<iterator, bool> pair(nullptr, flag);
    if (find(value) == nullptr) {
      pair.first = tree_.RecursionInsert(tree_.root_, value, nullptr, flag);
      pair.second = flag;
    }
    return pair;
  }

  void erase(iterator pos) { tree_.erase(pos); }

  void swap(Set& other) { tree_.swap(other.tree_); }

  void merge(Set& other) { tree_.merge(other.tree_); }

  const_iterator find(const Key& key) const { return tree_.find(key); }

  bool contains(const Key& key) { return tree_.contains(key); }

  template <typename... Args>
  s21::vector<std::pair<iterator, bool>> insert_many(Args&&... args) {
    s21::vector<std::pair<iterator, bool>> my_vector;
    iterator iter = begin();
    bool flag = false;
    std::pair<iterator, bool> pair(nullptr, flag);
    for (auto i : {std::forward<Args>(args)...}) {
      flag = false;
      iter.unit = nullptr;
      if (find(i) == nullptr) {  // ИСКЛЮЧАЕТ ПОВТОРЕНИЯ (ДЛЯ Set)
        pair.first = tree_.RecursionInsert(tree_.root_, i, nullptr, flag);
        pair.second = flag;
      } else {
        pair.first = iter;
        pair.second = flag;
      }
      my_vector.push_back(pair);
    }
    return my_vector;
  }

 private:
  Container tree_;
};

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_S21_Set_H_