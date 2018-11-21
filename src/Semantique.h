#ifndef SEMANTIQUE_H
#define SEMANTIQUE_H
#include "pch.h"
class Semantique {
public:
	Semantique();
	void checkOperator(char);
	char checkCommenaireEtEnd(char, FILE*& SnailFile);
	void check_key(char *);
	void checkprintf(char, FILE*& SnailFile);
protected:
private:
};

#endif