#include "Lexical.h"
#include "Syntaxique.h"
#include "Semantique.h"
#include "pch.h"

int choix;
char caractere;
bool intilg = true;
bool TurnMe = true;
bool doit = true;
char manyC[30];
int j=0;

FILE* SnailFile = fopen("Test.snl", "r");
int main()
{

	if (!SnailFile){
		printf("          [*]----------------------------------------[*]\n");
	    printf("          [|]         Erreur du fichier Snail  !     [|]\n");
	    printf("          [*]----------------------------------------[*]\n");
	}
	else {
		printf("          [*]----------------------------------------[*]\n");
		printf("          [|]    Fichier Snail est Bien charger !    [|]\n");
		printf("          [|]----------------------------------------[|]\n");
		printf("          [|]        (1) Analyse Lexical             [|]\n");
		printf("          [|]        (2) Analyse Syntaxique          [|]\n");
	    printf("          [|]        (3) Analyse Semantique          [|]\n");
		printf("          [*]----------------------------------------[*]\n");
		printf("\n\n");
		printf("Snail>");
		cin >> choix;
		printf("\n\n");
		switch (choix)
		{
		case 1:{
		Lexical Lex; 
		while ((caractere = getc(SnailFile)) != EOF) {
			Lex.checkOperator(caractere);
			Lex.checkCommenaireEtEnd(caractere, SnailFile);
			Lex.checkprintf(caractere, SnailFile);

			if ((caractere >= 48 && caractere <= 57) || (caractere >= 97 && caractere <= 122) || (caractere >= 65 && caractere <= 90) || (caractere == '_') || (caractere == '.'))
				manyC[j++] = caractere;
			else if ((caractere == ' ') || (caractere == '\n') || (caractere == ',') && (j != 0))
			{
				manyC[j] = '\0';
				j = 0;
				if (strcmp("If", manyC) == 0)
				{
					printf("%s : Condition\n", manyC);
				}
				else if (strcmp("Snl_Start", manyC) == 0)
				{
					printf("%s : Mot reserve debut de programme \n", manyC);
				}
				else if (strcmp("Snl_Put", manyC) == 0)
				{
					printf("%s : Mot reserve debut de programme \n", manyC);
				}
				else if (strcmp("Snl_Close", manyC) == 0)
				{
					printf("%s : Mot reserve fin de programme\n", manyC);
				}
				else if (strcmp("Snl_Int", manyC) == 0)
				{
					printf("%s   : Mot reserve declaration d'un entier\n", manyC);
				}
				else if (strcmp("Snl_Real", manyC) == 0)
				{
					printf("%s : Mot reserve declaration d'un reel\n", manyC);
				}
				else if (strcmp("Get", manyC) == 0)
				{
					printf("%s : Mot reserve pour affectation d'une valeur \n", manyC);
				}
				else if (strcmp("Set", manyC) == 0)
				{
					printf("%s : Mot reserve pour affectation d'une valeur \n", manyC);
				}
				else {
					Lex.check_key(manyC);
				}

			}
		}
		break;}

		case 3:{
		Semantique Sem;
		while ((caractere = getc(SnailFile)) != EOF) {
			
			Sem.checkOperator(caractere);
			Sem.checkCommenaireEtEnd(caractere, SnailFile);
			Sem.checkprintf(caractere, SnailFile);

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
					
					while ((caractere = getc(SnailFile)) != '\n'){
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
					Sem.check_key(manyC);
				}

			}
		}
		break; }
	
		case 2:
		break;

	    }
	}
}