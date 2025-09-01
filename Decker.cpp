#include "Decker.h"
#include "PizzaDecorator.h"


double Decker::getPrice(){
    return pizza->getPrice() + 39; 
}

std::string Decker::getName(){
    return pizza->getName() + " Decker ";
}

void Decker::printPizza() {
    std::cout << getName() << " : R" << getPrice() << std::endl;
}

Decker::Decker(Pizza* p): PizzaDecorator(p){}
