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
BasePizza* BasePizzaGenerator(std::string name){// makes the plain pizza with just dough
    return new BasePizza(name,10.00,nullptr);
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

//cOMPOSITE

Topping* makeTopping(){
    cout << "Choose an ingredient: " << endl;
    cout << "0: Tomato Sauce "<< endl;
    cout << "1: Cheese "<< endl;
    cout << "2: Pepperoni"<< endl;
    cout << "3: Mushrooms"<< endl;
    cout << "4: Green Peppers"<< endl;
    cout << "5: Onions"<< endl;
    cout << "6: Beef Sausage"<< endl;
    cout << "7: Salami"<< endl;
    cout << "8: Feta Cheese"<< endl;
    cout << "9: Olives"<< endl;
 
    int c;
    cin >> c;
    switch(c){
        case 0:
            return new Topping("Tomato Sauce",5.00);
            break;
        case 1:
            return new Topping("Cheese",5.00);
            break;
        case 2:
            return new Topping("Pepperoni",20.00);
            break;
        case 3:
            return new Topping("Mushrooms",12.00);
            break;
        case 4:
            return new Topping("Green Peppers",10.00);
            break;
        case 5:
            return new Topping("Onions",8.00);
            break;
        case 6:
            return new Topping("Beef Sausage",25.00);
            break;
        case 7:
            return new Topping("Salami",22.00);
            break;
        case 8:
            return new Topping("Feta Cheese",18.00);
            break;
        case 9:
            return new Topping("Olives",15.00);
            break;
        default:
        cout << "error"<< endl;
        exit(1);
    }
}


Pizza* addToppings(Pizza* p,int numOfToppings){
    std::cout << "Enter combination name:\n";
    string name;
    std::getline(std::cin,name);
    ToppingGroup* tGroup= new ToppingGroup(name,0.0);
    for(int i=0; i < numOfToppings; i++){
        tGroup->add(makeTopping());
    }
    string pizzaName = p->getName();
    int pizzaPrice = p->getPrice();
    delete p;
    return new BasePizza(pizzaName,pizzaPrice,tGroup);
}


int main(){
    Pizza* base = BasePizzaGenerator("order1 ");
    cout << base->getPrice() <<endl;
    cout << endl;
    base = addToppings(base,0);
    cout << base->getName();
    cout << base->getPrice() <<endl;

    base = stuffCrust(base);
    cout << base->getName();
    delete base;
    return 0;
}