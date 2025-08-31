#include "PizzaDecorator.h"
#include <iostream>

PizzaDecorator::PizzaDecorator(Pizza* p):pizza(p),Pizza(p->getName(), p->getPrice()){};

PizzaDecorator::~PizzaDecorator() {
    if(pizza)
    delete pizza;
}

double PizzaDecorator::getPrice() {
    return pizza->getPrice();  // delegate
}

std::string PizzaDecorator::getName() {
    return pizza->getName();   // delegate
}

void PizzaDecorator::printPizza() {
    pizza->printPizza();       // delegate
}
