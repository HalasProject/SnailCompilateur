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
	int S = 0;
	 int F = 0;
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
				 cout << "\n >[ERROR] Start expected";
				 continue;
			 }
		 }

		 if (token[i] == "Start")
		 {
			 S = S + 1;
			 F = F + 1;
			 if (token[i - 1] == "Else")
			 {
				 continue;
			 }
			 else
			 {
				 cout << "\n >[ERROR] Else expected";
				 cout << "\n" + token[i];
				 continue;
			 }
		 }

		 if (token[i] == "Finish")
		 {
			 cout << "\n" + token[i] +"\n";
			 F = F - 1;
			 if (S > 0)
			 {
				 S = S - 1;
				 continue;
			 }
			 else
			 {
				 cout << "\n >[ERROR] Syntaxe error Start expected";
			 }
		 }

		 if (token[i] == "Snl_Close")
		 {
			 if (F <= 0)
			 {
				 cout << "\n" + token[i];
				 continue;
			 }
			 else
			 {
				 cout << "\n >[ERROR] Syntaxe error Finish expected in the end of the bloc";
				 cout << "\n" + token[i];
				 continue;
			 }

		 }

		 /** If % IDEN OPERATOR IDEN % */ if (token[i] == "If") {

			 if (token[i + 1] == "%")
			 {
				 cout<< token[i + 1];
			 }
			 else
			 {
				 cout << "\n * '%' expected after If";
			 }
		     cout << token[i + 2];

			 if (Operator(token[i + 3]))
			 {
				 cout << token[i + 3];
			 }
			 else
			 {
				 cout << "\n * Operateur expected";
			 }
				 cout << token[i + 4];
			 if (token[i + 5] == "%")
			 {
				 cout << token[i + 5];
			 }
			 else
			 {
				 cout << "\n * '%' expected";
			 }

	 }
		 else if (token[i] == "Snl_Put")
		 {
			 cout << token[i] << " " ;
			 string text = token[i + 1];
			  char First = text.at(0);
			  char Last = text.back();
			  if (First == 34) {
				  if (First == 34 && Last == 34)
				  {
					  cout << token[i + 1];
				  }
				  else
				  {
					  cout << "\n>[ERROR] Expected \" ";
				  }
			  }
			  else
			  {
				  cout << "Identificateur : " << token[i + 1];
				  
			  }
			  if (token[i + 2] != "%.")
			  {
				  cout << " >[ERROR] Expected End of instruction \"%.\" \n";
			  }
			  else
			  {
				  cout << " %." << "\n";
			  }
			

		 }

	 }
}

bool Syntaxique::Operator(string OPER) {

	if ((OPER == "<") || (OPER == ">") || (OPER == "=") || (OPER == "<=") || (OPER == ">=") || (OPER == "!="))
		return true;
	else
		return false;
}