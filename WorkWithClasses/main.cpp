#pragma warning
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <stdlib.h>
#include "Libs.h"
#include "event.cpp"
#include <vector>
//settings*************************************************************************************************
constexpr auto DEBUG = 0;



//settings*************************************************************************************************
using namespace std;
//------
void FEvent();
void Old_FEvent();
void Theme();
//------
int main()
{
	if (!DEBUG) {
		setlocale(0, "ru");
		scalar(Blue, White, 1);
		while (1) {
			input("*", "tip: type \"sys_help\" if you need help or \"help\" for help cmd");
			if (inret() == "cmd") {
				system("start cmd");
			}
			else if (inret() == "notepad") {
				system("start notepad");
			}
			else if (inret() == "tree")
			{
				system("tree");
			}
			else if (inret() == "sys_help")
			{
				cout << "-----------------help-------------------------------------" << endl;
				cout << "notepad - run notepad" << endl;
				cout << "tree - see root of project structure" << endl;
				cout << "prgmng <list|name_of_programm>  - " << endl;
				cout << "info - see \"about programm\" " << endl;
				cout << "exit - exit (0_o)" << endl;
				cout << "help  - write help" << endl;
				cout << "-----------------help-------------------------------------" << endl;
			}
			else if (inret() == "new") {}//-------------------
			else if (inret() == "new") {}//-------------------
			else if (inret() == "info") {
				cout << "-----------------info-------------------------------------" << endl;
				cout << "Author: NewLife" << endl;
				cout << "VK: https://vk.com/newlife2019_szhs" << endl;
				cout << "-----------------info-------------------------------------" << endl;
			
			}
			else if (inret() == "prgmng") {
				input("/sys:/prgmng", "use list or name of programm");
				if (inret() == "list") {
					cout << "-----------------list-------------------------------------" << endl;
					cout << "event - run Event" << endl;
					cout << "theme - run Theme manager" << endl;
					cout << "help  - write help" << endl;
					cout << "-----------------list-------------------------------------" << endl;
				}
				if (inret() == "theme") Theme();
				if (inret() == "event") FEvent();
			}
			else system(inret("Выполнение команды в cmd...").c_str());

		}
	}
	else
	{
		setlocale(0, "ru");
		scalar(Blue, White, 1);
		cout << "DEBUG MODE IS ON" << endl;

	}
}


void FEvent() {
	vector<Event> EventDB;
	int counter = 0;
	
	while (1) {
		cout << endl;
		input("/sys:/event", "use help for see help");
		if (inret() == "new") {
			EventDB.push_back(Event());
		}
		if (inret() == "delete") {
			int searchID;
			cin >> searchID;
			for (size_t i = 0; i < EventDB.size(); i++)
				if (searchID == EventDB[i].iniID())
					EventDB.erase(EventDB.begin() + i);
		}
		if (inret() == "list") {
			for (size_t i = 0; i < EventDB.size(); i++)
			{
				cout << "id \t" << EventDB[i].iniID() << endl;
			}
		}
		if (inret() == "exit") break;
		if (inret() == "help") {
			cout << "-----------------help-------------------------------------" << endl;
			cout << "list - list of all events" << endl;
			cout << "new - create new event" << endl;
			cout << "exit - exit (0_o)" << endl;
			cout << "delete <id>  - delete Event with this id" << endl;
			cout << "help  - write help" << endl;
			cout << "-----------------help-------------------------------------" << endl;
		}
	}
}
void Theme() {
	while (1) {
		input("/sys:/theme", "Type help for write help");
		if (inret() == "help") {
			cout << "-----------------help-------------------------------------" << endl;
			cout << "cls - clear cmd screen" << endl;
			cout << "set <color> <color> - set background and text color in your window" << endl;
			cout << "list - list of avaliable colors" << endl;
			cout << "exit - exit (0_o)" << endl;
			cout << "help  - write help" << endl;
			cout << "-----------------help-------------------------------------" << endl;
		}
		if (inret() == "cls")
			clr();

		if (inret() == "set")
		{
			input("", "");
			string selectBT = inret();
			input("", "");
			string selectColor = inret();
			if (selectBT == "bg") {
				scalar(selectBT, selectColor);
			}
		}
		if (inret() == "list")
		{
			cout << "-----------------list-------------------------------------" << endl;
			cout << "Black			 \t Blue" << endl;
			cout << "Green			 \t Cyan" << endl;
			cout << "Magenta		 \t Brown" << endl;
			cout << "LightGray		 \t DarkGray" << endl;
			cout << "LightBlue		 \t LightGreen " << endl;
			cout << "LightCyan		 \t LightRed " << endl;
			cout << "LightMagenta	 \t Yellow " << endl;
			cout << "White			 \t Red" << endl;
			cout << "-----------------list-------------------------------------" << endl;
		}
		if (inret() == "exit")
		{
			break;
		}
	}
};
