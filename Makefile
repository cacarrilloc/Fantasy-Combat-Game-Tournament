#Author: Carlos Carrillo
#Date:   11/21/2015
#Description: This is the makefile for Assignment_4

#This target will compile the entire program

All: total

total:	mainCreature.o Creature.o Barbarian.o Reptile.o Blue.o Goblin.o Shadow.o QueueWin.o StackLose.o QueueLineup1.o QueueLineup2.o 
	g++ mainCreature.o Creature.o Barbarian.o Reptile.o Blue.o Goblin.o Shadow.o QueueWin.o StackLose.o QueueLineup1.o QueueLineup2.o -o creature

mainCreature.o: mainCreature.cpp
	g++ -c mainCreature.cpp

Creature.o: Creature.cpp
	g++ -c Creature.cpp

Barbarian.o: Barbarian.cpp
	g++ -c Barbarian.cpp

Reptile.o: Reptile.cpp
	g++ -c Reptile.cpp

Blue.o: Blue.cpp
	g++ -c Blue.cpp

Goblin.o: Goblin.cpp
	g++ -c Goblin.cpp

Shadow.o: Shadow.cpp
	g++ -c Shadow.cpp

QueueWin.o: QueueWin.cpp
	g++ -c QueueWin.cpp

StackLose.o: StackLose.cpp
	g++ -c StackLose.cpp

QueueLineup1.o: QueueLineup1.cpp
	g++ -c QueueLineup1.cpp

QueueLineup2.o: QueueLineup2.cpp
	g++ -c QueueLineup2.cpp

clean:
	rm -rf *o total