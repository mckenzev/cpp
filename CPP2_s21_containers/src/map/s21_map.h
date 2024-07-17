#ifndef CPP2_S21_CONTAINERS_S21_Map_H_
#define CPP2_S21_CONTAINERS_S21_Map_H_

#include "../tree/s21_tree.h"
#include "../vector/s21_vector.h"

namespace s21 {

template <typename Key, typename T>
class Map {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = TreeIterator<Key, value_type>;
  using const_iterator = TreeConstIterator<Key, value_type>;
  using size_type = size_t;

  Map(){};
  Map(std::initializer_list<value_type> const& items) : tree_() {
    size_type n = items.size();
    if (n > max_size()) throw "Error max limit";
    for (size_type i = 0; i < n; i++) {
      insert(*(items.begin() + i));
    }
  };

  Map(const Map& other) : tree_(other.tree_){};
  Map(Map&& other) : tree_(std::move(other.tree_)){};
  ~Map() {}

  Map& operator=(Map&& other) {
    if (this == &other) return *this;
    tree_ = std::move(other.tree_);
    return *this;
  }

  Map& operator=(const Map& other) {
    if (this == &other) return *this;
    tree_ = other.tree_;
    return *this;
  }

  T& at(const Key& key) {
    T t{};
    std::pair<Key, T> value(key, t);
    iterator iter = find(value);
    if (iter != nullptr)
      return (*iter).second;
    else
      throw std::out_of_range("Iterator is pointing to nullptr");
  }

  const T& at(const Key& key) const {
    T t{};
    std::pair<Key, T> value(key, t);
    iterator iter = find(value);
    if (iter != nullptr)
      return (*iter).second;
    else
      throw std::out_of_range("Iterator is pointing to nullptr");
  }

  T& operator[](const Key& key) {
    T t{};
    std::pair<Key, T> value(key, t);
    return (*find(value)).second;
  }

  const T& operator[](const Key& key) const {
    T t{};
    std::pair<Key, T> value(key, t);
    return (*find(value)).second;
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

  std::pair<iterator, bool> insert(const Key& key, const T& obj) {
    const value_type value = std::pair<const key_type, mapped_type>(key, obj);
    return insert(value);
  }

  std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj) {
    bool flag = false;
    std::pair<iterator, bool> pair(nullptr, flag);
    const value_type value = std::pair<const key_type, mapped_type>(key, obj);
    iterator res_find = find(value);
    if (res_find == nullptr) {
      pair.first = tree_.RecursionInsert(tree_.root_, value, nullptr, flag);
      pair.second = flag;
    } else {
      res_find.unit->data.second = obj;
      pair.first = res_find;
    }
    return pair;
  }

  void erase(iterator pos) { tree_.erase(pos); }

  void swap(Map& other) { tree_.swap(other.tree_); }

  void merge(Map& other) { tree_.merge(other.tree_); }

  bool contains(const Key& key) {
    T y = {};
    std::pair<Key, T> pair(key, y);
    if (find(pair) != nullptr) return true;
    return false;
  }

  template <typename... Args>
  s21::vector<std::pair<iterator, bool>> insert_many(Args&&... args) {
    s21::vector<std::pair<iterator, bool>> my_vector;
    iterator iter = begin();
    bool flag = false;
    std::pair<iterator, bool> pair(nullptr, flag);
    for (auto i : {std::forward<Args>(args)...}) {
      flag = false;
      iter.unit = nullptr;
      if (find(i) == nullptr) {  // ИСКЛЮЧАЕТ ПОВТОРЕНИЯ (ДЛЯ Map)
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
  tree<Key, value_type> tree_;

  iterator find(const value_type& value) const {
    if (!tree_.root_) return nullptr;
    TreeNode<Key, value_type>* tmp = tree_.root_;
    while (tmp) {
      if (value.first == tmp->data.first) {
        return iterator(tmp);
      } else if (value.first < tmp->data.first) {
        tmp = tmp->left;
      } else {
        tmp = tmp->right;
      }
    }
    return nullptr;
  }
};

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_S21_Map_H_