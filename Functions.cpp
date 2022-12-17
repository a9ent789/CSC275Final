//Tecumseh McMullin, CSC275, Filename: Functions.cpp
//This is the cpp file that holds all of the definitions of the functions for CSC275Final.cpp.

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

//This is the title() function, it returns nothing.
void title() {
	//This is outputing the welcome screen and the basis of how to play.
	cout << "Welcome to The Adventurer's Guild" << endl;
	cout << "This is a basic adventure game where you will take on missions to beat the game." << endl;
	cout << "To win you must slay the dragon!!!" << endl;
	cout << "You have two options for each fight." << endl;
	cout << "Attack and Heal" << endl;
	cout << "Attack is self explanitory." << endl;
	cout << "Heal uses 10% of your mana and transfers it to health." << endl;
	cout << "If you are out of mana you can't use heal." << endl;
	cout << "If you use more mana than health it will Full heal you." << endl;
	cout << "Just remember you only have 100 health." << endl;
	cout << "" << endl;
	//This is pausing the program so the user can read and understand.
	system("pause");
}

//This is the menu() function, it returns and int.
int menu() {
	//This is declaring local variables.
	int choice;
	bool error = true;
	//This is a while loop for exception handling.
	while (error == true) {
		//This is clearing the screen for looks.
		system("CLS");
		//This is prompting the user for an input.
		cout << "             *** The Adventurer's Guild ***" << endl;
		cout << "*** Please enter the corresponding number to your choice ***" << endl;
		cout << "" << endl;
		cout << "        1. New Game" << endl;
		cout << "        2. Continue" << endl;
		cout << "        3. Exit" << endl;
		cout << "" << endl;
		//this is getting the user input for choice.
		cin >> choice;
		//This is a switch statement based on the choice.
		switch (choice)
		{
			//This is if the case was 1.
		case 1:
			//This is setting error to false to exit the loop.
			error = false;
			//This is breaking the switch statement.
			break;
			//This is if the case was 2.
		case 2:
			//This is setting error to false to exit the loop.
			error = false;
			//This is breaking from the switch statement.
			break;
			//This is if the case was 3.
		case 3:
			//This is setting error to false to exit the loop.
			error = false;
			//This is running the goodbye() function.
			goodbye();
			//This is running the exit() functin which exits the program and returns 0 to the computer
			exit(0);
			//This is the default case if they didn't enter a valid response.
		default:
			//Telling the user how they failed.
			cout << "Please enter a valid response!" << endl;
			//Space for spice.
			cout << "" << endl;
			//This breaks out of the switch statement.
			break;
		}
	}
	//This returns the choice that the user made.
	return choice;
}

//This is the train() function it takes in a class, in and file, it promptes the user for input between fights and returns a bool.
bool train(Player& User, int saveNum, fstream& saved) {
	//Declaring local variables.
	bool answer;
	int choice;
	//Setting error to true to start the loop.
	bool error = true;
	//This is a while loop that makes sure that the input is valid.
	while (error == true) {
		//This clears the screen.
		system("CLS");
		//This is the output promting the user for an input.
		cout << "Here are your options before you fight your next opponent." << endl;
		cout << "Please input the corresponding number." << endl;
		cout << "1. Go Straight to the fight." << endl;
		cout << "2. Train" << endl;
		cout << "3. Exit, your progress will be saved." << endl;
		//This is getting the user input for choice.
		cin >> choice;
		//This is a switch statement using choice as the input.
		switch (choice)
		{
			//This is in case the input is 1.
		case 1:
			//This changes answer to false for the return value.
			answer = false;
			//This changes error to false to exit the loop.
			error = false;
			//This breaks from the switch statement.
			break;
			//This is in case the input is 2.
		case 2:
			//This changes answer to true for the return value.
			answer = true;
			//This changes error to false to exit the loop.
			error = false;
			//This breaks from the switch statement.
			break;
			//This is in case the input is 3.
		case 3:
			//This changes error to false to exit the loop.
			error = false;
			//This runs the goodbye() function.
			goodbye();
			//This runs the saveGame() function.
			saveGame(saveNum, User, saved);
			//This runs the exit() function and returns 0 to the user saying that no errors occured.
			exit(0);
			//This breaks from the switch statement.
			break;
			//This is if the input wasn't valid.
		default:
			//This is telling the user that the input was invalid.
			cout << "Please Enter a Valid Input!!" << endl;
			//This breaks from the switch statement.
			break;
		}
	}
	//This returns answer a bool output.
	return answer;
}

//This is the train() function that takes a class as an input, and returns nothing.
void train(Player& User) {
	//Declaring local variables and setting error to true for the loop.
	bool error = true;
	int choice;
	//This is a while loop to make sure the input is valid.
	while (error == true) {
		//This clears the screen.
		system("CLS");
		//This is the output prompting the user for an input.
		cout << "What would you like to train?" << endl;
		cout << "       1. Attack Power" << endl;
		cout << "       2. Defence and Magic" << endl;
		//This is the input for choice.
		cin >> choice;
		//This is a switch statement that uses choice as an input.
		switch (choice)
		{
			//This is in case the input is 1.
		case 1:
			//This runs the training() method.
			User.training(User.getAttack());
			//This sleeps the thread for 3 seconds.
			this_thread::sleep_for(3000ms);
			//This changes error to false to break the loop.
			error = false;
			//This breaks from the switch statement.
			break;
			//This is in case the input is 2.
		case 2:
			//This runs the training() method.
			User.training(User.getDefence(), User.getMagic());
			//This sleeps the thread for 3 seconds.
			this_thread::sleep_for(3000ms);
			//This changes error to false to break the loop.
			error = false;
			//This breaks from the loop.
			break;
			//This is the default case if they didn't enter a valid input.
		default:
			//This tells the user that they didn't enter a valid input.
			cout << "Please Enter a Valid Input!!" << endl;
			//This breaks from the switch statement.
			break;
		}
	}
}

//This is the goodbye() function, it returns nothing.
void goodbye() {
	//This is output telling the user goodbye.
	cout << "Thank you for playing The Adventurer's Guild!!" << endl;
}

//This is the deathMessage() function, it returns nothing.
void deathMessage() {
	//This is declaring local variables and setting messageChoose to a random number between 1 and 5.
	int messageChoose = rand()%4+1;
	//Space for Spice.
	cout << "" << endl;
	//This is a switch statement taking messageChoose as an input.
	switch (messageChoose)
	{
		//This is if the input was 1.
	case 1:
		//Death output.
		cout << "You were beaten to a pulp." << endl;
		//This breaks from the switch statement.
		break;
		//This is if the input was 2.
	case 2:
		//Death output.
		cout << "The ground has good fertilizer now." << endl;
		//This breaks from the switch statement.
		break;
		//This is if the input was 3.
	case 3:
		//Death output.
		cout << "You're only skin and bones, not appetizing for a monster." << endl;
		//This breaks from the switch statement.
		break;
		//This is if the input was 4.
	case 4:
		//Death output.
		cout << "YOU DIED!!!" << endl;
		//This breaks from the switch statement.
		break;
	}
	//Space for Spice.
	cout << "" << endl;
	//This sleeps the thread for 3 seconds.
	this_thread::sleep_for(3000ms);
}

//This is the saveGame() function, it saves the game, takes in an int, class, and file as input, and returns nothing.
void saveGame(int save, Player User, fstream& saved) {
	//This opens savedData.txt and deletes everything from it by using trunc, this makes sure that there are no issues.
	saved.open("savedData.txt", ofstream::out | ofstream::trunc);
	//This closes savedData.txt to save the file.
	saved.close();
	//This opens Remember.txt so the program can write to it.
	saved.open("savedData.txt");
	//This inputs save into the file.
	saved << save << endl;
	//This inputs the class health into the file.
	saved << User.getHealth() << endl;
	//This inputs the class Attack into the file.
	saved << User.getAttack() << endl;
	//This inputs the class Defence into the file.
	saved << User.getDefence() << endl;
	//This inputs the class Magic into the file.
	saved << User.getMagic() << endl;
	//This inputs the class Name into the file.
	saved << User.getName() << endl;

	//This closes the file.
	saved.close();
}

//This is the saveFind() function it finds a previous save, takes in a file and a class. It returns nothing.
int saveFind(Player& User,fstream& saved) {
	//This opens savedData.txt.
	saved.open("savedData.txt");
	//Declaring local variables.
	string saveS;
	int save;
	string healthS;
	int health;
	string attackS;
	int attack;
	string defenceS;
	int defence;
	string magicS;
	int magic;
	string name;
	
	//This is taking the first line as input for saveS.
	getline(saved, saveS);
	//This is taking the second line as input for healthS.
	getline(saved, healthS);
	//This is taking the third line as input for attackS.
	getline(saved, attackS);
	//This is taking the fourth line as input for defenceS.
	getline(saved, defenceS);
	//This is taking the fifth line as input for magicS.
	getline(saved, magicS);
	//This is taking the sixth line as input for name.
	getline(saved, name);

	//This is an if statement that checks to see if the first line was empty.
	if (saveS.length() == 0)
	{
		//This is setting local variables as default numbers.
		save = 0;
		health = 100;
		attack = 1;
		defence = 10;
		magic = 50;
		//This is output telling the user that there wasn't a save.
		cout << "Since there is no save, You will start a new game." << endl;
	}
	//This is if the first line wasn't empty.
	else {
		//This converts saveS to an int.
		save = stoi(saveS);
		//This converts healthS to an int.
		health = stoi(healthS);
		//This converts attackS to an int.
		attack = stoi(attackS);
		//This converts defenceS to an int.
		defence = stoi(defenceS);
		//This converts magicS to an int.
		magic = stoi(magicS);

		//This outputs the save number and the stats of the character from the save.
		cout << save << endl;
		cout << "Health: " << health << endl;
		cout << "Attack: " << attack << endl;
		cout << "Defence: " << defence << endl;
		cout << "Magic: " << magic << endl;
		cout << "Name: " << name << endl;
		//This pauses the system waiting for the user to enter a key.
		system("pause");
	}
	//This runs the savedSet() method to set the User stats.
	User.savedSet(health, defence, magic, attack, name);

	//This closes the file.
	saved.close();
	//This returns the save number as an int.
	return save;
}

//This is the storyIntro function it takes in a class and returns nothing.
void storyIntro(Player User) {
	//This clears the screen.
	system("CLS");
	//Story stuff.
	cout << "\"Today's the day, The day I finally become an adventurer.\"" << endl;
	cout << "\"I am finally 18\"" << endl;
	cout << "" << endl;
	//This sleeps the thread for 2 seconds.
	this_thread::sleep_for(2000ms);
	//Mores story stuff.
	cout << "You walk up to the desk to sign up." << endl;
	cout << "" << endl;
	//This sleeps the thread for 1 second.
	this_thread::sleep_for(1000ms);
	//Even more story stuff.
	cout << "\"Hey " << User.getName() << " Happy Birthday!\"" << endl;
	cout << "\"Now that you can sign up you can take the intro test.\"" << endl;
	cout << "\"The test will be defeating one slime on the outskurts of town\"" << endl;
	cout << "\"Once you defeat the slime come back here and you will be a rank F adventurer\"" << endl;
	cout << "\"To rank up you need to defeat higher level monsters!\"" << endl;
	cout << "" << endl;
	//This sleeps the thread for 2 seconds.
	this_thread::sleep_for(2000ms);
}

//This is the tryAgain() function, it returns a bool.
bool tryAgain() {
	//Declaring local variables.
	bool oneMore;
	char choice;
	//Declaring error and setting it to true for the loop.
	bool error = true;
	//This is a while loop to check that the input was valid.
	while (error == true) {
		//This is prompting the user for an input.
		cout << "Would you like to try again? y/n" << endl;
		//This runs cin.ignore() so that the input doesn't have to be entered twice.
		cin.ignore();
		//This is getting the input from the user.
		cin >> choice;
		//This is a switch statement using choice as input.
		switch (choice)
		{
			//This is if the user entered y or Y.
		case 'y'|'Y':
			//This is setting oneMore to true.
			oneMore = true;
			//This is setting error to false to exit the loop.
			error = false;
			//This breaks from the switch statement.
			break;
			//This is if the user entered n or N.
		case 'n'|'N':
			//This is setting oneMore to false.
			oneMore = false;
			//This is setting error to false to exit the loop.
			error = false;
			//This breaks from the switch statement.
			break;
			//This is the default if they didn't enter a valid input.
		default:
			//This is telling the user their mistake.
			cout << "Please Enter a Valid Input!" << endl;
			//This breaks from the switch statement.
			break;
		}
	}
	//This returns the bool oneMore.
	return oneMore;
}

//This is the fightMenu() function, it returns an int.
int fightMenu() {
	//Declaring local variables.
	int choice;
	//Declaring and setting error to false for a loop.
	bool error = true;
	//This is a while loop that makes sure the user entered a valid input.
	while (error == true) {
		//This is prompting the user for and input.
		cout << "" << endl;
		cout << "Please enter the corresponding number to your choice." << endl;
		cout << "***You have 2 options.***" << endl;
		cout << "       1. Attack" << endl;
		cout << "       2. Heal" << endl;
		//This is taking user input for choice.
		cin >> choice;
		//This is a switch statement taking choice as an input.
		switch (choice) {
			//This is in case the user entered 1.
		case 1:
			//Output telling the user what they did.
			cout << "You Chose to attack." << endl;
			//Setting error to false to exit the loop.
			error = false;
			//This breaks from the switch statement.
			break;
			//This is in case the user entered 2.
		case 2:
			//Output telling the user what they did.
			cout << "You Chose to Heal." << endl;
			//Setting error to false to exit the loop.
			error = false;
			//This breaks from the switch statement.
			break;
			//This is the default in case the user didn't put a valid input.
		default:
			//This tells the user their failure.
			cout << "Please enter a valid input!!" << endl;
			//This breaks from the switch statement.
			break;
		}
	}
	//This returns choice as an int.
	return choice;
}

//This is the fight1() function, it takes in a class as a reference and returns nothing.
void fight1(Player& User) {
	//Declaring local variables.
	bool alive = true;
	int creaturDam;
	int PlayerDam;
	//This is setting playerMP to using the class method getMagic().
	int playerMP = User.getMagic();
	//This is creating a unique pointer to the FTeir class.
	unique_ptr<FTeir> Slime(new FTeir);
	//This is using the fightScene() method for Slime.
	Slime->fightScene();
	//This is running the introQuip() method for Slime.
	Slime->introQuip();
	//This sleeps the thread for 2 seconds.
	this_thread::sleep_for(2000ms);
	//This is an if statement that checks to see if the users defence is greater than the monsters attack.
	if (User.getDefence() >= Slime->getAttack()) {
		//If it is, it sets creatureDam to 0.
		creaturDam = 0;
	}
	//If it isn't.
	else {
		//This sets creatureDam to the attack power of the monster minus the defence of the player.
		creaturDam = Slime->getAttack() - User.getDefence();
	}
	//This is setting PlayerDam by using the method getAttack().
	PlayerDam = User.getAttack();
	//This is a while loop that checks to see if anything is alive.
	while (alive == true) {
		//This clears the screen.
		system("CLS");
		//This outputs the monsters information.
		cout << "Slime: " << Slime->getHealth() << "HP" << endl;
		cout << creaturDam << " Attack power against the Player" << endl;
		cout << "" << endl;
		//This outputs the players information.
		cout << User.getName() << ": " << User.getHealth() << "HP" << endl;
		cout << User.getAttack() << " Attack Power" << endl;
		cout << User.getDefence() << " Defence" << endl;
		cout << User.getMagic() << " MP" << endl;
		cout << "" << endl;
		//This is a switch statement that uses the function. fightMenu() as input
		switch (fightMenu())
		{
			//This is in case the input is 1.
		case 1:
			//Output telling the player what they do.
			cout << "You chose to attack and do " << PlayerDam << " Damage!" << endl;
			//This sleeps the thread for 1 second.
			this_thread::sleep_for(1000ms);
			//This sets the health of the monster based on damage done.
			Slime->setHealth(PlayerDam);
			//If the monster died.
			if (Slime->getHealth() <= 0) {
				//Victory output.
				cout << "You beat the slime, now you can go back to the guild and finish registering as an F rank adventurer!!" << endl;
				//This pauses the system.
				system("pause");
				//This sets alive to false to exit the loop.
				alive = false;
			}
			//The monster didn't die.
			else {
				//Output telling the user that the creature attacked.
				cout << "The creature attacks and does " << creaturDam << " Damage!" << endl;
				//This sleeps the thread for 1 second.
				this_thread::sleep_for(1000ms);
				//This sets the health of the user based on the creature damage.
				User.setHealth(creaturDam);
				//If the user dies.
				if (User.getHealth() <= 0) {
					//This runs the deathMessage() function.
					deathMessage();
					//This runs the tryAgain() function to see if they want to try again.
					if (tryAgain() == false)
					{
						//This sets alive to false to exit the loop.
						alive = false;
						//This runs the goodbye() function.
						goodbye();
						//This exits the program returning 0 to the computer saying no errors have occured.
						//This is here because it is literally impossible to lose to the slime.
						exit(0);
					}
					//If the user wanted to try again.
					else {
						//This runs the reset() method to reset the player.
						User.reset(playerMP);
					}
				}
				//This breaks from the switch statement.
				break;
		case 2:
			//This uses the heal() method to heal the player based on their MP.
			User.heal(playerMP);
			//This is outputing telling the user what the monster did.
			cout << "The creature attacks and does " << creaturDam << " Damage!" << endl;
			//This is setting the player health based on the damage the creature did.
			User.setHealth(creaturDam);
			//If the user died.
			if (User.getHealth() <= 0) {
				//This runs the deathMessage() function.
				deathMessage();
				//This runs the tryAgain() function to see if they want to try again.
				if (tryAgain() == false)
				{
					//This sets alive to false to exit the loop.
					alive = false;
					//Output telling the user what happened.
					cout << "Complete failure for that, relaunch!!!" << endl;
					//This runs the goodbye() function.
					goodbye();
					//This exits the program returning 0 to the computer saying no errors have occured.
					//This is here because it is literally impossible to lose to the slime.
					exit(0);
				}
				//If they want to try again.
				else {
					//This resets the player based on their MP.
					User.reset(playerMP);
				}
			}
			//This breaks from the switch statement.
			break;
			}
		}
	}
	//This resets the player based on their MP.
	User.reset(playerMP);
}

//This is the fight2() function it takes in a reference to the Player class, and returns a bool.
bool fight2(Player& User) {
	//Declaring local variables.
	bool fail;
	bool alive = true;
	int creaturDam;
	int PlayerDam;
	//This is setting playerMP by using the getMagic() method.
	int playerMP = User.getMagic();
	//This is creating a DTeir object using a unique pointer.
	unique_ptr<DTeir> Bear(new DTeir);
	//This is running the fightScene() method for Bear.
	Bear->fightScene();
	//This is running the introQuip() method for Bear.
	Bear->introQuip();
	//This sleeps the thread for 2 seconds.
	this_thread::sleep_for(2000ms);
	//This checks to see if the Monsters attack is less than the player's defence.
	if (User.getDefence() >= Bear->getAttack()) {
		//This sets creaturDam to 0.
		creaturDam = 0;
	}
	//If the monster's attack is more than player's defence.
	else {
		//This sets creaturDam to the monsters attack minus the players defence.
		creaturDam = Bear->getAttack() - User.getDefence();
	}
	//This sets PlayerDam by using the getAttack() method.
	PlayerDam = User.getAttack();
	//This is a while statement that checks to see if everything is alive.
	while (alive == true) {
		//This clears the screen.
		system("CLS");
		//this displays the monster's info.
		cout << "Bear: " << Bear->getHealth() << "HP" << endl;
		cout << creaturDam << " Attack power against the Player" << endl;
		cout << "" << endl;
		//This displays the users info
		cout << User.getName() << ": " << User.getHealth() << "HP" << endl;
		cout << User.getAttack() << " Attack Power" << endl;
		cout << User.getDefence() << " Defence" << endl;
		cout << User.getMagic() << " MP" << endl;
		cout << "" << endl;
		//This is a switch statement that uses fightMenu() as an input.
		switch (fightMenu())
		{
			//If the input is 1.
		case 1:
			//Output telling the user what they did.
			cout << "You chose to attack and do " << PlayerDam << " Damage!" << endl;
			//This sleeps the thread for 1 second.
			this_thread::sleep_for(1000ms);
			//This sets the monster's health based on the PlayerDam.
			Bear->setHealth(PlayerDam);
			//this is an if statement that checks to see if the monster is alive.
			if (Bear->getHealth() <= 0) {
				//Output to tell you that you won.
				cout << "You beat the Bear, now you can rank up to a D rank adventurer!!" << endl;
				//This changes alive to false to exit the loop.
				alive = false;
				//This changes fail to false for the return value.
				fail = false;
			}
			//If the bear is still alive.
			else {
				//Outputs what the monster does.
				cout << "The creature attacks and does " << creaturDam << " Damage!" << endl;
				//This sleeps the thread for 1 second.
				this_thread::sleep_for(1000ms);
				//This sets the User's health based on creaturDam.
				User.setHealth(creaturDam);
				//This is an if statement that checks to see if the player died.
				if (User.getHealth() <= 0) {
					//This runs the deathMessage() function.
					deathMessage();
					//This runs the tryAgain() function to see if the user wants to try the fight again.
					if (tryAgain() == false)
					{
						//This changes alive to false to exit the loop.
						alive = false;
						//This sets faile to true for the return value.
						fail = true;
					}
					//If the player wants to try again.
					else {
						//This uses the reset() method to reset the players stats.
						User.reset(playerMP);
					}
				}
				//This breaks out of the switch statement.
				break;
				//This is in case the input is 2.
		case 2:
			//This runs the heal() method based on playerMP.
			User.heal(playerMP);
			//This outputs what the monster does.
			cout << "The creature attacks and does " << creaturDam << " Damage!" << endl;
			//This sleeps the thread for 1 second.
			this_thread::sleep_for(1000ms);
			//This sets the users health based on creaturDam.
			User.setHealth(creaturDam);
			//This checks to see if the player died.
			if (User.getHealth() <= 0) {
				//This runs the deathMessage() function.
				deathMessage();
				//This is an if statement that runs the tryAgain() function to see if the user want to try again.
				if (tryAgain() == false)
				{
					//This changes alive to false to exit the loop.
					alive = false;
					//This changes fail to true for the return value.
					fail = true;
				}
				//If the player wanted to play again.
				else {
					//this runs the reset() method to reset the players stats based on playerMP.
					User.reset(playerMP);
				}
			}
			//This breaks out of the switch statement.
			break;
			}
		}
	}
	//This runs the reset() method to reset the players stats based on playerMP.
	User.reset(playerMP);
	//This returns fail a bool value.
	return fail;
}

//This is the fight3() function it takes in a reference to the Player class, and returns a bool.
bool fight3(Player& User) {
	//Declaring local variables.
	bool fail;
	bool alive = true;
	int creaturDam = 90;
	int PlayerDam;
	//This sets playerMP by using the getMagic() method.
	int playerMP = User.getMagic();
	//This creates a unique pointer of a CTeri class.
	unique_ptr<CTeir> Goblin(new CTeir);
	//This runs the fightScene() method.
	Goblin->fightScene();
	//This runs the introQuip() method.
	Goblin->introQuip();
	//This sleeps the thread for 2 seconds.
	this_thread::sleep_for(2000ms);
	//This is an if statement that checks to see if the attack power of the monseter is less than the players defence.
	if (User.getDefence() >= Goblin->getAttack()) {
		//This sets creaturDam to 0.
		creaturDam = 0;
	}
	//If the monsters damage is more than the players defence.
	else {
		//This sets creaturDam to the monsters attack minus the players defence.
		creaturDam = Goblin->getAttack() - User.getDefence();
	}
	//This sets PlayerDam by running the getAttack() method.
	PlayerDam = User.getAttack();
	//This is a while loop that checks to see if everything is alive.
	while (alive == true) {
		//This clears the screen.
		system("CLS");
		//This outputs the monsters information.
		cout << "Goblin: " << Goblin->getHealth() << "HP" << endl;
		cout << creaturDam << " Attack power against the Player" << endl;
		cout << "" << endl;
		//This outputs the players information.
		cout << User.getName() << ": " << User.getHealth() << "HP" << endl;
		cout << User.getAttack() << " Attack Power" << endl;
		cout << User.getDefence() << " Defence" << endl;
		cout << User.getMagic() << " MP" << endl;
		cout << "" << endl;
		//This is a switch statement that uses the fightMenu() function as an input.
		switch (fightMenu())
		{
			//This is if the input is 1.
		case 1:
			//This is output telling the User what they chose to do.
			cout << "You chose to attack and do " << PlayerDam << " Damage!" << endl;
			//This sleeps the thread for 1 second.
			this_thread::sleep_for(1000ms);
			//This sets the monsters health based on PlayerDam.
			Goblin->setHealth(PlayerDam);
			//This is an ifstatement that checks to see if the monster is dead.
			if (Goblin->getHealth() <= 0) {
				//Victory output.
				cout << "You beat the Goblin, now you can rank up to a C rank adventurer!!" << endl;
				//this changes alive to false to exit the loop.
				alive = false;
				//This changes fail to false for the return value.
				fail = false;
			}
			//If the Monster is still alive.
			else {
				//This is output telling the User what the monster does.
				cout << "The creature attacks and does " << creaturDam << " Damage!" << endl;
				//This sleeps the thread for 1 second.
				this_thread::sleep_for(1000ms);
				//This sets the players health based on creaturDam.
				User.setHealth(creaturDam);
				//This is an if statement that checks to see if the player died.
				if (User.getHealth() <= 0) {
					//This runs the deathMessage() function.
					deathMessage();
					//This is an if statement that runst the tryAgain() function to see if the user wants to try again.
					if (tryAgain() == false)
					{
						//This sets alive to false to exit the loop.
						alive = false;
						//This sets fail to true for the return value.
						fail = true;
					}
					//If the player didn't want to try again.
					else {
						//This runs the reset() method based on playerMP.
						User.reset(playerMP);
					}
				}
				//This breaks out of the switch statement.
				break;
				//This is in case the input is 2.
		case 2:
			//This runs the heal() method based on playerMP.
			User.heal(playerMP);
			//This is output telling the user what the monster does.
			cout << "The creature attacks and does " << creaturDam << " Damage!" << endl;
			//This sleeps the thread for 1 second.
			this_thread::sleep_for(1000ms);
			//This sets the users health based on creaturDam.
			User.setHealth(creaturDam);
			//This is checking to see if the player is dead.
			if (User.getHealth() <= 0) {
				//This runs the deathMessage() funcion.
				deathMessage();
				//This is an if statement that runs the tryAgain() function to see if the user wanted to try again.
				if (tryAgain() == false)
				{
					//This sets alive to false to exit the loop.
					alive = false;
					//This sets fail to true for the return value.
					fail = true;
				}
				//If the user didn't want to try again.
				else {
					//This runs the reset() method based on playerMP.
					User.reset(playerMP);
				}
			}
			//This breaks from the switch statement.
			break;
			}
		}
	}
	//This runs the reset() method based on playerMP.
	User.reset(playerMP);
	//This returns fail a bool value.
	return fail;
}

//This is the fight4() function it takes in a reference to the Player class, and returns a bool.
bool fight4(Player& User) {
	//Declaring local variables.
	bool fail;
	bool alive = true;
	int creaturDam = 90;
	int PlayerDam;
	//This sets playerMP by running the getMagic() method.
	int playerMP = User.getMagic();
	//This creates a unique pointer for the BTeir class.
	unique_ptr<BTeir> OrcKing(new BTeir);
	//This runs the fightScene() method.
	OrcKing->fightScene();
	//This runs the introQuip() method.
	OrcKing->introQuip();
	//This sleeps the thread for 2 seconds.
	this_thread::sleep_for(2000ms);
	//This checks to see if the monsters attack is less than the players defence.
	if (User.getDefence() >= OrcKing->getAttack()) {
		//This sets creaturDam to 0.
		creaturDam = 0;
	}
	//If the monters attack is more than the players defence.
	else {
		//This sets creatureDam to the monsters attack minus the users defence.
		creaturDam = OrcKing->getAttack() - User.getDefence();
	}
	//This sets PlayerDam by using the getAttack() method.
	PlayerDam = User.getAttack();
	//This is a while loop that checks to see if everything is alive.
	while (alive == true) {
		//This clears the screen.
		system("CLS");
		//This is outputting the monsters information.
		cout << "Orc King: " << OrcKing->getHealth() << "HP" << endl;
		cout << creaturDam << " Attack power against the Player" << endl;
		cout << "" << endl;
		//This displays the users informaiton.
		cout << User.getName() << ": " << User.getHealth() << "HP" << endl;
		cout << User.getAttack() << " Attack Power" << endl;
		cout << User.getDefence() << " Defence" << endl;
		cout << User.getMagic() << " MP" << endl;
		cout << "" << endl;
		//This is a switch statemetn that uses the fightMenu() function as an input.
		switch (fightMenu())
		{
			//In case the input is 1.
		case 1:
			//Output telling the user what they chose.
			cout << "You chose to attack and do " << PlayerDam << " Damage!" << endl;
			//This sleeps the thread for 1 second.
			this_thread::sleep_for(1000ms);
			//This sets the monsters health based on PlayerDam
			OrcKing->setHealth(PlayerDam);
			//This is an if statement that checks to see if the monster died.
			if (OrcKing->getHealth() <= 0) {
				//Victory output.
				cout << "You beat the Orc King, now you can rank up to a B rank adventurer!!" << endl;
				//This sets alive to false to exit the loop.
				alive = false;
				//This sets fail to false for the return value.
				fail = false;
			}
			//If the monster didn't die.
			else {
				//This tells the user what the monster did.
				cout << "The creature attacks and does " << creaturDam << " Damage!" << endl;
				//This sleeps the thread for 1 second.
				this_thread::sleep_for(1000ms);
				//This runs the setHealth() method based on creaturDam.
				User.setHealth(creaturDam);
				//This is an if statement that checks to see if the player died.
				if (User.getHealth() <= 0) {
					//This runs the deathMessage() function.
					deathMessage();
					//This is an if statement that runs the tryAgain() function to see if the user wanted to try again.
					if (tryAgain() == false)
					{
						//This changes alive to false to exit the loop.
						alive = false;
						//This sets fail to true for the return value.
						fail = true;
					}
					//If the user wanted to try again.
					else {
						//this runs the reset() method based on playerMP.
						User.reset(playerMP);
					}
				}
				//This breaks out of the switch statement.
				break;
				//This is in case the input is 2.
		case 2:
			//This runs the heal() method based on playerMP.
			User.heal(playerMP);
			//This outputs what the creature does.
			cout << "The creature attacks and does " << creaturDam << " Damage!" << endl;
			//This sleeps the thread for 1 second.
			this_thread::sleep_for(1000ms);
			//This sets the players health based on creaturDam.
			User.setHealth(creaturDam);
			//This is an if statement that checks to see if the player died.
			if (User.getHealth() <= 0) {
				//This runs the deathMessage() function.
				deathMessage();
				//This is an if statement that runs the tryAgain() function to see if the user wanted to try again.
				if (tryAgain() == false)
				{
					//This sets alive to false to exit the loop.
					alive = false;
					//This sets fail to true for the return value.
					fail = true;
				}
				//If the user wanted to try again.
				else {
					//This runs the reset() method based on playerMP.
					User.reset(playerMP);
				}
			}
			//This breaks out of the switch statement.
			break;
			}
		}
	}
	//This runs the reset() method based on playerMP.
	User.reset(playerMP);
	//This returns fail a bool value.
	return fail;
}

//This is the fight5() function it takes in a reference to the Player class, and returns a bool.
bool fight5(Player& User) {
	//Declaring local variables.
	bool fail;
	bool alive = true;
	int creaturDam = 90;
	int PlayerDam;
	//This sets playerMP by running the getMagic() method.
	int playerMP = User.getMagic();
	//This creates a unique pointer for the ATeir class.
	unique_ptr<ATeir> Dragon(new ATeir);
	//This runs the fightScene() method.
	Dragon->fightScene();
	//This runs the introQuip() method.
	Dragon->introQuip();
	//This sleeps the thread for 2 seconds.
	this_thread::sleep_for(2000ms);
	//This is an if statement that checks to see if the monsters attack is greater than the players defense.
	if (User.getDefence() >= Dragon->getAttack()) {
		//This sets creaturDam to 0.
		creaturDam = 0;
	}
	//If the monsters attack is greater than the players defense.
	else {
		//This sets creaturDam to the monsters attack minus the users defense.
		creaturDam = Dragon->getAttack() - User.getDefence();
	}
	//This sets PlayerDam by running the getAttack() method.
	PlayerDam = User.getAttack();
	//This is a while loop that checks to see if everything is alive.
	while (alive == true) {
		//This clears the screen.
		system("CLS");
		//This outputs the monsters information.
		cout << "Dragon: " << Dragon->getHealth() << "HP" << endl;
		cout << creaturDam << " Attack power against the Player" << endl;
		cout << "" << endl;
		//This outputs the players information.
		cout << User.getName() << ": " << User.getHealth() << "HP" << endl;
		cout << User.getAttack() << " Attack Power" << endl;
		cout << User.getDefence() << " Defence" << endl;
		cout << User.getMagic() << " MP" << endl;
		cout << "" << endl;
		//This is a switch statement that uses the fightMenu() function as an input.
		switch (fightMenu())
		{
			//This is in case the input is 1.
		case 1:
			//This outputs what the player chose to do.
			cout << "You chose to attack and do " << PlayerDam << " Damage!" << endl;
			//This sleeps the thread for 1 second.
			this_thread::sleep_for(1000ms);
			//This sets the monsters health based on PlayerDam.
			Dragon->setHealth(PlayerDam);
			//This checks to see if the monster died.
			if (Dragon->getHealth() <= 0) {
				//victory message.
				cout << "You beat the Dragon, now you can rank up to a A rank adventurer!!" << endl;
				//This sets alive to false to exit the loop.
				alive = false;
				//This sets fail to false for the return value.
				fail = false;
			}
			//If the monster is still alive.
			else {
				//This tells the user what the monster does.
				cout << "The creature attacks and does " << creaturDam << " Damage!" << endl;
				//This sleeps the thread for 1 second.
				this_thread::sleep_for(1000ms);
				//This sets the users health based on creaturDam.
				User.setHealth(creaturDam);
				//This checks to see if the player is dead.
				if (User.getHealth() <= 0) {
					//This runs the deathMessage() funciton.
					deathMessage();
					//This is an if statement that uses the tryAgain() function to see if the user wanted to try again.
					if (tryAgain() == false)
					{
						//This changes alive to false to exit the loop.
						alive = false;
						//This changes fail to true for the return value.
						fail = true;
					}
					//If the user wanted to try again.
					else {
						//This runs the reset() method based on playerMP.
						User.reset(playerMP);
					}
				}
				//This breaks out of the switch statement.
				break;
				//In case the input is 2.
		case 2:
			//This runs the heal() method based on playerMP.
			User.heal(playerMP);
			//This tells the user what the monster did.
			cout << "The creature attacks and does " << creaturDam << " Damage!" << endl;
			//This sleeps the thread for 1 second.
			this_thread::sleep_for(1000ms);
			//This sets the players health based on creaturDam.
			User.setHealth(creaturDam);
			//This checks to see if the player died.
			if (User.getHealth() <= 0) {
				//This runs the deathMessage() function.
				deathMessage();
				//This is an if statement that runs the tryAgain() function to see if the user wanted to try again.
				if (tryAgain() == false)
				{
					//This sets alive to false to exit the loop.
					alive = false;
					//This sets fail to true for the return value.
					fail = true;
				}
				//This is if the user wanted to try again.
				else {
					//This runs the reset() method based on playerMP.
					User.reset(playerMP);
				}
			}
			//This breaks out of the switch statement.
			break;
			}
		}
	}
	//This runs the reset() method based on playerMP.
	User.reset(playerMP);
	//This returns fail as a bool value.
	return fail;
}

//This is the story1() function it passes in a class and returns nothing.
void story1(Player User) {
	//This clears the screen.
	system("CLS");
	//Story output.
	cout << "Welcome back " << User.getName() << endl;
	cout << "I see you defeated the slime." << endl;
	cout << "You are now a rank F adventurer." << endl;
	cout << "" << endl;
	//This sleeps the thread for 2 seconds.
	this_thread::sleep_for(2000ms);
	//More story output.
	cout << "I have your next quest." << endl;
	cout << "You must defeat the bear that plagues the outskurts of the forest of depravity." << endl;
	cout << "Once you have completed this quest you will be a rank D adventurer." << endl;
	//This pauses the system waiting for user input.
	system("pause");
}

//This is the story2() function it passes in a class and returns nothing.
void story2(Player User) {
	//This clears the screen.
	system("CLS");
	//Story output.
	cout << "Welcome back " << User.getName() << endl;
	cout << "That bear is a tough one, but I'm not surprised you beat it though." << endl;
	cout << "You are now a rankd D adventurer." << endl;
	cout << "" << endl;
	//This sleeps the thread for 2 seconds.
	this_thread::sleep_for(2000ms);
	//More story.
	cout << "I have your next quest." << endl;
	cout << "You must defeat a goblin and bring it back here." << endl;
	cout << "I heard there is a cave just south of the Eastern Gate." << endl;
	cout << "Once you have completed this quest you will be a rank C adventurer." << endl;
	//This pauses the system waiting for user input.
	system("pause");
}

//This is the story3() function it passes in a class and returns nothing.
void story3(Player User) {
	//This clears the screen.
	system("CLS");
	//Story output.
	cout << "Welcome back " << User.getName() << endl;
	cout << "Thanks for getting one for us. We need it for research to make sure they aren't getting too smart." << endl;
	cout << "You are now a rank C adventurer." << endl;
	cout << "" << endl;
	//This sleeps the thread for 2 seconds.
	this_thread::sleep_for(2000ms);
	//More story.
	cout << "I have your next quest, and this is going to be a tough one." << endl;
	cout << "There is an Orc King that has taken over the village of durandal." << endl;
	cout << "I'm sure you can see where I am headed with this." << endl;
	cout << "If you complete this quest you will be a rank B adventurer." << endl;
	//This pauses the system waiting for user input.
	system("pause");
}

//This is the story4() function it passes in a class and returns nothing.
void story4(Player User) {
	//This clears the screen.
	system("CLS");
	//Story output.
	cout << "Welcome back " << User.getName() << endl;
	cout << "I'm glad you made it back alive." << endl;
	cout << "Since you made it back though the Guild Master would like a word with you." << endl;
	//This sleeps the thread for 2 seconds.
	this_thread::sleep_for(2000ms);
	//More story.
	cout << "" << endl;
	cout << "you start to head upstairs to the Guild Master's office." << endl;
	cout << "" << endl;
	//This sleeps the thread for 1 second.
	this_thread::sleep_for(1000ms);
	//Even more story.
	cout << "*knock knock*" << endl;
	cout << "" << endl;
	//This sleeps the thread for 1 second.
	this_thread::sleep_for(1000ms);
	//Extra more story.
	cout << "Come in!" << endl;
	cout << "" << endl;
	//This sleeps the thread for 1 second.
	this_thread::sleep_for(1000ms);
	//How long is this story.
	cout << "You walk through the door and see an old man, looks like he's 1000 years old." << endl;
	cout << "Ahhhh " << User.getName() << " Sit down, please." << endl;
	cout << "" << endl;
	cout << "You take a seet at his desk." << endl;
	//This sleeps the thread for 1 second.
	this_thread::sleep_for(1000ms);
	//Crazy how much story their is.
	cout << "" << endl;
	cout << "I bet you're wondering why I called for you." << endl;
	cout << "Well to put it simply it has to do with the recent awakening of the Dragon of Venture." << endl;
	//This sleeps the thread for 1 second.
	this_thread::sleep_for(1000ms);
	//This story is big.
	cout << "I want you to take care of it for us." << endl;
	cout << "If you do your name will go down in the history books, and You will be paid so hansomly that you can live fruvely for the rest of your life." << endl;
	//This sleeps the thread for 1 second.
	this_thread::sleep_for(1000ms);
	//Astonishing amount of story.
	cout << "If you can defeat this monster you will become a rank A adventurer, one of only four." << endl;
	cout << "It has made its home the Volcano known as Harbenger." << endl;
	cout << "That is all. You can go now." << endl;
	//This pauses the system waiting for user input.
	system("pause");
}

//This is the storyEnd() function it passes in a class and returns nothing.
void storyEnd(Player User) {
	//This clears the screen.
	system("CLS");
	//Story output.
	cout << "As you're walking back into town you can see the townspeople gathered doing something." << endl;
	//This sleeps the thread for 1 second.
	this_thread::sleep_for(1000ms);
	//More story.
	cout << "You walk up to find out what it is." << endl;
	//This sleeps the thread for 1 second.
	this_thread::sleep_for(1000ms);
	//More story.
	cout << "You see the guild master making a speech and before you can figure out what he is talking about he grabs you." << endl;
	//This sleeps the thread for 1 second.
	this_thread::sleep_for(1000ms);
	//More story.
	cout << "Behold The Hero of Camelot, This young man defeated the Dragon of Venture!!!!" << endl;
	//This sleeps the thread for 1 second.
	this_thread::sleep_for(1000ms);
	//More story.
	cout << "There is a round of aplauce and cheering, everyone pushing past each other to shake your hand." << endl;
	//This sleeps the thread for 1 second.
	this_thread::sleep_for(1000ms);
	//Victory output.
	cout << "You Won" << endl;
	//This pauses the system waiting for user input.
	system("pause");
}
