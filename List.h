/*
 * Name: Shaine O'Neal
 * Date Submitted: 9/15/2022
 * Lab Section: 004
 * Assignment Name: Lab 1
 */

#pragma once

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>
class List{

    private:
        Node<T> * start; //pointer to the first node in this list
        int mySize;  //size (or length) of this list

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

  //Print the name and this list's size and values to stdout
  //This function is already implemented (no need to change it)
    void print(string name){
        cout << name << ": ";
        cout << "size = " << size();
        cout << ", values = ";
        Node<T> * iterator = start;
        while(iterator != nullptr){
            cout << iterator->value << ' ';
            iterator = iterator->next;
        }
        cout << endl;
    }
}; //end of class interface (you may modify the code below)

//Implement all of the functions below
//Construct an empty list by initializing this list's instance variables
template <class T>
List<T>::List(){
  //create an empty list of size 0
    start = nullptr;
    mySize = 0;
}

//Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List(){
    Node<T> * i = start;

    while(i != NULL) {
        Node<T> * temp = i;
        i = i->next;
        delete temp;
    }
}

//Return the size of this list
template <class T>
int List<T>::size(){
    return mySize;
}

//Return true if this list is empty
//Otherwise, return false
template <class T>
bool List<T>::empty(){
    if(size() == 0) { return true; }

    else { return false; }
}

//Create a new node with value, and insert that new node
//into this list at start
template <class T>
void List<T>::insertStart(T value){
    Node<T> * newNode = new Node<T>(value);

    newNode->next = start;
    start = newNode;

    mySize++;
}

//Create a new node with value, and insert that new node
//into this list at end
template <class T>
void List<T>::insertEnd(T value){
    Node<T> * newNode = new Node<T>(value);
    Node<T> * i = start;

  //if newNode is first node added
    if(start == nullptr) { insertStart(value); }

  //else search for last node in list
    else{
        while(i != NULL && i->next != NULL) {
            i = i->next;
        }
    i->next = newNode;
    mySize++;
    }
}



//Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j){
    Node<T> * newNode = new Node<T>(value);
    Node<T> * i = start;

    //if position is 0
    if(j == 0) { insertStart(value); }
    else if(j > mySize) { insertEnd(value); }

    //otherwise
    else{
        for(int f = 0; f < j - 1; f++) {
            i = i->next;
        }
        newNode->next = i->next;
        i->next = newNode;
        mySize++;
    }

    
}   

//Remove node at start
//Make no other changes to list
template <class T>
void List<T>::removeStart(){
    Node<T> * temp = start;
    //if(temp->next != NULL && temp != NULL) {
        start = temp->next;
        delete temp;
        mySize--;
    //}
}

//Remove node at end
//Make no other changes to list
template <class T>
void List<T>::removeEnd(){
    Node<T> * i = start;

    if(i->next == nullptr){
        delete i;
        start = nullptr;
        mySize--;
    }

    else if(i != nullptr){

        //find and move i to second to last node
        while(i->next->next != NULL) {
            i = i->next;
        }

        delete i->next;

        i->next = nullptr;

        mySize--;
    }
}

//Remove node at position j
//Make no other changes to list
template <class T>
void List<T>::removeAt(int j){
    Node<T> * i = start;

    if(j == 0) {
        start = i->next;
        delete i;
    }
    else {
        for(int f = 0; f < j - 2; f++) {
            i = i->next;
        }

        Node<T> * temp = i;

        temp = i->next->next;

        delete i->next;

        i->next = temp;
    }

    mySize--;
}

//Return the value of the first node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst(){
    if(start == nullptr) { return T(); }
    return start->value;
}

//Return the value of the last node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast(){
    if(start == nullptr) { return T(); }
    Node<T> * i = start;

    while(i->next != NULL) {
        i = i->next;
    }

    return i->value;
}

//Return the value of the node at position j in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j){
    Node<T> * i = start;

    if(start == nullptr) { return T(); }
    for(int f = 0; f < j; f++) {
        i = i->next;
    }
    return i->value;
}

//Return the position of the (first) node whose value is equal to the key
//Otherwise, return -1
template <class T>
int List<T>::find(T key){
    Node<T> * i = start;
    int pos = 0;

    while(i->next != NULL) {
        if(i->value == key) { return pos; }
        i = i->next;
        pos++;
    }

    return -1; 

}
