#include "InOven.h"
#include "Plated.h"
#include "PizzaStateContext.h"
#include <iostream>

InOven::InOven() : PizzaState(1) {}

void InOven::handle(PizzaStateContext *c){
    if (getHeat() == 1)
    {
        std::cout<< "Setting state to Plated" << std::endl;
        c->setState(new Plated());
    }
}