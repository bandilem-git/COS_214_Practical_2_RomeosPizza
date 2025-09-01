#include "Customer.h"

void Customer::update(Menus *subject, std::string message){
    if (this->subject != subject){ // set the subject if the subject is different
        setSubject(subject);
    }

    // Deep copy of current state
    std::vector<Pizza*> currentState = subject->getState();
    std::vector<Pizza*> stateCopy;

    // Creating a copy of pizzas so that the snapshot of internal state is independent of the actual internal state.
    for(Pizza* pizza: currentState){
        stateCopy.push_back(pizza); // currently storing pointers. If pizza had a clone then it would work
    }
    
    observerStates.push_back(stateCopy);
    std::cout << "Customer update:" << message << std::endl;
}