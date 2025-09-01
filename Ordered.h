#ifndef ORDERED_H
#define ORDERED_H

#include "PizzaState.h"
#include "PizzaStateContext.h"

class Ordered : public PizzaState {
public:
    Ordered(); // heatLevel 0
    void handle(PizzaStateContext* context);
    std::string getName();
};

#endif
