#include "Pizza.h"

Pizza::Pizza(std::string name, double price):name(name),price(price){}

double Pizza::getPrice(){
    return price;
}

std::string Pizza::getName(){
    return name;
}

void Pizza::printPizza(){}

Pizza::~Pizza(){}