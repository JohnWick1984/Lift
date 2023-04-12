// Lift.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include<iostream>
#include"lift.h"
using namespace std;


int main()
{
    int floorNumber = 1;
    setlocale(0, "");
    Lift lift(1, 10);
    lift.turnOn();
    cout << "Лифт включен: " << lift.getState() << endl;
    cout << "Лифт в данный момент на этаже №: " << lift.getFloor() << endl;
    cout << "На какой этаж отправить лифт?" << endl;
    cin >> floorNumber;
    lift.call(floorNumber);
    cout << "Лифт приехал на этаж №: " << lift.getFloor() << endl;
    lift.turnOff();
    cout << "Лифт выключен: " << lift.getState() << endl;
    return 0;
}
