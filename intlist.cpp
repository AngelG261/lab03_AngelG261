// intlist.cpp
// Angel Gutierrez, April 22nd 2021

#include "intlist.h"
#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {

    Node* p = source.first;
    Node* currentNode = nullptr;

    first = new Node{p->info, nullptr};
    currentNode = first;

    p = p->next;
    while(p)             
    {
        currentNode->next = new Node;
        currentNode = currentNode->next;
        currentNode->info = p->info;
        currentNode->next = nullptr;
        p = p->next;                
    }
}


// destructor deletes all nodes
IntList::~IntList() {
    while(first)
        {
            Node* nextNode;
            nextNode = first->next;
            delete first;
            first = nextNode;
        }
        first = nullptr;
}

// return sum of values in list
int IntList::sum() const {
    int summation(0);
    Node* p = first;
    while(p)
    {
        summation += p->info;
        p = p->next;
    }
    return summation;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* p = first;

    while(p)
    {
        if(value == p->info)
        {
            return true;
        }
        p = p->next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    Node* p = first;

    if(!p)
    {
        return 0;
    }

    int maxVal(p->info);

    while(p)
    {
        if(maxVal < p->info)
        {
            maxVal = p->info;
        }
        p = p->next;
    }
    return maxVal;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    Node* p = first;
    if(!p)
    {
        return 0;
    }
    double average(0.0), summation(0.0);
    int count(0);
    while(p)
    {
        summation += p->info;
        ++count;
        p = p->next;
    }
    average = summation / count;
    return average;
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    Node* newNode = new Node{value, nullptr};
    Node* p = first;

    if(!first)
    {
        first = newNode;
    }
    else {
        newNode->next = p;
        first = newNode;
    }
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //deletes existing nodes
    while(first)
        {
            Node* nextNode =  first-> next;
            delete first;
            first = nextNode;
        }
    first = nullptr;

    if(this != &source)
    {
        
        if(!source.first)
        {
            return *this;              //if it is empty, return it as is
        }

        Node* p = source.first;
        Node* current = nullptr;

        first = new Node{p->info, nullptr};
        current = first;
    
        p = p->next;
        while(p)                    //current is a  pointer to first so it is techincally just 
        {                           //adding nodes to first but it is doing so implicitly 
        current->next = new Node;
        current = current-> next;
        current->info = p->info;
        current->next = nullptr;
        p = p->next;                //traversing through p and adding new nodes if it is not null
        }
    }

    return *this;
}

// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}