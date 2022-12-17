//Tecumseh McMullin, CSC275, Filename: Classes.cpp
//This is the cpp file for all of the classes, it holds the methods definitions for the classes.

//This is where I am including the header files for use.
#include "Classes.h"
#include "CSC275Final.h"

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

//This the the setHealth() method for the Monster class it passes in a damTaken int, and returns nothing.
void Monster::setHealth(int damTaken) {
	//This sets the health to health - the damTaken.
	health = health - damTaken;
}

//This is the setHealth() method for the Monster class, it passes in lower and upper int, and returns nothing.
void Monster::setHealth(int lower, int upper) 
{
	//This sets the health randomly within the scope of lower and upper.
	health = rand() % lower + upper;
}

//This is the setAttack() method for the Monster class, it passes in lower and upper int, and returns nothing.
void Monster::setAttack(int lower, int upper)
{
	//This sets the attack randomly within the scope of lower and upper.
	attack = rand() % lower + upper;
}

//This is the getAttack() method for the Monster class, it returns an int.
int Monster::getAttack() 
{
	//This returns the attack of the monster as an int.
	return attack;
}

//This is the getHealth() method for the Monster class, it returns an int.
int Monster::getHealth()
{
	//This returns the health of the monster as an int.
	return health;
}

//This is the constructor for the Player class and passes in a string for the name.
Player::Player(string user)
{
	//This is setting all of the default variables for the Player class.
	name = user;
	health = 100;
	magic = 50;
	defence = 10;
	attack = 1;
}

//This is the deconstructor for the Player class.
Player::~Player()
{
}

//This is the setHealth() method for the Player class, it passes in damTaken, and returns nothing.
void Player::setHealth(int damTaken) {
	//This subtracts the damTaken out of the health.
	health = health - damTaken;
	//If it is 0 it sets the health to 100.
	if (damTaken == 0) {
		//This is setting health to 100.
		health = 100;
	}
	//If the health is less than or equal to 0 it sets the health to 0.
	if (health <= 0) {
		//This is setting health to 0.
		health = 0;
	}
}

//This is the setName() method for the Player class, it returns nothing.
void Player::setName() {
	//Prompting input from the user.
	cout << "Please Enter a name for your character." << endl;
	//Uses getline() to set the name so that the user can use spaces if they want.
	getline(cin >> ws, name);
	//Spacing for look.
	cout << "" << endl;
	//Welcomes the user using the name so that the user knows it worked.
	cout << "Welcome " << name << " to The Adventurer's Guild!" << endl;
}

//This is the heal() method for the Player class, it passes in totalMP int, and returns nothing.
void Player::heal(int totalMP)
{
	//This is creating a temp int so that it can figure how much to remove.
	int temp = totalMP /10;
	//This is checking to make sure the user has enough magic.
	if (magic >= temp||temp >= 100) {
		//This subtracts the temp from the magic.
		magic = magic - temp;
		//This adds temp to the health.
		health = health + temp;
		
		//if the health is greater than or equal to 100 it will set it to 100.
		if (health >= 100) {
			//This is setting health to 100.
			health = 100;
		}
		//This is telling the user the amount they healed.
		cout << "You healed for " << temp << " health." << endl;
		//This is telling the user what their health is at.
		cout << "Your health is now at " << health << "." << endl;
		//This is sleeping the thread for 1 second so the user can read it.
		this_thread::sleep_for(1000ms);
	}
	//If the user didn't have enough magic.
	else {
		//Spacing for look.
		cout << "" << endl;
		//Telling the user that they don't have enough mana.
		cout << "Not enough mana to heal" << endl;
		//Spacing for look.
		cout << "" << endl;
	}
	//This is sleeping the thread for 2 seconds so the user can read it.
	this_thread::sleep_for(2000ms);
}

//This is the reset() method for the Player class, it passes in MP int, and returns nothing.
void Player::reset(int MP) {
	//This is setting magic to MP.
	magic = MP;
	//This is setting health to 100.
	health = 100;
}

//This is the training() method for the Player class, it passes in atk int, and returns nothing.
void Player::training(int atk) 
{
	//This is declaring and setting trained to a random number based on atk.
	int trained = rand() % atk + 1;
	//This is telling the user what they decided to train.
	cout << "You decided to train your attack power!" << endl;
	//This is increasing the users attack.
	attack = atk + trained;
	//This is telling the user how much they gained.
	cout << "You gained " << trained << " attack power." << endl;
	//This is telling the user the total attack power.
	cout << "Your current power level is " << attack << "!" << endl;
	//This is sleeping the thread for 2 seconds so the user can read it.
	this_thread::sleep_for(2000ms);
}

//This is the overloaded training() method for the Player class, it passes int def and MP int, and returns nothing.
void Player::training(int def, int MP) 
{
	//This is declaring and setting trained to a random number based on def.
	int Trained = rand()%def +1;
	//This is telling the user what they decided to train.
	cout << "You decided to train your defense!" << endl;
	//This is increasing the defence.
	defence = def + Trained;
	//This is increasing the magic by 25.
	magic = MP + 25;
	//This is telling the user the amount of defense they gained.
	cout << "You gained " << Trained << " defense!" << endl;
	//This is telling the user that they gained 25 magic.
	cout << "You gained 25 magic!" << endl;
	//This is showing the user the total defense.
	cout << "Defense: " << defence << endl;
	//This is showeing the user the total magic.
	cout << "Magic:   " << magic << endl;
	//This is sleeping the thread for 2 secons so the user can read it.
	this_thread::sleep_for(2000ms);
}

//This is the savedSet() method for the Player class it returns nothing.
//It passes in HP, DEF, MP, ATK as ints, and USER as a string.
void Player::savedSet(int HP, int DEF, int MP, int ATK, string USER)
{
	//This is setting the health to HP.
	health = HP;
	//This is setting the magic to MP.
	magic = MP;
	//This is setting defence to DEF.
	defence = DEF;
	//This is setting attack to ATK.
	attack = ATK;
	//This is setting name to USER.
	name = USER;
}

//This is the gethealth() method for the Player class it returns an int.
int Player::getHealth()
{
	//This is returning health as an int.
	return health;
}

//This is the getAttack() method for the Player class it returns an int.
int Player::getAttack()
{
	//This is returning attack as an int.
	return attack;
}

//This is the getMagic() method for the Player class it returns an int.
int Player::getMagic()
{
	//This is returning magic as an int.
	return magic;
}

//This is the getDefence() method for the Player class it returns an int.
int Player::getDefence()
{
	//This is returning defence as an int.
	return defence;
}

//This is the getName() method for the Player class it returns a string.
string Player::getName()
{
	//This is returning name as a string.
	return name;
}

//This is the setAttack() method for the Player class it sets the base attack and returns nothing.
void Player::setAttack()
{
	//This is setting attack to 1.
	attack = 1;
}

//This is the setMagic() method for the Player class it sets the base magic and returns nothing.
void Player::setMagic()
{
	//This is setting magic to 50.
	magic = 50;
}

//This is the setDefence() method for the Player class it sets the base defense and returns nothing.
void Player::setDefence()
{
	//This is setting defence to 10.
	defence = 10;
}

//This is the constructor for the ATeir class.
ATeir::ATeir()
{
	//This is using the setHealth method to set the health between 10000 and 100000.
	setHealth(90000, 10000);
	//This is using the setAttack method to set the Attack between 400 and 500.
	setAttack(100, 400);
}

//This is the deconstructor for the ATeir class.
ATeir::~ATeir()
{
}

//This is the introQuip() method for the ATeir class, it returns nothing.
void ATeir::introQuip()
{
	//This is outputing what the monster says.
	cout << "You dare Challenge Me, MORTAL!!!!!" << endl;
}

//This is the fightScene() method for the ATeir class, it returns nothing.
void ATeir::fightScene() 
{
	//This is outputing the scene of the fight.
	cout << "You have reached the apex of the volcano, Inside you see a pure black dragon flying towards you." << endl;
}

//This is the constructor for the BTeir class.
BTeir::BTeir()
{
	//This is using the setHealth() method to set the health between 1000 and 10000.
	setHealth(9000, 1000);
	//This is using the setAttack() method to set the Attack between 300 and 400.
	setAttack(100, 300);
}

//This is the deconstructor for the BTeir class.
BTeir::~BTeir()
{
}

//This is the introQuip() method for the BTeir class, it returns nothing.
void BTeir::introQuip()
{
	//This is outputing what the monster says.
	cout << "*THUMP THUMP* Puny Human!" << endl;
}

//This is the fightScene() method for the BTeir class, it returns nothing.
void BTeir::fightScene()
{
	//This is outputing the scene of the fight. With rizz.
	cout << "At first there seemed to be no one here, in this small forgotten village." << endl;
	cout << "Then you see and Orc with a crown made of limbs, That must be the Orc King" << endl;
}

//This is the constructor for the CTeir class.
CTeir::CTeir()
{
	//This is using the setHealth() method to set the health between 100 and 1000.
	setHealth(900, 100);
	//This is using the setAttack() method to set the Attack between 100 and 200.
	setAttack(100, 100);
}

//This is the deconstructor for the CTeir class.
CTeir::~CTeir()
{
}

//This is the introQuip() method for the CTeir class, it returns nothing.
void CTeir::introQuip()
{
	//This is outputing what the monster says.
	cout << "*RAAAAWWWWWRRRRR!!!! STOMP STOMP*" << endl;
}

//This is the fightScene() method for the CTeir class, it returns nothing.
void CTeir::fightScene()
{
	//This is outputing the scene of the fight.
	cout << "You have approaced a cave, there is a goblin guarding the entrance, it seems it has spotted you." << endl;
}

//This is the constructor for the DTeir class.
DTeir::DTeir()
{
	//This is using the setHealth() method to set the health between 10 and 100.
	setHealth(90, 10);
	//This is using the setAttack() method to set the Attack between 10 and 100.
	setAttack(90, 10);
}

//This is the deconstructor for the DTeir class.
DTeir::~DTeir()
{
}

//This is the introQuip() method for the DTeir class, it returns nothing.
void DTeir::introQuip()
{
	//This is outputing what the monster says.
	cout << "*GRRRRRRRR*" << endl;
}

//This is the fightScene() method for the DTeir class, it returns nothing.
void DTeir::fightScene()
{
	//This is outputing the scene of the fight.
	cout << "In the middle of the forest you have followed countless claw marks on trees, but you have finally found the den where the bear keeps all of its food." << endl;
}

//This is the constructor for the FTeir class.
FTeir::FTeir()
{
	//This is using the setHealth() method to set the health between 1 and 10.
	setHealth(9, 1);
	//This is using the setAttack() method to set the Attack between 1 and 10.
	setAttack(9, 1);
}

//This is the deconstructor for the FTeir class.
FTeir::~FTeir()
{
}

//This is the introQuip() method for the FTeir class, it returns nothing.
void FTeir::introQuip()
{
	//This is outputing what the monster says.
	cout << "*bloop bloop*" << endl;
}

//This is the fightScene() method for the FTeir class, it returns nothing.
void FTeir::fightScene() 
{
	//This is outputing the scene of the fight.
	cout << "You come across your first Monster, a Slime" << endl;
}