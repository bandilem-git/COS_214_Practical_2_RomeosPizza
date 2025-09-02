#ifndef MENUS_H
#define MENUS_H

#include "Pizza.h"
#include "Observer.h"
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

class Observer;

class Menus{
    public:
        void addObserver(Observer* observer);
        void removeObserver(Observer* observer);
        void addPizza(Pizza* pizza);
        void removePizza(Pizza* pizza);
        virtual void notifyObservers(std::string message) = 0;
        std::vector<Pizza*> getState() const;
        void setState(const std::vector<Pizza*>& pizzas);

        void removeAllObservers();

        virtual ~Menus();

        protected:
            const std::vector<Observer *> &getObservers() const; // only derived classes can access
        private:
        std::vector<Observer*> observers;
        std::vector<Pizza*> pizzas;
};

#endif