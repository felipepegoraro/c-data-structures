#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

template <typename T>
struct Node {
  T value;
  Node<T> *next;

  Node(T v) :  value(v), next(nullptr){}
};

template <typename T>
class List {
  private:
    std::string name;
    Node<T> *head;
    size_t length;

  public:
    List(const std::string& name) :
      name(name),
      head(nullptr),
      length(0){}

    ~List(void);

    void clear(void);
    bool is_empty(void);
    void add(T value);
    bool insert(T value, size_t index);
    bool remove(size_t index);
    bool remove_last(void);
    bool contains(T value);
    size_t get_length(void);
    T get_head_value(void);
    T get_tail_value(void);
    void display(void);
    void reverse(void);
    T get_value_by_index(size_t);
};

#endif // !LINKED_LIST_H
