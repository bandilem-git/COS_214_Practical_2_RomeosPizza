#include "ExtraCheese.h"
#include "PizzaDecorator.h"

double ExtraCheese::getPrice(){
    return pizza->getPrice() + 12;// added R12 for extra cheese 
}

std::string ExtraCheese::getName(){
    return pizza->getName() + " with extra cheese ";
}


void ExtraCheese::printPizza() {
    std::cout << getName() << " : R" << getPrice() << std::endl;
}

ExtraCheese::ExtraCheese(Pizza* p): PizzaDecorator(p){}