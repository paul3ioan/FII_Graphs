#include "Interface.h"

void Interface::changeToStandardFont() {
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
}
void Interface::initInterface() {
    int gd = DETECT, gm;
    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenWidth, screenHeight, "Graph editor");
    changeToStandardFont();
}
void Interface::closeInterface() {
    closegraph();
}
void Interface::createMenuButton(int x, int y, char* label, Interface& inter, bool isActive, bool isInitialCreation, int bgColor, int color) {
    // set colors for the button
    if (!isActive) {
        setfillstyle(SOLID_FILL, bgColor);
        setbkcolor(bgColor);
        setcolor(color);
    }
    else {
        setfillstyle(SOLID_FILL, ACTIVE_BUTTON_BGCOLOR);
        setbkcolor(ACTIVE_BUTTON_BGCOLOR);
        setcolor(ACTIVE_BUTTON_COLOR);
    }
    //
    int textWidth = textwidth(label);
    int textHeight = textheight(label);
    int points[] = { x, y, (int) x + BUTTONS_WIDTH + textWidth, y, (int) x + BUTTONS_WIDTH + textWidth, (int) y + BUTTONS_HEIGHT + textHeight, x, (int)y + textHeight + BUTTONS_HEIGHT };
    fillpoly(4, points);
    int buttonWidth = x + BUTTONS_WIDTH/ 2;
    int buttonHeight = y + BUTTONS_HEIGHT/ 2;
    outtextxy(buttonWidth, buttonHeight, label);
    if (isActive) {
        setcolor(ACTIVE_BUTTON_BGCOLOR);
        drawpoly(4, points);
    }
    // reset option back to default
    setcolor(WHITE);
    setbkcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    //
    if (!isInitialCreation) {
        return;
    }
    Button newButton;
    newButton.x = x;
    newButton.y = y;
    newButton.isActive = isActive;
    newButton.x2 = x + BUTTONS_WIDTH + textWidth;
    newButton.y2 = y + BUTTONS_HEIGHT + textHeight;
    newButton.label = label;
    inter.Buttons[inter.numberOfButtons++] = newButton;
}
void Interface::centeredText(int height, char* msg, int paddingLeft, int color ) {
    settextstyle(DEFAULT_FONT,HORIZ_DIR, 4);
    setcolor(color);
    int midX = getmaxx() / 2;
    int width = textwidth(msg);
    outtextxy(midX - width / 2 + paddingLeft, height, msg);
    changeToStandardFont();
    setcolor(WHITE);
}
void Interface::createElipses(int x, int y) {
    int points[] = { x, y, (int)x + ELIPSE_WIDTH, y, x, (int)y + ELIPSE_HEIGHT, (int)x + ELIPSE_WIDTH, (int)y + ELIPSE_HEIGHT };
    fillpoly(4, points);
}
void Interface::createLayout(Interface& inter) {
    centeredText(30, "Graph Editor", -10, GREEN);
    int width = getmaxx() - 85;
    int height = getmaxy()- 75;

    createElipses(SCREEN_PADDING, SCREEN_PADDING);
    createElipses(width - SCREEN_PADDING, SCREEN_PADDING);
    createElipses(SCREEN_PADDING, height - SCREEN_PADDING);
    createElipses(width - SCREEN_PADDING, height - SCREEN_PADDING);
    createMenuButton(90, 10, "Create random graph", inter,false, true);
    createMenuButton(840, 10, "Get randomly from file", inter, false, true);
    createMenuButton(10, 80, "Kruskal", inter, false, true);
    createMenuButton(160, 80, "Prim", inter, false, true);
    createMenuButton(260, 80, "Dijkstra", inter, false, true);
    createMenuButton(430, 80, "Bellman", inter, false, true);
    createMenuButton(570, 80, "Floyd", inter, false, true);
    createMenuButton(700, 80, "Ford", inter, false, true);
    createMenuButton(800, 80, "APM", inter, false, true);
}