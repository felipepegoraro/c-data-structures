/*
  author: Felipe S. Pegoraro
  date: March 16th, 2023
  about: implementation of a generic linked list class in C++
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
// todo: convert from O(n) to O(log n) if its possible
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
    

// getters: length, head and tail value
template <typename T>
size_t List<T>::get_length(void) { return length; }

template <typename T>
T List<T>::get_head_value(void)
{
  if (is_empty()) return T();
  return head->value;
}

template <typename T>
T List<T>::get_tail_value(void)
{
  if (is_empty()) return T();
  Node<T> *current = head;
  while (current->next != nullptr)
    current = current->next;
  return current->value;
}

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

// TODO: void reverse(void)
