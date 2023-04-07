/*
  author: Felipe S. Pegoraro
  date..: march 16th, 2023
  about.: implementation of a generic linked list class in C++
  source: github.com/felipepegoraro/c-data-structures/
*/

#include <iostream>
#include <string>
#include "./linked-list.h"

template <typename T>
List<T>::~List() { clear(); }

// delete all elements
template <typename T>
void List<T>::clear(void)
{
  Node<T> *current = head;
  while (current != nullptr)
  {
    Node<T> *next = current->next;
    delete current;
    current = next;
  }
  head = nullptr;
  length = 0;
}

// verify if list is empty
template <typename T>
bool List<T>::is_empty(void)
{
  return (length == 0) || (head == nullptr);
}

// just like push
template <typename T>
void List<T>::add(T value)
{
  Node<T> *node = new Node<T>(value);
  if (head == NULL){
    head = node;
  } else {
    Node<T> *current = head;
    while (current->next != nullptr) current = current->next;
    current->next = node;
  }
  length++;
}


// add a new element passing a index
template <typename T>
bool List<T>::insert(T value, size_t index)
{
  Node<T> *newnode = new Node<T>(value), *current = head;
  
  if (index > length)
  {
    delete newnode;
    return false;
  }

  if (index == 0) {
    newnode->next = head;
    head = newnode;
  } else {
    current = head;
    for (size_t i = 0; i < index - 1; i++)
      current = current->next;
    newnode->next = current->next;
    current->next = newnode;
  }
  return true;
}


// remove element by index
template <typename T>
bool List<T>::remove(size_t index)
{
  if (index >= length || is_empty()) return false;
  Node<T> *aux = nullptr, *current = head;

  if (index == 0) {
    head = current->next;
    delete current;
  } else {
    for (size_t i = 0; i < index - 1; i++)
      current = current->next;
    aux = current->next;
    current->next = aux->next;
    delete aux;
  }

  length--;
  return true;
}


// just like pop
template <typename T>
bool List<T>::remove_last(void)
{
  if (is_empty()) return false;

  if (length == 1)
  {
    delete head;
    head = nullptr;
    length = 0;
    return true;
  }

  Node<T> *current = head;
  while (current->next->next != nullptr) 
  current = current->next;

  delete current->next;
  current->next = nullptr;
  length--;
  return true;
}


// verify if value exists (using linear search)
// TODO: convert from O(n) to O(log n) if its possible
template <typename T>
bool List<T>::contains(T value)
{
  Node<T> *current = head;
  
  for (size_t i = 0; i < length; i++)
  {
    if (current->value == value)
      return true;
    current = current->next;
  }
  
  return false;
}


// getter: length
template <typename T>
size_t List<T>::get_length(void) { return length; }

template <typename T>
T List<T>::get_head_value(void)
{
  if (is_empty()) return T();
  return head->value;
}


// getter: tail
template <typename T>
T List<T>::get_tail_value(void)
{
  if (is_empty()) return T();
  Node<T> *current = head;
  while (current->next != nullptr)
    current = current->next;
  return current->value;
}


// aux fn: display the value of all elements
template <typename T>
void List<T>::display(void)
{
  if (is_empty())
    return;

  Node<T> *current = head;

  std::cout << "[ ";
  while (current != nullptr)
  {
    std::cout << current->value << " ";
    current = current->next;
  }
  std::cout << "]\n";

}


// reverse the order
template <typename T>
void List<T>::reverse(void)
{
  if (is_empty()) return;

  Node<T> *current  = head;
  Node<T> *previous = nullptr;
  Node<T> *next     = head->next;

  while (current != nullptr)
  {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }

  head = previous;
}

// getter: value by index
template <typename T>
T List<T>::get_value_by_index(size_t index)
{
  if (is_empty() || index >= length) return T();
  if (index == 0) return head->value;

  Node<T> *current = head;

  for (size_t i = 0; i < index; i++)
    current = current->next;

  return current->value;
}
