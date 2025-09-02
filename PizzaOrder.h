#ifndef PIZZAORDER_H
#define PIZZAORDER_H

#include "DiscountStrategy.h"
#include "RegularPrice.h"
#include "BulkDiscount.h"
#include "FamilyDiscount.h"

class PizzaOrder{
    public:
        PizzaOrder(){};
        double useAlgorithm(Pizza* pizza){
            return strategy->applyDiscount(pizza);
        };
        void bulkStrategy();
        void familyStrategy();
        void regularStrategy();
        ~PizzaOrder(){delete strategy;}
    private:
        DiscountStrategy* strategy = new RegularPrice();

};

#endif