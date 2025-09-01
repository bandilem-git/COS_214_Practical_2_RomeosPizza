// For Demo purposes:

//Composite
#include "Topping.h"
#include "ToppingGroup.h"

//Decorator
#include "BasePizza.h"
#include "StuffedCrust.h"
#include "ExtraCheese.h"
#include "Decker.h"

//strategy
#include "RegularPrice.h"
#include "BulkDiscount.h"
#include "FamilyDiscount.h"

//observer
#include "PizzaMenu.h"
#include "SpecialsMenu.h"
#include "Customer.h"
#include "Website.h"

//Decorator
BasePizza* BasePizzaGenerator(){// makes the plain pizza with just dough
    return new BasePizza("Base Pizza ",10.00,nullptr);
}

Pizza* extraCheesePizza(Pizza* p){
    return new ExtraCheese(p);
}

Pizza* deckeredPizza(Pizza* p){
    return new Decker(p);
}

Pizza* stuffCrust(Pizza* p){
    return new StuffedCrust(p);
}


// int main(){
//     Pizza* base = BasePizzaGenerator();
//     cout << base->getPrice() <<endl;
//     base = extraCheesePizza(base);
//     cout << base->getPrice() <<endl;
//     // base = deckeredPizza(base);
//     // cout << base->getPrice() <<endl;
//     base = stuffCrust(base);
//     cout << base->getPrice() <<endl;


//     cout << base->getName();
//     delete base;
//     return 0;
// }