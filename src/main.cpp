/**
	Salah Eddine Bentayeb
	GitHub.com/HalasProject
	FB | TWI | IG | @HalasDior
	Snail Compiler
	@version 1.0
*/

#include "Lexical.h"
#include "Token.h"
#include "Syntaxique.h"
#include "Semantique.h"
#include "pch.h"
 
int choix;

FILE* SnailFile = fopen("C:/Users/BENTAYEB/Desktop/MyProject/Test.snl", "r");
int main()
{
	// 13 Violet
	// 14 Jaune
	// 11 Blue fushia
	// 10 Vert
	color = 10;
	SetConsoleTextAttribute(hConsole, color);
	if (!SnailFile) {
		printf("          [*]----------------------------------------[*]\n");
		printf("          [!]         Erreur du fichier Snail  !     [!]\n");
		printf("          [*]----------------------------------------[*]\n");
	}
	else {
		{
		printf("          [*]----------------------------------------[*]\n");
		printf("          [|]    Fichier Snail est Bien charger !    [|]\n");
		printf("          [|]----------------------------------------[|]\n");
		printf("          [|]        (1) Analyse Lexical             [|]\n");
		printf("          [|]        (2) Analyse Syntaxique          [|]\n");
		printf("          [|]        (3) Analyse Semantique          [|]\n");
		printf("          [|]        (4) Show All Tokens             [|]\n");
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
		case 2: {
			Token tk(SnailFile, token, false);
			Syntaxique Syn(token);
			break; }
		case 3: {
			Semantique Sem(SnailFile);
			break; }
		case 4:
			Token tok(SnailFile, token, true);
			break;
		}
		fclose(SnailFile);
	}
}
