/**************************************************************************
 ** Program Filename: QueueLineup2.cpp
 ** Author: Carlos Carrillo
 ** Date: 11/18/2015
 ** Description: QueueLineup2 class methods for a QueueLineup2 of strings.
 **************************************************************************/

#include <iostream>
#include <string>
#include "QueueLineup2.hpp"

using namespace std;

/*********************************************************************
 ** Function: ~QueueLineup2
 ** Description: Destructor frees allocated memory.
 ** Parameters: none.
 ** Pre-Conditions: The QueueLineup2 must exist.
 ** Post-Conditions: All nodes will be deleted.
 *********************************************************************/
QueueLineup2::~QueueLineup2()
{
    QueueLineup2Node *nodePtr = front; // Start at head of list
    
    while (nodePtr != NULL){
        // garbage keeps track of node to be deleted
        QueueLineup2Node *trash = nodePtr;
        
        // Move on to the next node, if any
        nodePtr = nodePtr->next;
        
        // Delete the "garbage" node
        delete trash;}
}

/*********************************************************************
 ** Function: add
 ** Description: Add a node to the back of the QueueLineup2.
 ** Parameters: none.
 ** Pre-Conditions: The QueueLineup2 must exist.
 ** Post-Conditions: A node will be added to the back of the QueueLineup2.
 *********************************************************************/
void QueueLineup2::add(std::string item)
{
    if (front == NULL && back == NULL) {
        // add value to empty QueueLineup2
        front = back = new QueueLineup2Node(item);
        std::cout <<back->value<< " has been added to Lineup2.\n" << std::endl;}
    else {
        // add value to back of QueueLineup2
        QueueLineup2Node *lastIn = back;
        back = new QueueLineup2Node(item, back);
        lastIn->prev = back;
        std::cout <<back->value<< " has been added to the back of the line.\n"<<std::endl;}
}

/*********************************************************************
 ** Function: remove
 ** Description: Remove a node from the front of the QueueLineup2.
 ** Parameters: none.
 ** Pre-Conditions: The QueueLineup2 must exist.
 ** Post-Conditions: If the QueueLineup2 is not empty, a node will be removed
 **   from the front of the QueueLineup2.
 *********************************************************************/
std::string QueueLineup2::remove()
{
    std::string item = " ";
    
    if (front == NULL && back == NULL) {
        // the QueueLineup2 is empty
        std::cout << "The Lineup1 is empty." <<std::endl;}
    
    else if (front == back && front != NULL) {
        // just one item in QueueLineup2
        QueueLineup2Node *lastIn = back;
        std::cout <<lastIn->value << " has been removed from Lineup2.\n"<<std::endl;
        front = NULL;
        back = NULL;
        delete lastIn;}
    
    else {
        // more than one item in the QueueLineup2
        QueueLineup2Node *firstIn = front;
        item = firstIn->value;
        std::cout <<firstIn->value<< " has been removed from Lineup2.\n"<<std::endl;
        front = firstIn->prev;
        QueueLineup2Node *nextIn = firstIn->prev;
        nextIn->next = NULL;
        delete firstIn;}
    
    return item;
}

/*********************************************************************
 ** Function: returnName
 ** Description: Return the node at the front of the Lineup1.
 ** Parameters: none.
 ** Pre-Conditions: The QueueLineup2 must exist.
 ** Post-Conditions: If the QueueLineup2 is not empty *********************************************************************/
std::string QueueLineup2::returnName()
{
    std::string item2 = " ";
    
    // Return the item on the front of the line
    QueueLineup2Node *firstIn = front;
    item2 = firstIn->value;
    
    return item2;
}

/*********************************************************************
 ** Function: returnName
 ** Description: Display the entire QueueLineup2.
 ** Parameters: none.
 ** Pre-Conditions: The QueueLineup2 must exist.
 ** Post-Conditions: If the QueueLineup2 is not empty, the values in the
 **   QueueLineup2 will be printed in a row from front to back.
 *********************************************************************/
void QueueLineup2::display() const
{
    if (front == NULL && back == NULL) {
        // nothing to see here
        std::cout << "The QueueLineup2 is empty." << std::endl;}
    
    else {
        std::cout << "*** HERE'S THE TEAM #2 LINEUP (front to back) ***" <<std::endl;
        QueueLineup2Node *node = front;    // start at front
        
        while (node != NULL) {
            std::cout <<"Creature: "<<node->value<<std::endl;
            node = node->prev;}     // move back in the QueueLineup2
    }
}


