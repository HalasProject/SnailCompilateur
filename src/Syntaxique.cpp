/**
	Salah Eddine Bentayeb
	GitHub.com/HalasProject
	FB | TWI | IG | @HalasDior
	Snail Compiler
	@version 1.0
*/

#include "Syntaxique.h"
#include "pch.h"


Syntaxique::Syntaxique(vector<string> &token) {
	int S = 0;
	int F = 0;
	int Error = 0;
	cout << "[INFORMATION] Total Number of Token = " << token.size() << ".\n\n\n";
	for (i = 0; i < token.size(); i++) {

		if (token[i] == "Snl_Start")
		{
			cout << token[i] << endl;
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
				Error++;
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
				Error++;
				cout << "\n >[ERROR] Else expected";
				cout << "\n" + token[i];
				continue;
			}
		}

		if (token[i] == "Finish")
		{
			cout << "\n" + token[i] + "\n";
			F = F - 1;
			if (S > 0)
			{
				S = S - 1;
				continue;
			}
			else
			{
				Error++;
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
				Error++;
				cout << "\n >[ERROR] Syntaxe error Finish expected in the end of the bloc";
				cout << "\n" + token[i];
				continue;
			}

		}

		/** If % IDEN OPERATOR IDEN % */ if (token[i] == "If") {
			cout << token[i] << " ";
			if (token[i + 1] == "%")
			{
				cout << token[i + 1] << " ";
			}
			else
			{
				Error++;
				cout << "\n >[ERROR] '%' expected after If. ";
			}
			cout << token[i + 2];

			if (Operator(token[i + 3]))
			{
				cout << token[i + 3];
			}
			else
			{
				Error++;
				cout << "\n >[ERROR] Operateur expected. \n";
			}
			cout << token[i + 4] << " ";
			if (token[i + 5] == "%")
			{
				cout << token[i + 5];
			}
			else
			{
				Error++;
				cout << "\n >[ERROR] '%' expected. ";
			}
			continue;
		}

		else if (token[i] == "Snl_Put")
		{
			cout << token[i] << " ";
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
					Error++;
					cout << "\n>[ERROR] Expected \" ";
				}
			}
			else
			{
				cout << "Identificateur : " << token[i + 1];

			}
			if (token[i + 2] != "%.")
			{
				Error++;
				cout << " >[ERROR] Expected End of instruction \"%.\" \n";
			}
			else
			{
				cout << " %." << "\n";
			}


		}

		else if (token[i] == "Snl_Int" || token[i] == "Snl_Real")
		{
			cout << token[i] + " ";
			if (token[i + 1] == "%.")
			{
				cout << "\n >[ERROR]  expected identifier after Snl_Int";
			}
			int L = 1;
			while (token[i + L] != "%.")
			{
				cout << token[i + L] << " ";
				L++;
			}
			cout << token[i + L] << "\n";
			continue;
		}

		/**
		else if (token[i] == "Get")
		{
			cout << token[i] + " ";
			cout << token[1] + " ";
		else
		{
			console += "\n * Identificateur expected afer " + token[0];
		}
		if (token[2] == ":")
		{
			tmp += token[2] + " ";
		}
		else
		{
			console += "\n * ' : ' expected afer " + token[1];
		}
		if (Int(token[3]) || Float(token[3]))
		{
			tmp += token[3] + " ";
		}
		else
		{
			console += "\n * Valeur expected afer " + token[2];
		}
		if (token[token.length() - 1] == ";;")
		{
			tmp += token[4] + " ";
		}
		else
		{
			console += "\n * ' ;; ' expected at the en ";
		}
		}
		/**
		else if (token[0] == "Affect")
		{
			for (i = 0; i < token.length(); i++)
			{
				tmp += token[i] + " ";
			}
			console += "\n" + tmp;
			if (Identificateur(token[1]))
			{
				tmp += token[1] + " ";
			}
			else
			{
				console += "\n * Identificateur expected afer " + token[0];
			}
			if (token[2] == "to")
			{
				tmp += token[2] + " ";
			}
			else
			{
				console += "\n * ' to ' expected afer " + token[1];
			}
			if (Identificateur(token[3]))
			{
				tmp += token[3] + " ";
			}
			else
			{
				console += "\n * Identificateur expected afer " + token[2];
			}
			if (token[4] == ";;")
			{
				tmp += token[4] + " ";
			}
			else
			{
				console += "\n * ' ;; ' expected afer " + token[3];
			}
		}
		**/
		else if (token[i] == "%..")
		{
		    cout << token[i] << " ";
			cout << token[i + 1];
			continue;
		}


	}


	if (Error > 0)
		cout << "\n\n[INFORMATION] Total Number Of Error = " << Error << endl;
	else
		cout << "\n\n[INFORMATION] No Error on your Snail File!" << endl;

}

bool Syntaxique::Operator(string OPER) {

	if ((OPER == "<") || (OPER == ">") || (OPER == "=") || (OPER == "<=") || (OPER == ">=") || (OPER == "!="))
		return true;
	else
		return false;
}