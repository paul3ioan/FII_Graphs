#include "Exceptions.h"
void Exceptions::logError(const char* msg, const bool isDev) {
	if (!isDev) {
		return;
	}

	// changes the color of output to red
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout,
		FOREGROUND_RED | FOREGROUND_INTENSITY);
	//

	std::cout << '\n' << "Error comes from: " << msg << '\n';

	// changes the color of output back to white
	SetConsoleTextAttribute(hStdout,
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	//
}