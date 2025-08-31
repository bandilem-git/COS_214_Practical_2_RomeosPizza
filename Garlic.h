#ifndef GARLIC_H
#define GARLIC_H

#include "PizzaDecorator.h"

class Garlic: public PizzaDecorator{
    public:
    Garlic(Pizza* p);
    double getPrice() override;
    std::string getName() override;
    void printPizza() override;

};
#endif