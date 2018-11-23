#include "Lexical.h"
#include "Token.h"
#include "Syntaxique.h"
#include "Semantique.h"
#include "pch.h"

int choix;


FILE* SnailFile = fopen("Test.snl", "r");
int main()
{

	if (!SnailFile) {
		printf("          [*]----------------------------------------[*]\n");
		printf("          [!]         Erreur du fichier Snail  !     [!]\n");
		printf("          [*]----------------------------------------[*]\n");
	}
	else {
		{printf("          [*]----------------------------------------[*]\n");
		printf("          [|]    Fichier Snail est Bien charger !    [|]\n");
		printf("          [|]----------------------------------------[|]\n");
		printf("          [|]        (1) Analyse Lexical             [|]\n");
		printf("          [|]        (2) Analyse Syntaxique          [|]\n");
		printf("          [|]        (3) Analyse Semantique          [|]\n");
		printf("          [|]        (4) Show All Tocken             [|]\n");
		printf("          [*]----------------------------------------[*]\n");
		printf("\n\n"); } //Command Printf
		
		printf("Snail>");
		cin >> choix;
		printf("\n\n");
		switch (choix)
		{
		case 1: {
			Lexical Lex(SnailFile);
			break;
		}
		case 2:
			break;
		case 3: {
			Semantique Sem(SnailFile);
			break; }
		case 4:
			Token tok(SnailFile);
			break;
		}
		fclose(SnailFile);
		}
	}
