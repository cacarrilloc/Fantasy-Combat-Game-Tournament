 /*********************************************************
 ** Author: Carlos Carrillo                              *
 ** Date:   11/03/2015                                   *
 ** Description: This is the class implementation file   *
 *  of a class called Shadow. This class is a derived    *
 *  class from the Creature class. The subclass overides *
 *  the virtual member function attacks() in order to    *
 *  calculate the battle scores for the Shadow warrior.  *
 ********************************************************/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "Creature.hpp"
#include "Shadow.hpp"

using namespace std;

double Shadow::attacks(double attackRollScore, double defenseRollScore)
{
    double damage;
    
    damage = attackRollScore/achilles - defenseRollScore;
    
    cout <<"A 6-side die will determine 50% chance of NO damage for Shadow"<<endl;
    cout <<"If die roll > 3, Shadow gets 0 damage!\n"<<endl;
    
    srand(time(0));// Seed random to determine Shadow's damage
    
    int damageRoll = rand() % 6 + 1;
    cout <<"Damage Roll = "<<damageRoll<<"\n"<<endl;
    if(damageRoll > 3){
        damage = 0;
        cout <<"SHADOW RECEIVES NO DAMAGE IN THIS ATTACK!"<<endl;}

    cout <<"DAMAGE to Shadow: "<<damage<<endl;
    cout <<"Shadow's INITIAL Strength: "<<"12"<<endl;
    
    if(fuerza != 12)
     {cout <<"Shadow's Strength after LAST ATTACK: "<<fuerza<<endl;}
    
    double newStrength;
    newStrength = fuerza - damage;
    
    if(newStrength > fuerza) {newStrength = fuerza;}
    
    else {fuerza = newStrength;}
    
    cout <<"Shadow's Strength after THIS ATTACK: "<<fuerza<<"\n"<<endl;
    
    return fuerza;
}












