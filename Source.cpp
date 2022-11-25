#include "graphics.h"
#include <iostream>
#include <math.h>
#include "Queue.h";
#include "Exceptions.h";
#include <stdlib.h> // Provides exit
#include <ctype.h>
int main()
{
    const bool isDevelopment = true;
    try {
        Queue::queue q;
        Queue::push(q, 10);
        Queue::push(q, 30);
        Queue::pop(q);
        std::cout << Queue::isEmpty(q);
        Queue::top(q);
        Queue::pop(q);
    }
    catch (Exceptions::LogicException& err) {
        std::cout << err.what();
        Exceptions::logError(err.rootOfError(), isDevelopment);
    }
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);
    //you can also pass NULL for third parameter if you did above setup successfully
    //example: initgraph(&gd, &gm, NULL);
    circle(300, 200, 100);
    getch();
    closegraph();
    return 0;
}