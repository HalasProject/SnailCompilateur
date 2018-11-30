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
	Token(std::ifstream&);
	std::vector<std::string> getVector();
	void checkOperator(char, std::ifstream& SnailFile);
	char checkCommenaireEtEnd(char, std::ifstream& SnailFile);
	char checkprintf(char, std::ifstream& SnailFile);
	void ShowMe();
protected:
private:

};

#endif
