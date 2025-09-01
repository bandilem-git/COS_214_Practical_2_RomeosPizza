#ifndef BOXED_H
#define BOXED_H

#include "PizzaState.h"

class Boxed : public PizzaState{
    public:
    Boxed();
    ~Boxed() {}
    void handle(PizzaStateContext *);
};

#endif