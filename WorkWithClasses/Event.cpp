#include <iostream>
#include <Windows.h>
#include <ctime>
#include <stdlib.h>
#include "Event.h"
#include "Libs.h"



void Event::ActionCustomText(string custom)
{
	cout << "Action started" << endl << custom << endl << "ID:" << mainID << endl;
}
void Event::Hackmode()
{
	/*******************************************************/
	scalar(Green, Black, true); clr();
	cout << "Enter Login" << endl << "/USER/root/system_files/";
	cin >> *loginIn; cout << endl;
	cout << "Enter Pass" << endl << "/USER/root/system_files/" << *loginIn << "/";
	cin >> *passwordIn; cout << endl;
	progress = PROGRESS_Login;
	/*******************************************************/
	for (size_t i = 0; i < 25; i++) system("tree c:");
	progress = PROGRESS_Tree;
	/*******************************************************/
	cout << "Start mode \"Alpha\" ";
	Sleep(1000);
	cout << "Start mode \"Beta\" ";
	Sleep(1000);
	cout << "Succesful, loading base" << endl;
	progress = PROGRESS_LoadingModes;
	/*******************************************************/
	cout << "Enter Login" << endl << "/USER/root/system_files/";
	cin >> *loginIn; cout << endl;
	cout << "Enter Pass" << endl << "/USER/root/system_files/" << *loginIn << "/";
	cin >> *passwordIn; cout << endl;
	progress = PROGRESS_Relogin;
	/*******************************************************/
	for (size_t i = 0; i < 25; i++)
	{
		downloadBar += "<";
		for (size_t i2 = 0; i2 < i; i2++) downloadBar += "-";
		for (size_t i2 = 0; i2 < 25 - i; i2++) downloadBar += " ";
		downloadBar += ">";
		cout << downloadBar << " " << Frandom(50, 5000, 1) << "KB/sec" << endl;
		Sleep(20 * i);
	}
	cout << "Succesful, loading files from server" << endl;
	clr();
	progress = PROGRESS_DownloadingDB;
	/*******************************************************/
	for (size_t i = 0; i < 10; i++)
	{
		*connectIP += Frandom_string(0, 255);
		*connectIP += ".";
		*connectIP += Frandom_string(0, 255);
		*connectIP += ".";
		*connectIP += Frandom_string(0, 255);
		*connectIP += ".";
		*connectIP += Frandom_string(0, 255);
		for (size_t i = 0; i < 8; i++)
		{
			switch (Frandom(1, 4))
			{
			case 1: *connectPassword += (char)Frandom(48, 57);
			case 2: *connectPassword += (char)Frandom(65, 90);
			case 3: *connectPassword += (char)Frandom(97, 122);
			case 4: if (chance(20)) *connectPassword += 95;
			}
		}
		cout << "-----------------------------------------" << endl;
		cout << "Connecting to: \t\t\t " << *connectIP << endl;
		cout << "Using password to connect:  \t " << *connectPassword << endl;
		cout << "-----------------------------------------" << endl;
		*connectIP = "";
		*connectPassword = "";
	}
	/*******************************************************/
}
int Event::iniID(bool set = false, int newID = 0) {
	if (set) {
		mainID = newID;
	}
	int retMID = mainID;
	return retMID;
}


Event::Event()
{
	progress = PROGRESS_Stoped;
	mainID = counterNext;
	counterNext++;
	cout << "New event with ID: "<< mainID << endl;
}
void Event::DEvent()
{
	delete customString;
	delete loginIn;
	delete passwordIn;
	delete connectIP;
	delete connectPassword;

	cout << "Event #" << mainID << " ends!" << endl;
}