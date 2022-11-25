#pragma once
#include <stdlib.h> // Provides exit
#include <ctype.h>
#include "graphics.h"
#include "InterfaceConstants.h"
namespace Interface
{
	struct Button {
		char* label = "";
		int x = 0, y = 0, x2 = 0, y2 = 0;
		bool isActive = false;
	};
	struct Interface {
		Button Buttons[10];
		int numberOfButtons = 0;
		int menuButtons = 2;
	};
	void initInterface();
	void closeInterface();
	void createElipses(int, int);
	void centeredText(int height, char* text, int paddingLeft=0, int color=WHITE);
	void changeToStandardFont();
	void createLayout(Interface&);
	void createMenuButton(int,int, char*, Interface&, bool isActive=false, bool isInitialCreation = false,  int bgColor=LIGHTGRAY, int color=GREEN);
};

