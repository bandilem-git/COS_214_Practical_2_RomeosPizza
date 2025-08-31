#include "ExtraCheese.h"
#include "PizzaDecorator.h"

double ExtraCheese::getPrice(){
    return PizzaDecorator::getPrice()+15; // add R15 for extra cheese
}

std::string ExtraCheese::getName(){
    return PizzaDecorator::getName() + " with extra cheese";
}


void ExtraCheese::printPizza() {
    std::cout << getName() << " : R" << getPrice() << std::endl;
}

ExtraCheese::ExtraCheese(Pizza* p): PizzaDecorator(p){}