/***********************************************************
 ** Author: Carlos Carrillo                                *
 ** Date:   11/21/2015                                     *
 ** Description: This is the main fuction to implement the *
 *  Creature abstract base class.                          *
 **********************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

#include "Creature.hpp"
#include "Barbarian.hpp"
#include "Reptile.hpp"
#include "Blue.hpp"
#include "Goblin.hpp"
#include "Shadow.hpp"
#include "QueueLineup1.hpp"
#include "QueueLineup2.hpp"
#include "QueueWin.hpp"
#include "StackLose.hpp"

using namespace std;

// Variables for drive program
double fuerzaAttack;
double fuerzaDefense;
std::string winnerWarrior;
std::string loserWarrior;
double totalStrengthPoints1;
double totalStrengthPoints2;
int team1Wins = 0;
int team2Wins = 0;
vector<double>scores;
vector<std::string>winners;

// Functions for drive program
void restoreStrength(std::string, double, std::string, double);//Restores Strength
void winner(std::string, double, std::string, double); // Keep track of the winners score
void objects(std::string, std::string); // Create the necessary object for a fight
void selectionSort(vector<double> &, vector<std::string> &); // Sort values
void displayVector(vector<double>, vector<std::string>); // Display results
int intValid(); // input validation function prototype for int type

int main ()
{
    std::string teamMemberName;
    int teamMember;
    int TEAMSIZE;
    
    
    QueueLineup1 myQueueLineup1; // create lineup1 object
    QueueLineup2 myQueueLineup2; // create lineup2 object
    StackLose myStackLose; // create object for the loser pile
    QueueWin myQueueWin; //create object for the winner pile
    
    cout <<"\n\n*** WELCOME TO CCC_FANTASY COMBAT TOURNAMENT ***"<<endl;
    
    //Prompt the user to enter the number of fighter for each lineup.
    cout<<"\nHOW MANY WARRIORS PER TEAM WOULD YOU LIKE?: ";
    TEAMSIZE = intValid();
    cout<<endl;
    
    // Menu for Team #1
    cout<<"\n*PLEASE SELECT THE WARRIORS FOR TEAM #1:*"<<endl;
    cout<< "Enter 1 to select BARBARIAN." <<endl;
    cout<< "Enter 2 to select REPTILE." <<endl;
    cout<< "Enter 3 to select BLUEMEN." <<endl;
    cout<< "Enter 4 to select GOBLIN." <<endl;
    cout<< "Enter 5 to select THE SHADOW.\n" <<endl;
    
    // Add fighters to the list1/group1
    for(int i=0; i<TEAMSIZE; i++){
        //Prompt the user to enter a warrior
        cout << "Please Select Warrior #"<<i+1<<": ";
        teamMember = intValid(); //take the input value
        if(teamMember>5 || teamMember<1){
            cout<<"Invalid input! Try again!!"<<endl;
            return 0;}
        if(teamMember==1){teamMemberName="BARBARIAN";}
        if(teamMember==2){teamMemberName="REPTILE";}
        if(teamMember==3){teamMemberName="BLUEMEN";}
        if(teamMember==4){teamMemberName="GOBLIN";}
        if(teamMember==5){teamMemberName="SHADOW";}
        myQueueLineup1.add(teamMemberName);
        teamMember=0;}
    
    myQueueLineup1.display();// Display Group #1 members
    
    // Menu for Team #2
    cout<<"\n*PLEASE SELECT THE WARRIORS FOR TEAM #2:*"<<endl;
    cout<< "Enter 1 to select BARBARIAN." <<endl;
    cout<< "Enter 2 to select REPTILE." <<endl;
    cout<< "Enter 3 to select BLUEMEN." <<endl;
    cout<< "Enter 4 to select GOBLIN." <<endl;
    cout<< "Enter 5 to select THE SHADOW.\n" <<endl;
    
    // Add fighters to the list2/group2
    for(int i=0; i<TEAMSIZE; i++){
        //Prompt the user to enter a warrior
        cout << "Please Select Warrior #"<<i+1<<": ";
        teamMember = intValid(); //take the input value
        if(teamMember>5 || teamMember<1){
            cout<<"Invalid input! Try again!!"<<endl;
            return 0;}
        if(teamMember==1){teamMemberName="BARBARIAN";}
        if(teamMember==2){teamMemberName="REPTILE";}
        if(teamMember==3){teamMemberName="BLUEMEN";}
        if(teamMember==4){teamMemberName="GOBLIN";}
        if(teamMember==5){teamMemberName="SHADOW";}
        myQueueLineup2.add(teamMemberName);
        teamMember=0;}
    
    myQueueLineup2.display(); // Display Group #2 members
    cout<<endl;
    
    // Loop to perform the actual tournament
    for(int i=0; i<TEAMSIZE; i++)
    {
        std::string warrior1 = myQueueLineup1.returnName(); // Take fighter1 from the pile/list
        std::string warrior2 = myQueueLineup2.returnName(); // Take fighter2 from the pile/list
        objects(warrior1, warrior2); // Make fighters subclass objects
        myQueueWin.add(winnerWarrior); // Send winners to the winner pile
        myStackLose.add(loserWarrior); // Send losers to the loser pile
        myQueueLineup1.remove(); // Remove node from the pile to prepare next combat
        myQueueLineup2.remove(); // Remove node from the pile to prepare next combat
        system("sleep 2");
     }
    
    objects(" ", " "); // Stops additional calls to objects()

    myQueueWin.display(); // Display winners
    myStackLose.display(); // Display losers
    cout <<endl;
    
    // Sort the strength points and winner names in descending order
    // to  determine the final three finishers.
    selectionSort(scores, winners);
    
    // Display the final results of the tournament (Team #1 Vs. Team #2 only).
    displayVector(scores, winners);
    cout <<endl;
    
    cout<<"\n********** END OF BATTLE BETWEEN TEAMS **********\n"<<endl;
    
    // Promt user to see the great finale
    int door1;
    do{
        cout << "Enter 1 to see the *** GREAT FINALE!!!! ***"<<endl;
        cout << "Enter 2 to EXIT the game. "<<endl;
        door1 = intValid();
        
        if(door1 == 2){return 0;}
        
        if(door1 != 1 && door1 != 2){
            cout<<"Sorry! Wrong input. Try again!!"<<endl;
            return 0;}
    }while(door1 != 1);
    
    // The final battle starts!
    cout<<"\n********** THE BATTLE AMONG WINNERS STARTS NOW!!! **********\n"<<endl;
    
    // Erase prior scores. Punctuation starts over for the great finale
    for(int i=0; i<scores.size(); i++) {scores.at(i) = 0;}
    
    // Empty loser pile to be re-used for the great finale
    for(int i=0; i<TEAMSIZE; i++) {myStackLose.remove();}
    
    winnerWarrior = " "; // clean winnerWarrior variable
    
    TEAMSIZE = TEAMSIZE - 1; // only combats -1 are needed to determine the Great WINNER!!
    
    // Loop for the Great Finale: Removes the 2 warriors on the front of the pile
    // and re-insert the winner to the tail/back of the pile
    do{
        std::string fighter1 = myQueueWin.returnName(); // Take fighter1 from the pile/list
        cout<<"Fighter1: "<<fighter1<<endl;
        myQueueWin.remove(); // Remove node from the pile to prepare the combat
    
        std::string fighter2 = myQueueWin.returnName(); // Take fighter2 from the pile/list
        cout<<"Fighter2: "<<fighter2<<endl;
        myQueueWin.remove(); // Remove node from the pile to prepare next combat
        myQueueWin.display();
        cout<<endl;
        
        objects(fighter1, fighter2); // Make fighters subclass objects
        myQueueWin.add(winnerWarrior); // Send winner to the back of the winner pile
        myStackLose.add(loserWarrior); // Send winners to the finishers pile
        cout<<endl;
        
        TEAMSIZE--;
        system("sleep 2");
        
    }while(TEAMSIZE > 0);
    
    myQueueWin.display();
    
    // Display the GREAT CHAMPION
    std::string winnerWarrior = myQueueWin.returnName();
    cout <<"\n"<<"******** THE GREAT WINNER IS "<<winnerWarrior<<"1!!! *******\n"<<endl;
    
    // Display 2nd place
    std::string warrior1 = myStackLose.returnName();
    cout <<"2nd PLACE IS FOR: "<<warrior1<<"2"<<endl;
    myStackLose.remove();
    
    // Display 3rd place
    std::string warrior2 = myStackLose.returnName();
    cout <<"3rd PLACE IS FOR: "<<warrior2<<endl;
    myStackLose.remove();
    
    cout<<endl;
    cout <<"\n*** THE END!! ***\n"<<endl;
    cout<<endl;
    
    return 0;
}

/*********************************************************
 *                   restoreStrength                     *
 * This function restores the winner's Strength Points.  *
 * The creature that wins a round gets 4 additional      *
 * strenth points.                                       *
 ********************************************************/

void restoreStrength (std::string winner1, double fuerza1, std::string winner2, double fuerza2)
{
    double iniForce1;
    double iniForce2;
    double tempForce1;
    double tempForce2;

    if(winner1 == "BARBARIAN") {iniForce1 = 12;}
    if(winner2 == "BARBARIAN") {iniForce2 = 12;}
    if(winner1 == "REPTILE") {iniForce1 = 18;}
    if(winner2 == "REPTILE") {iniForce2 = 18;}
    if(winner1 == "BLUEMEN") {iniForce1 = 12;}
    if(winner2 == "BLUEMEN") {iniForce2 = 12;}
    if(winner1 == "GOBLIN") {iniForce1 = 8;}
    if(winner2 == "GOBLIN") {iniForce2 = 8;}
    if(winner1 == "SHADOW") {iniForce1 = 12;}
    if(winner2 == "SHADOW") {iniForce2 = 12;}
    
    if (fuerza1 > fuerza2){
        cout <<winner1<<" WINS THIS COMBAT!!"<<endl;
        tempForce1 = (fuerza1 + 4); //give a 4-points bonus to the winner
        fuerzaAttack = tempForce1;
        if(fuerzaAttack > iniForce1)
        {fuerzaAttack = iniForce1;}
        cout<<winner1<<" RESTORES STRENGTH FROM "<<fuerza1<<" TO "<<fuerzaAttack<<"!!\n"<<endl;}
    
    if (fuerza1 == fuerza2)
    {cout <<"THERE IS A TIE!! BOTH FIGHTERS GOT THE SAME STRENGTH POINTS\n"<<endl;}
    
    if (fuerza2 > fuerza1){
        cout <<winner2<<" WINS THIS COMBAT!!"<<endl;
        tempForce2 = (fuerza2 + 4); //give a 4-points bonus to the winner
        fuerzaDefense = tempForce2;
        if(fuerzaDefense > iniForce2)
        {fuerzaDefense = iniForce2;}
        cout<<winner2<<" RESTORES ITS STRENGTH FROM "<<fuerza2<<" TO "<<fuerzaDefense<<"!!\n"<<endl;}
}

/**********************************************************
 *                        winner                          *
 * This function updates the score status every single    *
 * time a round is finished.                              *
 **********************************************************/

void winner(std::string attacker, double force1, std::string defender, double force2)
{
    if(force1 < 1){
        winnerWarrior = defender;
        loserWarrior = attacker;
        scores.push_back(force2);
        winners.push_back(winnerWarrior);
        team2Wins++;
        totalStrengthPoints2=totalStrengthPoints2+force2;}
    
    if (force2 < 1){
        winnerWarrior = attacker;
        loserWarrior = defender;
        scores.push_back(force1);
        winners.push_back(winnerWarrior);
        team1Wins++;
        totalStrengthPoints1=totalStrengthPoints1+force1;}
}

/************************************************************
 *                      selectionSort                       *
 * This function performs a descending-order selection sort *
 * on the vectors that hold the Strength points and Winner  *
 * names values.                                            *
 ***********************************************************/
void selectionSort(vector<double> &forces, vector<std::string> &names)
{
    double startScan;
    double minIndex;
    double minValue;
    std::string minValue2;
    
    for (startScan = 0; startScan < (forces.size() - 1); startScan++){
        minIndex = startScan;
        minValue = forces[startScan];
        minValue2 = names[startScan];
        
        for(int index = startScan + 1; index < forces.size(); index++){
            if (forces[index] > minValue){
                minValue = forces[index];
                minValue2 = names[index];
                minIndex = index;}}
        
        forces[minIndex] = forces[startScan];
        names[minIndex] = names[startScan];
        forces[startScan] = minValue;
        names[startScan] = minValue2;}
}

/*************************************************************
 *                      displayResults                       *
 * This function displays the contents of the vectors that   *
 * hold the Strength points and Winner names values.         *
 ************************************************************/
void displayVector(vector<double> forces, vector<std::string> names)
{
    cout <<"TEAM #1 HAD "<<team1Wins<<" WINS and SCORED ";
    cout <<totalStrengthPoints1<<" POINTS."<<endl;
    cout <<"TEAM #2 HAD "<<team2Wins<<" WINS and SCORED ";
    cout <<totalStrengthPoints2<<" POINTS.\n"<<endl;
    
    if(team1Wins>team2Wins && totalStrengthPoints1>totalStrengthPoints2)
    {cout <<"***** TEAM #1 WINS! *****\n"<< endl;}
    if(team1Wins<team2Wins && totalStrengthPoints1<totalStrengthPoints2)
    {cout <<"***** TEAM #2 WINS! *****\n"<< endl;}
    if(team1Wins==team2Wins && totalStrengthPoints1==totalStrengthPoints2)
    {cout <<"*** THERE IS A TIE! BOTH TEAMS GOT THE SAME SCORE ***\n"<< endl;}
    
    cout <<"*** THESE ARE THE 3 BEST WARRIORS OF THE TOURNAMENT ***\n"<< endl;
    cout <<"1st PLACE IS FOR "<<names[0]<<" ---> (Final Strength Points = "<<forces[0]<<")"<<endl;
    cout <<"2nd PLACE IS FOR "<<names[1]<<" ---> (Final Strength Points = "<<forces[1]<<")"<<endl;
    cout <<"3rd PLACE IS FOR "<<names[2]<<" ---> (Final Strength Points = "<<forces[2]<<")"<<endl;
}

/**************************************************************
 *                          objects                           *
 * This function creates the pointer objects to creature      *
 * subclasses and polymorphism in order to ensure the correct *
 * function is called                                         *
 *************************************************************/
void objects (std::string attacker, std::string defender)
{
    //BARBARIAN COMBINATIONS
    if(attacker == "BARBARIAN" && defender == "BARBARIAN")
    {
        double strengthAttack = 12;
        double strengthDefense = 12;
        
        cout <<"******* ROUND #1 *******"<<endl;
        Barbarian *pBarbarian1 = new Barbarian(strengthDefense, 1);
        pBarbarian1->creature(attacker, defender);
        fuerzaDefense = pBarbarian1->getFuerza();
        system("sleep 0.5");
        
        //////////////////////////////////////////
        
        cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
        Barbarian *pBarbarian = new Barbarian(strengthAttack, 1);
        pBarbarian->creature(defender, attacker);
        fuerzaAttack = pBarbarian->getFuerza();
        system("sleep 1");
        cout <<"******* END OF ROUND #1 *******\n"<<endl;
        
        restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        int counter = 1;
        do
        {   counter++;
            cout <<"\n******* ROUND #"<<counter<<" *******"<<endl;
            strengthDefense = fuerzaDefense;
            Barbarian *pBarbarian1 = new Barbarian(strengthDefense, 1);
            pBarbarian1->creature(attacker, defender);
            fuerzaDefense = pBarbarian1->getFuerza();
            system("sleep 0.5");
            
            if(fuerzaDefense < 1) {break;}
            
            cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
            strengthAttack = fuerzaAttack;
            Barbarian *pBarbarian = new Barbarian(strengthAttack, 1);
            pBarbarian->creature(defender, attacker);
            fuerzaAttack = pBarbarian->getFuerza();
            system("sleep 1");
            cout <<"******* END OF ROUND #"<<counter<<" *******\n"<<endl;
            
            restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
            
        }while(fuerzaDefense > 0 && fuerzaAttack > 0);
        
        winner(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        //deallocate memory
        delete pBarbarian1;
        delete pBarbarian;
        
        //clean up dangling pointer
        pBarbarian1 = NULL;
        pBarbarian = NULL;
    }

/////////////////////////////////////////////////////////////////
    
    if(attacker == "REPTILE" && defender == "BARBARIAN")
    {
        double strengthAttack = 18;
        double strengthDefense = 12;
        
        cout <<"******* ROUND #1 *******"<<endl;
        Barbarian *pBarbarian = new Barbarian(strengthDefense, 1);
        pBarbarian->creature(attacker, defender);
        fuerzaDefense = pBarbarian->getFuerza();
        system("sleep 0.5");
        
        //////////////////////////////////////////
        
        cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
        Reptile *pReptile = new Reptile(strengthAttack, 1);
        pReptile->creature(defender, attacker);
        fuerzaAttack = pReptile->getFuerza();
        system("sleep 1");
        cout <<"******* END OF ROUND #1 *******\n"<<endl;
        
        restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        int counter = 1;
        do
        {   counter++;
            cout <<"\n******* ROUND #"<<counter<<" *******"<<endl;
            strengthDefense = fuerzaDefense;
            Barbarian *pBarbarian = new Barbarian(strengthDefense, 1);
            pBarbarian->creature(attacker, defender);
            fuerzaDefense = pBarbarian->getFuerza();
            system("sleep 0.5");
            
            if(fuerzaDefense < 1) {break;}
            
            cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
            strengthAttack = fuerzaAttack;
            Reptile *pReptile = new Reptile(strengthAttack, 1);
            pReptile->creature(defender, attacker);
            fuerzaAttack = pReptile->getFuerza();
            system("sleep 1");
            cout <<"******* END OF ROUND #"<<counter<<" *******\n"<<endl;
            
            restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
            
        }while(fuerzaDefense > 0 && fuerzaAttack > 0);
        
        winner(attacker, fuerzaAttack, defender, fuerzaDefense);

        //deallocate memory
        delete pBarbarian;
        delete pReptile;
        
        //clean up dangling pointer
        pBarbarian = NULL;
        pReptile = NULL;
    }
    
/////////////////////////////////////////////////////////////////
    
   if(attacker == "BLUEMEN" && defender == "BARBARIAN")
    {
        double strengthAttack = 12;
        double strengthDefense = 12;
        
        cout <<"******* ROUND #1 *******"<<endl;
        Barbarian *pBarbarian = new Barbarian(strengthDefense, 1);
        pBarbarian->creature(attacker, defender);
        fuerzaDefense = pBarbarian->getFuerza();
        system("sleep 0.5");
        
        //////////////////////////////////////////
        
        cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
        Blue *pBlue = new Blue(strengthAttack, 1);
        pBlue->creature(defender, attacker);
        fuerzaAttack = pBlue->getFuerza();
        system("sleep 1");
        cout <<"******* END OF ROUND #1 *******\n"<<endl;
        
        restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        int counter = 1;
        do
        {   counter++;
            cout <<"\n******* ROUND #"<<counter<<" *******"<<endl;
            strengthDefense = fuerzaDefense;
            Barbarian *pBarbarian = new Barbarian(strengthDefense, 1);
            pBarbarian->creature(attacker, defender);
            fuerzaDefense = pBarbarian->getFuerza();
            system("sleep 0.5");
            
            if(fuerzaDefense < 1) {break;}
            
            cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
            strengthAttack = fuerzaAttack;
            Blue *pBlue = new Blue(strengthAttack, 1);
            pBlue->creature(defender, attacker);
            fuerzaAttack = pBlue->getFuerza();
            system("sleep 1");
            cout <<"******* END OF ROUND #"<<counter<<" *******\n"<<endl;
            
            restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
            
        }while(fuerzaDefense > 0 && fuerzaAttack > 0);
        
        winner(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        //deallocate memory
        delete pBarbarian;
        delete pBlue;
        
        //clean up dangling pointer
        pBarbarian = NULL;
        pBlue = NULL;
    }
    
/////////////////////////////////////////////////////////////////
    
    if(attacker == "GOBLIN" && defender == "BARBARIAN")
    {
        double strengthAttack = 8;
        double strengthDefense = 12;
        
        cout <<"******* ROUND #1 *******"<<endl;
        Barbarian *pBarbarian = new Barbarian(strengthDefense, 1);
        pBarbarian->creature(attacker, defender);
        fuerzaDefense = pBarbarian->getFuerza();
        system("sleep 0.5");
        
        //////////////////////////////////////////
        
        cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
        Goblin *pGoblin = new Goblin(strengthAttack, 1);
        pGoblin->creature(defender, attacker);
        fuerzaAttack = pGoblin->getFuerza();
        system("sleep 1");
        cout <<"******* END OF ROUND #1 *******\n"<<endl;
        
        restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        int counter = 1;
        do
        {   counter++;
            cout <<"\n******* ROUND #"<<counter<<" *******"<<endl;
            strengthDefense = fuerzaDefense;
            Barbarian *pBarbarian = new Barbarian(strengthDefense, 1);
            pBarbarian->creature(attacker, defender);
            fuerzaDefense = pBarbarian->getFuerza();
            system("sleep 0.5");
            
            if(fuerzaDefense < 1) {break;}
            
            cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
            strengthAttack = fuerzaAttack;
            Goblin *pGoblin = new Goblin(strengthAttack, 1);
            pGoblin->creature(defender, attacker);
            fuerzaAttack = pGoblin->getFuerza();
            system("sleep 1");
            cout <<"******* END OF ROUND #"<<counter<<" *******\n"<<endl;
            
            restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
            
        }while(fuerzaDefense > 0 && fuerzaAttack > 0);
        
        winner(attacker, fuerzaAttack, defender, fuerzaDefense);
 
        //deallocate memory
        delete pBarbarian;
        delete pGoblin;
        
        //clean up dangling pointer
        pBarbarian = NULL;
        pGoblin = NULL;
    }
    
/////////////////////////////////////////////////////////////////
    
    if(attacker == "SHADOW" && defender == "BARBARIAN")
    {
        double strengthAttack = 12;
        double strengthDefense = 12;
        
        cout <<"******* ROUND #1 *******"<<endl;
        Barbarian *pBarbarian = new Barbarian(strengthDefense, 1);
        pBarbarian->creature(attacker, defender);
        fuerzaDefense = pBarbarian->getFuerza();
        system("sleep 0.5");
        
        //////////////////////////////////////////
        
        cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
        Shadow *pShadow = new Shadow(strengthAttack, 1);
        pShadow->creature(defender, attacker);
        fuerzaAttack = pShadow->getFuerza();
        system("sleep 1");
        cout <<"******* END OF ROUND #1 *******\n"<<endl;
        
        restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        int counter = 1;
        do
        {   counter++;
            cout <<"\n******* ROUND #"<<counter<<" *******"<<endl;
            strengthDefense = fuerzaDefense;
            Barbarian *pBarbarian = new Barbarian(strengthDefense, 1);
            pBarbarian->creature(attacker, defender);
            fuerzaDefense = pBarbarian->getFuerza();
            system("sleep 0.5");
            
            if(fuerzaDefense < 1) {break;}
            
            cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
            strengthAttack = fuerzaAttack;
            Shadow *pShadow = new Shadow(strengthAttack, 1);
            pShadow->creature(defender, attacker);
            fuerzaAttack = pShadow->getFuerza();
            system("sleep 1");
            cout <<"******* END OF ROUND #"<<counter<<" *******\n"<<endl;
            
            restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
            
        }while(fuerzaDefense > 0 && fuerzaAttack > 0);
        
        winner(attacker, fuerzaAttack, defender, fuerzaDefense);

        //deallocate memory
        delete pBarbarian;
        delete pShadow;
        
        //clean up dangling pointer
        pBarbarian = NULL;
        pShadow = NULL;
    }
    
/////////////////////////////////////////////////////////////////
    
    //REPTILE COMBINATIONS
    if(attacker == "BARBARIAN" && defender == "REPTILE")
    {
        double strengthAttack = 12;
        double strengthDefense = 18;
        
        cout <<"******* ROUND #1 *******"<<endl;
        Reptile *pReptile = new Reptile(strengthDefense, 1);
        pReptile->creature(attacker, defender);
        fuerzaDefense = pReptile->getFuerza();
        system("sleep 0.5");
        
        //////////////////////////////////////////
        
        cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
        Barbarian *pBarbarian = new Barbarian(strengthAttack, 1);
        pBarbarian->creature(defender, attacker);
        fuerzaAttack = pBarbarian->getFuerza();
        system("sleep 1");
        cout <<"******* END OF ROUND #1 *******\n"<<endl;
        
        restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        int counter = 1;
        do
        {   counter++;
            cout <<"\n******* ROUND #"<<counter<<" *******"<<endl;
            strengthDefense = fuerzaDefense;
            Reptile *pReptile = new Reptile(strengthDefense, 1);
            pReptile->creature(attacker, defender);
            fuerzaDefense = pReptile->getFuerza();
            system("sleep 0.5");
            
            if(fuerzaDefense < 1) {break;}
            
            cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
            strengthAttack = fuerzaAttack;
            Barbarian *pBarbarian = new Barbarian(strengthAttack, 1);
            pBarbarian->creature(defender, attacker);
            fuerzaAttack = pBarbarian->getFuerza();
            system("sleep 1");
            cout <<"******* END OF ROUND #"<<counter<<" *******\n"<<endl;
            
            restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
            
        }while(fuerzaDefense > 0 && fuerzaAttack > 0);
        
        winner(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        //deallocate memory
        delete pBarbarian;
        delete pReptile;
        
        //clean up dangling pointer
        pBarbarian = NULL;
        pReptile = NULL;
    }
    
/////////////////////////////////////////////////////////////////
    
    if(attacker == "REPTILE" && defender == "REPTILE")
    {
        double strengthAttack = 18;
        double strengthDefense = 18;
        
        cout <<"******* ROUND #1 *******"<<endl;
        Reptile *pReptile1 = new Reptile(strengthDefense, 1);
        pReptile1->creature(attacker, defender);
        fuerzaDefense = pReptile1->getFuerza();
        system("sleep 0.5");
        
        //////////////////////////////////////////
        
        cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
        Reptile *pReptile = new Reptile(strengthAttack, 1);
        pReptile->creature(defender, attacker);
        fuerzaAttack = pReptile->getFuerza();
        system("sleep 1");
        cout <<"******* END OF ROUND #1 *******\n"<<endl;
        
        restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        int counter = 1;
        do
        {   counter++;
            cout <<"\n******* ROUND #"<<counter<<" *******"<<endl;
            strengthDefense = fuerzaDefense;
            Reptile *pReptile1 = new Reptile(strengthDefense, 1);
            pReptile1->creature(attacker, defender);
            fuerzaDefense = pReptile1->getFuerza();
            system("sleep 0.5");
            
            if(fuerzaDefense < 1) {break;}
            
            cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
            strengthAttack = fuerzaAttack;
            Reptile *pReptile = new Reptile(strengthAttack, 1);
            pReptile->creature(defender, attacker);
            fuerzaAttack = pReptile->getFuerza();
            system("sleep 1");
            cout <<"******* END OF ROUND #"<<counter<<" *******\n"<<endl;
            
            restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
            
        }while(fuerzaDefense > 0 && fuerzaAttack > 0);
        
        winner(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        //deallocate memory
        delete pReptile1;
        delete pReptile;
        
        //clean up dangling pointer
        pReptile1 = NULL;
        pReptile = NULL;
    }
    
/////////////////////////////////////////////////////////////////
    
    if(attacker == "BLUEMEN" && defender == "REPTILE")
    {
        double strengthAttack = 12;
        double strengthDefense = 18;
        
        cout <<"******* ROUND #1 *******"<<endl;
        Reptile *pReptile = new Reptile(strengthDefense, 1);
        pReptile->creature(attacker, defender);
        fuerzaDefense = pReptile->getFuerza();
        system("sleep 0.5");
        
        //////////////////////////////////////////
        
        cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
        Blue *pBlue = new Blue(strengthAttack, 1);
        pBlue->creature(defender, attacker);
        fuerzaAttack = pBlue->getFuerza();
        system("sleep 1");
        cout <<"******* END OF ROUND #1 *******\n"<<endl;
        
        restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        int counter = 1;
        do
        {   counter++;
            cout <<"\n******* ROUND #"<<counter<<" *******"<<endl;
            strengthDefense = fuerzaDefense;
            Reptile *pReptile = new Reptile(strengthDefense, 1);
            pReptile->creature(attacker, defender);
            fuerzaDefense = pReptile->getFuerza();
            system("sleep 0.5");
            
            if(fuerzaDefense < 1) {break;}
            
            cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
            strengthAttack = fuerzaAttack;
            Blue *pBlue = new Blue(strengthAttack, 1);
            pBlue->creature(defender, attacker);
            fuerzaAttack = pBlue->getFuerza();
            system("sleep 1");
            cout <<"******* END OF ROUND #"<<counter<<" *******\n"<<endl;
            
            restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
            
        }while(fuerzaDefense > 0 && fuerzaAttack > 0);
        
        winner(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        //deallocate memory
        delete pReptile;
        delete pBlue;
        
        //clean up dangling pointer
        pReptile = NULL;
        pBlue = NULL;
    }
    
/////////////////////////////////////////////////////////////////
    
    if(attacker == "GOBLIN" && defender == "REPTILE")
    {
        double strengthAttack = 8;
        double strengthDefense = 18;
        
        cout <<"******* ROUND #1 *******"<<endl;
        Reptile *pReptile = new Reptile(strengthDefense, 1);
        pReptile->creature(attacker, defender);
        fuerzaDefense = pReptile->getFuerza();
        system("sleep 0.5");
        
        //////////////////////////////////////////
        
        cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
        Goblin *pGoblin = new Goblin(strengthAttack, 1);
        pGoblin->creature(defender, attacker);
        fuerzaAttack = pGoblin->getFuerza();
        system("sleep 1");
        cout <<"******* END OF ROUND #1 *******\n"<<endl;
        
        restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        int counter = 1;
        do
        {   counter++;
            cout <<"\n******* ROUND #"<<counter<<" *******"<<endl;
            strengthDefense = fuerzaDefense;
            Reptile *pReptile = new Reptile(strengthDefense, 1);
            pReptile->creature(attacker, defender);
            fuerzaDefense = pReptile->getFuerza();
            system("sleep 0.5");
            
            if(fuerzaDefense < 1) {break;}
            
            cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
            strengthAttack = fuerzaAttack;
            Goblin *pGoblin = new Goblin(strengthAttack, 1);
            pGoblin->creature(defender, attacker);
            fuerzaAttack = pGoblin->getFuerza();
            system("sleep 1");
            cout <<"******* END OF ROUND #"<<counter<<" *******\n"<<endl;
            
            restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
            
        }while(fuerzaDefense > 0 && fuerzaAttack > 0);
        
        winner(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        //deallocate memory
        delete pReptile;
        delete pGoblin;
        
        //clean up dangling pointer
        pReptile = NULL;
        pGoblin = NULL;
    }
    
/////////////////////////////////////////////////////////////////
    
    if(attacker == "SHADOW" && defender == "REPTILE")
    {
        double strengthAttack = 12;
        double strengthDefense = 18;
        
        cout <<"******* ROUND #1 *******"<<endl;
        Reptile *pReptile = new Reptile(strengthDefense, 1);
        pReptile->creature(attacker, defender);
        fuerzaDefense = pReptile->getFuerza();
        system("sleep 0.5");
        
        //////////////////////////////////////////
        
        cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
        Shadow *pShadow = new Shadow(strengthAttack, 1);
        pShadow->creature(defender, attacker);
        fuerzaAttack = pShadow->getFuerza();
        system("sleep 1");
        cout <<"******* END OF ROUND #1 *******\n"<<endl;
        
        restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        int counter = 1;
        do
        {   counter++;
            cout <<"\n******* ROUND #"<<counter<<" *******"<<endl;
            strengthDefense = fuerzaDefense;
            Reptile *pReptile = new Reptile(strengthDefense, 1);
            pReptile->creature(attacker, defender);
            fuerzaDefense = pReptile->getFuerza();
            system("sleep 0.5");
            
            if(fuerzaDefense < 1) {break;}
            
            cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
            strengthAttack = fuerzaAttack;
            Shadow *pShadow = new Shadow(strengthAttack, 1);
            pShadow->creature(defender, attacker);
            fuerzaAttack = pShadow->getFuerza();
            system("sleep 1");
            cout <<"******* END OF ROUND #"<<counter<<" *******\n"<<endl;
            
            restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
            
        }while(fuerzaDefense > 0 && fuerzaAttack > 0);
        
        winner(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        //deallocate memory
        delete pReptile;
        delete pShadow;
        
        //clean up dangling pointer
        pReptile = NULL;
        pShadow = NULL;
    }

/////////////////////////////////////////////////////////////////

    //BLUEMEN COMBINATIONS
    if(attacker == "BARBARIAN" && defender == "BLUEMEN")
    {
        double strengthAttack = 12;
        double strengthDefense = 12;
        
        cout <<"******* ROUND #1 *******"<<endl;
        Blue *pBlue = new Blue(strengthDefense, 1);
        pBlue->creature(attacker, defender);
        fuerzaDefense = pBlue->getFuerza();
        system("sleep 0.5");
        
        //////////////////////////////////////////
        
        cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
        Barbarian *pBarbarian = new Barbarian(strengthAttack, 1);
        pBarbarian->creature(defender, attacker);
        fuerzaAttack = pBarbarian->getFuerza();
        system("sleep 1");
        cout <<"******* END OF ROUND #1 *******\n"<<endl;
        
        restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        int counter = 1;
        do
        {   counter++;
            cout <<"\n******* ROUND #"<<counter<<" *******"<<endl;
            strengthDefense = fuerzaDefense;
            Blue *pBlue = new Blue(strengthDefense, 1);
            pBlue->creature(attacker, defender);
            fuerzaDefense = pBlue->getFuerza();
            system("sleep 0.5");
            
            if(fuerzaDefense < 1) {break;}
            
            cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
            strengthAttack = fuerzaAttack;
            Barbarian *pBarbarian = new Barbarian(strengthAttack, 1);
            pBarbarian->creature(defender, attacker);
            fuerzaAttack = pBarbarian->getFuerza();
            system("sleep 1");
            cout <<"******* END OF ROUND #"<<counter<<" *******\n"<<endl;
            
            restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
            
        }while(fuerzaDefense > 0 && fuerzaAttack > 0);
        
        winner(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        //deallocate memory
        delete pBlue;
        delete pBarbarian;
        
        //clean up dangling pointer
        pBlue = NULL;
        pBarbarian = NULL;
    }
    
/////////////////////////////////////////////////////////////////
    
    if(attacker == "REPTILE" && defender == "BLUEMEN")
    {
        double strengthAttack = 18;
        double strengthDefense = 12;
        
        cout <<"******* ROUND #1 *******"<<endl;
        Blue *pBlue = new Blue(strengthDefense, 1);
        pBlue->creature(attacker, defender);
        fuerzaDefense = pBlue->getFuerza();
        system("sleep 0.5");
        
        //////////////////////////////////////////
        
        cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
        Reptile *pReptile = new Reptile(strengthAttack, 1);
        pReptile->creature(defender, attacker);
        fuerzaAttack = pReptile->getFuerza();
        system("sleep 1");
        cout <<"******* END OF ROUND #1 *******\n"<<endl;
        
        restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        int counter = 1;
        do
        {   counter++;
            cout <<"\n******* ROUND #"<<counter<<" *******"<<endl;
            strengthDefense = fuerzaDefense;
            Blue *pBlue = new Blue(strengthDefense, 1);
            pBlue->creature(attacker, defender);
            fuerzaDefense = pBlue->getFuerza();
            system("sleep 0.5");
            
            if(fuerzaDefense < 1) {break;}
            
            cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
            strengthAttack = fuerzaAttack;
            Reptile *pReptile = new Reptile(strengthAttack, 1);
            pReptile->creature(defender, attacker);
            fuerzaAttack = pReptile->getFuerza();
            system("sleep 1");
            cout <<"******* END OF ROUND #"<<counter<<" *******\n"<<endl;
            
            restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
            
        }while(fuerzaDefense > 0 && fuerzaAttack > 0);
        
        winner(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        //deallocate memory
        delete pReptile;
        delete pBlue;
        
        //clean up dangling pointer
        pReptile = NULL;
        pBlue = NULL;
    }
    
/////////////////////////////////////////////////////////////////
    
    if(attacker == "BLUEMEN" && defender == "BLUEMEN")
    {
        double strengthAttack = 12;
        double strengthDefense = 12;
        
        cout <<"******* ROUND #1 *******"<<endl;
        Blue *pBlue1 = new Blue(strengthDefense, 1);
        pBlue1->creature(attacker, defender);
        fuerzaDefense = pBlue1->getFuerza();
        system("sleep 0.5");
        
        //////////////////////////////////////////
        
        cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
        Blue *pBlue = new Blue(strengthAttack, 1);
        pBlue->creature(defender, attacker);
        fuerzaAttack = pBlue->getFuerza();
        system("sleep 1");
        cout <<"******* END OF ROUND #1 *******\n"<<endl;
        
        restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        int counter = 1;
        do
        {   counter++;
            cout <<"\n******* ROUND #"<<counter<<" *******"<<endl;
            strengthDefense = fuerzaDefense;
            Blue *pBlue1 = new Blue(strengthDefense, 1);
            pBlue1->creature(attacker, defender);
            fuerzaDefense = pBlue1->getFuerza();
            system("sleep 0.5");
            
            if(fuerzaDefense < 1) {break;}
            
            cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
            strengthAttack = fuerzaAttack;
            Blue *pBlue = new Blue(strengthAttack, 1);
            pBlue->creature(defender, attacker);
            fuerzaAttack = pBlue->getFuerza();
            system("sleep 1");
            cout <<"******* END OF ROUND #"<<counter<<" *******\n"<<endl;
            
            restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
            
        }while(fuerzaDefense > 0 && fuerzaAttack > 0);
        
        winner(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        //deallocate memory
        delete pBlue1;
        delete pBlue;
        
        //clean up dangling pointer
        pBlue1 = NULL;
        pBlue = NULL;
    }
    
/////////////////////////////////////////////////////////////////
    
    if(attacker == "GOBLIN" && defender == "BLUEMEN")
    {
        double strengthAttack = 8;
        double strengthDefense = 12;
        
        cout <<"******* ROUND #1 *******"<<endl;
        Blue *pBlue = new Blue(strengthDefense, 1);
        pBlue->creature(attacker, defender);
        fuerzaDefense = pBlue->getFuerza();
        system("sleep 0.5");
        
        //////////////////////////////////////////
        
        cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
        Goblin *pGoblin = new Goblin(strengthAttack, 1);
        pGoblin->creature(defender, attacker);
        fuerzaAttack = pGoblin->getFuerza();
        system("sleep 1");
        cout <<"******* END OF ROUND #1 *******\n"<<endl;
        
        restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        int counter = 1;
        do
        {   counter++;
            cout <<"\n******* ROUND #"<<counter<<" *******"<<endl;
            strengthDefense = fuerzaDefense;
            Blue *pBlue = new Blue(strengthDefense, 1);
            pBlue->creature(attacker, defender);
            fuerzaDefense = pBlue->getFuerza();
            system("sleep 0.5");
            
            if(fuerzaDefense < 1) {break;}
            
            cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
            strengthAttack = fuerzaAttack;
            Goblin *pGoblin = new Goblin(strengthAttack, 1);
            pGoblin->creature(defender, attacker);
            fuerzaAttack = pGoblin->getFuerza();
            system("sleep 1");
            cout <<"******* END OF ROUND #"<<counter<<" *******\n"<<endl;
            
            restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
            
        }while(fuerzaDefense > 0 && fuerzaAttack > 0);
        
        winner(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        //deallocate memory
        delete pBlue;
        delete pGoblin;
        
        //clean up dangling pointer
        pBlue = NULL;
        pGoblin = NULL;
    }
    
/////////////////////////////////////////////////////////////////
    
    if(attacker == "SHADOW" && defender == "BLUEMEN")
    {
        double strengthAttack = 12;
        double strengthDefense = 12;
        
        cout <<"******* ROUND #1 *******"<<endl;
        Blue *pBlue = new Blue(strengthDefense, 1);
        pBlue->creature(attacker, defender);
        fuerzaDefense = pBlue->getFuerza();
        system("sleep 0.5");
        
        //////////////////////////////////////////
        
        cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
        Shadow *pShadow = new Shadow(strengthAttack, 1);
        pShadow->creature(defender, attacker);
        fuerzaAttack = pShadow->getFuerza();
        system("sleep 1");
        cout <<"******* END OF ROUND #1 *******\n"<<endl;
        
        restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        int counter = 1;
        do
        {   counter++;
            cout <<"\n******* ROUND #"<<counter<<" *******"<<endl;
            strengthDefense = fuerzaDefense;
            Blue *pBlue = new Blue(strengthDefense, 1);
            pBlue->creature(attacker, defender);
            fuerzaDefense = pBlue->getFuerza();
            system("sleep 0.5");
            
            if(fuerzaDefense < 1) {break;}
            
            cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
            strengthAttack = fuerzaAttack;
            Shadow *pShadow = new Shadow(strengthAttack, 1);
            pShadow->creature(defender, attacker);
            fuerzaAttack = pShadow->getFuerza();
            system("sleep 1");
            cout <<"******* END OF ROUND #"<<counter<<" *******\n"<<endl;
            
            restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
            
        }while(fuerzaDefense > 0 && fuerzaAttack > 0);
        
        winner(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        //deallocate memory
        delete pBlue;
        delete pShadow;
        
        //clean up dangling pointer
        pBlue = NULL;
        pShadow = NULL;
    }
    
/////////////////////////////////////////////////////////////////

    //GOBLIN COMBINATIONS
    if(attacker == "BARBARIAN" && defender == "GOBLIN")
    {
        double strengthAttack = 12;
        double strengthDefense = 8;
        
        cout <<"******* ROUND #1 *******"<<endl;
        Goblin *pGoblin = new Goblin(strengthDefense, 1);
        pGoblin->creature(attacker, defender);
        fuerzaDefense = pGoblin->getFuerza();
        system("sleep 0.5");
        
        //////////////////////////////////////////
        
        cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
        Barbarian *pBarbarian = new Barbarian(strengthAttack, 1);
        pBarbarian->creature(defender, attacker);
        fuerzaAttack = pBarbarian->getFuerza();
        system("sleep 1");
        cout <<"******* END OF ROUND #1 *******\n"<<endl;
        
        restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        int counter = 1;
        do
        {   counter++;
            cout <<"\n******* ROUND #"<<counter<<" *******"<<endl;
            strengthDefense = fuerzaDefense;
            Goblin *pGoblin = new Goblin(strengthDefense, 1);
            pGoblin->creature(attacker, defender);
            fuerzaDefense = pGoblin->getFuerza();
            system("sleep 0.5");
            
            if(fuerzaDefense < 1) {break;}
            
            cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
            strengthAttack = fuerzaAttack;
            Barbarian *pBarbarian = new Barbarian(strengthAttack, 1);
            pBarbarian->creature(defender, attacker);
            fuerzaAttack = pBarbarian->getFuerza();
            system("sleep 1");
            cout <<"******* END OF ROUND #"<<counter<<" *******\n"<<endl;
            
            restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
            
        }while(fuerzaDefense > 0 && fuerzaAttack > 0);
        
        winner(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        //deallocate memory
        delete pBarbarian;
        delete pGoblin;
        
        //clean up dangling pointer
        pBarbarian = NULL;
        pGoblin = NULL;
    }
    
/////////////////////////////////////////////////////////////////
    
    if(attacker == "REPTILE" && defender == "GOBLIN")
    {
        double strengthAttack = 18;
        double strengthDefense = 8;
        
        cout <<"******* ROUND #1 *******"<<endl;
        Goblin *pGoblin = new Goblin(strengthDefense, 1);
        pGoblin->creature(attacker, defender);
        fuerzaDefense = pGoblin->getFuerza();
        system("sleep 0.5");
        
        //////////////////////////////////////////
        
        cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
        Reptile *pReptile = new Reptile(strengthAttack, 1);
        pReptile->creature(defender, attacker);
        fuerzaAttack = pReptile->getFuerza();
        system("sleep 1");
        cout <<"******* END OF ROUND #1 *******\n"<<endl;
        
        restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        int counter = 1;
        do
        {   counter++;
            cout <<"\n******* ROUND #"<<counter<<" *******"<<endl;
            strengthDefense = fuerzaDefense;
            Goblin *pGoblin = new Goblin(strengthDefense, 1);
            pGoblin->creature(attacker, defender);
            fuerzaDefense = pGoblin->getFuerza();
            system("sleep 0.5");
            
            if(fuerzaDefense < 1) {break;}
            
            cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
            strengthAttack = fuerzaAttack;
            Reptile *pReptile = new Reptile(strengthAttack, 1);
            pReptile->creature(defender, attacker);
            fuerzaAttack = pReptile->getFuerza();
            system("sleep 1");
            cout <<"******* END OF ROUND #"<<counter<<" *******\n"<<endl;
            
            restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
            
        }while(fuerzaDefense > 0 && fuerzaAttack > 0);
        
        winner(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        //deallocate memory
        delete pReptile;
        delete pGoblin;
        
        //clean up dangling pointer
        pReptile = NULL;
        pGoblin = NULL;
    }
    
/////////////////////////////////////////////////////////////////
    
    if(attacker == "BLUEMEN" && defender == "GOBLIN")
    {
        double strengthAttack = 12;
        double strengthDefense = 8;
        
        cout <<"******* ROUND #1 *******"<<endl;
        Goblin *pGoblin = new Goblin(strengthDefense, 1);
        pGoblin->creature(attacker, defender);
        fuerzaDefense = pGoblin->getFuerza();
        system("sleep 0.5");
        
        //////////////////////////////////////////
        
        cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
        Blue *pBlue = new Blue(strengthAttack, 1);
        pBlue->creature(defender, attacker);
        fuerzaAttack = pBlue->getFuerza();
        system("sleep 1");
        cout <<"******* END OF ROUND #1 *******\n"<<endl;
        
        restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        int counter = 1;
        do
        {   counter++;
            cout <<"\n******* ROUND #"<<counter<<" *******"<<endl;
            strengthDefense = fuerzaDefense;
            Goblin *pGoblin = new Goblin(strengthDefense, 1);
            pGoblin->creature(attacker, defender);
            fuerzaDefense = pGoblin->getFuerza();
            system("sleep 0.5");
            
            if(fuerzaDefense < 1) {break;}
            
            cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
            strengthAttack = fuerzaAttack;
            Blue *pBlue = new Blue(strengthAttack, 1);
            pBlue->creature(defender, attacker);
            fuerzaAttack = pBlue->getFuerza();
            system("sleep 1");
            cout <<"******* END OF ROUND #"<<counter<<" *******\n"<<endl;
            
            restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
            
        }while(fuerzaDefense > 0 && fuerzaAttack > 0);
        
        winner(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        //deallocate memory
        delete pBlue;
        delete pGoblin;
        
        //clean up dangling pointer
        pBlue = NULL;
        pGoblin = NULL;
    }
    
/////////////////////////////////////////////////////////////////
    
    if(attacker == "GOBLIN" && defender == "GOBLIN")
    {
        double strengthAttack = 8;
        double strengthDefense = 8;
        
        cout <<"******* ROUND #1 *******"<<endl;
        Goblin *pGoblin1 = new Goblin(strengthDefense, 1);
        pGoblin1->creature(attacker, defender);
        fuerzaDefense = pGoblin1->getFuerza();
        system("sleep 0.5");
        
        //////////////////////////////////////////
        
        cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
        Goblin *pGoblin = new Goblin(strengthAttack, 1);
        pGoblin->creature(defender, attacker);
        fuerzaAttack = pGoblin->getFuerza();
        system("sleep 1");
        cout <<"******* END OF ROUND #1 *******\n"<<endl;
        
        restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        int counter = 1;
        do
        {   counter++;
            cout <<"\n******* ROUND #"<<counter<<" *******"<<endl;
            strengthDefense = fuerzaDefense;
            Goblin *pGoblin1 = new Goblin(strengthDefense, 1);
            pGoblin1->creature(attacker, defender);
            fuerzaDefense = pGoblin1->getFuerza();
            system("sleep 0.5");
            
            if(fuerzaDefense < 1) {break;}
            
            cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
            strengthAttack = fuerzaAttack;
            Goblin *pGoblin = new Goblin(strengthAttack, 1);
            pGoblin->creature(defender, attacker);
            fuerzaAttack = pGoblin->getFuerza();
            system("sleep 1");
            cout <<"******* END OF ROUND #"<<counter<<" *******\n"<<endl;
            
            restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
            
        }while(fuerzaDefense > 0 && fuerzaAttack > 0);
        
        winner(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        //deallocate memory
        delete pGoblin1;
        delete pGoblin;
        
        //clean up dangling pointer
        pGoblin1 = NULL;
        pGoblin = NULL;
    }
    
/////////////////////////////////////////////////////////////////
    
    if(attacker == "SHADOW" && defender == "GOBLIN")
    {
        double strengthAttack = 12;
        double strengthDefense = 8;
        
        cout <<"******* ROUND #1 *******"<<endl;
        Goblin *pGoblin = new Goblin(strengthDefense, 1);
        pGoblin->creature(attacker, defender);
        fuerzaDefense = pGoblin->getFuerza();
        system("sleep 0.5");
        
        //////////////////////////////////////////
        
        cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
        Shadow *pShadow = new Shadow(strengthAttack, 1);
        pShadow->creature(defender, attacker);
        fuerzaAttack = pShadow->getFuerza();
        system("sleep 1");
        cout <<"******* END OF ROUND #1 *******\n"<<endl;
        
        restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        int counter = 1;
        do
        {   counter++;
            cout <<"\n******* ROUND #"<<counter<<" *******"<<endl;
            strengthDefense = fuerzaDefense;
            Goblin *pGoblin = new Goblin(strengthDefense, 1);
            pGoblin->creature(attacker, defender);
            fuerzaDefense = pGoblin->getFuerza();
            system("sleep 0.5");
            
            if(fuerzaDefense < 1) {break;}
            
            cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
            strengthAttack = fuerzaAttack;
            Shadow *pShadow = new Shadow(strengthAttack, 1);
            pShadow->creature(defender, attacker);
            fuerzaAttack = pShadow->getFuerza();
            system("sleep 1");
            cout <<"******* END OF ROUND #"<<counter<<" *******\n"<<endl;
            
            restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
            
        }while(fuerzaDefense > 0 && fuerzaAttack > 0);
        
        winner(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        //deallocate memory
        delete pGoblin;
        delete pShadow;
        
        //clean up dangling pointer
        pGoblin = NULL;
        pShadow = NULL;
    }
    
/////////////////////////////////////////////////////////////////
    
    //SHADOW COMBINATIONS
    if(attacker == "BARBARIAN" && defender == "SHADOW")
    {
        double strengthAttack = 12;
        double strengthDefense = 8;
        
        cout <<"******* ROUND #1 *******"<<endl;
        Shadow *pShadow = new Shadow(strengthDefense, 1);
        pShadow->creature(attacker, defender);
        fuerzaDefense = pShadow->getFuerza();
        system("sleep 0.5");
        
        //////////////////////////////////////////
        
        cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
        Barbarian *pBarbarian = new Barbarian(strengthAttack, 1);
        pBarbarian->creature(defender, attacker);
        fuerzaAttack = pBarbarian->getFuerza();
        system("sleep 1");
        cout <<"******* END OF ROUND #1 *******\n"<<endl;
        
        restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        int counter = 1;
        do
        {   counter++;
            cout <<"\n******* ROUND #"<<counter<<" *******"<<endl;
            strengthDefense = fuerzaDefense;
            Shadow *pShadow = new Shadow(strengthDefense, 1);
            pShadow->creature(attacker, defender);
            fuerzaDefense = pShadow->getFuerza();
            system("sleep 0.5");
            
            if(fuerzaDefense < 1) {break;}
            
            cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
            strengthAttack = fuerzaAttack;
            Barbarian *pBarbarian = new Barbarian(strengthAttack, 1);
            pBarbarian->creature(defender, attacker);
            fuerzaAttack = pBarbarian->getFuerza();
            system("sleep 1");
            cout <<"******* END OF ROUND #"<<counter<<" *******\n"<<endl;
            
            restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
            
        }while(fuerzaDefense > 0 && fuerzaAttack > 0);
        
        winner(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        //deallocate memory
        delete pShadow;
        delete pBarbarian;
        
        //clean up dangling pointer
        pShadow = NULL;
        pBarbarian = NULL;
    }
    
/////////////////////////////////////////////////////////////////
    
    if(attacker == "REPTILE" && defender == "SHADOW")
    {
        double strengthAttack = 18;
        double strengthDefense = 12;
        
        cout <<"******* ROUND #1 *******"<<endl;
        Shadow *pShadow = new Shadow(strengthDefense, 1);
        pShadow->creature(attacker, defender);
        fuerzaDefense = pShadow->getFuerza();
        system("sleep 0.5");
        
        //////////////////////////////////////////
        
        cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
        Reptile *pReptile = new Reptile(strengthAttack, 1);
        pReptile->creature(defender, attacker);
        fuerzaAttack = pReptile->getFuerza();
        system("sleep 1");
        cout <<"******* END OF ROUND #1 *******\n"<<endl;
        
        restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        int counter = 1;
        do
        {   counter++;
            cout <<"\n******* ROUND #"<<counter<<" *******"<<endl;
            strengthDefense = fuerzaDefense;
            Shadow *pShadow = new Shadow(strengthDefense, 1);
            pShadow->creature(attacker, defender);
            fuerzaDefense = pShadow->getFuerza();
            system("sleep 0.5");
            
            if(fuerzaDefense < 1) {break;}
            
            cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
            strengthAttack = fuerzaAttack;
            Reptile *pReptile = new Reptile(strengthAttack, 1);
            pReptile->creature(defender, attacker);
            fuerzaAttack = pReptile->getFuerza();
            system("sleep 1");
            cout <<"******* END OF ROUND #"<<counter<<" *******\n"<<endl;
            
            restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
            
        }while(fuerzaDefense > 0 && fuerzaAttack > 0);
        
        winner(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        //deallocate memory
        delete pReptile;
        delete pShadow;
        
        //clean up dangling pointer
        pReptile = NULL;
        pShadow = NULL;
    }
    
/////////////////////////////////////////////////////////////////
    
    if(attacker == "BLUEMEN" && defender == "SHADOW")
    {
        double strengthAttack = 12;
        double strengthDefense = 12;
        
        cout <<"******* ROUND #1 *******"<<endl;
        Shadow *pShadow = new Shadow(strengthDefense, 1);
        pShadow->creature(attacker, defender);
        fuerzaDefense = pShadow->getFuerza();
        system("sleep 0.5");
        
        //////////////////////////////////////////
        
        cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
        Blue *pBlue = new Blue(strengthAttack, 1);
        pBlue->creature(defender, attacker);
        fuerzaAttack = pBlue->getFuerza();
        system("sleep 1");
        cout <<"******* END OF ROUND #1 *******\n"<<endl;
        
        restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        int counter = 1;
        do
        {   counter++;
            cout <<"\n******* ROUND #"<<counter<<" *******"<<endl;
            strengthDefense = fuerzaDefense;
            Shadow *pShadow = new Shadow(strengthDefense, 1);
            pShadow->creature(attacker, defender);
            fuerzaDefense = pShadow->getFuerza();
            system("sleep 0.5");
            
            if(fuerzaDefense < 1) {break;}
            
            cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
            strengthAttack = fuerzaAttack;
            Blue *pBlue = new Blue(strengthAttack, 1);
            pBlue->creature(defender, attacker);
            fuerzaAttack = pBlue->getFuerza();
            system("sleep 1");
            cout <<"******* END OF ROUND #"<<counter<<" *******\n"<<endl;
            
            restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
            
        }while(fuerzaDefense > 0 && fuerzaAttack > 0);
        
        winner(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        //deallocate memory
        delete pBlue;
        delete pShadow;
        
        //clean up dangling pointer
        pBlue = NULL;
        pShadow = NULL;
    }
    
/////////////////////////////////////////////////////////////////
    
    if(attacker == "GOBLIN" && defender == "SHADOW")
    {
        double strengthAttack = 8;
        double strengthDefense = 12;
        
        cout <<"******* ROUND #1 *******"<<endl;
        Shadow *pShadow = new Shadow(strengthDefense, 1);
        pShadow->creature(attacker, defender);
        fuerzaDefense = pShadow->getFuerza();
        system("sleep 0.5");
        
        //////////////////////////////////////////
        
        cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
        Goblin *pGoblin = new Goblin(strengthAttack, 1);
        pGoblin->creature(defender, attacker);
        fuerzaAttack = pGoblin->getFuerza();
        system("sleep 1");
        cout <<"******* END OF ROUND #1 *******\n"<<endl;
        
        restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        int counter = 1;
        do
        {   counter++;
            cout <<"\n******* ROUND #"<<counter<<" *******"<<endl;
            strengthDefense = fuerzaDefense;
            Shadow *pShadow = new Shadow(strengthDefense, 1);
            pShadow->creature(attacker, defender);
            fuerzaDefense = pShadow->getFuerza();
            system("sleep 0.5");
            
            if(fuerzaDefense < 1) {break;}
            
            cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
            strengthAttack = fuerzaAttack;
            Goblin *pGoblin = new Goblin(strengthAttack, 1);
            pGoblin->creature(defender, attacker);
            fuerzaAttack = pGoblin->getFuerza();
            system("sleep 1");
            cout <<"******* END OF ROUND #"<<counter<<" *******\n"<<endl;
            
            restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
            
        }while(fuerzaDefense > 0 && fuerzaAttack > 0);
        
        winner(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        //deallocate memory
        delete pGoblin;
        delete pShadow;
        
        //clean up dangling pointer
        pGoblin = NULL;
        pShadow = NULL;
    }
    
/////////////////////////////////////////////////////////////////
    
    if(attacker == "SHADOW" && defender == "SHADOW")
    {
        double strengthAttack = 12;
        double strengthDefense = 12;
        
        cout <<"******* ROUND #1 *******"<<endl;
        Shadow *pShadow1 = new Shadow(strengthDefense, 1);
        pShadow1->creature(attacker, defender);
        fuerzaDefense = pShadow1->getFuerza();
        system("sleep 0.5");
        
        //////////////////////////////////////////
        
        cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
        Shadow *pShadow = new Shadow(strengthAttack, 1);
        pShadow->creature(defender, attacker);
        fuerzaAttack = pShadow->getFuerza();
        system("sleep 1");
        cout <<"******* END OF ROUND #1 *******\n"<<endl;
        
        restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        int counter = 1;
        do
        {   counter++;
            cout <<"\n******* ROUND #"<<counter<<" *******"<<endl;
            strengthDefense = fuerzaDefense;
            Shadow *pShadow1 = new Shadow(strengthDefense, 1);
            pShadow1->creature(attacker, defender);
            fuerzaDefense = pShadow1->getFuerza();
            system("sleep 0.5");
            
            if(fuerzaDefense < 1) {break;}
            
            cout <<"**"<<defender<<"'S RESPONSE**"<<endl;
            strengthAttack = fuerzaAttack;
            Shadow *pShadow = new Shadow(strengthAttack, 1);
            pShadow->creature(defender, attacker);
            fuerzaAttack = pShadow->getFuerza();
            system("sleep 1");
            cout <<"******* END OF ROUND #"<<counter<<" *******\n"<<endl;
            
            restoreStrength(attacker, fuerzaAttack, defender, fuerzaDefense);
            
        }while(fuerzaDefense > 0 && fuerzaAttack > 0);
        
        winner(attacker, fuerzaAttack, defender, fuerzaDefense);
        
        //deallocate memory
        delete pShadow1;
        delete pShadow;
        
        //clean up dangling pointer
        pShadow1 = NULL;
        pShadow = NULL;
    }
}

/*******************************************************************
 *                           intValid                              *
 * This function validates an integer input and displays an error  *
 * message to the user when an invalid input has been entered.     *
 * (borrowed from TA Ian).                                         *
 ******************************************************************/
int intValid()
{
    int input;
    std::cin >> input;
    
    while (true)
    { //loops until the right input comes
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(512, '\n');
            std::cout <<"Invalid option entered. Try again!\n";
            std::cin >> input;
        }
        else break;
    }
    return input;
}





