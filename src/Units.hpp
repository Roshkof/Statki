#pragma once
#include <vector>
#include"Statki.hpp"

class Ship
{
    public:
    virtual int getShipSize()=0;
    virtual int getShipQuantity()=0;
    virtual ~Ship() { };

};

class SingleShip:public Ship
{
    int shipSize=1;
    int shipQuantity=4;
    public:
    int getShipSize();
    int getShipQuantity();
};

class DoubleShip:public Ship
{
    int shipSize=2;
    int shipQuantity=3;
    public:
    int getShipSize();
    int getShipQuantity();
};

class TripleShip:public Ship
{
    int shipSize=3;
    int shipQuantity=2;
    public:
    int getShipSize();
    int getShipQuantity();
};

class QuadraShip:public Ship
{
    int shipSize=4;
    int shipQuantity=1;
    public:
    int getShipSize();
    int getShipQuantity();
};