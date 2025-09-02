#ifndef DISCOUNTSTRATEGY_H
#define DISCOUNTSTRATEGY_H

#include "Pizza.h"
#include <iostream>

class DiscountStrategy{
    public:
        virtual double applyDiscount(Pizza*) = 0;
        virtual double getDiscount()=0;
        virtual ~DiscountStrategy(){};
};

#endif