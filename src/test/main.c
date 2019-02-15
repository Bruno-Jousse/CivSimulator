#include <iostream>

//#include "../controller/Simulator.h"
#include "../model/World.h"
#include "../model/Grid.h"

using namespace std;

/*
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
*/

int main(int argc, char const *argv[])
{
    Grid g(1000, 0, 0);

    for(int i=0; i<World::NB_ROW; i++)
    {
        for(int j=0; j<World::NB_COL; j++)
        {
            cout << g(i, j)  << " ";
        }
        cout << endl;
    }
}