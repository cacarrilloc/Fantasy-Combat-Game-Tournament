/*********************************************************
 ** Author: Carlos Carrillo                              *
 ** Date:   11/14/2015                                   *
 ** Description: This is the class specification file    *
 *  of a class called QueueWin. This class Implement an  *
 *  abstract data type using linked structures           *
 ********************************************************/

#ifndef QueueWin_hpp
#define QueueWin_hpp

#include <iostream>
#include <string>

class QueueWin
{
    
protected:
    // each node consists of a string value
    // and pointers to the next and previous nodes
    struct QueueWinNode
    {
        std::string value;
        QueueWinNode *next;
        QueueWinNode *prev;
        QueueWinNode(std::string name, QueueWinNode *n = NULL, QueueWinNode *p = NULL)
        {
            value = name;
            next = n;
            prev = p;
        }
    };
    QueueWinNode *front;  // front node
    QueueWinNode *back;   // back node
    
public:
    QueueWin() {front = NULL; back = NULL;}       // constructor, empty QueueWin
    ~QueueWin();                                  // destructor
    void add(std::string);                        // add a node to the back
    std::string remove();                         // remove a node from the front
    std::string returnName();                     // return the front node
    void display() const;                         // display the QueueWin
};

#endif



