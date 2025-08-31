#include "StuffedCrust.h"
#include "PizzaDecorator.h"

std::string StuffedCrust::getName(){
    return PizzaDecorator::getName()+ "w/ Stuffed Crust";
}

double StuffedCrust::getPrice(){
    return PizzaDecorator::getPrice()+ 6;
}
