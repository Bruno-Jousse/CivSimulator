#include <iostream>

#include "../controller/Simulator.h"

using namespace std;

int main(int argc, char const *argv[])
{
    if(argc!=2)
    {
        cout << "Please give me a number of turn to simulate" << endl;
        return 0;
    }

    Simulator simulator;

    for(int i = 0; i < atoi(argv[1]); i++)
    {
        simulator.simulateOneTurn(); // simulate
        simulator.display(); // display
    }
    
    return 0;
}
