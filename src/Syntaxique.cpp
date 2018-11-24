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
	color = 11;
	SetConsoleTextAttribute(hConsole, color);
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

		else if (token[i] == "Else")
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

		else if (token[i] == "Start")
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

		else if (token[i] == "Finish")
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

		else if (token[i] == "Snl_Close")
		{
			if (F <= 0)
			{
				cout << token[i];
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

		/** If % IDEN OPERATOR IDEN % */ else if (token[i] == "If") {
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
				Error++;
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

		else if (token[i] == "Get")
		{
			cout << "\n" << token[i] + " ";
			cout << token[i + 1] + " ";
			if (token[i + 2] != "from")
			{
				Error++;
				cout << "\n>[ERROR] Expected from after identificateur. \n";
			}
			else
			{
				cout << token[i + 2] << " ";
			}
			cout << token[i + 3];
			if (token[i + 4] != "%.")
			{
				Error++;
				cout << "\n>[ERROR] Expected \"%.\" at the End of instruction. \n";
			}
			else
			{
				cout << token[i + 4];
			}
			continue;
		}

		else if (token[i] == "Set")
		{
			cout << "\n" << token[i] + " ";
			cout << token[i + 1] + " ";
			cout << token[i + 2] << " ";
			if (token[i + 3] != "%.")
			{
				Error++;
				cout << "\n>[ERROR] Expected \"%.\" at the End of instruction. \n";
			}
			else { cout << token[i + 3]; }
			continue;
		}

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