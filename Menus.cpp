#include "Menus.h"
#include <vector>

void Menus::addObserver(Observer *observer){
    if (observer != nullptr){
        // check if already added to avoid duplicates
        auto it = std::find(observers.begin(), observers.end(), observer);
        if(it==observers.end()){
            observer->setSubject(this);
            observers.push_back(observer);
        }
    }
    
};

void Menus::removeObserver(Observer *observer){
    if (observer == nullptr){
        return;
    }

    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()){
        observers.erase(it);
    }
    
};

void Menus::addPizza(Pizza* pizza){
    if (pizza != nullptr){
        // Check for duplicates
        auto it = std::find(pizzas.begin(), pizzas.end(), pizza);
        if (it == pizzas.end()){
            pizzas.push_back(pizza);
            std::string message = "Pizza: " + pizza->getName() + " Price: R" + std::to_string(pizza->getPrice()) + " has been added.";
            notifyObservers(message);
        }
    }
    
};

void Menus::removePizza(Pizza *pizza){
    if (pizza == nullptr){
        return;
    }

    auto it = std::find(pizzas.begin(), pizzas.end(), pizza);
    if (it != pizzas.end()){
        pizzas.erase(it);
        std::string message = "Pizza: " + pizza->getName() + " Price: R" + std::to_string(pizza->getPrice()) + " has been removed.";
        notifyObservers(message);
    }
};

const std::vector<Observer *>& Menus::getObservers() const{
    return observers;
};
std::vector<Pizza *> Menus::getState() const{
    return pizzas; // Returns copy
};

void Menus::setState(const std::vector<Pizza*>& newPizzas){
    // Clear old pizzas:
    //1. If Menus owns pizzas:
    // for(auto* pizza: pizzas){
    //     delete pizza;
    // }
    //2. If Menus does not own pizzas
    pizzas.clear();
    this->pizzas = newPizzas;
    notifyObservers("Menu has been updated");
};

Menus::~Menus(){
    removeAllObservers();
    // for(auto* p: pizzas){
    //     delete p; // assumes that pizzas are owned by Menus
    // }
    pizzas.clear();
}
void Menus::removeAllObservers()
{
    for (auto *observer : observers)
    {
        if (observer)
        {
            observer->setSubject(nullptr);
        }
    }
    observers.clear();
}