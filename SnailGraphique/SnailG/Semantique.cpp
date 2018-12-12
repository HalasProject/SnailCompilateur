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

Semantique::Semantique(std::ifstream& SnailFile)
{
	
	bezzaf.clear();
	intilg = true;
	TurnMe = true;
	doit = true;
	bezzaf += "#include<iostream>\r\n#include<string>\r\n\r\nusing namespace std;\r\n\r\n";
	while ((caractere = SnailFile.get()) != EOF) {
		
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
				while ((caractere = SnailFile.get()) != '\n') {
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
			else if (strcmp("SnlSt", manyC) == 0)
			{
				bezzaf += "string ";
				while ((caractere = SnailFile.get()) != ' ') {
					bezzaf += caractere;
				}
				bezzaf += " = ";
			}
			else if (strcmp("Snl_Real", manyC) == 0)
			{
				bezzaf += "float ";
			}
			else if (strcmp("Else", manyC) == 0)
			{
				bezzaf += "else \r\n";
			}
			else if (strcmp("Start", manyC) == 0)
			{
				bezzaf += "{\r\n";
			}
			else if (strcmp("Finish", manyC) == 0)
			{
				bezzaf += "}\r\n";

			}
			else if (strcmp("do", manyC) == 0)
			{
				bezzaf += " ";
			}
			else if (strcmp("Get", manyC) == 0)
			{
				while ((caractere = SnailFile.get()) != '\n') {
					if (caractere == '%')
					{
						caractere = SnailFile.get(); 
						bezzaf += ";\r\n";
						intilg = true;
						break;
					}
					if (caractere == 'f')
					{
						caractere = SnailFile.get();
						caractere = SnailFile.get();
						caractere = SnailFile.get();
						caractere = SnailFile.get();
						caractere = SnailFile.get();
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

				while ((caractere = SnailFile.get()) != '\n') {
					if (caractere == '%')
					{
						caractere = SnailFile.get();  bezzaf += ";\r\n";
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
char Semantique::checkCommenaireEtEnd(char A, std::ifstream& SnailFile)
{
	if (A == '%')
		if ((A = SnailFile.get()) == '.') {
			if ((A = SnailFile.get()) == '.') {

				bezzaf += "//";
				while (A != '\n') {
					A = SnailFile.get();
					bezzaf += A;
				}
				bezzaf += "\r\n";
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
void Semantique::checkprintf(char A, std::ifstream& SnailFile)
{
	if (A == '"') {
		bezzaf += "\"";
		A = SnailFile.get();
		bezzaf += A;
		while ((A != '"') && (A != '\n'))
		{

			A = SnailFile.get();
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