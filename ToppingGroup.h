#ifndef TOPPINGGROUP_H
#define TOPPINGGROUP_H

#include "PizzaComponent.h"
#include <vector>

class ToppingGroup: public PizzaComponent{
    private:
        std::vector<PizzaComponent*> toppings; // no more * arrays

    public:
        void add(PizzaComponent* component);
        std::string getName() override;
        double getPrice() override;

};

#endif 