#ifndef PIZZA_H
#define PIZZA_H
#include "PizzaComponent.h"
#include <iostream>
#include <string>

using namespace std;

class Pizza{
    private:
    std::string name;
    double price;
    public:
        Pizza(std::string name, double price);
        virtual ~Pizza();
        virtual double getPrice();
        virtual std::string getName();
        virtual void printPizza();
        virtual void addToToppings(PizzaComponent* component);

};

#endif