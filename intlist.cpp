// intlist.cpp
// Implements class IntList
// Angel Gutierrez, April 22nd
//YOUR NAME(S), AND DATE

#include "intlist.h"
#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    //IMPLEMENT THIS
     if(source.first == nullptr)
    {
        return;
    }

    Node* p = source.first;
    Node* current = nullptr;
    first = new Node;

    first->info = p->info;
    first->next = nullptr;
    current = first;
    
    p = p->next;
    while(p)            //current is a  pointer to first so it is techincally just 
    {                      //adding nodes to first but it is doing so implicitly 
        current->next = new Node;
        current = current-> next;
        current->info = p->info;
        current->next = nullptr;
        p = p->next;                //traversing through p and adding new nodes if it is not null
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    //IMPLEMENT THIS
    //while(first)
   // {
        /*
        Node* p = track->p;
        delete track;
        track = p;
        */
         while(first)
        {
            Node* next =  first-> next;
            delete first;
            first = next;
        }

    
        
    //}



}


// return sum of values in list
int IntList::sum() const {
    int sum(0);
    Node* p = first;
    while(p)
    {
        sum += p->info;
        p = p->next;
    }
    return sum; // REPLACE THIS NON-SOLUTION
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
    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    Node* p = first;
    if(!p)
    {
        return 0;
    }
    int max(p->info);
    while(p)
    {
        if(max < p->info)
        {
            max = p->info;
        }
        p = p->next;
    }
    return max; // REPLACE THIS NON-SOLUTION
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    Node* p = first;
    if(!p)
    {
        return 0;
    }
    double average(0.0), sum(0.0);
    int count(0);
    while(p)
    {
        sum += p->info;
        ++count;
        p = p->next;
    }
    average = sum / count;
    return average; // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    Node* newNode = new Node;
    Node* p = first;

    newNode->info = value;
    newNode->next = nullptr;

    if(first == nullptr)
    {
        first = newNode;
    }
    else {
        newNode->next = p;
        first = newNode;
    }
    // IMPLEMENT
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //IMPLEMENT
    
    /*


    */

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