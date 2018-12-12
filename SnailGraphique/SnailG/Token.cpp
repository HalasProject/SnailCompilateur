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

Token::Token(std::ifstream& SnailFile)
{
	HOKI.clear();
	while ((caractere = SnailFile.get()) != EOF) {
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
}
std::vector<std::string> Token::getVector() {
	return HOKI;
}
void Token::checkOperator(char A, std::ifstream& SnailFile)
{
	for (int U = 0; U < sizeof(operation); U++) {
		if (A == operation[U])
		{
			manyC[j++] = A;
			manyC[j] = '\0';
			std::string TOK(manyC);
			HOKI.push_back(TOK);
			j = 0;
			SnailFile.get();
		}
	}
}
char Token::checkCommenaireEtEnd(char A, std::ifstream& SnailFile)
{
	if (A == '%')
	{
		manyC[j++] = A;
		if ((A = SnailFile.get()) == '.') {
			manyC[j++] = A;

			if ((A = SnailFile.get()) == '.') {
				manyC[j++] = A;
				manyC[j] = '\0';
				std::string TOK(manyC);
				HOKI.push_back(TOK);
				j = 0;
				while (A != '\n')
				{
					A = SnailFile.get();
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
char Token::checkprintf(char A, std::ifstream& SnailFile) {

	if (A == '"') {

		manyC[j++] = A;
		A = SnailFile.get();
		while (A != '"')
		{
			manyC[j++] = A;
			A = SnailFile.get();
		}
		manyC[j++] = '"';
		manyC[j] = '\0';
		std::string TOK(manyC);
		HOKI.push_back(TOK);
		j = 0;
		return A = SnailFile.get();
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