#include "StuffedCrust.h"
#include "PizzaDecorator.h"

std::string StuffedCrust::getName(){
    return pizza->getName()+ "with Stuffed Crust";
}

double StuffedCrust::getPrice(){
    return pizza->getPrice()+ 20;// add 20 to the price
}


void StuffedCrust::printPizza() {
    std::cout << getName() << " : R" << getPrice() << std::endl;
}

StuffedCrust::StuffedCrust(Pizza* p):PizzaDecorator(p){};