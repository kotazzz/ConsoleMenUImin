#pragma warning(disable  : 4996)
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <stdlib.h>
using namespace std;
enum ConsoleColor
{
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
int old_seed = 0; // Buffer for srand() formula
string stringBuffer = "";  // Bufer for cin/cout in cmd or programm

/*
|---------------------------|
|        Color              |
|          LIB              |
|---------------------------|
*/

 void clr() {
	system("cls");
}
/*
*analog of system("cls");
*/
 void scalar(ConsoleColor text, ConsoleColor background = Black, bool clrscrn = 0)
{
	 
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
	if (clrscrn) clr(); 
}
/*
*function for change color
*text - color of text
*background - color of background,
*clrscrn - if 1 then clear screen(for change all background)
*else not run cls()
*/
 void scalar_none(ConsoleColor text, ConsoleColor background, string couts)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
	cout << couts;
	scalar(White, Black);
}
/*
* function for change color with reset to default color
* text - color of text
* background - color of background,
* couts - string with new colors
*/
 void StrToCColor(string prmtr, ConsoleColor savr) {
	 if (prmtr == "Black")			savr = Black;
	 if (prmtr == "Blue")				savr = Blue;
	 if (prmtr == "Green")			savr = Green;
	 if (prmtr == "Magenta")			savr = Magenta;
	 if (prmtr == "Brown")			savr = Brown;
	 if (prmtr == "LightGray")		savr = LightGray;
	 if (prmtr == "LightBlue")		savr = LightBlue;
	 if (prmtr == "LightCyan")		savr = LightCyan;
	 if (prmtr == "LightMagenta")		savr = LightMagenta;
	 if (prmtr == "White")			savr = White;
	 if (prmtr == "Cyan")				savr = Cyan;
	 if (prmtr == "DarkGray")			savr = DarkGray;
	 if (prmtr == "LightGreen")		savr = LightGreen;
	 if (prmtr == "Yellow")			savr = Yellow;
	 if (prmtr == "Red")				savr = Red;
	 if (prmtr == "LightRed")			savr = LightRed;

 }
 void scalar(string text, string background = "Black", bool clrscrn = 0)
 {
	 ConsoleColor setBG = Black;
	 ConsoleColor setTXT = White;
	 StrToCColor(text, setTXT);
	 StrToCColor(background, setBG);
	 HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	 SetConsoleTextAttribute(hStdOut, (WORD)((setBG << 4) | setTXT));
	 if (clrscrn) clr();
 }
 /*
 *function for change color, using witg strings parametrs
 *text - color of text
 *background - color of background,
 *clrscrn - if 1 then clear screen(for change all background)
 *else not run cls()
 */
 void scalar_none(string text, string background, string couts)
 {
	 ConsoleColor setBG = Black;
	 ConsoleColor setTXT = White;
	 StrToCColor(text, setTXT);
	 StrToCColor(background, setBG);
	 HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	 SetConsoleTextAttribute(hStdOut, (WORD)((setBG << 4) | setTXT));
	 cout << couts;
	 scalar(White, Black);
 }
 /*
 * function for change color with reset to default color
 * text - color of text
 * background - color of background,
 * couts - string with new colors
 */


/*
|---------------------------|
|        Frandom            |
|          LIB              |
|---------------------------|
*/

 int Frandom(int start, int end, int mltplr = 1, int seed = old_seed) {
	 seed = old_seed;
	 srand(time(0) + seed);
	 old_seed++;
	return (start + rand() % (end - start)) * mltplr;
}
/*
 * function for return random int
 * start - minimal
 * end - maximal
 * mltplr - return will be multiple as this value
*/
 string Frandom_string(int min, int max, int mltlr = 1, int seed = old_seed) {

	char ct[50];
	srand(time(0) + seed); old_seed++;
	int i = Frandom(min, max, mltlr);
	char buf[40];
	sprintf(buf, "%d", i);
	return buf;
}
 /*
*function for return random int, also return her as string (return "123")
*min - minimal
*max - maximal
*mltplr - return will be multiple as this value
*/
 bool chance(int chance)
{
	chance = chance < 0 ? 0 : chance;
	chance = chance <= 100 ? chance : 100;
	if (chance > Frandom(0, 99))
		return true;
	return false;
}
 /*
 *function for return 1 with chance (custom: int chance)
 */



/*
|---------------------------|
|        Input CMD          |
|          LIB              |
|---------------------------|
*/

 void input(string path = "/sys:/", string tip = "") {
	if (path == "*") path = "/sys:/";
	if (!(tip == "")) cout << tip;
	cout << endl << path;
	cin >> stringBuffer;
	cout << endl;
} 
/*
*function for cin/cout as cmd mode
*path - prefix for cin
*tip - cout this before cout path and cin data
*---------
*for replace tip to castom string need to set path as "*"
*function will replace path to default (/sys:/)
*/
 string inret(string tip = "") {

	if (!(tip == "")) cout << endl << tip << endl;
	return stringBuffer;
}
/*
 *function return input string from input()
 *if you need to comment your processing with bufer
 *you can cout tip (set her in "tip" parametr)
*/
 string inretBar(string tip = "", string barrier = "-------") {
	string ret = barrier + "\n" + inret(tip);
	return ret;
}
/*
*function work as inret also have parametr barrier
*his cout tip before barrier
*exemple:
*
*working with your personal data
*********************
*Steve
*/

/*
|---------------------------|
|        FromTo CMD         |
|          LIB              |
|---------------------------|
*/

 //no libs :_(