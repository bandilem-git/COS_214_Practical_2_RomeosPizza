#ifndef PIZZADECORATOR_H
#define PIZZADECORATOR_H

#include "Pizza.h"

class PizzaDecorator : public Pizza {
protected:
    Pizza* pizza;    

public:
    PizzaDecorator(Pizza* p);
    virtual ~PizzaDecorator();

    virtual double getPrice();          
    virtual std::string getName();      
    virtual void printPizza();          
};

#endif
