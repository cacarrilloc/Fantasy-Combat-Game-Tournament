/***********************************************************************
 ** Program Filename: QueueLineup1.cpp
 ** Author: Carlos Carrillo
 ** Date: 11/18/2015
 ** Description: QueueLineup1 class definition for a QueueLineup1 of strings.
 ***********************************************************************/

#ifndef QueueLineup1_hpp
#define QueueLineup1_hpp

#include <string>
#include <iostream>

class QueueLineup1
{
    
protected:
    // each node consists of a string value
    // and pointers to the next and previous nodes
    struct QueueLineup1Node
    {
        std::string value;
        QueueLineup1Node *next;
        QueueLineup1Node *prev;
        QueueLineup1Node(std::string name, QueueLineup1Node *n = NULL, QueueLineup1Node *p = NULL)
        {
            value = name;
            next = n;
            prev = p;
        }
    };
    QueueLineup1Node *front;  // front node
    QueueLineup1Node *back;   // back node
    
public:
    QueueLineup1() {front = NULL; back = NULL;}    // constructor, empty QueueLineup1
    ~QueueLineup1();                               // destructor
    void add(std::string);                        // add a node to the back
    std::string remove();                         // remove a node from the front
    std::string returnName();                     // return the front node
    void display() const;                         // display the QueueLineup1
};
#endif

