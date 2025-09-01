#include "PizzaMenu.h"
#include "Observer.h"

void PizzaMenu::notifyObservers(std::string message){

    safeNotify("PizzaMenu: " + message);

    // auto& observers = getObservers();
    // for (auto* obs: observers)
    // {
    //     if (obs)
    //     {
    //         obs->update(this,message);
    //     }
        
    // }
    
    // std::vector<Observer*>::iterator it = observers.begin();
    // for (it = observers.begin();it != observers.end(); ++it){
    //     (*it)->update(message);
    // }
}