/**
	Salah Eddine Bentayeb
	GitHub.com/HalasProject
	FB | TWI | IG | @HalasDior
	Snail Compiler
	@version 1.0
*/

#ifndef PCH_H
#define PCH_H

// TODO: Ajoutez les en-têtes à précompiler ici

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// TODO: Ajoutez les variable global ici
using namespace std;
static char operation[] = { "!&*+-/<>=" };
static char instruction[][10] = { "Else","Finish","from" };
static int sizeInstruction = sizeof(instruction) / sizeof(instruction[0]);
static int i;
static char caractere;
static char manyC[100];
static int j = 0;
static vector<string> token;


#endif //PCH_H
