#include "BasePizza.h"
#include "Topping.h"
#include "ToppingGroup.h"

BasePizza::BasePizza(std::string name, double price): Pizza(name,price){
        toppings = new ToppingGroup("",0.0);
        toppings->add(new Topping("Dough",10.00));
        toppings->add(new Topping("Tomato Sauce",5.00));
        toppings->add(new Topping("Cheese",15.00));

    
}

BasePizza::~BasePizza(){
    
        delete this->toppings;
    
}

void BasePizza::addToToppings(PizzaComponent* component){
    toppings->add(component);
    cout << component->getName()<< " added\n";
}

double BasePizza::getPrice() {
    double temp = Pizza::getPrice();
    if(toppings)
        temp += toppings->getPrice(); 
    return temp;
}


std::string BasePizza::getName() {
    std::ostringstream os;
    os << Pizza::getName() << " (";  
    if (toppings && !toppings->isEmpty()) {
        os << toppings->getName(); 
    }
    os << ")";
    return os.str();
}



void BasePizza::printPizza() {
    std::cout << getName() << " : R" << getPrice() << std::endl;
}

