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
	Token(FILE *, vector<string>& HOKI, bool);
	vector<string> getVector(vector<string>& HOKI);
	void checkOperator(char, vector<string>& HOKI, FILE*& SnailFile);
	void ShowMe(vector<string>& HOKI);
	char checkCommenaireEtEnd(char, FILE*& SnailFile, vector<string>& HOKI);
	char checkprintf(char, FILE*& SnailFile, vector<string>& HOKI);
protected:
private:

};

#endif
