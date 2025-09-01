#ifndef PIZZASTATECONTEXT_H
#define PIZZASTATECONTEXT_H

#include <iostream>
#include "Pizza.h"



class PizzaState;

class PizzaStateContext{
public:
    PizzaStateContext(Pizza* pizza);
    ~PizzaStateContext();
    void request();
    void setState(PizzaState *state);
    void displayCurrentState();
    void reversePlate();

private:
    PizzaState *state = nullptr;
    Pizza* pizza;
};

#endif