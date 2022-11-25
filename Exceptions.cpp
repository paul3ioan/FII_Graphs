#include "Exceptions.h"
void Exceptions::logError(const char* msg, const bool isDev) {
	if (!isDev) {
		return;
	}

	// changes the color of output to blue
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout,
		FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	//
	std::cout << '\n' << "Error comes from: ";

	// changes the color of output to green
	SetConsoleTextAttribute(hStdout,
		FOREGROUND_RED | FOREGROUND_INTENSITY);
	//
	std::cout <<msg << '\n'<<'\n';

	// changes the color of output back to white
	SetConsoleTextAttribute(hStdout,
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	//
}