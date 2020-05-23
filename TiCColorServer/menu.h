#pragma once
#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;

//func declar
void help_menu_view();
void hidecursor();
void UNhidecursor();
void man_menu_view();
//display main menu
void man_menu_view() {
	hidecursor();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << endl << "***|";
	SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | 5);
	cout << "TiKKColorServer";
	SetConsoleTextAttribute(hConsole, 7);
	cout << endl << "***|";
	SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | 5);
	cout << "Help menu";
	SetConsoleTextAttribute(hConsole, 7);
	SetConsoleTextAttribute(hConsole, 8);
	cout << endl << "***|" << "TiKKColorServer(1)";
	SetConsoleTextAttribute(hConsole, 7);
	SetConsoleTextAttribute(hConsole, 8);
	cout << endl << "***|" << "SYNOPSIS:";
	SetConsoleTextAttribute(hConsole, 7);
	cout << endl << "***|" << "		TiKKColorServer [OPTION] ... [DATA]";
	cout << endl << "***|" << "		TiKKColorServer [OPTION] ... [DATA] ... [DATA]";
	SetConsoleTextAttribute(hConsole, 8);
	cout << endl << "***|" << "DESCRIPTION:";
	SetConsoleTextAttribute(hConsole, 7);
	cout << endl << "***|" << "		./TiKKColorServer /s(server start) ... IPADDRESS FOR SRV ... PORT";
	cout << endl << "***|" << "		./dipscan /f(find) ... RGB color like(111 111 111) or name in TIKKURILA catalog(g300 ... G300)";
	cout << endl << "***|" << "		./dipscan /?(help menu)";
	cout << endl << "***|" << "		./dipscan /man(man menu)";
	SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | 9);
	cout << endl << "...by Dies_Irae" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	SetConsoleTextAttribute(hConsole, 7);
	UNhidecursor();
}

void help_menu_view() {
	cout << "	Usage: TiKKColorServer /f ... RGB or COLOR NAME" << endl << endl;
	cout << "	Usage: TiKKColorServer /s ... IP ... PORT" << endl << endl;
	cout << "	OPTIONS: " << endl;
	cout << "		s - Start server" << endl;
	cout << "		f - Find color in console" << endl;
	cout << "		m - man menu" << endl;
	cout << "		? - help menu" << endl << endl;
	cout << "	EXAMPLES: " << endl;
	cout << "		TiKKColorServer.exe /s 0.0.0.0 8080" << endl;
	cout << "		TiKKColorServer.exe /s 192.168.1.1 80" << endl << endl;
	cout << "		TiKKColorServer.exe /f 111 111 111 or g300" << endl;
	cout << "		TiKKColorServer.exe /h" << endl;
	cout << "		TiKKColorServer.exe /?" << endl;
}

void hidecursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
void UNhidecursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.bVisible = TRUE;
	SetConsoleCursorInfo(consoleHandle, &info);
}