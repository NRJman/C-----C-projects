#include "source.h"

void LetsGetItStarted()

{

	ofstream fout;
	fout.open("OUT.txt");
	fout.close();

	char buf[50];   //file var
	string lexeme;   //string for the writing from buf
	int num_str, num_lex;
	Token S_name;

	num_str = 0;
	ifstream fin("file.txt");
	
	num_str++;										//1
	num_lex = 0;
	fin.getline(buf, 50);
	Check(buf, lexeme, num_lex, num_str, S_name);

	num_str++;										//2
	num_lex = 0;
	fin.getline(buf, 50);
	Check(buf, lexeme, num_lex, num_str, S_name);

	num_str++;										//3
	num_lex = 0;
	fin.getline(buf, 50);
	Check(buf, lexeme, num_lex, num_str, S_name);

	num_str++;										//4
	num_lex = 0;
	fin.getline(buf, 50);
	Check(buf, lexeme, num_lex, num_str, S_name);

	num_str++;										//5
	num_lex = 0;
	fin.getline(buf, 50);
	Check(buf, lexeme, num_lex, num_str, S_name);
	
	num_str++;										//6
	num_lex = 0;
	fin.getline(buf, 50);
	Check(buf, lexeme, num_lex, num_str, S_name);
	
	num_str++;										//7
	num_lex = 0;
	fin.getline(buf, 50);
	Check(buf, lexeme, num_lex, num_str, S_name);
	
	num_str++;										//8
	num_lex = 0;
	fin.getline(buf, 50);
	Check(buf, lexeme, num_lex, num_str, S_name);

	num_str++;										//9
	num_lex = 0;
	fin.getline(buf, 50);
	Check(buf, lexeme, num_lex, num_str, S_name);

	num_str++;										//10
	num_lex = 0;
	fin.getline(buf, 50);
	Check(buf, lexeme, num_lex, num_str, S_name);

	num_str++;										//11
	num_lex = 0;
	fin.getline(buf, 50);
	Check(buf, lexeme, num_lex, num_str, S_name);

	num_str++;										//12
	num_lex = 0;
	fin.getline(buf, 50);
	Check(buf, lexeme, num_lex, num_str, S_name);

	num_str++;										//13
	num_lex = 0;
	fin.getline(buf, 50);
	Check(buf, lexeme, num_lex, num_str, S_name);

	num_str++;										//14
	num_lex = 0;
	fin.getline(buf, 50);
	Check(buf, lexeme, num_lex, num_str, S_name);

	num_str++;										//15
	num_lex = 0;
	fin.getline(buf, 50);
	Check(buf, lexeme, num_lex, num_str, S_name);

	num_str++;										//16
	num_lex = 0;
	fin.getline(buf, 50);
	Check(buf, lexeme, num_lex, num_str, S_name);

	num_str++;										//17
	num_lex = 0;
	fin.getline(buf, 50);
	Check(buf, lexeme, num_lex, num_str, S_name);

	num_str++;										//18
	num_lex = 0;
	fin.getline(buf, 50);
	Check(buf, lexeme, num_lex, num_str, S_name);

	num_str++;										//19
	num_lex = 0;
	fin.getline(buf, 50);
	Check(buf, lexeme, num_lex, num_str, S_name);

	num_str++;										//20
	num_lex = 0;
	fin.getline(buf, 50);
	Check(buf, lexeme, num_lex, num_str, S_name);
	
	num_str++;										//21
	num_lex = 0;
	fin.getline(buf, 50);
	Check(buf, lexeme, num_lex, num_str, S_name);

	num_str++;										//22
	num_lex = 0;
	fin.getline(buf, 50);
	Check(buf, lexeme, num_lex, num_str, S_name);

	num_str++;										//23
	num_lex = 0;
	fin.getline(buf, 50);
	Check(buf, lexeme, num_lex, num_str, S_name);

	num_str++;										//24
	num_lex = 0;
	fin.getline(buf, 50);
	Check(buf, lexeme, num_lex, num_str, S_name);

	num_str++;										//25
	num_lex = 0;
	fin.getline(buf, 50);
	Check(buf, lexeme, num_lex, num_str, S_name);

	num_str++;										//26
	num_lex = 0;
	fin.getline(buf, 50);
	Check(buf, lexeme, num_lex, num_str, S_name);

	num_str++;										//27
	num_lex = 0;
	fin.getline(buf, 50);
	Check(buf, lexeme, num_lex, num_str, S_name);
}

void Check(char* buf, string lexeme, int num_lex, int num_str, Token S_name)
{
	int i, j, len, help, mem;
	int k, prapor;
	ofstream fout;
	fout.open("OUT.txt", std::ofstream::out | std::ofstream::app);
	fout << endl;
	for (i = 0; (buf[i] != '\0'); i++) {
		if (buf[i] != '\'')
			buf[i] = toupper(buf[i]);
		else
			do {
				++i;
			} while ((buf[i] != '\0') & (buf[i] != '\''));
	}

	mem = 0;
	help = 0;
	do {	
		for (j = (mem); (buf[j] != '	') && (buf[j] != ' ') && ((buf[j] != ',') && (buf[j] != ':') && (buf[j] != '[') && (buf[j] != ']') && (buf[j] != '\\') && (buf[j] != '+') && (buf[j] != '-')) && (buf[j] != '\0'); j++, help++) {
			lexeme += buf[j];
		}
		if ((lexeme[0] == '\'') && (lexeme[lexeme.size() - 1] == '\'')) {
			num_lex++;
			len = lexeme.size();
			S_name.lex_n = num_lex;
			S_name.lex = lexeme;
			S_name.lex_len = len;
			S_name.type_lex = "TXT_const";
			S_name.str_n = num_str;
			Vadim.push_back(S_name);
			fout << "Lexeme number " << S_name.lex_n << "  Lexeme: " << S_name.lex << "  Length: " << S_name.lex_len << "  Type: " << S_name.type_lex << "  String number: " << S_name.str_n << endl;
			mem = help;
			lexeme = "";
		}
		else if (((lexeme[0] == '1') || (lexeme[0] == '2') || (lexeme[0] == '3') || (lexeme[0] == '4') || (lexeme[0] == '5') || (lexeme[0] == '6') || (lexeme[0] == '7') || (lexeme[0] == '8') || (lexeme[0] == '9') || (lexeme[0] == '0'))
	    && ((lexeme[lexeme.size() - 1] == 'D') || (lexeme[lexeme.size() - 1] == 'B') || (lexeme[lexeme.size() - 1] == 'H')
		|| (lexeme[lexeme.size() - 1] == '1') || (lexeme[lexeme.size() - 1] == '2') || (lexeme[lexeme.size() - 1] == '3') || (lexeme[lexeme.size() - 1] == '4') || (lexeme[lexeme.size() - 1] == '5') || (lexeme[lexeme.size() - 1] == '6') || (lexeme[lexeme.size() - 1] == '7') || (lexeme[lexeme.size() - 1] == '8') || (lexeme[lexeme.size() - 1] == '9') || (lexeme[lexeme.size() - 1] == '0'))) {
			prapor = 0;
			num_lex++;
			len = lexeme.size();
			S_name.lex_n = num_lex;
			S_name.lex = lexeme;
			S_name.lex_len = len;
			S_name.type_lex = "NUM_const";
			S_name.str_n = num_str;
			Vadim.push_back(S_name);
			for (k = 1; k < (lexeme.size() - 1); ++k) {
				if ((lexeme[k] != '1') && (lexeme[k] != '2') && (lexeme[k] != '3') && (lexeme[k] != '4') && (lexeme[k] != '5') && (lexeme[k] != '6') && (lexeme[k] != '7') && (lexeme[k] != '8') && (lexeme[k] != '9') && (lexeme[k] != '0'))
					prapor = 1;
			}
			if (prapor == 1)
				fout << "ALARM! PLEASE, WRITE CORRECT NUMBER!!!!!!!";
			else
				fout << "Lexeme number " << S_name.lex_n << "  Lexeme: " << S_name.lex << "  Length: " << S_name.lex_len << "  Type: " << S_name.type_lex << "  String number: " << S_name.str_n << endl;
			mem = help;
			lexeme = "";
			prapor = 0;
		}
		else if (index_reg.find(lexeme) != (index_reg.end())) {
			num_lex++;
			len = lexeme.size();
			S_name.lex_n = num_lex;
			S_name.lex = lexeme;
			S_name.lex_len = len;
			S_name.type_lex = "Index reg";
			S_name.str_n = num_str;
			Vadim.push_back(S_name);
			fout << "Lexeme number " << S_name.lex_n << "  Lexeme: " << S_name.lex << "  Length: " << S_name.lex_len << "  Type: " << S_name.type_lex << "  String number: " << S_name.str_n << endl;
			mem = help;
			lexeme = "";
		}
		else if (bit16.find(lexeme) != (bit16.end())) {
			num_lex++;
			len = lexeme.size();
			S_name.lex_n = num_lex;
			S_name.lex = lexeme;
			S_name.lex_len = len;
			S_name.type_lex = "16 Bit";
			S_name.str_n = num_str;
			Vadim.push_back(S_name);
			fout << "Lexeme number " << S_name.lex_n << "  Lexeme: " << S_name.lex << "  Length: " << S_name.lex_len << "  Type: " << S_name.type_lex << "  String number: " << S_name.str_n << endl;
			mem = help;
			lexeme = "";
		}
		else if (instruct.find(lexeme) != (instruct.end())) {
			num_lex++;
			len = lexeme.size();
			S_name.lex_n = num_lex;
			S_name.lex = lexeme;
			S_name.lex_len = len;
			S_name.type_lex = "Instruction";
			S_name.str_n = num_str;
			Vadim.push_back(S_name);
			fout << "Lexeme number " << S_name.lex_n << "  Lexeme: " << S_name.lex << "  Length: " << S_name.lex_len << "  Type: " << S_name.type_lex << "  String number: " << S_name.str_n << endl;
			mem = help;
			lexeme = "";
		}
		else if (direct.find(lexeme) != (direct.end())) {
			num_lex++;
			len = lexeme.size();
			S_name.lex_n = num_lex;
			S_name.lex = lexeme;
			S_name.lex_len = len;
			S_name.type_lex = "Directive";
			S_name.str_n = num_str;
			Vadim.push_back(S_name);
			fout << "Lexeme number " << S_name.lex_n << "  Lexeme: " << S_name.lex << "  Length: " << S_name.lex_len << "  Type: " << S_name.type_lex << "  String number: " << S_name.str_n << endl;
			mem = help;
			lexeme = "";
		}
		else if (identifier.find(lexeme) != (identifier.end())) {
			num_lex++;
			len = lexeme.size();
			S_name.lex_n = num_lex;
			S_name.lex = lexeme;
			S_name.lex_len = len;
			S_name.type_lex = "Identifier";
			S_name.str_n = num_str;
			Vadim.push_back(S_name);
			if (S_name.lex_len <= 8)
				fout << "Lexeme number " << S_name.lex_n << "  Lexeme: " << S_name.lex << "  Length: " << S_name.lex_len << "  Type: " << S_name.type_lex << "  String number: " << S_name.str_n << endl;
			else
				fout << "The identifier length is more than 8! Write correct identifier!!!" << endl;
			mem = help;
			lexeme = "";
		}
		else if (segment.find(lexeme) != (segment.end())) {
			num_lex++;
			len = lexeme.size();
			S_name.lex_n = num_lex;
			S_name.lex = lexeme;
			S_name.lex_len = len;
			S_name.type_lex = "Segment";
			S_name.str_n = num_str;
			Vadim.push_back(S_name);
			fout << "Lexeme number " << S_name.lex_n << "  Lexeme: " << S_name.lex << "  Length: " << S_name.lex_len << "  Type: " << S_name.type_lex << "  String number: " << S_name.str_n << endl;
			mem = help;
			lexeme = "";
		}
		else if (bit32.find(lexeme) != (bit32.end())) {
			num_lex++;
			len = lexeme.size();
			S_name.lex_n = num_lex;
			S_name.lex = lexeme;
			S_name.lex_len = len;
			S_name.type_lex = "32 Bit";
			S_name.str_n = num_str;
			Vadim.push_back(S_name);
			fout << "Lexeme number " << S_name.lex_n << "  Lexeme: " << S_name.lex << "  Length: " << S_name.lex_len << "  Type: " << S_name.type_lex << "  String number: " << S_name.str_n << endl;
			mem = help;
			lexeme = "";
		}
		else if (bit8.find(lexeme) != (bit8.end())) {
			num_lex++;
			len = lexeme.size();
			S_name.lex_n = num_lex;
			S_name.lex = lexeme;
			S_name.lex_len = len;
			S_name.type_lex = "8 Bit";
			S_name.str_n = num_str;
			Vadim.push_back(S_name);
			fout << "Lexeme number " << S_name.lex_n << "  Lexeme: " << S_name.lex << "  Length: " << S_name.lex_len << "  Type: " << S_name.type_lex << "  String number: " << S_name.str_n << endl;
			mem = help;
			lexeme = "";
		}
		else if (((buf[j] == ',') || (buf[j] == ':') || (buf[j] == '[') || (buf[j] == ']') || (buf[j] == '\\') || (buf[j] == '+') || (buf[j] == '-')) && (lexeme == "")) {
			num_lex++;
			len = 1;
			S_name.lex_n = num_lex;
			S_name.lex = buf[j];
			S_name.lex_len = len;
			S_name.type_lex = "One symbol";
			S_name.str_n = num_str;
			Vadim.push_back(S_name);
			fout << "Lexeme number " << S_name.lex_n << "  Lexeme: " << S_name.lex << "  Length: " << S_name.lex_len << "  Type: " << S_name.type_lex << "  String number: " << S_name.str_n << endl;
			++help; //bo v cikl ne zaishlo, tomu zbilshuemo vruchnu
			mem = help;
			++j;
			lexeme = "";
		}
		else if (lexeme.size() == 0) {
			help++;
			mem = help;
		}
		else
		{
			num_lex++;
			len = lexeme.size();
			S_name.lex_n = num_lex;
			S_name.lex = lexeme;
			S_name.lex_len = len;
			S_name.type_lex = "Identifier";
			S_name.str_n = num_str;
			Vadim.push_back(S_name);
			if (S_name.lex_len <= 8)
				fout << "Lexeme number " << S_name.lex_n << "  Lexeme: " << S_name.lex << "  Length: " << S_name.lex_len << "  Type: " << S_name.type_lex << "  String number: " << S_name.str_n << endl;
			else
				fout << "The identifier length is more than 8! Write correct identifier!!!" << endl;
			mem = help;
			lexeme = "";
		}
	} while (buf[j] != '\0');

	fout.close();
}