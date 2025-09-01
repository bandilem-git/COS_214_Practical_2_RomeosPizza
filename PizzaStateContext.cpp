#include "PizzaStateContext.h"
#include "PizzaState.h"
#include "InOven.h"

void PizzaStateContext::request(){
    state->handle(this);
}

void PizzaStateContext::reversePlate(){
    state->reversePlate();
}

void PizzaStateContext::setState(PizzaState* state){
    if (state == nullptr)
    {
        return;
    }
    if (this->state == nullptr)
    {
        this->state = state;
    }
    else
    {
        delete this->state;
        this->state = state;
    }
}

void PizzaStateContext::displayCurrentState(){
    switch (this->state->getHeat())
    {
    case -1:
        std::cout << "Pizza is Boxed" << std::endl;
        break;

    case 0:
        std::cout << "Pizza is Plated" << std::endl;
        break;

    case 1:
        std::cout << "Pizza is in the Oven" << std::endl;
        break;

    default:
        std::cout << "Should never reach here through the states themselves" << std::endl;
        break;
    }
}

PizzaStateContext::PizzaStateContext(Pizza* pizza) : pizza(pizza)
{
    this->state = new InOven();
}

PizzaStateContext::~PizzaStateContext(){
    if (state)
    {
        delete state;
    }
}

