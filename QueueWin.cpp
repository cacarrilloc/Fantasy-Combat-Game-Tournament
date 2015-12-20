/*********************************************************
 ** Author: Carlos Carrillo                              *
 ** Date:   11/14/2015                                   *
 ** Description: This is the class implementation file   *
 *  of a class called QueueWin. This class Implement an  *
 *  abstract data type using linked structures           *
 ********************************************************/

#include <iostream>
#include <string>
#include "QueueWin.hpp"

using namespace std;

/*********************************************************************
 ** Function: ~QueueWin
 ** Description: Destructor frees allocated memory.
 ** Parameters: none.
 ** Pre-Conditions: The QueueWin must exist.
 ** Post-Conditions: All nodes will be deleted.
 *********************************************************************/
QueueWin::~QueueWin()
{
    QueueWinNode *nodePtr = front; // Start at head of list
    
    while (nodePtr != NULL){
        // garbage keeps track of node to be deleted
        QueueWinNode *trash = nodePtr;
        
        // Move on to the next node, if any
        nodePtr = nodePtr->next;
        
        // Delete the "garbage" node
        delete trash;}
}

/*********************************************************************
 ** Function: add
 ** Description: Add a node to the back of the QueueWin.
 ** Parameters: none.
 ** Pre-Conditions: The QueueWin must exist.
 ** Post-Conditions: A node will be added to the back of the QueueWin.
 *********************************************************************/
void QueueWin::add(std::string item)
{
    if (front == NULL && back == NULL) {
        // add value to empty QueueWin
        front = back = new QueueWinNode(item);
        std::cout <<back->value<< " has been added to the WINNER PILE." << std::endl;}
    else {
        // add value to back of QueueWin
        QueueWinNode *lastIn = back;
        back = new QueueWinNode(item, back);
        lastIn->prev = back;
        std::cout <<back->value<< " has been added to the back of the WINNER PILE."<<std::endl;}
}

/*********************************************************************
 ** Function: remove
 ** Description: Remove a node from the front of the QueueWin.
 ** Parameters: none.
 ** Pre-Conditions: The QueueWin must exist.
 ** Post-Conditions: If the QueueWin is not empty, a node will be removed
 **   from the front of the QueueWin.
 *********************************************************************/
std::string QueueWin::remove()
{
    std::string item = " ";
    
    if (front == NULL && back == NULL) {
        // the QueueWin is empty
        std::cout << "The winner pile is empty." <<std::endl;}
    
    else if (front == back && front != NULL) {
        // just one item in QueueWin
        QueueWinNode *lastIn = back;
        std::cout <<"\n"<<lastIn->value << " has been removed from the WINNER PILE.\n"<<std::endl;
        front = NULL;
        back = NULL;
        delete lastIn;}
    
    else {
        // more than one item in the QueueWin
        QueueWinNode *firstIn = front;
        item = firstIn->value;
        std::cout <<"\n"<<firstIn->value<< " has been removed from the WINNER PILE.\n"<<std::endl;
        front = firstIn->prev;
        QueueWinNode *nextIn = firstIn->prev;
        nextIn->next = NULL;
        delete firstIn;}
    
    return item;
}

/*********************************************************************
 ** Function: returnName
 ** Description: Return the node at the front of the Lineup1.
 ** Parameters: none.
 ** Pre-Conditions: The QueueWin must exist.
 ** Post-Conditions: If the QueueWin is not empty *********************************************************************/
std::string QueueWin::returnName()
{
    std::string item2 = " ";
    
    // Return the item on the front of the line
    QueueWinNode *firstIn = front;
    item2 = firstIn->value;
    
    return item2;
}

/*********************************************************************
 ** Function: display
 ** Description: Display the entire QueueWin.
 ** Parameters: none.
 ** Pre-Conditions: The QueueWin must exist.
 ** Post-Conditions: If the QueueWin is not empty, the values in the
 **   QueueWin will be printed in a row from front to back.
 *********************************************************************/
void QueueWin::display() const
{
    if (front == NULL && back == NULL) {
        // nothing to see here
        std::cout << "The QueueWin is empty." << std::endl;}
    
    else {
        std::cout << "*** HERE'S THE WINNER PILE (front to back) ***" <<std::endl;
        QueueWinNode *node = front;    // start at front
        
        while (node != NULL) {
            std::cout <<"Creature: "<<node->value<<std::endl;
            node = node->prev;}     // move back in the QueueWin
    }
}

