#include "MouseEvents.h";
#include <iostream>
void MouseEvents::makeActionOfButton(int actionType) {
    switch (actionType) {
    case ACTION_TYPE_BUTTON::CREATE_NEW_GRAPH:
        std::cout << "Create new graph\n";
        // create random graph
        break;
    case ACTION_TYPE_BUTTON::GET_GRAPH_FROM_FILE:
        // get graph from file
        std::cout << "Get graph from file\n";
        break;
    default:
        break;
    }
}