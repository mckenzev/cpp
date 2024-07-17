#ifndef CPP2_S21_CONTAINERS_Tree_H_
#define CPP2_S21_CONTAINERS_Tree_H_

#include "../vector/s21_vector.h"

template <typename Key, typename value_type>
class TreeNode {
 public:
  value_type data;
  int height;
  TreeNode* left;
  TreeNode* right;
  TreeNode* parent;
  TreeNode(value_type value = value_type());
};

template <typename Key, typename value_type>
class TreeIterator {
 public:
  TreeNode<Key, value_type>* unit;
  TreeIterator();
  TreeIterator(TreeNode<Key, value_type>* value);
  value_type& operator*();
  TreeIterator& operator++();
  TreeIterator operator++(int);
  TreeIterator& operator--();
  TreeIterator operator--(int);
  bool operator==(const TreeIterator& other);
  bool operator!=(const TreeIterator& other);
};

template <typename Key, typename value_type>
class TreeConstIterator {
 public:
  TreeNode<Key, value_type>* unit;
  TreeConstIterator();
  TreeConstIterator(TreeNode<Key, value_type>* value);
  const value_type& operator*();
  TreeConstIterator& operator++();
  TreeConstIterator operator++(int);
  TreeConstIterator& operator--();
  TreeConstIterator operator--(int);
  bool operator==(const TreeConstIterator& other);
  bool operator!=(const TreeConstIterator& other);
};

template <typename Key, typename T>
class tree {
 public:
  using key_type = Key;
  using value_type = T;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = TreeIterator<Key, value_type>;
  using const_iterator = TreeConstIterator<Key, value_type>;
  using size_type = size_t;

  tree();
  tree(std::initializer_list<value_type> const& items);
  tree(const tree& t);
  tree(tree&& t);
  ~tree();
  tree<Key, T>& operator=(tree&& t);
  tree<Key, T>& operator=(const tree& t);

  iterator begin();
  iterator end();
  const_iterator cbegin();
  const_iterator cend();

  bool empty();
  size_type size();
  size_type max_size();

  void clear();
  std::pair<iterator, bool> insert(const value_type& value);
  void erase(iterator pos);
  void swap(tree& other);
  void merge(tree& other);

  const_iterator find(const value_type& key) const;
  bool contains(const Key& key);

  template <typename... Args>
  s21::vector<std::pair<iterator, bool>> insert_many(Args&&... args);

  TreeNode<Key, value_type>* root_;
  TreeNode<Key, value_type>* end_;
  size_type size_;
  void Add_End();
  void DelTreeNodeRecursion(TreeNode<Key, value_type>* root);
  TreeNode<Key, value_type>* DelTreeNode(TreeNode<Key, value_type>* root);
  void FreeRoot(TreeNode<Key, value_type>*(&root));
  void CheckParent(TreeNode<Key, value_type>* root_parent,
                   TreeNode<Key, value_type>*(&root),
                   TreeNode<Key, value_type>* result);
  TreeNode<Key, value_type>* FindMin(TreeNode<Key, value_type>* tmp);
  int UpdateHeight(TreeNode<Key, value_type>*(&root));
  int UpdateBalance(TreeNode<Key, value_type>*(&root));
  void Check();
  TreeNode<Key, value_type>* CopyTree(TreeNode<Key, value_type>* root,
                                      TreeNode<Key, value_type>* parent);

  int Height(TreeNode<Key, value_type>* root);
  void SetBalance(TreeNode<Key, value_type>*(&root));
  void TurnRight(TreeNode<Key, value_type>*(&root),
                 TreeNode<Key, value_type>* parent);
  void TurnLeft(TreeNode<Key, value_type>*(&root),
                TreeNode<Key, value_type>* parent);
  void TurnR(TreeNode<Key, value_type>*(&root),
             TreeNode<Key, value_type>* parent);
  void TurnL(TreeNode<Key, value_type>*(&root),
             TreeNode<Key, value_type>* parent);
  iterator RecursionInsert(TreeNode<Key, value_type>*(&root), value_type value,
                           TreeNode<Key, value_type>* parent, bool& flag);
};

#include "s21_tree.tpp"

#endif  // CPP2_S21_CONTAINERS_Tree_H_