#include "Topping.h"

Topping::Topping(std::string name, double price):PizzaComponent(name,price){
    this->name = name;
    this->price = price;
}

std::string Topping::getName(){
    return name;
}

double Topping::getPrice(){
    return price;
}