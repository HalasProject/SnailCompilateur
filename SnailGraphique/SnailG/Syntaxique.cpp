/**
	Salah Eddine Bentayeb
	GitHub.com/HalasProject
	FB | TWI | IG | @HalasDior
	Snail Compiler
	@version 1.0
*/

#include "Syntaxique.h"
#include "pch.h"


Syntaxique::Syntaxique(std::vector<std::string> &token) {
	bezzaf.clear();
	int S = 0;
	int F = 0;
	Error = 0;
	for (i = 0; i < token.size(); i++) {

		if (token[i] == "Snl_Start")
		{
			bezzaf += token[i] + " \r\n";
			continue;
		}

		else if (token[i] == "Else")
		{
			bezzaf += "\r\n"+token[i];
			if (token[i + 1] == "Start")
			{
				bezzaf += "\r\n" + token[i + 1] + "\r\n";
				continue;
			}
			else
			{
				Error++;
				bezzaf += "\r\n >[ERROR] Start expected";
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
				bezzaf += "\r\n >[ERROR] Else expected";
				bezzaf += "\r\n" + token[i];
				continue;
			}
		}

		else if (token[i] == "Finish")
		{
			bezzaf += "\r\n" + token[i] + "\r\n";
			F = F - 1;
			if (S > 0)
			{
				S = S - 1;
				continue;
			}
			else
			{
				Error++;
				bezzaf += "\r\n >[ERROR] Syntaxe error Start expected";
			}
		}

		else if (token[i] == "Snl_Close")
		{
			if (F <= 0)
			{
				bezzaf += token[i];
				continue;
			}
			else
			{
				Error++;
				bezzaf += "\r\n >[ERROR] Syntaxe error Finish expected in the end of the bloc";
				bezzaf += "\r\n" + token[i];
				continue;
			}

		}

		/** If % IDEN OPERATOR IDEN % */ else if (token[i] == "If") {
			bezzaf += token[i] + " ";
			if (token[i + 1] == "%")
			{
				bezzaf += token[i + 1] + " ";
			}
			else
			{
				Error++;
				bezzaf += "\r\n >[ERROR] '%' expected after If. \r\n ";
			}
			bezzaf += token[i + 2];

			if (Operator(token[i + 3]))
			{
				bezzaf += token[i + 3];
			}
			else
			{
				Error++;
				bezzaf += "\r\n >[ERROR] Operateur expected. \r\n";
			}
			bezzaf += token[i + 4] + " ";
			if (token[i + 5] == "%")
			{
				bezzaf += token[i + 5];
			}
			else
			{
				Error++;
				bezzaf += "\r\n >[ERROR] '%' expected. \r\n  ";
			}
			if (token[i + 6] == "do")
			{
				bezzaf += " "+token[i + 6]+" ";
			}
			else
			{
				Error++;
				bezzaf += "\r\n >[ERROR] 'do' expected. \r\n  ";
			}

			continue;
		}

		else if (token[i] == "Snl_Put")
		{
			bezzaf += token[i] + " ";
			std::string text = token[i + 1];
			char First = text.at(0);
			char Last = text.back();
			if (First == 34) {
				if (First == 34 && Last == 34)
				{
					bezzaf += token[i + 1];
				}
				else
				{
					Error++;
					bezzaf += "\r\n>[ERROR] Expected \" \r\n ";
				}
			}
			else
			{
				bezzaf += "Identificateur : " + token[i + 1];

			}
			if (token[i + 2] != "%.")
			{
				Error++;
				bezzaf += " >[ERROR] Expected End of instruction \"%.\" \r\n";
			}
			else
			{
				bezzaf += " %. \r\n";
			}


		}

		else if (token[i] == "SnlSt")
		{
		bezzaf += token[i] + " ";
		bezzaf += token[i+1] + " ";
		std::string text = token[i + 2];
		char lowal = text.at(0);
		char tali = text.back();
		if (lowal == 34) {
			if (lowal == 34 && tali == 34)
			{
				bezzaf += token[i + 2];
			}
			else
			{
				Error++;
				bezzaf += "\r\n>[ERROR] Expected \" \r\n ";
			}
		}
		else
		{
			bezzaf += "Identificateur : " + token[i + 2];

		}
		if (token[i + 3] != "%.")
		{
			Error++;
			bezzaf += " >[ERROR] Expected End of instruction \"%.\" \r\n";
		}
		else
		{
			bezzaf += " %. \r\n";
		}


		}

		else if (token[i] == "Snl_Int" || token[i] == "Snl_Real")
		{
			bezzaf += token[i] + " ";
			if (token[i + 1] == "%.")
			{
				Error++;
				bezzaf += "\r\n >[ERROR]  expected identifier after Snl_Int";
			}
			int L = 1;
			while (token[i + L] != "%.")
			{
				bezzaf += token[i + L] + " ";
				L++;
			}
			bezzaf += token[i + L] + "\r\n";
			continue;
		}

		else if (token[i] == "Get")
		{
			bezzaf += "\r\n" + token[i] + " ";
			bezzaf += token[i + 1] + " ";
			if (token[i + 2] != "from")
			{
				Error++;
				bezzaf += "\r\n>[ERROR] Expected from after identificateur. \n";
			}
			else
			{
				bezzaf += token[i + 2] + " ";
			}
			bezzaf += token[i + 3];
			if (token[i + 4] != "%.")
			{
				Error++;
				bezzaf += "\r\n>[ERROR] Expected \"%.\" at the End of instruction. \r\n";
			}
			else
			{
				bezzaf += token[i + 4] + "\r\n";
			}
			continue;
		}

		else if (token[i] == "Set")
		{
			bezzaf += "\n" + token[i] + " ";
			bezzaf += token[i + 1] + " ";
			bezzaf += token[i + 2] + " ";
			if (token[i + 3] != "%.")
			{
				Error++;
				bezzaf += "\r\n>[ERROR] Expected \"%.\" at the End of instruction. \r\n";
			}
			else { bezzaf += token[i + 3]+"\r\n"; }
			continue;
		}

		else if (token[i] == "%..")
		{
			bezzaf += token[i] + " ";
			bezzaf += token[i + 1] + "\r\n";
			continue;
		}

	}

	if (Error > 0)

		bezzaf += "\r\n\r\n[INFORMATION] Total Number Of Error = " + std::to_string(Error) + " ";
	else
		bezzaf += "\r\n\r\n[INFORMATION] No Error on your Snail File!";

}
bool Syntaxique::Operator(std::string OPER) {

	if ((OPER == "<") || (OPER == ">") || (OPER == "=") || (OPER == "<=") || (OPER == ">=") || (OPER == "!="))
		return true;
	else
		return false;
}
std::string Syntaxique::fin() {
	return bezzaf;
}
int Syntaxique::ErrorNombre()
{
	return Error;
}