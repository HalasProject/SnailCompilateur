/**
	Salah Eddine Bentayeb
	GitHub.com/HalasProject
	FB | TWI | IG | @HalasDior
	Snail Compiler
	@version 1.0
*/

#ifndef PCH_H
#define PCH_H

// TODO: Ajoutez les en-t�tes � pr�compiler ici
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream> // std::cout
#include <filesystem>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>  //std::ifstream
#include <sstream> 

// TODO: Ajoutez les variable global ici
//using namespace std;
static char operation[] = { "!&*+-/<>=" };
static char instruction[][10] = { "Start","Else","Finish","from" };
static int sizeInstruction = sizeof(instruction) / sizeof(instruction[0]);
static int i;
static char caractere;
static char manyC[100];
static int j = 0;
static int color;
static std::vector<std::string> token;
static int split;
static std::string bezzaf;
static std::vector<std::string> TabDeToken;
static std::ifstream Filo;
#endif //PCH_H
