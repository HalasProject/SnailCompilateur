#include "Lexical.h"
#include "pch.h"


using namespace std;
bool DoF = true;
Lexical::Lexical()
{
}

void Lexical::checkOperator(char A)
{
	for (i = 0; i < sizeof(operation); i++) {
		if (A == operation[i])
		{printf("Operator   : %c \n",A);}
	}
}
char Lexical::checkCommenaireEtEnd(char A,FILE*& SnailFile)
{
	if (A == '%')
		if ((A = getc(SnailFile)) == '.') {
			if ((A = getc(SnailFile)) == '.') {

				printf ("Commentaire: ");
				while (A != '\n') {
					A = getc(SnailFile);
					printf ("%c", A);
				}
			}
			else
			{
				printf("%%. : Mot reserve pour fin d'une instruction \n");
				printf("-----------------------------------------------------------------------\n");
			}
		}
		else 
			if (DoF)
			{
				printf("%% :Debut De condition\n");
				DoF = false;
			}
			else
			{
				printf("%% :Fin de Condition\n");
				DoF = true;
			}
	
	return A;
}
void Lexical::check_key(char* manyC)
{
    int flag = 0;
	for (i = 0; i < sizeInstruction; ++i)
	{
		/* linear search for the keyword */
		if (strcmp(instruction[i], manyC) == 0)
		{
			printf ("Keyword    : %s\n", manyC);
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
			printf ("%d : Literal\n", temp);
			return;
		}
		else
		{
			printf ("Identificateur : %s (invalid)\n", manyC);
			return;
		}
	}

	/* if string starts with alphabet */
	if (manyC[0] >= 65 && manyC[0] <= 90 || manyC[0] >= 97 && manyC[0] <= 122)
	{
		printf ("%s : Identificateur\n", manyC);
		return;
	}
}
void Lexical::checkprintf(char A, FILE*& SnailFile)
{
	if (A == '"') {
		printf ("Chaine     : (");
		A = getc(SnailFile);
		printf ("%c", A);
		while ((A != '"') && (A != '\n'))
		{

			A = getc(SnailFile);
			if (A != '"') { printf("%c", A); }
			
		}
		printf (")\n");
	}
	else
		return;
}