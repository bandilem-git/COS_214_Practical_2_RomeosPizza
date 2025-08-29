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
        virtual double getPrice() = 0;
        virtual std::string getName() = 0;
        virtual void printPizza();
};

#endif