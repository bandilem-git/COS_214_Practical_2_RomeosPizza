#ifndef STUFFEDCRUST_H
#define STUFFEDCRUST_H

#include "PizzaDecorator.h"

class StuffedCrust: public PizzaDecorator{
    public:
    double getPrice() override;
    std::string getName() override;
    void printPizza() override;

};


#endif