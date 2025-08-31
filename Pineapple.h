#ifndef PINEAPPLE_H
#define PINEAPPLE_H

#include "PizzaDecorator.h"

class Pineapple: public PizzaDecorator{
    public:
    double getPrice() override;
    std::string getName() override;
    void printPizza() override;

};
#endif