#ifndef DECKER_H
#define DECKER_H

#include "PizzaDecorator.h"

class Decker: public PizzaDecorator{
    public:
    Decker(Pizza* p);
    double getPrice() override;
    std::string getName() override;
    void printPizza() override;

};
#endif