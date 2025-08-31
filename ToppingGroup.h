#ifndef TOPPINGGROUP_H
#define TOPPINGGROUP_H

#include "PizzaComponent.h"
#include <vector>
#include <sstream>

class ToppingGroup : public PizzaComponent {
private:

    std::vector<PizzaComponent*> toppings; 
public:

    ToppingGroup(std::string name, double price);

    void add(PizzaComponent* component);
    std::string getName() override;
    double getPrice() override;
    bool isEmpty();
    
    ~ToppingGroup();
};

#endif