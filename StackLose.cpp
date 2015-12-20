/***********************************************************************
 ** Program Filename: StackLose.cpp
 ** Author: Carlos Carrillo
 ** Date: 11/18/2015
 ** Description: StackLose class methods for a StackLose of strings.
 ***********************************************************************/

#include <iostream>
#include <string>
#include "StackLose.hpp"

using namespace std;

/*********************************************************************
 ** Function: ~StackLose
 ** Description: Destructor frees allocated memory.
 ** Parameters: none.
 ** Pre-Conditions: The StackLose must exist.
 ** Post-Conditions: All nodes will be deleted.
 *********************************************************************/
StackLose::~StackLose()
{
    StackLoseNode *nodePtr = front; // Start at head of list
    
    while (nodePtr != NULL){
        // garbage keeps track of node to be deleted
        StackLoseNode *trash = nodePtr;
        
        // Move on to the next node, if any
        nodePtr = nodePtr->next;
        
        // Delete the "garbage" node
        delete trash;}
}

/*********************************************************************
 ** Function: add
 ** Description: Add a node to the back of the StackLose.
 ** Parameters: none.
 ** Pre-Conditions: The StackLose must exist.
 ** Post-Conditions: A node will be added to the back of the StackLose.
 *********************************************************************/
void StackLose::add(std::string item)
{
    if (front == NULL && back == NULL) {
        // add value to empty StackLose
        front = back = new StackLoseNode(item);
        std::cout <<back->value<< " has been added to StackLose.\n" << std::endl;}
    else {
        // add value to back of StackLose
        StackLoseNode *lastIn = back;
        back = new StackLoseNode(item, back);
        lastIn->prev = back;
        std::cout <<back->value<< " has been added to the back of the line.\n"<<std::endl;}
}

/*********************************************************************
 ** Function: remove
 ** Description: Remove a node from the front of the StackLose.
 ** Parameters: none.
 ** Pre-Conditions: The StackLose must exist.
 ** Post-Conditions: If the StackLose is not empty, a node will be removed
 **   from the front of the StackLose.
 *********************************************************************/
std::string StackLose::remove()
{
    std::string item = " ";
    
    if (front == NULL && back == NULL) {
        // the StackLose is empty
        std::cout << "The StackLose is empty." <<std::endl;}
    else if (front == back && front != NULL) {
        // just one item in StackLose
        StackLoseNode *lastIn = back;
        //std::cout <<lastIn->value << " has been removed from StackLose."<<std::endl;
        front = NULL;
        back = NULL;
        delete lastIn;}
    
    else {
        // more than one item in the StackLose
        StackLoseNode *firstOut = back;
        item = firstOut->value;
        //std::cout <<firstOut->value<< " has been removed from StackLose."<<std::endl;
        back = firstOut->next;
        StackLoseNode *nextOut = firstOut->next;
        nextOut->prev = NULL;
        delete firstOut;}
    
    return item;
}

/*********************************************************************
 ** Function: returnName
 ** Description: Return the node at the front of the Lineup1.
 ** Parameters: none.
 ** Pre-Conditions: The StackLose must exist.
 ** Post-Conditions: If the StackLose is not empty *********************************************************************/
std::string StackLose::returnName()
{
    std::string item2 = " ";
    
    // Return the item on the front of the line
    StackLoseNode *backOut = back;
    item2 = backOut->value;
    
    return item2;
}

/*********************************************************************
 ** Function: returnName
 ** Description: Display the entire StackLose.
 ** Parameters: none.
 ** Pre-Conditions: The StackLose must exist.
 ** Post-Conditions: If the StackLose is not empty, the values in the
 **   StackLose will be printed in a row from front to back.
 *********************************************************************/
void StackLose::display() const
{
    if (front == NULL && back == NULL) {
        // nothing to see here
        std::cout << "The StackLose is empty." << std::endl;}
    
    else {
        std::cout <<"\n*** HERE'S THE LOSER PILE (front to back) ***" <<std::endl;
        StackLoseNode *node = front;    // start at front
        
        while (node != NULL) {
            std::cout <<"Creature: "<<node->value<<std::endl;
            node = node->prev;}     // move back in the StackLose
    }
}


