#include <iostream>
#include <time.h>
#include "RectangleExample.h"

void test_static_counters(){
    rectangle::printRectangleCount();
    rectangle testobj1;
    rectangle::printRectangleCount();
    cout << "testobj1 ID: " << testobj1.getRectangleID() << endl;
    testobj1.inputRandomSides();
    rectangle::printRectangleCount();
    {
        cout << endl << "Entering a local scope:"<< endl;
        const int localaraysize=5;
        rectangle testobjarray[localaraysize];
        rectangle::printRectangleCount();
        for(int i=0; i<localaraysize; i++){
            cout << "testobjarray[" << i << "] ID: " << testobjarray[i].getRectangleID() << endl;
            testobjarray[i].inputRandomSides();
            rectangle::printRectangleCount();
        }
        cout << "Exiting local scope;"<< endl << endl;
    }
    rectangle::printRectangleCount();
    testobj1.reset();
    rectangle::printRectangleCount();
}

int main(int argv, char *argc[]){

    test_static_counters();

    std::cout << "Hello World" << std::endl;



    return 0;
}
