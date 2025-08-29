#ifndef BASEPIZZA_H
#define BASEPIZZA_H

#include "Pizza.h"
#include "PizzaComponent.h"
#include <vector>
class BasePizza : public Pizza{
    private:
        vector<PizzaComponent*> toppings;
    public:
        double getPrice() override;
        std::string getName() override;
        void printPizza() override;
};

#endif