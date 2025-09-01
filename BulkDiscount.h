#ifndef BULKDISCOUNT_H
#define BULKDISCOUNT_H

#include "DiscountStrategy.h"
#include "Pizza.h"

class BulkDiscount : public DiscountStrategy
{
public:
    double applyDiscount(Pizza *pizza);

private:
    double discount = 0.10;
};

#endif