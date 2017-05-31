#pragma once
#include <set>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

struct Token
{
	int lex_n;
	int str_n;
	int lex_len;
	string lex;
	string type_lex;
};

static vector <Token> Vadim;

enum TYPE_OF_LEX { REG8, REG32, REG8ADDR, REGSEG, DB, DW, DD, CONST, TEXT_CONST, DIRECTIVE, ID, INSTRUCTION, SEPARATOR };

static set<string> bit8 = { "AL", "AH", "BL", "BH", "DL", "DH", "CL", "CH" };
static set<string> bit16 = { "AX", "BX", "DX", "CX" };
static set<string> bit32 = { "EAX", "EBX", "ECX", "EDX", "EBI", "EDI", "ESI", "ESP" };
static set<string> index_reg = { "SP", "BP", "SI", "DI" };
static set<string> segment = { "SS", "GS", "CS", "DS", "FS", "ES" };
static set<string> direct = { "IF", "THEN", "ELSE", "ENDIF", "SEGMENT", "ENDS", "END", "DB", "DW", "DD", "ASSUME", "USE16", "WORD", "DWORD", "PTR" };
static set<string> identifier = { "DATA", "CODE"};
static set<string> instruct = { "JMP", "JC", "MOV", "CLI", "INC", "DEC", "ADD", "ADC", "EQU", "JBE", "CMP", "AND", "OR", "XOR", "PUSH", "MUL", "SUB" };
static set<string> one = { ",", ":", "[", "]", "\"" };
static set<string> nums = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "0" };

void LetsGetItStarted();
void Check(char* buf, string lexeme, int num_lex, int num_str, Token S_name);
void SentencePart();
void SentenceCheck(char* buf, string lexeme, int num_lex, int num_str);
