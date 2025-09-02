#ifndef PIZZASTATE_H
#define PIZZASTATE_H

#include <string>
#include <iostream>

class PizzaStateContext;

class PizzaState{
public:
    PizzaState(int heatLevel): heat(heatLevel){}
    virtual ~PizzaState(){}
    virtual void handle(PizzaStateContext*c) = 0;
    int getHeat(){return heat;}
    virtual void reversePlate(){}
private:
    int heat; // state that changes
};


#endif