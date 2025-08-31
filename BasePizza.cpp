#include "BasePizza.h"

BasePizza::BasePizza(std::string name, double price, ToppingGroup* toppings): Pizza(name,price){
    this->toppings = toppings;
}

BasePizza::~BasePizza(){
    if (this->toppings){
        delete this->toppings;
    }
}

double BasePizza::getPrice() {
    double temp = Pizza::getPrice();
    if(toppings)
        temp += toppings->getPrice(); 
    return temp;
}


std::string BasePizza::getName() {
    if (toppings && !toppings->isEmpty())
        return Pizza::getName() + " (" + toppings->getName() + ")";
    return Pizza::getName();
}

void BasePizza::printPizza() {
    std::cout << getName() << " : R" << getPrice() << std::endl;
}

