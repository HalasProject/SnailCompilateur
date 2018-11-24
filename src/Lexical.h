/**
	Salah Eddine Bentayeb
	GitHub.com/HalasProject
	FB | TWI | IG | @HalasDior
	Snail Compiler
	@version 1.0
*/

#ifndef LEXICAL_H
#define LEXICAL_H
#include "pch.h"

class Lexical {
public:
	Lexical(FILE*);
	void checkOperator(char);
	char checkCommenaireEtEnd(char, FILE*& SnailFile);
	void check_key(char *);
	void checkprintf(char, FILE*& SnailFile);
protected:
private:
};

#endif
