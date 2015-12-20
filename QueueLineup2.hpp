/**************************************************************************
 ** Program Filename: QueueLineup2.cpp
 ** Author: Carlos Carrillo
 ** Date: 11/18/2015
 ** Description: QueueLineup2 class definition for a QueueList of strings.
 **************************************************************************/

#ifndef QueueLineup2_hpp
#define QueueLineup2_hpp

#include <string>
#include <iostream>

class QueueLineup2
{
    
protected:
    // each node consists of a string value
    // and pointers to the next and previous nodes
    struct QueueLineup2Node
    {
        std::string value;
        QueueLineup2Node *next;
        QueueLineup2Node *prev;
        QueueLineup2Node(std::string name, QueueLineup2Node *n = NULL, QueueLineup2Node *p = NULL)
        {
            value = name;
            next = n;
            prev = p;
        }
    };
    QueueLineup2Node *front;  // front node
    QueueLineup2Node *back;   // back node
    
public:
    QueueLineup2() { front = NULL; back = NULL; }  // constructor, empty QueueLineup2
    ~QueueLineup2();                               // destructor
    void add(std::string);                        // add a node to the back
    std::string remove();                         // remove a node from the front
    std::string returnName();                     // return the front node
    void display() const;                         // display the QueueLineup2
};
#endif

