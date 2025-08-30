#ifndef SPECIALSMENU_H
#define SPECIALSMENU_H

#include "Menus.h"

class SpecialsMenu: public Menus{
    public:
        void notifyObservers(std::string message) override;
};

#endif