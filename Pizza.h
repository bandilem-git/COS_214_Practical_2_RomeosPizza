#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <string>
using namespace std;
class Pizza{
    private:
    std::string name;
    double price;
    public:
        Pizza(std::string name, double price);
        virtual double getPrice();
        virtual std::string getName();
        virtual void printPizza();
};

#endif