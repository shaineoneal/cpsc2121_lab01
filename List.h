/*
 * Name:
 * Date Submitted:
 * Lab Section:
 * Assignment Name:
 */

#pragma once

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

// This class represents a linked list of node objects
// Do not modify anything in the class interface
template <class T>
class List
{

private:
  Node<T> *start; // pointer to the first node in this list
  int mySize;     // size (or length) of this list

public:
  List();
  ~List();
  int size();
  bool empty();
  void insertStart(T);
  void insertEnd(T);
  void insertAt(T, int);
  void removeStart();
  void removeEnd();
  void removeAt(int);
  T getFirst();
  T getLast();
  T getAt(int);
  int find(T);

  // Print the name and this list's size and values to stdout
  // This function is already implemented (no need to change it)
  void print(string name)
  {
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> *iterator = start;
    while (iterator != nullptr)
    {
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }

}; // end of class interface (you may modify the code below)

// Implement all of the functions below
// Construct an empty list by initializing this list's instance variables
template <class T>
List<T>::List()
{
  start = NULL;
  mySize = 0;
}

// Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List()
{
  Node<T> *iterator;
  iterator = start;

  for (int count = 0; count < mySize; count++)
  {
    Node<T> *del;
    del = iterator;
    iterator = del->next;
    delete del;
  }
}

// Return the size of this list
template <class T>
int List<T>::size()
{
  Node<T> *iterator = start;

  while(iterator->next != NULL) { mySize++; }
  return mySize;
}

// Return true if this list is empty
// Otherwise, return false
template <class T>
bool List<T>::empty()
{
  if (mySize == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Create a new node with value, and insert that new node
// into this list at start
template <class T>
void List<T>::insertStart(T value)
{

  Node<T> *temp = new Node<T>(value);
  if(start == NULL) {
    start = temp;
  }
else{
  temp->next = start;
  start = temp;
}
}

// Create a new node with value, and insert that new node
// into this list at end
template <class T>
void List<T>::insertEnd(T value)
{
  Node<T> *temp = new Node<T>(value);
  Node<T> *iterator = start;

  if(iterator == NULL) {
    start = temp;
    return;
  }

  while (iterator->next != nullptr)
  {
    iterator = iterator->next;
  }

  iterator->next = temp;
}

// Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j)
{
  Node<T> *temp = new Node<T>(value);
  Node<T> *iterator = start;
  int position = 0;

  if(j == 0) { 
    insertStart(value);
    return;
  }

  else{
  while (position != j-1 && j>1)
  {
    iterator = iterator->next;
    position++;
  }

  temp->next = iterator->next;
  iterator->next = temp;
  }
}

// Remove node at start
// Make no other changes to list
template <class T>
void List<T>::removeStart()
{
  Node<T> *iterator = start;
  start = iterator->next;
  
  delete iterator;
}

// Remove node at end
// Make no other changes to list
template <class T>
void List<T>::removeEnd()
{
  Node<T> *iterator = start;

  while (iterator->next != NULL)
  {
    iterator = iterator->next;
  }

  delete iterator;
}

// Remove node at position j
// Make no other changes to list
template <class T>
void List<T>::removeAt(int j)
{
  int position = 0;
  Node<T> *iterator = start;

  while (position != j)
  {
    iterator = iterator->next;
    position++;
  }
}

// Return the value of the first node in the Linked List,
// If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst()
{
  if (mySize == 0)
  {
    return T();
  }

  return start->value;
}

// Return the value of the last node in the Linked List,
// If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast()
{
  if (mySize == 0)
  {
    return T();
  }

  Node<T> *iterator = start;

  while (iterator->next != NULL)
  {
    iterator = iterator->next;
  }

  return iterator->value;
}

// Return the value of the node at position j in the Linked List,
// If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j)
{
  if (mySize == 0)
  {
    return T();
  }

  Node<T> *iterator = start;

  int position = 0;

  while (position != j)
  {
    iterator = iterator->next;
    position++;
  }

  return iterator->value;
}

// Return the position of the (first) node whose value is equal to the key
// Otherwise, return -1
template <class T>
int List<T>::find(T key)
{
  Node<T> *iterator = start;
  int position = 0;

  while (iterator->data != key && position < mySize)
  {
    iterator = iterator->next;
    position++;
  }

  if (iterator->value != key)
  {
    return -1;
  }

  return position;
}
