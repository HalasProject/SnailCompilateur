#include "pch.h"
#include "Token.h"

Token::Token(FILE * SnailFile)
{
	printf("[*]------------------------------------------------------[*]\n");
	printf("[*]-------------------T---O---K---E---N------------------[*]\n");
	printf("[*]------------------------------------------------------[*]\n");
	printf("\n\n");

	while ((caractere = getc(SnailFile)) != EOF) {
		checkCommenaireEtEnd(caractere, SnailFile);
		checkprintf(caractere, SnailFile);
		if ((caractere >= 48 && caractere <= 57) || (caractere >= 97 && caractere <= 122) || (caractere >= 65 && caractere <= 90) || (caractere == '_') || (caractere == '.'))
			manyC[j++] = caractere;
		else if ((caractere == ' ') || (caractere == '\n') || (caractere == ',') && (j != 0))
		{
			manyC[j] = '\0';
			string TOK(manyC);
			token.push_back(TOK);
			j = 0;
		}
	}

	ShowMe(token);
	
}
vector<string> Token::getVector() {
	return token;
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
				string TOK(manyC);
				token.push_back(TOK);
				j = 0;
				while (A != '\n')
				{
					A = getc(SnailFile);
					manyC[j++] = A;
					
				}
				manyC[j] = '\0';
				string TOK1(manyC);
				token.push_back(TOK1);
				j = 0;
			}
			else
			{
				manyC[j] = '\0';
				string TOK(manyC);
				token.push_back(TOK);
				j = 0;
			}
		}
	}
	else
		return A;
}
char Token::checkprintf(char A, FILE*& SnailFile)
{
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
		string TOK(manyC);
		token.push_back(TOK);
		j = 0;
		return A = getc(SnailFile);
	}
	else
		return A;
}
void Token::ShowMe(vector<string> Token)
{
	int T = 0;
	for (T = 0; T < Token.size(); T++)
	{
		cout << "Token " << T << " : " << Token[T] << "\n";
	}
}