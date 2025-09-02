#ifndef FAMILYDISCOUNT_H
#define FAMILYDISCOUNT_H

#include "DiscountStrategy.h"
#include "Pizza.h"

class FamilyDiscount: public DiscountStrategy{
public:
    double applyDiscount(Pizza *pizza) override;
    double getDiscount() override { return discount; }

private:
    double discount = 0.15;
};

#endif