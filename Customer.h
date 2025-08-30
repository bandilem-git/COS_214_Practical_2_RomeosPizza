#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Observer.h"

class Customer: public Observer{
    public:
        void update(std::string message) override;
};

#endif