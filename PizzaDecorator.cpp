#include "PizzaDecorator.h"

PizzaDecorator::PizzaDecorator(Pizza* p):pizza(p),Pizza(p->getName(), p->getPrice()){};

PizzaDecorator::~PizzaDecorator() {
    if(pizza)
    delete pizza;
}

double PizzaDecorator::getPrice() {
    return pizza->getPrice();  
}

std::string PizzaDecorator::getName() {
    return pizza->getName();    
}

void PizzaDecorator::printPizza() {
    pizza->printPizza();        
}
