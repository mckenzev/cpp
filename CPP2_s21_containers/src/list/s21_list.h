#include <iostream>
#include <limits>

namespace s21 {

template <class T>
class node {
 public:
  T data_;
  node<T> *next_;
  node<T> *prev_;
  node(T value = T()) : data_(value), next_(nullptr), prev_(nullptr) {}
};

template <class T>
class list {
 public:
  class ListIterator;
  class ListConstIterator;

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = ListIterator;
  using const_iterator = ListConstIterator;
  using size_type = size_t;

  class ListIterator {
   public:
    node<value_type> *ptr_;

    ListIterator() { ptr_ = nullptr; }
    ListIterator(node<value_type> *obj) { ptr_ = obj; }
    reference operator*() { return ptr_->data_; }

    iterator &operator++(int) {
      ptr_ = ptr_->next_;
      return *this;
    }

    iterator &operator++() {
      ptr_ = ptr_->next_;
      return *this;
    }

    iterator &operator--(int) {
      ptr_ = ptr_->prev_;
      return *this;
    }

    iterator &operator--() {
      ptr_ = ptr_->prev_;
      return *this;
    }

    bool operator==(const iterator &obj) { return ptr_ == obj.ptr_; }

    bool operator!=(const iterator &obj) { return ptr_ != obj.ptr_; }
  };

  class ListConstIterator {
   public:
    node<value_type> *cptr_;

    ListConstIterator() { cptr_ = nullptr; }
    ListConstIterator(node<value_type> *obj) { cptr_ = obj; }
    const_reference operator*() { return cptr_->data_; }

    const_iterator &operator++(int) {
      cptr_ = cptr_->next_;
      return *this;
    }

    const_iterator &operator++() {
      cptr_ = cptr_->next_;
      return *this;
    }

    const_iterator &operator--(int) {
      cptr_ = cptr_->prev_;
      return *this;
    }

    const_iterator &operator--() {
      cptr_ = cptr_->prev_;
      return *this;
    }

    bool operator==(const const_iterator &obj) const {
      return cptr_ == obj.cptr_;
    }

    bool operator!=(const const_iterator &obj) const {
      return cptr_ != obj.cptr_;
    }

    node<value_type> *get_ptr() const { return cptr_; }
  };

  list() : head_(nullptr), tail_(nullptr), count_(0) { add_end(); }

  list(size_type n) : head_(nullptr), tail_(nullptr), count_(0) {
    if (n > max_size()) throw "Error max limit";
    add_end();
    while (n--) {
      push_back(value_type());
    }
  }

  list(std::initializer_list<value_type> const &items)
      : head_(nullptr), tail_(nullptr), count_(0) {
    add_end();
    for (auto &obj : items) {
      push_back(obj);
    }
  }

  list(const list<value_type> &l) : head_(nullptr), tail_(nullptr), count_(0) {
    add_end();
    copy(l);
  }

  list(list<value_type> &&l) : head_(nullptr), tail_(nullptr), count_(0) {
    add_end();
    swap(l);
  }

  ~list() {
    clear();
    delete end_;
  }

  list<value_type> &operator=(list<value_type> &&l) {
    clear();
    delete end_;
    zeroing();
    add_end();
    swap(l);
    return *this;
  }

  list<value_type> &operator=(list<value_type> &l) {
    clear();
    delete end_;
    zeroing();
    add_end();
    copy(l);
    return *this;
  }

  const_reference front() {
    if (!count_) return end_->data_;
    return head_->data_;
  };

  const_reference back() {
    if (!count_) return end_->data_;
    return tail_->data_;
  };

  iterator begin() {
    if (!head_) return iterator(end_);
    return iterator(head_);
  };

  const_iterator begin() const {
    if (!head_) return const_iterator(end_);
    return const_iterator(head_);
  };

  iterator end() { return iterator(end_); };

  const_iterator cbegin() {
    if (!head_) return const_iterator(end_);
    return const_iterator(head_);
  };

  const_iterator cend() { return const_iterator(end_); };

  bool empty() {
    if (count_ == 0) return true;
    return false;
  }

  void push_back(const_reference value) {
    node<value_type> *new_node = new (std::nothrow) node<value_type>(value);
    if (!new_node) throw "no memory";
    if (!head_ && !tail_) {
      head_ = tail_ = new_node;
    } else {
      new_node->prev_ = tail_;
      tail_->next_ = new_node;
      tail_ = new_node;
    }
    connect();
  }

  void pop_back() {
    if (!count_) throw "empty list";
    node<value_type> *tmp = tail_;
    if (head_ == tail_) {
      head_ = tail_ = nullptr;
      end_->prev_ = end_->next_ = end_;
    } else {
      tail_ = tail_->prev_;
      tail_->next_ = end_;
      end_->prev_ = tail_;
    }
    delete tmp;
    end_->data_ = --count_;
  }

  void push_front(const_reference value) {
    node<value_type> *new_node = new (std::nothrow) node<value_type>(value);
    if (!new_node) throw "no memory";
    if (!head_ && !tail_) {
      head_ = tail_ = new_node;
    } else {
      new_node->next_ = head_;
      head_->prev_ = new_node;
      head_ = new_node;
    }
    connect();
  }

  void pop_front() {
    if (!count_) throw "empty list";
    node<value_type> *tmp = head_;
    head_ = head_->next_;
    head_->prev_ = end_;
    end_->next_ = head_;
    delete tmp;
    end_->data_ = --count_;
  }

  void swap(list &other) {
    std::swap(head_, other.head_);
    std::swap(tail_, other.tail_);
    std::swap(end_, other.end_);
    std::swap(count_, other.count_);
  }

  void merge(list &other) {
    if (this != &other) {
      auto it_t = begin();
      auto it_o = other.begin();

      while (it_t != end() && it_o != other.end()) {
        if (*it_o < *it_t) {
          insert(it_t, *it_o);
          ++it_o;
        } else {
          ++it_t;
        }
      }

      while (it_o != other.end()) {
        push_back(*it_o);
        ++it_o;
      }

      other.clear();
    }
  }

  void splice(const_iterator pos, list &other) {
    auto it = other.begin();
    iterator it_pos(pos.get_ptr());
    for (size_type i = 0; i < other.size(); i++, ++it) {
      insert(it_pos, *it);
    }
    other.clear();
  }

  void reverse() {
    if (count_ > 1) {
      int rev = count_ / 2;
      node<value_type> *tmp_head_ = head_;
      node<value_type> *tmp_tail_ = tail_;
      while (rev--) {
        std::swap(tmp_head_->data_, tmp_tail_->data_);
        tmp_head_ = tmp_head_->next_;
        tmp_tail_ = tmp_tail_->prev_;
      }
    }
  }

  void unique() {
    auto it = begin();
    for (int i = 1; i < count_; i++, ++it) {
      if (it.ptr_->data_ == it.ptr_->next_->data_) {
        erase(it.ptr_->next_);
      }
    }
  }

  void sort() {
    for (int i = 1; i < count_; i++) {
      auto it = begin();
      auto it_n = ++begin();
      for (int j = 1; j < count_; j++, ++it, ++it_n) {
        if (*it > *it_n) {
          std::swap(it.ptr_->data_, it_n.ptr_->data_);
        }
      }
    }
  }

  void clear() {
    if (count_ != 0) {
      while (count_) {
        pop_back();
      }
    }
  }

  iterator insert(iterator pos, const_reference value) {
    if (pos == head_) {
      push_front(value);
    } else if (pos == end_) {
      push_back(value);
    } else {
      node<value_type> *new_obj = new (std::nothrow) node<value_type>;
      if (!new_obj) throw "no memory";
      node<value_type> *temp = pos.ptr_->prev_;
      end_->data_ = ++count_;
      new_obj->data_ = value;
      temp->next_ = new_obj;
      new_obj->prev_ = temp;
      new_obj->next_ = pos.ptr_;
      pos.ptr_->prev_ = new_obj;
    }
    return --pos;
  }

  void erase(iterator pos) {
    if (pos == head_) {
      pop_front();
    } else if (pos == tail_) {
      pop_back();
    } else {
      pos.ptr_->next_->prev_ = pos.ptr_->prev_;
      pos.ptr_->prev_->next_ = pos.ptr_->next_;
      delete pos.ptr_;
      end_->data_ = --count_;
    }
  }

  size_type size() { return count_; }

  size_type max_size() {
    return std::numeric_limits<size_type>::max() / sizeof(node<value_type>) / 2;
  }

  template <class... Args>
  iterator insert_many(const_iterator pos, Args &&...args) {
    iterator it(pos.get_ptr());

    for (auto &q : {std::forward<Args>(args)...}) {
      insert(it, q);
    }

    return it;
  }

  template <class... Args>
  void insert_many_back(Args &&...args) {
    insert_many(cend(), args...);
  }

  template <class... Args>
  void insert_many_front(Args &&...args) {
    insert_many(cbegin(), args...);
  }

 private:
  void add_end() { end_ = new (std::nothrow) node<value_type>(); }

  void zeroing() {
    head_ = tail_ = nullptr;
    count_ = 0;
  }

  void copy(const list<value_type> &l) {
    node<value_type> *temp = l.head_;
    int i = l.count_;
    while (i--) {
      push_back(temp->data_);
      temp = temp->next_;
    }
  }

  void connect() {
    end_->next_ = head_;
    end_->prev_ = tail_;
    end_->data_ = ++count_;
    head_->prev_ = end_;
    tail_->next_ = end_;
  }

 private:
  node<value_type> *head_;
  node<value_type> *tail_;
  node<value_type> *end_;
  int count_;
};
}  // namespace s21