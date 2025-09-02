#ifndef PLATED_H
#define PLATED_H

#include "PizzaState.h"


class Plated : public PizzaState{
public:
    Plated();
    ~Plated(){};
    void handle(PizzaStateContext *c) override;
    void backToOven(){ oven = true; }
    void reversePlate() override;

private:
    bool oven = false;
};

#endif