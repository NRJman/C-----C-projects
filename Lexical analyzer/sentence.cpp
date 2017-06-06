#include "source.h"

void SentencePart(){
	ofstream fout;
	fout.open("sent_OUT.txt");
	fout.close();
	fout.open("sent_OUT.txt", std::ofstream::out | std::ofstream::app);
	fout << endl;

	
	char buf[50];   //file var
	string lexeme;   //string for the writing from buf
	int num_str, num_lex;
	num_str = 0;
	ifstream fin("file.txt");


	fout << "|Label field|      Mnem field      |    1st operand     |    2nd operand     |" << endl;
	fout << "|   Number  |  Num_first|Quantity  | Num_first|Quantity | Num_first|Quantity |" << endl;

	int i;

	for (i = 0; i < 27; i++){
		num_str++;
		num_lex = 0;
		fin.getline(buf, 50);
		SentenceCheck(buf, lexeme, num_lex, num_str);
	}
}

void SentenceCheck(char* buf, string lexeme, int num_lex, int num_str){
	int label_place;
	int mnem_place, mnem_quant;
	int operand1_place, operand1_quant;
	int operand2_place, operand2_quant;
	int comma_flag;
	int mnem_flag;
	int change_flag1, change_flag2;
	int i, j, len, help, mem;

	ofstream fout;
	fout.open("sent_OUT.txt", std::ofstream::out | std::ofstream::app);
	fout << endl;

	label_place = 0;
	mnem_place = 0;
	mnem_quant = 0;
	operand1_place = 0;
	operand1_quant = 0;
	operand2_place = 0;
	operand2_quant = 0;

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
	comma_flag = 0;
	mnem_flag = 0;
	change_flag1 = 0;
	change_flag2 = 0;
	do {
		for (j = (mem); (buf[j] != '	') && (buf[j] != ' ') && ((buf[j] != ',') && (buf[j] != ':') && (buf[j] != '[') && (buf[j] != ']') && (buf[j] != '\\') && (buf[j] != '+') && (buf[j] != '-')) && (buf[j] != '\0'); j++, help++) {
			lexeme += buf[j];
		}
		if (identifier.find(lexeme) != (identifier.end())) {
			++num_lex;
				if (num_lex > 1) {
					if (comma_flag == 0) {
						if (change_flag1 == 0) {
							operand1_place = num_lex;
							change_flag1 = 1;
						}
						++operand1_quant;
						if ((buf[j] == ',') || (buf[j] == ':') || (buf[j] == '[') || (buf[j] == ']') || (buf[j] == '\\') || (buf[j] == '+') || (buf[j] == '-')) {
							lexeme = "";
							mem = help;
						}
					}
					if (comma_flag == 1) {
						if (change_flag2 == 0) {
							operand2_place = num_lex;
							change_flag2 = 1;
						}
						++operand2_quant;
						if ((buf[j] == ',') || (buf[j] == ':') || (buf[j] == '[') || (buf[j] == ']') || (buf[j] == '\\') || (buf[j] == '+') || (buf[j] == '-')) {
							lexeme = "";
							mem = help;
						}
					}
				}
				else {
					label_place = num_lex;
					lexeme = "";
					help++;
					mem = help;
				}
		}
		else if ((direct.find(lexeme) != (direct.end())) || (instruct.find(lexeme)) != (instruct.end())) {
			++num_lex;
			if (mnem_flag == 0) {
				mnem_place = num_lex;
				lexeme = "";
				mnem_flag = 1;
			}
			else {
				if (comma_flag == 0) {
					if (change_flag1 == 0) {
						operand1_place = num_lex;
						change_flag1 = 1;
					}
					++operand1_quant;
				}
				if (comma_flag == 1) {
					if (change_flag2 == 0) {
						operand2_place = num_lex;
						change_flag2 = 1;
					}
					++operand2_quant;
				}
			}
			lexeme = "";
			help++;
			mem = help;
		}
		else if ((bit8.find(lexeme) != (bit8.end())) || (bit16.find(lexeme) != (bit16.end())) || (bit32.find(lexeme) != (bit32.end())) ||
		(index_reg.find(lexeme) != (index_reg.end())) || (segment.find(lexeme) != (segment.end())) || (((lexeme[0] == '1') || (lexeme[0] == '2') || (lexeme[0] == '3') || (lexeme[0] == '4') || (lexeme[0] == '5') || (lexeme[0] == '6') || (lexeme[0] == '7') || (lexeme[0] == '8') || (lexeme[0] == '9') || (lexeme[0] == '0'))
		&& ((lexeme[lexeme.size() - 1] == 'D') || (lexeme[lexeme.size() - 1] == 'B') || (lexeme[lexeme.size() - 1] == 'H') || 
		(lexeme[lexeme.size() - 1] == '1') || (lexeme[lexeme.size() - 1] == '2') || (lexeme[lexeme.size() - 1] == '3') || (lexeme[lexeme.size() - 1] == '4') || (lexeme[lexeme.size() - 1] == '5') || (lexeme[lexeme.size() - 1] == '6') || (lexeme[lexeme.size() - 1] == '7') || (lexeme[lexeme.size() - 1] == '8') || (lexeme[lexeme.size() - 1] == '9') || (lexeme[lexeme.size() - 1] == '0'))) || 
		((lexeme[0] == '\'') && (lexeme[lexeme.size() - 1] == '\''))) {
			++num_lex;
			if (mnem_flag == 1) {
				if (comma_flag == 0) {
					if (change_flag1 == 0) {
						operand1_place = num_lex;
						change_flag1 = 1;
					}
					++operand1_quant;
				}
				if (comma_flag == 1) {
					if (change_flag2 == 0) {
						operand2_place = num_lex;
						change_flag2 = 1;
					}
					++operand2_quant;
				}
				if ((buf[j] == ',') || (buf[j] == ':') || (buf[j] == '[') || (buf[j] == ']') || (buf[j] == '\\') || (buf[j] == '+') || (buf[j] == '-')) {
					lexeme = "";
					mem = help;
				}
				else {
					lexeme = "";
					++help;
					mem = help;
				}
			}
		}
		else if (((buf[j] == ',') || (buf[j] == ':') || (buf[j] == '[') || (buf[j] == ']') || (buf[j] == '\\') || (buf[j] == '+') || (buf[j] == '-')) && (lexeme == "")) {
			++num_lex;
			if (buf[j] == ',') {
				comma_flag = 1;
			}
			if ((comma_flag == 1) && (buf[j] != ','))
				++operand2_quant;
			else if (buf[j] != ',')
				++operand1_quant;
			help++;
			mem = help;
		}
		else if (lexeme.size() == 0) {
			help++;
			mem = help;
		}
		else {
			if (mnem_flag == 0) {
				++num_lex;
				lexeme = "";
				label_place = num_lex;
			}
			else {
				++num_lex;
				if (comma_flag == 0) {
					if (change_flag1 == 0) {
						operand1_place = num_lex;
						change_flag1 = 1;
					}
					++operand1_quant;
				}
				if (comma_flag == 1) {
					if (change_flag2 == 0) {
						operand2_place = num_lex;
						change_flag2 = 1;
					}
					++operand2_quant;
				}
			}
			help++;
			mem = help;
		}
	} while (buf[j] != '\0');
	if (mnem_place > 0)
		mnem_quant = 1;
	fout << "|     " << label_place << "     |         " << mnem_place << " | " << mnem_quant << "        |        " << operand1_place << " | " << operand1_quant << "       |        " << operand2_place << " | " << operand2_quant << "       |" << endl;
	fout.close();
}
