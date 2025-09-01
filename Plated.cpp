#include "Plated.h"
#include "PizzaStateContext.h"
#include "InOven.h"
#include "Boxed.h"
#include <iostream>

Plated::Plated() : PizzaState(0) {}
void Plated::handle(PizzaStateContext *c)
{
    if (getHeat() == 0)
    {
        if (oven){
            std::cout << "Setting state to InOven" << std::endl;
            c->setState(new InOven());
        }else{
            std::cout << "Setting state to Boxed" << std::endl;
            c->setState(new Boxed());
        }
    }
}

void Plated::reversePlate(){
    this->backToOven();
}