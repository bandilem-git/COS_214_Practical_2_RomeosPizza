#include "Ordered.h"

Ordered::Ordered() : PizzaState(0) {} 

void Ordered::handle(PizzaStateContext* context){
        std::cout << "Pizza is ordered" << std::endl;
    }
    
std::string Ordered::getName() { return "Ordered"; }
