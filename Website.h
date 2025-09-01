#ifndef WEBSITE_H
#define WEBSITE_H

#include "Observer.h"
#include "Pizza.h"
#include "Menus.h"
#include <vector>

class Website: public Observer{
    public:
        void update(Menus *subject, std::string message) override;
        ~Website(){
            clearHistory();
        }
};

#endif