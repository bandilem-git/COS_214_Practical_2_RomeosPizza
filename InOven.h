#ifndef INOVEN_H
#define INOVEN_H

#include "PizzaState.h"


class InOven: public PizzaState{
    public:
        InOven();
        ~InOven(){}
        void handle(PizzaStateContext* c) override;
};

#endif