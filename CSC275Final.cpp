//Tecumseh McMullin, CSC275, Filename: CSC275Final.cpp
//This is the main cpp file for the program, it holds the main function necessary for the programs running.
//This is an adventure game, With fighting and NPCs.

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

//This is the main() function it runs the whole program then returns 0 to the computer saying that there were no errors.
int main() {
	//This is setting the seed for the srand() based on the time it is so that it is a true random number.
	srand((unsigned int)time(NULL));
	//This is declaring local variables for the main() function.
	bool onGoGame = true;
	int saveNumber = 0;
	bool playGame;
	bool trainingLoop = true;
	//This is making the file saved for input and output.
	fstream saved;
	//This is creating TheChosenOne from the Player class.
	Player TheChosenOne("");
	//This is clearing the screen so that it doesn't get cluttered.
	system("CLS");
	//This is a while loop that keeps the game going until the user wants to exit.
	while(onGoGame == true) {
		//This is setting playGame to true so that the game after the title screen keeps going until the user wants to exit.
		playGame = true;
		//This is running the title() function.
		title();
		//This is a switch statement that is running the menu() function for input.
		switch (menu()) {
			//This is if the menu() function returned 1.
		case 1: {
			//This is setting the saveNumber to 0 for the beginning of the game.
			saveNumber = 0;
			//This is breaking from the switch statement.
			break;
		}
			  //This is if the menu() function returned 2.
		case 2:
			//This is using saveFind() to set saveNumber if the User wanted to continue their previous game.
				saveNumber = saveFind(TheChosenOne, saved);
				//This is breaking from the switch statement.
				break;
		}
		//This is a while loop for the main portion of the game.
		while (playGame == true) {
			//This is setting training to true for the training loops.
			bool training = true;
			//This is a switch statement that uses the saveNumber to decide where in the story the player is.
			switch (saveNumber)
			{
				//This is if saveNumber is 0. It is the beginning of the game.
			case 0: {
				//This uses the setName() method for TheChosenOne to set the name of the character.
				TheChosenOne.setName();
				//This is creating the thread SI using the function storyIntro().
				thread SI(storyIntro, TheChosenOne);
				//This is joining the thread SI.
				SI.join();
				//This is pausing the system so that it gives the user some time.
				system("pause");
				//This is running the fight1() function passing TheChosenOne in by reference.
				fight1(TheChosenOne);
				//This is setting the saveNumber to 1 because they completed this section.
				saveNumber = 1;
				//This is breaking from the switch statement.
				break;
			}
				  //This is if saveNumber is 1. It is the second portion of the game.
			case 1: {
				//This is creating the thread S! using the function story1().
				thread S1(story1, TheChosenOne);
				//This is joining the thread S1.
				S1.join();
				//This is setting training to true for a loop.
				training = true;
				//This is setting trainingLoop to true so that the user can keep training.
				trainingLoop = true;
				//This is a while loop that will keep going until the user wins the fight.
				while (training == true) {
					//This is a while loop that will keep going until the user doesn't want to train anymore.
					while (trainingLoop == true) {
						//This is an if statement using train() to find out if they want to traing.
						if (train(TheChosenOne, saveNumber, saved) == true) {
							//If they wanted to train it will use the train() function to start the training process.
							train(TheChosenOne);
						}
						//If the user didn't want to train.
						else {
							//This will set trainingLoop to false so it can exit this loop.
							trainingLoop = false;
						}

					}
					//This is setting training by running the fight2() function based on whether they succeed or not.
					training = fight2(TheChosenOne);
					//This is setting the trainingLoop to true so that they can train after the fight if they failed.
					trainingLoop = true;
				}
				//This is setting the saveNumber to 2 because the user completed this section of the game.
				saveNumber = 2;
				//This breaks from the switch statement.
				break;
			}
				  //This is if saveNumber is 2. It is the third portion of the game.
			case 2: {
				//This is creating the thread S2 running the function story2().
				thread S2(story2, TheChosenOne);
				//This is joining the thread S2.
				S2.join();
				//This is setting training to true for a loop.
				training = true;
				//This is setting trainingLoop to true so that the user can keep training.
				trainingLoop = true;
				//This is a while loop that will keep going until the user wins the fight.
				while (training == true) {
					//This is a while loop that will keep going until the user doesn't want to train anymore.
					while (trainingLoop == true) {
						//This is an if statement using train() to find out if they want to traing.
						if (train(TheChosenOne, saveNumber, saved) == true) {
							//If they wanted to train it will use the train() function to start the training process.
							train(TheChosenOne);
						}
						//If the user didn't want to train.
						else {
							//This will set trainingLoop to false so it can exit this loop.
							trainingLoop = false;
						}

					}
					//This is setting training by running the fight3() function based on whether they succeed or not.
					training = fight3(TheChosenOne);
					//This is setting the trainingLoop to true so that they can train after the fight if they failed.
					trainingLoop = true;
				}
				//This is setting the saveNumber to 3 because the user completed this section of the game.
				saveNumber = 3;
				//This breaks from the switch statement.
				break;
			}
				  //This is if saveNumber is 3. This is the fourth portion of the game.
			case 3: {
				//This is creating the thread S3 that uses the function story3().
				thread S3(story3, TheChosenOne);
				//This is joining the thread S3.
				S3.join();
				//This is setting training to true for a loop.
				training = true;
				//This is setting trainingLoop to true so that the user can keep training.
				trainingLoop = true;
				//This is a while loop that will keep going until the user wins the fight.
				while (training == true) {
					//This is a while loop that will keep going until the user doesn't want to train anymore.
					while (trainingLoop == true) {
						//This is an if statement using train() to find out if they want to traing.
						if (train(TheChosenOne, saveNumber, saved) == true) {
							//If they wanted to train it will use the train() function to start the training process.
							train(TheChosenOne);
						}
						//If the user didn't want to train.
						else {
							//This will set trainingLoop to false so it can exit this loop.
							trainingLoop = false;
						}

					}
					//This is setting training by running the fight4() function based on whether they succeed or not.
					training = fight4(TheChosenOne);
					//This is setting the trainingLoop to true so that they can train after the fight if they failed.
					trainingLoop = true;
				}
				//This is setting the saveNumber to 4 because the user completed this section of the game.
				saveNumber = 4;
				//This breaks from the switch statement.
				break;
			}
				  //This is if saveNumber is 4. This is the fifth portion of the game.
			case 4: {
				//This is creating the thread S4 that uses the function story4().
				thread S4(story4, TheChosenOne);
				//This is joining the thread S4
				S4.join();
				//This is setting training to true for a loop.
				training = true;
				//This is setting trainingLoop to true so that the user can keep training.
				trainingLoop = true;
				//This is a while loop that will keep going until the user wins the fight.
				while (training == true) {
					//This is a while loop that will keep going until the user doesn't want to train anymore.
					while (trainingLoop == true) {
						//This is an if statement using train() to find out if they want to traing.
						if (train(TheChosenOne, saveNumber, saved) == true) {
							//If they wanted to train it will use the train() function to start the training process.
							train(TheChosenOne);
						}
						//If the user didn't want to train.
						else {
							//This will set trainingLoop to false so it can exit this loop.
							trainingLoop = false;
						}

					}
					//This is setting training by running the fight5() function based on whether they succeed or not.
					training = fight5(TheChosenOne);
					//This is setting the trainingLoop to true so that they can train after the fight if they failed.
					trainingLoop = true;
				}
				//This is setting the saveNumber to 5 because the user completed this section of the game.
				saveNumber = 5;
				//This breaks from the switch statement.
				break;
			}
				  //This is if saveNumber is 5. This is the end of the game.
			case 5: {
				//This is creating the thread SE that uses the function storyEnd().
				thread SE(storyEnd, TheChosenOne);
				//This is joining the thread S4
				SE.join();
				//This is setting playGame to false so that it takes the user back to the title screen.
				playGame = false;
				//This breaks from the switch statement.
				break;
			}
			}
		}
	}
	//This deconstructs theChosenOne Player.
	TheChosenOne.~Player();
	//This returns 0 to the computer telling it that there were no errors.
	return 0;
}