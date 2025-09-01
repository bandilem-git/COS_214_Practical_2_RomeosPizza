#include "SpecialsMenu.h"
#include "Observer.h"

void SpecialsMenu::notifyObservers(std::string message){
    safeNotify("SpecialsMenu: " + message);

    // auto &observers = getObservers();
    // for (auto *obs : observers)
    // {
    //     if (obs)
    //     {
    //         obs->update(this, message);
    //     }
    // }
    // std::vector<Observer *> observers = getObservers();
    // std::vector<Observer *>::iterator it = observers.begin();
    // for (it = observers.begin(); it != observers.end(); ++it)
    // {
    //     (*it)->update(message);
    // }
}