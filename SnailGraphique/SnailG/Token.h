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


class Token {
public:
	Token(FILE *, bool);
	std::vector<std::string> getVector();
	void checkOperator(char, FILE*& SnailFile);
	void ShowMe();
	char checkCommenaireEtEnd(char, FILE*& SnailFile);
	char checkprintf(char, FILE*& SnailFile);
protected:
private:

};

#endif
