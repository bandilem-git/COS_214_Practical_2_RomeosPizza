#ifndef PIZZADECORATOR_H
#define PIZZADECORATOR_H

#include "Pizza.h"
class PizzaDecorator: public Pizza{
    private:
        Pizza* pizza;
    public:
        virtual double getPrice() = 0;
        virtual std::string getName()= 0;
    };


#endif