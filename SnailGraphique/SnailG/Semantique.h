/**
	Salah Eddine Bentayeb
	GitHub.com/HalasProject
	FB | TWI | IG | @HalasDior
	Snail Compiler
	@version 1.0
*/

#ifndef SEMANTIQUE_H
#define SEMANTIQUE_H
#include "pch.h"
class Semantique {
public:
	Semantique(FILE*);
	void checkOperator(char);
	char checkCommenaireEtEnd(char, FILE*& SnailFile);
	void check_key(char *);
	void checkprintf(char, FILE*& SnailFile);
	static std::string fin();
protected:
private:
};

#endif