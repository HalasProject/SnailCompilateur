/**
	Salah Eddine Bentayeb
	GitHub.com/HalasProject
	FB | TWI | IG | @HalasDior
	Snail Compiler
	@version 1.0
*/


#ifndef TOKEN_H
#define TOKEN_H
#include "pch.h"


class Token{
public:
Token(FILE *);
vector<string> getVector();
void ShowMe(vector<string> Token);
char checkCommenaireEtEnd(char, FILE*& SnailFile);
char checkprintf(char, FILE*& SnailFile);
protected:
private:

};

#endif
