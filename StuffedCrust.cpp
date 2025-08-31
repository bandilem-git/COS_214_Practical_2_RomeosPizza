#include "StuffedCrust.h"
#include "PizzaDecorator.h"

std::string StuffedCrust::getName(){
    return PizzaDecorator::getName()+ "w/ Stuffed Crust";
}

double StuffedCrust::getPrice(){
    return PizzaDecorator::getPrice()+ 6;
}


void StuffedCrust::printPizza() {
    std::cout << getName() << " : R" << getPrice() << std::endl;
}

StuffedCrust::StuffedCrust(Pizza* p):PizzaDecorator(p){};