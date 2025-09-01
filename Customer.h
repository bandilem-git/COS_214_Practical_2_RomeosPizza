#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Observer.h"
#include "Pizza.h"
#include "Menus.h"
#include <vector>

class Customer: public Observer{
    public:
        void update(Menus *subject, std::string message) override;
        ~Customer(){
            clearHistory();
        }
};

#endif