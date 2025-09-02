#ifndef REGULARPRICE_H
#define REGULARPRICE_H

#include "DiscountStrategy.h"
#include "Pizza.h"

class RegularPrice : public DiscountStrategy
{
public:
    double applyDiscount(Pizza *pizza);
    double getDiscount() { return discount; }

private:
    double discount = 0.0;
};

#endif