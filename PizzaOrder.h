#ifndef PIZZAORDER_H
#define PIZZAORDER_H

#include "DiscountStrategy.h"

class PizzaOrder{
    public:
        PizzaOrder(DiscountStrategy* strategy) : strategy(strategy){};
        double useAlgorithm(Pizza* pizza){
            return strategy->applyDiscount(pizza);
        };
        ~PizzaOrder(){
            delete strategy;
        }
    private:
        DiscountStrategy* strategy;

};

#endif