#include "Ordered.h"
#include "InOven.h"

Ordered::Ordered() : PizzaState(0) {} 

void Ordered::handle(PizzaStateContext* context){
        std::cout << "Pizza is ordered" << std::endl;
        context->setState(new InOven());
    }
    
std::string Ordered::getName() { return "Ordered"; }
