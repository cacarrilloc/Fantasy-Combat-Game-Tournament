/***********************************************************************
 ** Program Filename: QueueLineup1.cpp
 ** Author: Carlos Carrillo
 ** Date: 11/18/2015
 ** Description: QueueLineup1 class methods for a QueueLineup1 of strings.
 ***********************************************************************/

#include <iostream>
#include <string>
#include "QueueLineup1.hpp"

using namespace std;

/*********************************************************************
 ** Function: ~QueueLineup1
 ** Description: Destructor frees allocated memory.
 ** Parameters: none.
 ** Pre-Conditions: The QueueLineup1 must exist.
 ** Post-Conditions: All nodes will be deleted.
 *********************************************************************/
QueueLineup1::~QueueLineup1()
{
    QueueLineup1Node *nodePtr = front; // Start at head of list
    
    while (nodePtr != NULL){
        // garbage keeps track of node to be deleted
        QueueLineup1Node *trash = nodePtr;
        
        // Move on to the next node, if any
        nodePtr = nodePtr->next;
        
        // Delete the "garbage" node
        delete trash;}
}

/*********************************************************************
 ** Function: add
 ** Description: Add a node to the back of the QueueLineup1.
 ** Parameters: none.
 ** Pre-Conditions: The QueueLineup1 must exist.
 ** Post-Conditions: A node will be added to the back of the QueueLineup1.
 *********************************************************************/
void QueueLineup1::add(std::string item)
{
    if (front == NULL && back == NULL) {
        // add value to empty QueueLineup1
        front = back = new QueueLineup1Node(item);
        std::cout <<back->value<< " has been added to Lineup1.\n" << std::endl;}
    else {
        // add value to back of QueueLineup1
        QueueLineup1Node *lastIn = back;
        back = new QueueLineup1Node(item, back);
        lastIn->prev = back;
        std::cout <<back->value<< " has been added to the back of the line.\n"<<std::endl;}
}

/*********************************************************************
 ** Function: remove
 ** Description: Remove a node from the front of the QueueLineup1.
 ** Parameters: none.
 ** Pre-Conditions: The QueueLineup1 must exist.
 ** Post-Conditions: If the QueueLineup1 is not empty, a node will be removed
 **   from the front of the QueueLineup1.
 *********************************************************************/
std::string QueueLineup1::remove()
{
    std::string item = " ";
    
    if (front == NULL && back == NULL) {
        // the QueueLineup1 is empty
        std::cout << "The Lineup1 is empty." <<std::endl;}
    
    else if (front == back && front != NULL) {
        // just one item in QueueLineup1
        QueueLineup1Node *lastIn = back;
        std::cout <<lastIn->value << " has been removed from Lineup1."<<std::endl;
        front = NULL;
        back = NULL;
        delete lastIn;}
    
    else {
        // more than one item in the QueueLineup1
        QueueLineup1Node *firstIn = front;
        item = firstIn->value;
        std::cout <<firstIn->value<< " has been removed from Lineup1."<<std::endl;
        front = firstIn->prev;
        QueueLineup1Node *nextIn = firstIn->prev;
        nextIn->next = NULL;
        delete firstIn;}
    
    return item;
}

/*********************************************************************
 ** Function: returnName
 ** Description: Return the node at the front of the Lineup1.
 ** Parameters: none.
 ** Pre-Conditions: The QueueLineup1 must exist.
 ** Post-Conditions: If the QueueLineup1 is not empty *********************************************************************/
std::string QueueLineup1::returnName()
{
    std::string item2 = " ";
    
        // Return the item on the front of the line
        QueueLineup1Node *firstIn = front;
        item2 = firstIn->value;
    
    return item2;
}

/*********************************************************************
 ** Function: returnName
 ** Description: Display the entire QueueLineup1.
 ** Parameters: none.
 ** Pre-Conditions: The QueueLineup1 must exist.
 ** Post-Conditions: If the QueueLineup1 is not empty, the values in the
 **   QueueLineup1 will be printed in a row from front to back.
 *********************************************************************/
void QueueLineup1::display() const
{
    if (front == NULL && back == NULL) {
        // nothing to see here
        std::cout << "The QueueLineup1 is empty." << std::endl;}
    
    else {
        std::cout << "*** HERE'S THE TEAM #1 LINEUP (front to back) ***" <<std::endl;
        QueueLineup1Node *node = front;    // start at front
        
        while (node != NULL) {
            std::cout <<"Creature: "<<node->value<<std::endl;
            node = node->prev;}     // move back in the QueueLineup1
    }
}


