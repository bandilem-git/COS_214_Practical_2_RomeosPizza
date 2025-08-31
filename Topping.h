#ifndef TOPPING_H
#define TOPPING_H
#include "PizzaComponent.h"

class Topping: public PizzaComponent{
    private:
        std::string name;
        double price;
    public:
        Topping(std::string name, double price);
        std::string getName() override;
        double getPrice() override;
};


#endif