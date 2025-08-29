#ifndef STUFFEDCRUST_H
#define STUFFEDCRUST_H

#include "PizzaDecorator.h"

class StuffedCheese: public PizzaDecorator{
    public:
    double getPrice() override;
    std::string getName() override;
};


#endif