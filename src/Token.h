#ifndef TOKEN_H
#define TOKEN_H
#include "pch.h"


class Token{
public:
Token(FILE *);
void ShowMe(vector<string> Token);
char checkCommenaireEtEnd(char, FILE*& SnailFile);
char checkprintf(char, FILE*& SnailFile);
protected:
private:

};

#endif
