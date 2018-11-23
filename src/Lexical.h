#ifndef LEXICAL_H
#define LEXICAL_H
#include "pch.h"

class Lexical{
public:
Lexical(FILE*);
void checkOperator(char);
char checkCommenaireEtEnd(char,FILE*& SnailFile);
void check_key(char *);
void checkprintf(char,FILE*& SnailFile);
protected:
private:
};

#endif
