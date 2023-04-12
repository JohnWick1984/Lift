#pragma once
#include<iostream>
using namespace std;
class Lift
{
private:
    int bottomFloor;
    int topFloor;
    bool running;
    int currentFloor;

public:
    Lift(int bottom, int top)
    {
        bottomFloor = bottom;
        topFloor = top;
        running = false;
        currentFloor = bottom;
    }

    void turnOn()
    {
        running = true;

    }

    void turnOff()
    {
        running = false;
    }

    bool getState()
    {
        return running;
    }

    int getFloor()
    {
        return currentFloor;
    }

    void call(int floor)
    {
        if (floor >= bottomFloor && floor <= topFloor)
        {
            currentFloor = floor;
        }
        else
        {
            cout << "Такого этажа нет" << endl;
        }
    }
};
