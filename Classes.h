//Tecumseh McMullin, CSC275, Filename: Classes.h
//This is the header file for the classes for CSC275Final.cpp.

#ifndef CLASSES_H //This is checking to see if Classes.h is defined.
#define CLASSES_H //This is defining Classes.h if it isn't.

//This is where I am including all of the libraries that I will use.
#include <iostream> //This includes the iostream library for basic input.
#include <string> //This includes the string library for use of strings in unorthodox places.
#include <memory> //This includes the memory library for the use of smart pointers.
#include <thread> //This includes the thread library for the use of threads.
#include <chrono> //This includes the chrono library for the user of ms/time.
#include <mutex> //This includes the mutex library for data protection.
#include <ctime> //This includes the ctime library for random generation.
#include <fstream> //This includes the fstream library for file input and output.

//This tells the program that we are using the std namespace so that I don't have to use std:: all the time.
using namespace std;

//This is the Monster class which holds all the necessary methods for all of the Monsters.
class Monster
{
	//This is the public section of the Monster class.
public:
	//This is declaring all of the public method for all of the Monster classes and subclasses.
	void setHealth(int lower, int upper);
	void setHealth(int damTaken);
	void setAttack(int lower, int upper);
	int getAttack();
	int getHealth();
	//These are virtual methods that will be in all of the subclasses, just not used here.
	virtual void introQuip() = 0;
	virtual void fightScene() = 0;
	//This is the private section of the Monster class.
private:
	//Declaring private variables for all of the Monster classes and subclasses.
	int health = 0;
	int attack = 0;
};

//This is the player class this holds all the information for the user.
class Player
{
	//This is the public section for the methods for the Player class.
public:
	//This is the constructor for the Player class.
	Player(string user);
	//This is the deconstructor for the Player class.
	~Player();
	//This is declaring all of the methods for the Player class.
	void setHealth(int damTaken);
	void setName();
	void heal(int totalMP);
	void training(int atk);
	void training(int def, int magic);
	void savedSet(int HP, int DEF, int MP, int ATK, string USER);
	int getHealth();
	int getAttack();
	int getMagic();
	int getDefence();
	void setAttack();
	void setMagic();
	void setDefence();
	void reset(int MP);
	string getName();
	//This is the private section for the variables of the Player class.
private:
	//This is declaring local variables of the Player class.
	int health;
	int magic;
	int defence;
	int attack;
	string name;
};

//This is the ATeir class for ATeir Monsters.
class ATeir :
	//It is a sublcass of the Monster class.
	public Monster
{
	//This is holding the public methods for the ATeir class.
public:
	//This is the constructor for the ATeir class.
	ATeir();
	//This is the deconstructor for the ATeir class.
	~ATeir();
	//This is declaring public methods for the ATeir class.
	void introQuip();
	void fightScene();
};

//This is the BTeir class for the BTeir Monsters.
class BTeir :
	//It is a subclass of the Monster class.
	public Monster
{
	//This is holding the public methods for the BTeir class.
public:
	//This is the constructor for the BTeir class.
	BTeir();
	//This is the deconstructor for the BTeir class.
	~BTeir();
	//This is declaring public methods for the BTeir class.
	void introQuip();
	void fightScene();
};

//This is the CTeir class for the CTeir Monsters.
class CTeir :
	//It is a subclass of the Monster class.
	public Monster
{
	//This is holding the public methods for the CTeir class.
public:
	//This is the constructor for the CTeir class.
	CTeir();
	//This is the deconstructor for the CTeir class.
	~CTeir();
	//This is declaring public methods for the CTeir class.
	void introQuip();
	void fightScene();
};

//This is the DTeir class for the DTeir Monsters.
class DTeir :
	//It is a subclass of the Monster class.
	public Monster
{
	//This is holding the public methods for the DTeir class.
public:
	//This is the constructor for the DTeir class.
	DTeir();
	//This is the deconstructor for the DTeir class.
	~DTeir();
	//This is declaring public methods for the DTeir class.
	void introQuip();
	void fightScene();
};

//This is the FTeir class for the FTeir Monsters.
class FTeir :
	//It is a subclass of the Monster class.
	public Monster
{
	//This is holding the public methods for the FTeir class.
public:
	//This is the constructor for the FTeir class.
	FTeir();
	//This is the deconstructor for the FTeir class.
	~FTeir();
	//This is declaring public methods for the FTeir class.
	void introQuip();
	void fightScene();
};

#endif // !CLASSES_H

