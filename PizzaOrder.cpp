#include "PizzaOrder.h"

void PizzaOrder::bulkStrategy()
{
    if (strategy->getDiscount() == 0.10)
    {
        return;
    }
    delete this->strategy;
    strategy = new BulkDiscount();
}

void PizzaOrder::familyStrategy()
{
    if (strategy->getDiscount() == 0.15)
    {
        return;
    }
    delete this->strategy;
    strategy = new FamilyDiscount();
}

void PizzaOrder::regularStrategy(){
    if (strategy->getDiscount() == 0.0)
    {
        return;
    }
    delete this->strategy;
    strategy = new RegularPrice();
}