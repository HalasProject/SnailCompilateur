/**
	Salah Eddine Bentayeb
	GitHub.com/HalasProject
	FB | TWI | IG | @HalasDior
	Snail Compiler
	@version 1.0
*/

#include "pch.h"
#include "Token.h"

static std::vector<std::string> HOKI;
Token::Token(FILE * SnailFile, bool ShowONOFF)
{
	HOKI.clear();
	while ((caractere = getc(SnailFile)) != EOF) {
		checkOperator(caractere, SnailFile);
		checkCommenaireEtEnd(caractere, SnailFile);
		checkprintf(caractere, SnailFile);
		if ((caractere >= 48 && caractere <= 57) || (caractere >= 97 && caractere <= 122) || (caractere >= 65 && caractere <= 90) || (caractere == '_') || (caractere == '.'))
			manyC[j++] = caractere;
		else if ((caractere == ' ') || (caractere == '\n') || (caractere == ',') && (j != 0))
		{
			manyC[j] = '\0';
			std::string TOK(manyC);
			HOKI.push_back(TOK);
			j = 0;
		}
	}
	if (ShowONOFF) {
		//ShowMe(HOKI);
	}
}
std::vector<std::string> Token::getVector() {
	return HOKI;
}
void Token::checkOperator(char A, FILE*& SnailFile)
{
	for (int U = 0; U < sizeof(operation); U++) {
		if (A == operation[U])
		{
			manyC[j++] = A;
			manyC[j] = '\0';
			std::string TOK(manyC);
			HOKI.push_back(TOK);
			j = 0;
			getc(SnailFile);
		}
	}
}
char Token::checkCommenaireEtEnd(char A, FILE*& SnailFile)
{
	if (A == '%')
	{
		manyC[j++] = A;
		if ((A = getc(SnailFile)) == '.') {
			manyC[j++] = A;

			if ((A = getc(SnailFile)) == '.') {
				manyC[j++] = A;
				manyC[j] = '\0';
				std::string TOK(manyC);
				HOKI.push_back(TOK);
				j = 0;
				while (A != '\n')
				{
					A = getc(SnailFile);
					manyC[j++] = A;
				}
				manyC[j] = '\0';
				std::string TOK1(manyC);
				HOKI.push_back(TOK1);
				j = 0;
			}
			else
			{
				manyC[j] = '\0';
				std::string TOK(manyC);
				HOKI.push_back(TOK);
				j = 0;
			}

		}
		else
		{
			manyC[j] = '\0';
			std::string TOK(manyC);
			HOKI.push_back(TOK);
			j = 0;

		}
	}
	else
		return A;
}
char Token::checkprintf(char A, FILE*& SnailFile) {

	if (A == '"') {

		manyC[j++] = A;
		A = getc(SnailFile);
		while (A != '"')
		{
			manyC[j++] = A;
			A = getc(SnailFile);
		}
		manyC[j++] = '"';
		manyC[j] = '\0';
		std::string TOK(manyC);
		HOKI.push_back(TOK);
		j = 0;
		return A = getc(SnailFile);
	}
	else
		return A;
}
void Token::ShowMe()
{
	int T = 0;
	for (T = 0; T < HOKI.size(); T++)
	{
		std::cout << "Token " << T << " : " << HOKI[T] << "\n";
	}
}