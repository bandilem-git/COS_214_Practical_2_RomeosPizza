#ifndef PLATED_H
#define PLATED_H

#include "PizzaState.h"


class Plated : public PizzaState{
public:
    Plated();
    ~Plated(){};
    void handle(PizzaStateContext *c);
    void backToOven(){ oven = true; }
    void reversePlate();

private:
    bool oven = false;
};

#endif