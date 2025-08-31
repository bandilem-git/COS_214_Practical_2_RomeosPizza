#ifndef TOPPING_H
#define TOPPING_H

#include "PizzaComponent.h"

class Topping : public PizzaComponent {
public:
    Topping(std::string name, double price);
    ~Topping();
    std::string getName() override;
    double getPrice() override;
};

#endif
