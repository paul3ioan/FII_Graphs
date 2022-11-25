#pragma once

const short int MAX_NUMBER_OF_BUTTONS = 10;
const short int BUTTONS_WIDTH = 30;
const short int BUTTONS_HEIGHT = 10;
const short int ELIPSE_WIDTH = 70;
const short int ELIPSE_HEIGHT = 40;
const short int SCREEN_PADDING = 5;

const short int ACTIVE_BUTTON_BGCOLOR = RED;
const short int ACTIVE_BUTTON_COLOR = WHITE;

enum ACTION_TYPE_BUTTON {
	CREATE_NEW_GRAPH,
	GET_GRAPH_FROM_FILE,
};