#include "BasePizza.h"

BasePizza::BasePizza(std::string name, double price, ToppingGroup* toppings): Pizza(name,price){
    this->toppings = toppings;
}

BasePizza::~BasePizza(){
    if (this->toppings){
        delete this->toppings;
    }
}

double BasePizza::getPrice(){
    double temp = Pizza::getPrice();

    if(toppings->isEmpty()){
        return temp;
    }
    return temp;
}
std::string BasePizza::getName(){
    std::string toRet = BasePizza::getName()+" (" +toppings->getName()+")";
    return toRet;
}
void BasePizza::printPizza(){
    cout << getName()<<std::endl;
}
