#include "pch.h"
#include "Token.h"


Token::Token()
{
}

void Token::ShowMe(vector<string> Token)
{
	int T = 0;
	for (T = 0; T < Token.size(); T++)
	{
		cout << "Token" << T << " : " << Token[T] << "\n";
	}
}
