#ifndef PIZZACOMPONENT_H
#define PIZZACOMPONENT_H

#include <iostream>
#include <string>
using namespace std;// will be used in testing

class PizzaComponent{
    private:
        double price; // price of each topping i guess??
        std::string name; // tomatoes, pepperoni ,chicken, salami, ham, pineapple 
    public:
        virtual std::string getName() = 0;
        virtual double getPrice() = 0;
        PizzaComponent(std::string name, double price);
};

#endif