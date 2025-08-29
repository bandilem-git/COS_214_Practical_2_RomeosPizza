#ifndef EXTRACHEESE_H
#define EXTRACHEESE_H

#include "PizzaDecorator.h"

class ExtraCheese: public PizzaDecorator{
    public:
    double getPrice() override;
    std::string getName() override;
};
#endif