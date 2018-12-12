/**
	Salah Eddine Bentayeb
	GitHub.com/HalasProject
	FB | TWI | IG | @HalasDior
	Snail Compiler
	@version 1.0
*/

#include "Lexical.h"
#include "pch.h"
#include "MyForm2.h"
bool DoF = true;

Lexical::Lexical(std::ifstream& SnailFile) 
{
	bezzaf.clear();
		while (SnailFile.get(caractere)) {
			checkOperator(caractere);
			checkCommenaireEtEnd(caractere, SnailFile);
			checkprintf(caractere, SnailFile);

			if ((caractere >= 48 && caractere <= 57) || (caractere >= 97 && caractere <= 122) || (caractere >= 65 && caractere <= 90) || (caractere == '_') || (caractere == '.'))
				manyC[j++] = caractere;
			else if ((caractere == ' ') || (caractere == '\n') || (caractere == ',') && (j != 0))
			{
				manyC[j] = '\0';
				std::string TOK(manyC);
				token.push_back(TOK);
				j = 0;
				if (strcmp("If", manyC) == 0)
				{
					bezzaf += "If : Condition\r\n";
				}
				else if (strcmp("Snl_Start", manyC) == 0)
				{
					bezzaf += "Snl_Start : Mot reserve debut de programme \r\n";
				}
				else if (strcmp("SnlSt", manyC) == 0)
				{
					bezzaf += "SnlSt : Declaration d'une chaine de caractere \r\n";
				}
				else if (strcmp("Snl_Put", manyC) == 0)
				{
					bezzaf += "Snl_Put : Mot reserve pour affichage \r\n";
				}
				else if (strcmp("Snl_Close", manyC) == 0)
				{
					bezzaf += "Snl_Close : Mot reserve fin de programme\r\n";
				}
				else if (strcmp("Snl_Int", manyC) == 0)
				{
					bezzaf += "Snl_Int   : Mot reserve declaration d'un entier\r\n";
				}
				else if (strcmp("Snl_Real", manyC) == 0)
				{
					bezzaf += "Snl_Real : Mot reserve declaration d'un reel\r\n";
				}
				else if (strcmp("Get", manyC) == 0)
				{
					bezzaf += "Get : Mot reserve pour affectation d'une valeur \r\n";
				}
				else if (strcmp("Set", manyC) == 0)
				{
					bezzaf += "Set : Mot reserve pour affectation d'une valeur \r\n";
				}
				else {
					check_key(manyC);
				}

			}

		}
	}

void Lexical::checkOperator(char A)
{
	
	for (i = 0; i < sizeof(operation); i++) {
		if (A == operation[i])
		{
			bezzaf += "Operator   : ";
			bezzaf += A;
			bezzaf += " \r\n";
		}
	}
}
char Lexical::checkCommenaireEtEnd(char A, std::ifstream& SnailFile)
{
	if (A == '%')
		if ((A = SnailFile.get()) == '.') {
			if ((A = SnailFile.get()) == '.') {

				bezzaf += "Commentaire: ";
				while (A != '\n') {
					A = SnailFile.get();
					bezzaf += A;
				}
				bezzaf += "\r\n";
				
			}
			else
			{
				bezzaf += "%. : Mot reserve pour fin d'une instruction \r\n";
				bezzaf += "-------------------------------------------------------------------\r\n";
			}
		}
		else
			if (DoF)
			{
				bezzaf += "% :Debut De condition\r\n";
				DoF = false;
			}
			else
			{
				bezzaf += "% :Fin de Condition\r\n";
				DoF = true;
			}
	
	return 'c';
}
void Lexical::check_key(char* manyC)
{
	int flag = 0;
	for (i = 0; i < sizeInstruction; ++i)
	{
		/* linear search for the keyword */
		if (strcmp(instruction[i], manyC) == 0)
		{
			bezzaf += "Keyword    : " + std::string(manyC) + "\r\n";
			return;
		}
	}

	/* if string starts with number*/
	if (manyC[0] >= 48 && manyC[0] <= 57)
	{
		for (i = 0; i < strlen(manyC); i++)
		{
			/* checking whether it is literal or invalid identifier */
			if (!(manyC[i] >= 48 && manyC[i] <= 57 || manyC[i] == '.'))
				flag = 1;   /*0 flag=invalid ,1 flag=literal*/
		}

		if (flag != 1)
		{
			/* converting string into number */
			int temp = atoi(manyC);
			bezzaf += ""+std::string(manyC)+" : Chiffre\r\n" ;
			return;
		}
		else
		{
			bezzaf += "Identificateur : " + std::string(manyC) + " (invalid)\r\n";
			return;
		}
	}

	/* if string starts with alphabet */
	if (manyC[0] >= 65 && manyC[0] <= 90 || manyC[0] >= 97 && manyC[0] <= 122)
	{
		bezzaf += std::string(manyC) + " : Identificateur\r\n";
		return;
	}
}
void Lexical::checkprintf(char A, std::ifstream& SnailFile)
{
	if (A == '"') {
		bezzaf += "Chaine : ";
		bezzaf += "(";
		bezzaf += A;
		A = SnailFile.get();
		bezzaf += A;
	
			while ((A != '"') && (A != '%'))
			{

				A = SnailFile.get();
				bezzaf += A;

			}
			bezzaf += ")\r\n";
		
	}
	else
		return;
}
std::string Lexical::fin() {
	return bezzaf;
}