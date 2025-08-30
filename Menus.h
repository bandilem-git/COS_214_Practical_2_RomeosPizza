#ifndef MENUS_H
#define MENUS_H

#include "Pizza.h"
#include"Observer.h"
#include <vector>
#include <string>

class Menus{
    public:
        void addObserver(Observer* observer);
        void removeObserver(Observer* observer);
        void addPizza(Pizza pizza);
        void removePizza(Pizza pizza);
        virtual void notifyObservers(std::string message) = 0;
    private:
        std::vector<Observer*> observers;
        std::vector<Pizza*> pizzas;
};

#endif