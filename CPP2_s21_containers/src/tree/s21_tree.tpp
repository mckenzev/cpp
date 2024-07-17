
//////// TreeNode

template <typename Key, typename value_type>
TreeNode<Key, value_type>::TreeNode(value_type value)
    : data(value), height(1), left(nullptr), right(nullptr), parent(nullptr) {}

/////// TreeIterator

template <typename Key, typename value_type>
TreeIterator<Key, value_type>::TreeIterator() : unit(nullptr) {}

template <typename Key, typename value_type>
TreeIterator<Key, value_type>::TreeIterator(TreeNode<Key, value_type>* value)
    : unit(value) {}

template <typename Key, typename value_type>
value_type& TreeIterator<Key, value_type>::operator*() {
  if (unit)
    return unit->data;
  else
    throw std::runtime_error("Iterator is pointing to nullptr");
}

template <typename Key, typename value_type>
TreeIterator<Key, value_type>& TreeIterator<Key, value_type>::operator++() {
  if (!unit) return *this;
  TreeNode<Key, value_type>* tmp = unit;
  if (unit->right) {  // если есть правый потомок,
    tmp = unit->right;
    tmp->parent = unit;
    while (tmp->left) {  // то ищем там минимальный
      tmp = tmp->left;
    }  // и это будет следующий по величине узел
  } else {
    while (tmp->parent && tmp->parent->right == tmp) {
      tmp = tmp->parent;
    }
    tmp = tmp->parent;
  }
  unit = tmp;
  return *this;
}

template <typename Key, typename value_type>
TreeIterator<Key, value_type> TreeIterator<Key, value_type>::operator++(int) {
  TreeIterator temp(*this);
  operator++();
  return temp;
}

template <typename Key, typename value_type>
TreeIterator<Key, value_type>& TreeIterator<Key, value_type>::operator--() {
  if (!unit) return *this;
  TreeNode<Key, value_type>* tmp = unit;
  if (unit->left) {  // если есть левый потомок,
    tmp = unit->left;
    while (tmp->right) {  // то ищем там максимальный
      tmp = tmp->right;
    }  // и это будет следующий по величине узел
  } else {
    while (tmp->parent && tmp->parent->left == tmp) {
      tmp = tmp->parent;
    }
    tmp = tmp->parent;
  }
  unit = tmp;
  return *this;
}

template <typename Key, typename value_type>
TreeIterator<Key, value_type> TreeIterator<Key, value_type>::operator--(int) {
  TreeIterator temp(*this);
  operator--();
  return temp;
}

template <typename Key, typename value_type>
bool TreeIterator<Key, value_type>::operator==(const TreeIterator& other) {
  return unit == other.unit;
}

template <typename Key, typename value_type>
bool TreeIterator<Key, value_type>::operator!=(const TreeIterator& other) {
  return !(unit == other.unit);
}

////////// TreeConstIterator

template <typename Key, typename value_type>
TreeConstIterator<Key, value_type>::TreeConstIterator() : unit(nullptr) {}

template <typename Key, typename value_type>
TreeConstIterator<Key, value_type>::TreeConstIterator(
    TreeNode<Key, value_type>* value)
    : unit(value) {}

template <typename Key, typename value_type>
const value_type& TreeConstIterator<Key, value_type>::operator*() {
  if (unit)
    return unit->data;
  else
    throw std::runtime_error("Iterator is pointing to nullptr");
}

template <typename Key, typename value_type>
TreeConstIterator<Key, value_type>&
TreeConstIterator<Key, value_type>::operator++() {
  if (!unit) return *this;
  TreeNode<Key, value_type>* tmp = unit;
  if (unit->right) {  // если есть правый потомок,
    tmp = unit->right;
    tmp->parent = unit;
    while (tmp->left) {  // то ищем там минимальный
      tmp = tmp->left;
    }  // и это будет следующий по величине узел
  } else {
    while (tmp->parent && tmp->parent->right == tmp) {
      tmp = tmp->parent;
    }
    tmp = tmp->parent;
  }
  unit = tmp;
  return *this;
}

template <typename Key, typename value_type>
TreeConstIterator<Key, value_type>
TreeConstIterator<Key, value_type>::operator++(int) {
  TreeConstIterator temp(*this);
  operator++();
  return temp;
}

template <typename Key, typename value_type>
TreeConstIterator<Key, value_type>&
TreeConstIterator<Key, value_type>::operator--() {
  if (!unit) return *this;
  TreeNode<Key, value_type>* tmp = unit;
  if (unit->left) {  // если есть левый потомок,
    tmp = unit->left;
    while (tmp->right) {  // то ищем там максимальный
      tmp = tmp->right;
    }  // и это будет следующий по величине узел
  } else {
    while (tmp->parent && tmp->parent->left == tmp) {
      tmp = tmp->parent;
    }
    tmp = tmp->parent;
  }
  unit = tmp;
  return *this;
}

template <typename Key, typename value_type>
TreeConstIterator<Key, value_type>
TreeConstIterator<Key, value_type>::operator--(int) {
  TreeConstIterator temp(*this);
  operator--();
  return temp;
}

template <typename Key, typename value_type>
bool TreeConstIterator<Key, value_type>::operator==(
    const TreeConstIterator& other) {
  return unit == other.unit;
}

template <typename Key, typename value_type>
bool TreeConstIterator<Key, value_type>::operator!=(
    const TreeConstIterator& other) {
  return !(unit == other.unit);
}

////////////////////// TREE
////////////////////// CONSTRUCTORS

template <typename Key, typename T>
tree<Key, T>::tree() : root_(nullptr), end_(nullptr), size_(0) {
  Add_End();
}

template <typename Key, typename T>
tree<Key, T>::tree(std::initializer_list<value_type> const& items) : tree() {
  size_type n = items.size();
  if (n > max_size()) throw "Error max limit";
  for (size_type i = 0; i < n; i++) {
    insert(*(items.begin() + i));
  }
}

template <typename Key, typename T>
tree<Key, T>::tree(const tree& t) : tree() {
  clear();
  this->size_ = t.size_;
  root_ = CopyTree(t.root_, nullptr);
}

template <typename Key, typename T>
tree<Key, T>::tree(tree&& t) : tree() {
  swap(t);
  t.clear();
}

template <typename Key, typename T>
tree<Key, T>::~tree() {
  clear();
  if (end_) delete end_;
}

////////////////////// OPERATORS

template <typename Key, typename T>
tree<Key, T>& tree<Key, T>::operator=(tree&& t) {
  if (this == &t) return *this;
  swap(t);
  t.clear();
  return *this;
}

template <typename Key, typename T>
tree<Key, T>& tree<Key, T>::operator=(const tree& t) {
  if (this == &t) return *this;
  clear();
  this->size_ = t.size_;
  root_ = CopyTree(t.root_, nullptr);
  return *this;
}

////////////////////// PUBLIC FUNCTIONS

template <typename Key, typename T>
typename tree<Key, T>::iterator tree<Key, T>::begin() {
  if (!root_) return iterator(end_);
  TreeNode<Key, value_type>* tmp = root_;
  while (tmp->left) {
    tmp = tmp->left;
  }
  return iterator(tmp);
}

template <typename Key, typename T>
typename tree<Key, T>::iterator tree<Key, T>::end() {
  return iterator(end_);
}

template <typename Key, typename T>
typename tree<Key, T>::const_iterator tree<Key, T>::cbegin() {
  if (!root_) return const_iterator(end_);
  TreeNode<Key, value_type>* tmp = root_;
  while (tmp->left) {
    tmp = tmp->left;
  }
  return const_iterator(tmp);
}

template <typename Key, typename T>
typename tree<Key, T>::const_iterator tree<Key, T>::cend() {
  return const_iterator(end_);
}

template <typename Key, typename T>
bool tree<Key, T>::empty() {
  return (root_ == nullptr);
}

template <typename Key, typename T>
typename tree<Key, T>::size_type tree<Key, T>::size() {
  return size_;
}

template <typename Key, typename T>
typename tree<Key, T>::size_type tree<Key, T>::max_size() {
  return std::numeric_limits<size_type>::max() / sizeof(tree<Key, T>) / 5;
}

template <typename Key, typename T>
void tree<Key, T>::clear() {
  DelTreeNodeRecursion(root_);
  if (end_) delete end_;
  root_ = nullptr;
  end_ = nullptr;
}

template <typename Key, typename T>
std::pair<typename tree<Key, T>::iterator, bool> tree<Key, T>::insert(
    const value_type& value) {
  bool flag = false;
  std::pair<iterator, bool> pair(nullptr, flag);
  pair.first = RecursionInsert(root_, value, nullptr, flag);
  pair.second = flag;
  return pair;
}

template <typename Key, typename T>
void tree<Key, T>::erase(iterator pos) {
  DelTreeNode(pos.unit);
  UpdateHeight(root_);
  UpdateBalance(root_);
}

template <typename Key, typename T>
void tree<Key, T>::swap(tree& other) {
  std::swap(this->root_, other.root_);
  std::swap(this->end_, other.end_);
  std::swap(this->size_, other.size_);
}

template <typename Key, typename T>
void tree<Key, T>::merge(tree& other) {
  if (this == &other) return;
  if (other.root_ == nullptr) return;
  if (root_ == nullptr) {
    swap(other);
  } else {
    s21::vector<iterator> pos_to_erase{};
    iterator iter = other.begin();
    for (; iter != nullptr; iter++) {
      if (find(iter.unit->data) == nullptr) {  // для multiset убрать
        insert(iter.unit->data);
        pos_to_erase.push_back(iter);
      }
    }
    for (size_t i = 0; i < pos_to_erase.size(); i++) {
      other.erase(pos_to_erase[i]);
    }
  }
}

template <typename Key, typename T>
typename tree<Key, T>::const_iterator tree<Key, T>::find(
    const value_type& value) const {
  if (!root_) return nullptr;
  TreeNode<Key, value_type>* tmp = root_;
  while (tmp) {
    if (value == tmp->data) {
      return const_iterator(tmp);
    } else if (value < tmp->data) {
      tmp = tmp->left;
    } else {
      tmp = tmp->right;
    }
  }
  return nullptr;
}

template <typename Key, typename T>
bool tree<Key, T>::contains(const Key& key) {
  if (find(key) != nullptr) return true;
  return false;
}

template <typename Key, typename T>
template <typename... Args>
s21::vector<std::pair<typename tree<Key, T>::iterator, bool>>
tree<Key, T>::insert_many(Args&&... args) {
  s21::vector<std::pair<iterator, bool>> my_vector;
  bool flag = false;
  std::pair<iterator, bool> pair(nullptr, flag);

  for (auto i : {std::forward<Args>(args)...}) {
    flag = false;
    pair.first = RecursionInsert(root_, i, nullptr, flag);
    pair.second = flag;
    my_vector.push_back(pair);
  }
  return my_vector;
}

////////////////////// PRIVATE FUNCTIONS

template <typename Key, typename T>
void tree<Key, T>::DelTreeNodeRecursion(TreeNode<Key, value_type>* root) {
  if (root) {
    DelTreeNodeRecursion(root->left);
    DelTreeNodeRecursion(root->right);
    delete root;
    size_--;
  }
  root = nullptr;
}

template <typename Key, typename T>
void tree<Key, T>::TurnR(TreeNode<Key, value_type>*(&root),
                         TreeNode<Key, value_type>* parent) {
  TreeNode<Key, value_type>* left_subtree;
  TreeNode<Key, value_type>* right_subtree_for_left_subtree;

  left_subtree = root->left;
  left_subtree->parent = parent;
  right_subtree_for_left_subtree = left_subtree->right;

  left_subtree->right = root;
  left_subtree->right->parent = left_subtree;
  root->left = right_subtree_for_left_subtree;
  root = left_subtree;
  UpdateHeight(root);
}

template <typename Key, typename T>
void tree<Key, T>::TurnL(TreeNode<Key, value_type>*(&root),
                         TreeNode<Key, value_type>* parent) {
  TreeNode<Key, value_type>* right_subtree;
  TreeNode<Key, value_type>* left_subtree_for_right_subtree;

  right_subtree = root->right;
  right_subtree->parent = parent;
  left_subtree_for_right_subtree = right_subtree->left;

  right_subtree->left = root;
  right_subtree->left->parent = right_subtree;
  root->right = left_subtree_for_right_subtree;
  root = right_subtree;
}

template <typename Key, typename T>
int tree<Key, T>::UpdateHeight(TreeNode<Key, value_type>*(&root)) {
  if (!root) return 0;
  int l_height = UpdateHeight(root->left);
  int r_height = UpdateHeight(root->right);
  root->height = ((l_height > r_height) ? l_height : r_height) + 1;
  return root->height;
}

template <typename Key, typename T>
int tree<Key, T>::UpdateBalance(TreeNode<Key, value_type>*(&root)) {
  if (!root) return 0;
  int l_height = UpdateBalance(root->left);
  int r_height = UpdateBalance(root->right);
  if (l_height - r_height > 1) {
    if (UpdateBalance(root->left->right) > UpdateBalance(root->left->left))
      TurnL(root->left, root);
    TurnR(root, root->parent);
  } else if (l_height - r_height < -1) {
    if (UpdateBalance(root->right->left) > UpdateBalance(root->right->right))
      TurnR(root->right, root);
    TurnL(root, root->parent);
  }
  UpdateHeight(root);
  return root->height;
}

template <typename Key, typename T>
void tree<Key, T>::Check() {
  UpdateHeight(root_);
  UpdateBalance(root_);
}

template <typename Key, typename T>
typename tree<Key, T>::iterator tree<Key, T>::RecursionInsert(
    TreeNode<Key, value_type>*(&root), value_type value,
    TreeNode<Key, value_type>* parent, bool& flag) {
  iterator iter = iterator(root);
  if (!root) {
    root = new TreeNode<Key, value_type>(value);
    if (!root) throw "bad alloc";
    root->parent = parent;
    size_++;
    flag = true;
    iter = iterator(root);
  } else {
    if (value < root->data) {
      flag = false;
      iter = RecursionInsert(root->left, value, root, flag);
    } else {
      flag = false;
      iter = RecursionInsert(root->right, value, root, flag);
    }
  }
  UpdateHeight(root_);
  UpdateBalance(root_);
  return iter;
}

template <typename Key, typename T>
void tree<Key, T>::CheckParent(TreeNode<Key, value_type>* root_parent,
                               TreeNode<Key, value_type>*(&root),
                               TreeNode<Key, value_type>* result) {
  if (root_parent) {
    root_parent->left == root ? root_parent->left = result
                              : root_parent->right = result;
    if (root) FreeRoot(root);
    if (result) {
      result->parent = root_parent;
      root = result;
    }
  }
}

template <typename Key, typename T>
void tree<Key, T>::FreeRoot(TreeNode<Key, T>*(&root)) {
  if (root) {
    delete root;
    root = nullptr;
  }
}

template <typename Key, typename T>
TreeNode<Key, T>* tree<Key, T>::DelTreeNode(TreeNode<Key, T>* root) {
  if (!root) return nullptr;
  TreeNode<Key, value_type>* root_left = root->left;
  TreeNode<Key, value_type>* root_right = root->right;
  TreeNode<Key, value_type>* root_parent = root->parent;

  if (!root_left && !root_right) {
    CheckParent(root_parent, root, nullptr);
    if (!root_parent) {
      FreeRoot(root);
      root_ = root_right;
    }
    size_--;
  } else if (!root_left) {
    CheckParent(root_parent, root, root_right);
    if (!root_parent) {
      FreeRoot(root);
      root_ = root_right;
      root_->parent = nullptr;
    }
    size_--;
  } else if (!root_right) {
    CheckParent(root_parent, root, root_left);
    size_--;
  } else {
    TreeNode<Key, value_type>* tmp = FindMin(root->right);
    if (tmp->parent->left == tmp) {
      tmp->parent->left = tmp->right;
    } else if (tmp->parent->right == tmp) {
      tmp->parent->right = tmp->right;
    }
    CheckParent(root_parent, root, tmp);
    if (tmp->right) tmp->right->parent = tmp->parent;
    tmp->parent = root_parent;
    tmp->left = root_left;
    root_left->parent = tmp;
    if (root_right != tmp) {
      tmp->right = root_right;
      root_right->parent = tmp;
    }
    if (!root_parent) {
      FreeRoot(root);
      root_ = tmp;
    }
    root = tmp;
    size_--;
  }
  return root_;
}

template <typename Key, typename T>
TreeNode<Key, T>* tree<Key, T>::FindMin(TreeNode<Key, T>* tmp) {
  while (tmp->left) tmp = tmp->left;
  return tmp;
}

template <typename Key, typename T>
void tree<Key, T>::Add_End() {
  end_ = new (std::nothrow) TreeNode<Key, T>();
  if (!end_) throw "bad alloc";
}

template <typename Key, typename T>
TreeNode<Key, T>* tree<Key, T>::CopyTree(TreeNode<Key, T>* root,
                                         TreeNode<Key, T>* parent) {
  if (!root) return nullptr;
  TreeNode<Key, T>* new_TreeNode = new TreeNode<Key, T>(root->data);
  if (!new_TreeNode) throw "bad alloc";
  new_TreeNode->parent = parent;
  new_TreeNode->left = CopyTree(root->left, root);
  new_TreeNode->right = CopyTree(root->right, root);

  return new_TreeNode;
}