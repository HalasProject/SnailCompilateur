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
	while ((caractere = getc(SnailFile)) != EOF) {
		color = 11;
		SetConsoleTextAttribute(hConsole, color);
		checkOperator(caractere);
		checkCommenaireEtEnd(caractere, SnailFile);
		checkprintf(caractere, SnailFile);

		if ((caractere >= 48 && caractere <= 57) || (caractere >= 97 && caractere <= 122) || (caractere >= 65 && caractere <= 90) || (caractere == '_') || (caractere == '.') || (caractere == ','))
			manyC[j++] = caractere;
		else if ((caractere == ' ') || (caractere == '\n') && (j != 0))
		{
			manyC[j] = '\0';
			j = 0;
			if (strcmp("If", manyC) == 0)
			{

				printf("if");
				while ((caractere = getc(SnailFile)) != '\n') {
					if (caractere == '%' && doit == true) {
						if (TurnMe)
						{
							printf("(");
							TurnMe = false;
							continue;
						}
						else
						{
							printf(")");
							printf("\n");
							doit = false;
							break;
						}
					}
					printf("%c", caractere);
				}
			}
			else if (strcmp("Snl_Start", manyC) == 0)
			{
				printf("int main(){\n");
			}
			else if (strcmp("Snl_Put", manyC) == 0)
			{
				printf("cout << ");
			}
			else if (strcmp("Snl_Close", manyC) == 0)
			{
				printf("}");
			}
			else if (strcmp("Snl_Int", manyC) == 0)
			{
				printf("int ");
			}
			else if (strcmp("Snl_Real", manyC) == 0)
			{
				printf("float ");
			}
			else if (strcmp("Else", manyC) == 0)
			{
				printf("Else \n");
			}
			else if (strcmp("Start", manyC) == 0)
			{
				printf("{\n");
			}
			else if (strcmp("Finish", manyC) == 0)
			{
				printf("}\n");
			}
			else if (strcmp("Get", manyC) == 0)
			{
				while ((caractere = getc(SnailFile)) != '\n') {
					if (caractere == '%')
					{
						caractere = getc(SnailFile); printf(";\n");
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
						printf("");
					}
					if ((caractere == ' ') && (intilg == true))
					{
						printf("=");
						intilg = false;
					}
					else
						printf("%c", caractere);
				}
			}
			else if (strcmp("Set", manyC) == 0)
			{

				while ((caractere = getc(SnailFile)) != '\n') {
					if (caractere == '%')
					{
						caractere = getc(SnailFile); printf(";\n");
						intilg = true;
						break;
					}
					if ((caractere == ' ') && (intilg == true))
					{
						printf("=");
						intilg = false;
					}
					else
						printf("%c", caractere);
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
			printf("%c", A);
		}
	}
}
char Semantique::checkCommenaireEtEnd(char A, FILE*& SnailFile)
{
	if (A == '%')
		if ((A = getc(SnailFile)) == '.') {
			if ((A = getc(SnailFile)) == '.') {

				printf("//");
				while (A != '\n') {
					A = getc(SnailFile);
					printf("%c", A);
				}
			}
			else
				printf(";\n");

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
			printf("Keyword    : %s\n", manyC);
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
			printf("%d ", temp);
			return;
		}
		else
		{
			printf("Identificateur : %s (invalid)\n", manyC);
			return;
		}
	}

	/* if string starts with alphabet */
	if (manyC[0] >= 65 && manyC[0] <= 90 || manyC[0] >= 97 && manyC[0] <= 122)
	{
		printf("%s", manyC);
		return;
	}
}
void Semantique::checkprintf(char A, FILE*& SnailFile)
{
	if (A == '"') {
		printf("\"");
		A = getc(SnailFile);
		printf("%c", A);
		while ((A != '"') && (A != '\n'))
		{

			A = getc(SnailFile);
			if (A != '"') { printf("%c", A); }

		}
		printf("\"");
	}
	else
		return;
}