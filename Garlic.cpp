#include "Garlic.h"
#include "PizzaDecorator.h"

double Garlic::getPrice(){
    return PizzaDecorator::getPrice()+8; 
}

std::string Garlic::getName(){
    return PizzaDecorator::getName() + " with Garlic";
}


void Garlic::printPizza() {
    std::cout << getName() << " : R" << getPrice() << std::endl;
}

Garlic::Garlic(Pizza* p): PizzaDecorator(p){}