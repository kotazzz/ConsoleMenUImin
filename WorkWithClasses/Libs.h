#pragma once


// Начинаем с директив препроцессора. ADD_H – это произвольное уникальное имя (обычно используется имя заголовочного файла)
#ifndef Libs_H
#define Libs_H
using namespace std;
/*******************************************************************************/
 static		enum			ConsoleColor {
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};
 static		int				old_seed; // Buffer for srand() formula
 static		string			stringBuffer;  // Bufer for cin/cout in cmd or programm
/*******************************************************************************/
 void		clr				();
 void		scalar_none		(ConsoleColor text, ConsoleColor background, string couts);
 void		scalar_none		(string text, string background, string couts);
 void		scalar			(ConsoleColor text, ConsoleColor background = Black, bool clrscrn = 0);
 void		scalar			(string text, string background, bool clrscrn = 0);
 void		StrToCColor		(string prmtr, ConsoleColor savr);
 int		Frandom			(int start, int end, int mltplr = 1, int seed = old_seed);
 string		Frandom_string	(int min, int max, int mltlr = 1, int seed = old_seed);
 bool		chance			(int chance);
 void		input			(string path = "/sys:/", string tip = "");
 string		inret			(string tip = "");
 string		inretBar		(string tip = "", string barrier = "-------");
 /*******************************************************************************/
#endif
