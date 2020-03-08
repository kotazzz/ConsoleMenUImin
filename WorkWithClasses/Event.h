#pragma once
#pragma warning(disable  : 4430)
using namespace std;
static enum Progress {
	PROGRESS_Stoped = 0,
	PROGRESS_Login,
	PROGRESS_Tree,
	PROGRESS_LoadingModes,
	PROGRESS_DownloadingDB,
	PROGRESS_Relogin,
	PROGRESS_ConectToServer,
};
static int counterNext = 0;
class Event
{
public:
	inline Event();
	inline void DEvent();
	inline void ActionCustomText(string custom);
	inline void Hackmode();
	inline int iniID(bool set_get, int newID);
private:
	int mainID = 0;
	string* customString = new string;
	string* loginIn = new string;
	string* passwordIn = new string;
	string* connectIP = new string;
	string* connectPassword = new string;
	string downloadBar;
	Progress progress;
};

