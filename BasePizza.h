#ifndef BASEPIZZA_H
#define BASEPIZZA_H

#include "Pizza.h"
#include "PizzaComponent.h"
#include "ToppingGroup.h"
#include <vector>
class BasePizza : public Pizza{
    private:
        ToppingGroup* toppings;
    public:
        BasePizza(std::string name, double price);
        ~BasePizza();
        double getPrice() override;
        std::string getName() override;
        void printPizza() override;
        void addToToppings(PizzaComponent* component) override;
};

#endif