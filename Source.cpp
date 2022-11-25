#include "graphics.h"
#include <iostream>
#include <math.h>
#include "Queue.h";
#include "Stack.h";
#include "Interface.h";
#include "MouseEvents.h"
#include "Exceptions.h";
#include <stdlib.h> // Provides exit
#include <ctype.h>
int main()
{
    const bool isDevelopment = true;
    bool isRunning = true;
    try {
        Stack::stack q;
        std::cout <<Stack::top(q);
        Stack::push(q, 10);
        Stack::push(q, 30);
        std::cout << Stack::isEmpty(q);
        Stack::top(q);
        Stack::pop(q);
    }
    catch (Exceptions::LogicException& err) {
        HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdout,
            FOREGROUND_RED | FOREGROUND_INTENSITY);
        std::cout <<'\n'<< err.what();
        Exceptions::logError(err.rootOfError(), isDevelopment);
    }
    Interface::Interface inter;
    Interface::initInterface();
    Interface::createLayout(inter);
    MouseEvents::startListening(inter);
    return 0;
}