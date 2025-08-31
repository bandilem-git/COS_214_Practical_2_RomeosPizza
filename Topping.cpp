#include "Topping.h"


Topping::Topping(std::string name, double price) : PizzaComponent(name,price) {}

std::string Topping::getName() {
    return name;
}

double Topping::getPrice() {
    return price;
}

Topping::~Topping(){}