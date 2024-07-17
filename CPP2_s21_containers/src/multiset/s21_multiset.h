#ifndef CPP2_S21_CONTAINERS_S21_Multiset_H_
#define CPP2_S21_CONTAINERS_S21_Multiset_H_

#include "../tree/s21_tree.h"
#include "../vector/s21_vector.h"

namespace s21 {

template <typename Key, typename Container = tree<Key, Key>>
class Multiset {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = TreeIterator<Key, Key>;
  using const_iterator = TreeConstIterator<Key, Key>;
  using size_type = size_t;

  Multiset() : tree_(){};
  Multiset(std::initializer_list<value_type> const& items) : tree_(items){};
  Multiset(const Multiset& other) : tree_(other.tree_){};
  Multiset(Multiset&& other) : tree_(std::move(other.tree_)){};
  ~Multiset() {}

  Multiset& operator=(Multiset&& other) {
    tree_ = std::move(other.tree_);
    return *this;
  }

  Multiset& operator=(const Multiset& other) {
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
    return tree_.insert(value);
  }

  void erase(iterator pos) { tree_.erase(pos); }

  void swap(Multiset& other) { tree_.swap(other.tree_); }

  void merge(Multiset& other) {
    if (this == &other) return;
    if (other.tree_.root_ == nullptr) return;
    if (tree_.root_ == nullptr) {
      swap(other);
    } else {
      s21::vector<iterator> pos_to_erase{};
      iterator iter = other.begin();
      for (; iter != nullptr; iter++) {
        insert(iter.unit->data);
        pos_to_erase.push_back(iter);
      }
      other.clear();
    }
  }

  const_iterator find(const Key& key) const { return tree_.find(key); }

  bool contains(const Key& key) { return tree_.contains(key); }

  template <typename... Args>
  s21::vector<std::pair<iterator, bool>> insert_many(Args&&... args) {
    return tree_.insert_many(std::forward<Args>(args)...);
  }

 private:
  Container tree_;
};

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_S21_Multiset_H_