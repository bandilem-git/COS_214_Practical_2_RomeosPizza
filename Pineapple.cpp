#include "Pineapple.h"
#include "PizzaDecorator.h"


double Pineapple::getPrice(){
    return PizzaDecorator::getPrice() + 8; 
}

std::string Pineapple::getName(){
    return PizzaDecorator::getName() + " with Pineapple ";
}

void Pineapple::printPizza() {
    std::cout << getName() << " : R" << getPrice() << std::endl;
}

Pineapple::Pineapple(Pizza* p): PizzaDecorator(p){}
