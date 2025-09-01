#ifndef PIZZAORDER_H
#define PIZZAORDER_H

#include "DiscountStrategy.h"

class PizzaOrder{
    public:
        PizzaOrder(DiscountStrategy* strategy) : strategy(strategy){};
        void useAlgorithm();
    private:
        DiscountStrategy* strategy;
        
};

#endif