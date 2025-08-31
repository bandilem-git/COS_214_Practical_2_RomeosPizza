#ifndef PIZZACOMPONENT_H
#define PIZZACOMPONENT_H

#include <string>
#include <iostream>
using namespace std;

class PizzaComponent {
protected:
    std::string name;
    double price;
public:
    PizzaComponent(std::string name, double price);

    virtual ~PizzaComponent();// always
    virtual std::string getName() = 0;    
    virtual double getPrice() = 0;        
};

#endif
