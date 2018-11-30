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
	Semantique(std::ifstream&);
	void checkOperator(char);
	char checkCommenaireEtEnd(char, std::ifstream& SnailFile);
	void check_key(char *);
	void checkprintf(char, std::ifstream& SnailFile);
	static std::string fin();
protected:
private:
};

#endif