/***********************************************************************
 ** Program Filename: StackLose.cpp
 ** Author: Carlos Carrillo
 ** Date: 11/18/2015
 ** Description: StackLose class definition for a StackLose of strings.
 ***********************************************************************/

#ifndef StackLose_hpp
#define StackLose_hpp

#include <string>
#include <iostream>

class StackLose
{
protected:
    // each node consists of a string value
    // and pointers to the next and previous nodes
    struct StackLoseNode
    {
        std::string value;
        StackLoseNode *next;
        StackLoseNode *prev;
        StackLoseNode(std::string name, StackLoseNode *n = NULL, StackLoseNode *p = NULL)
        {
            value = name;
            next = n;
            prev = p;
        }
    };
    StackLoseNode *front;  // front node
    StackLoseNode *back;   // back node
    
public:
    StackLose() {front = NULL; back = NULL;}    // constructor, empty StackLose
    ~StackLose();                               // destructor
    void add(std::string);                      // add a node to the back
    std::string remove();                       // remove a node from the front
    std::string returnName();                   // return the front node
    void display() const;                       // display the StackLose
};
#endif

