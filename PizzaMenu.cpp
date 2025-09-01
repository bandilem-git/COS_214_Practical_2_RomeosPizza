#include "PizzaMenu.h"
#include "Observer.h"

void PizzaMenu::notifyObservers(std::string message){
    auto& observers = getObservers();
    auto observersCopy = observers;
    for (auto *observer : observersCopy)
    {
        if (observer && std::find(observers.begin(), observers.end(), observer) != observers.end())
        {
            observer->update(this, "PizzaMenu: " + message);
        }
    }
}