//Tecumseh McMullin, CSC275, Filename: CSC275Final.h
//This is the header file for all of the functions for CSC275Final.cpp

#ifndef CSC275FINAL_H
#define CSC275FINAL_H

//This is where I am including all of the libraries that I will use.
#include <iostream> //This includes the iostream library for basic input.
#include <string> //This includes the string library for use of strings in unorthodox places.
#include <memory> //This includes the memory library for the use of smart pointers.
#include <thread> //This includes the thread library for the use of threads.
#include <chrono> //This includes the chrono library for the user of ms/time.
#include <mutex> //This includes the mutex library for data protection.
#include <ctime> //This includes the ctime library for random generation.
#include <fstream> //This includes the fstream library for file input and output.
#include <fstream> //This includes the fstream library for file input and output.

//This tells the program that we are using the std namespace so that I don't have to use std:: all the time.
using namespace std;

//This is declaring all of the Functions for the use from the other files
void title();
int menu();
bool train(Player& User, int saveNum, fstream& saved);
void train(Player& User);
void goodbye();
void deathMessage();
void saveGame(int save, Player User,fstream& saved);
int saveFind(Player& User,fstream& saved);
void storyIntro(Player User);
void story1(Player User);
void story2(Player User);
void story3(Player User);
void story4(Player User);
void storyEnd(Player User);
int fightMenu();
void fight1(Player& User);
bool fight2(Player& User);
bool fight3(Player& User);
bool fight4(Player& User);
bool fight5(Player& User);

#endif // !CSC275FINAL_H
