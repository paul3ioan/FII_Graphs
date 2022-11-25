#include "MouseEvents.h"
#include <iostream>

void MouseEvents::startListening(Interface::Interface& inter) {
	bool isRunning = true;
	while (isRunning) {
        handleButtonsClick(inter);
        if (GetAsyncKeyState(VK_ESCAPE)) {
            isRunning = false;
        }
	}
    Interface::closeInterface();
}

void MouseEvents::handleButtonsClick(Interface::Interface& inter) {
    if (!ismouseclick(WM_LBUTTONDBLCLK)) {
        return;
    }
    int posX, posY;
    getmouseclick(WM_LBUTTONDOWN, posX, posY);
    bool isButtonPressed = false;
    int indexOfPressedButton = -1;
    for (int i = 0; i < inter.numberOfButtons && !isButtonPressed; i++) {
        Interface::Button checkedButton = inter.Buttons[i];
        if (!(checkedButton.x <= posX && checkedButton.x2 >= posX)) {
            continue;
        }
        if (!(checkedButton.y <= posY && checkedButton.y2 >= posY)) {
            continue;
        }
        checkedButton.isActive = true;
        isButtonPressed = true;
        indexOfPressedButton = i;
    }
    // check if the click hit any of the buttons
    // if so then we reset the already active button
    // here we need to separate de menu button for initiliaze graph 
    // from those of the algorithms 
    if (!isButtonPressed) {
        return;
    }
    // if the buttons where from top menu
    if (indexOfPressedButton < inter.menuButtons) {
        for (int i = 0; i < inter.menuButtons; i++) {
           Interface::Button checkedButton = inter.Buttons[i];
           if (checkedButton.isActive) {
                checkedButton.isActive = false;
                Interface::createMenuButton(checkedButton.x, checkedButton.y, checkedButton.label, inter, checkedButton.isActive);
           }
        }
    }
    else {
        // buttons from the algorithm part
        if (indexOfPressedButton >= inter.menuButtons) {
            for (int i = inter.menuButtons; i < inter.numberOfButtons; i++) {
                Interface::Button checkedButton = inter.Buttons[i];
                if (checkedButton.isActive) {
                    checkedButton.isActive = false;
                    Interface::createMenuButton(checkedButton.x, checkedButton.y, checkedButton.label, inter, checkedButton.isActive);
                }
            }
        }
    }
    // lastly we will make the action assigned to the button and make it active
    Interface::Button& pressedButton = inter.Buttons[indexOfPressedButton];
    pressedButton.isActive = true;
    Interface::createMenuButton(pressedButton.x, pressedButton.y, pressedButton.label, inter, pressedButton.isActive);
    makeActionOfButton(indexOfPressedButton);
}