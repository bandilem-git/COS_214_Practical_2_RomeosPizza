#include "Boxed.h"
#include "PizzaStateContext.h"
#include <iostream>

Boxed::Boxed() : PizzaState(-1) {}

void Boxed::handle(PizzaStateContext *c)
{
    if (getHeat() == -1)
    {
        std::cout << "Pizza is boxed and must be delivered" << std::endl;
    }
}