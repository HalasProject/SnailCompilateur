/**
	Salah Eddine Bentayeb
	GitHub.com/HalasProject
	FB | TWI | IG | @HalasDior
	Snail Compiler
	@version 1.0
*/

#include "Semantique.h"
#include "pch.h"

bool intilg = true;
bool TurnMe = true;
bool doit = true;

Semantique::Semantique(FILE* SnailFile)
{
	bezzaf.clear();
	while ((caractere = getc(SnailFile)) != EOF) {
		
		checkOperator(caractere);
		checkCommenaireEtEnd(caractere, SnailFile);
		checkprintf ( caractere, SnailFile);

		if ((caractere >= 48 && caractere <= 57) || (caractere >= 97 && caractere <= 122) || (caractere >= 65 && caractere <= 90) || (caractere == '_') || (caractere == '.') || (caractere == ','))
			manyC[j++] = caractere;
		else if ((caractere == ' ') || (caractere == '\n') && (j != 0))
		{
			manyC[j] = '\0';
			j = 0;
			if (strcmp("If", manyC) == 0)
			{

				bezzaf += "if";
				while ((caractere = getc(SnailFile)) != '\n') {
					if (caractere == '%' && doit == true) {
						if (TurnMe)
						{
							bezzaf += "(";
							TurnMe = false;
							continue;
						}
						else
						{
							bezzaf += ")";
							bezzaf += "\n";
							doit = false;
							break;
						}
					}
					bezzaf += caractere;
				}
			}
			else if (strcmp("Snl_Start", manyC) == 0)
			{
				bezzaf += "int main(){\r\n";
			}
			else if (strcmp("Snl_Put", manyC) == 0)
			{
				bezzaf += "cout << ";
			}
			else if (strcmp("Snl_Close", manyC) == 0)
			{
				bezzaf += "\r\n}";
			}
			else if (strcmp("Snl_Int", manyC) == 0)
			{
				bezzaf += "int ";
			}
			else if (strcmp("Snl_Real", manyC) == 0)
			{
				bezzaf += "float ";
			}
			else if (strcmp("Else", manyC) == 0)
			{
				bezzaf += "Else \r\n";
			}
			else if (strcmp("Start", manyC) == 0)
			{
				bezzaf += "{\r\n";
			}
			else if (strcmp("Finish", manyC) == 0)
			{
				bezzaf += "}\r\n";
			}
			else if (strcmp("Get", manyC) == 0)
			{
				while ((caractere = getc(SnailFile)) != '\n') {
					if (caractere == '%')
					{
						caractere = getc(SnailFile); 
						bezzaf += ";\r\n";
						intilg = true;
						break;
					}
					if (caractere == 'f')
					{
						caractere = getc(SnailFile);
						caractere = getc(SnailFile);
						caractere = getc(SnailFile);
						caractere = getc(SnailFile);
						caractere = getc(SnailFile);
						bezzaf += "";
					}
					if ((caractere == ' ') && (intilg == true))
					{
						bezzaf += "=";
						intilg = false;
					}
					else
						bezzaf += caractere;
				}
			}
			else if (strcmp("Set", manyC) == 0)
			{

				while ((caractere = getc(SnailFile)) != '\n') {
					if (caractere == '%')
					{
						caractere = getc(SnailFile); bezzaf += ";\r\n";
						intilg = true;
						break;
					}
					if ((caractere == ' ') && (intilg == true))
					{
						bezzaf += "=";
						intilg = false;
					}
					else
						bezzaf += caractere;
				}
			}


			else {
				check_key(manyC);
			}

		}
	}
}

void Semantique::checkOperator(char A)
{
	for (i = 0; i < sizeof(operation); i++) {
		if (A == operation[i])
		{
			bezzaf +=  A;
		}
	}
}
char Semantique::checkCommenaireEtEnd(char A, FILE*& SnailFile)
{
	if (A == '%')
		if ((A = getc(SnailFile)) == '.') {
			if ((A = getc(SnailFile)) == '.') {

				bezzaf += "//";
				while (A != '\n') {
					A = getc(SnailFile);
					bezzaf += A;
				}
			}
			else
				bezzaf += ";\r\n";

		}

	return A;
}
void Semantique::check_key(char* manyC)
{
	int flag = 0;
	for (i = 0; i < sizeInstruction; ++i)
	{
		/* linear search for the keyword */
		if (strcmp(instruction[i], manyC) == 0)
		{
			bezzaf += "Keyword    : "+std::string(manyC)+"\r\n";
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
			//int temp = atoi(manyC);
			bezzaf += std::string(manyC);
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
		bezzaf += std::string(manyC);
		return;
	}
}
void Semantique::checkprintf(char A, FILE*& SnailFile)
{
	if (A == '"') {
		bezzaf += "\"";
		A = getc(SnailFile);
		bezzaf += A;
		while ((A != '"') && (A != '\n'))
		{

			A = getc(SnailFile);
			if (A != '"') { bezzaf += A; }

		}
		bezzaf += "\"";
	}
	else
		return;
}
std::string Semantique::fin() {
	return bezzaf;
}