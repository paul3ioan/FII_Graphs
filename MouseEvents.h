#pragma once
#include "Interface.h";
namespace MouseEvents
{
	void startListening(Interface::Interface&);
	void handleButtonsClick(Interface::Interface&);
	void makeActionOfButton(int);
};

