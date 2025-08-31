#ifndef EXTRACHEESE_H
#define EXTRACHEESE_H

#include "PizzaDecorator.h"

class ExtraCheese: public PizzaDecorator{
    public:
    ExtraCheese(Pizza* p);
    double getPrice() override;
    std::string getName() override;
    void printPizza() override;

};
#endif