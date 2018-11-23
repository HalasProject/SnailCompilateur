/**
	Salah Eddine Bentayeb
	GitHub.com/HalasProject
	FB | TWI | IG | @HalasDior
	Snail Compiler
	@version 1.0
*/

#include "Syntaxique.h"
#include "pch.h"


Syntaxique::Syntaxique(vector<string> &token){
	int nbr_start = 0;
	 int nbr_finish = 0;
	 cout << token.size();
	for (i = 0; i < token.size(); i++) {
		if (token[i] == "Snl_Start")
		{
			cout << token[i];
			continue;
		}

		if (token[i] == "Else")
		{
			cout << "\n" + token[i];
			if (token[i + 1] == "Start")
			{
				cout << "\n" + token[i + 1];
				continue;
			}
			else
			{
				cout << "\n * Start expected";
				continue;
			}
		}

		if (token[i] == "Start")
		{
			nbr_start = nbr_start + 1;
			nbr_finish = nbr_finish + 1;
			if (token[i - 1] == "Else")
			{
				continue;
			}
			else
			{
				cout << "\n * Else expected";
				cout << "\n" + token[i];
				continue;
			}
		}

		if (token[i] == "Finish")
		{
			cout << "\n" + token[i];
			nbr_finish = nbr_finish - 1;
			if (nbr_start > 0)
			{
				nbr_start = nbr_start - 1;
				continue;
			}
			else
			{
				cout << "\n * Syntaxe error Start expected";
			}
		}

		if (token[i] == "Snl_Close")
		{
			if (nbr_finish <= 0)
			{
				cout << "\n" + token[i];
				continue;
			}
			else
			{
				cout << "\n * Syntaxe error Finish expected in the end of the bloc";
				cout << "\n" + token[i];
				continue;
			}

		}

	}
}