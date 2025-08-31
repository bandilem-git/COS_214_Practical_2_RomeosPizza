#include "Pineapple.h"
#include "PizzaDecorator.h"

double Pineapple::getPrice(){
    return PizzaDecorator::getPrice()+8; 
}

std::string Pineapple::getName(){
    return PizzaDecorator::getName() + " with Pineapple";
}