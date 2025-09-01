#include "Website.h"

void Website::update(Menus *subject, std::string message){
    if (this->subject != subject)
    {
        setSubject(subject);
    }

    std::vector<Pizza *> currentState = subject->getState();
    std::vector<Pizza *> stateCopy;

    for (Pizza *pizza : currentState)
    {
        stateCopy.push_back(pizza);
    }

    observerStates.push_back(stateCopy);
    std::cout << "Website update: " << message << std::endl;
}