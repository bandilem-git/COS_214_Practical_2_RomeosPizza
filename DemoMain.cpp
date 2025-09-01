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
    return new BasePizza(name,0.00);
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


Pizza* addToppings(BasePizza* p, int numOfToppings) {
    std::cout << "Enter combination name:\n";
    std::string groupName;
    std::getline(std::cin >> std::ws, groupName);// emwoves whitespace  

 
    ToppingGroup* extraGroup = new ToppingGroup(groupName, 0.0);

    for(int i = 0; i < numOfToppings; i++){
        extraGroup->add(makeTopping());
    }

     p->addToToppings(extraGroup);

    return p;
}


//Strategy
DiscountStrategy* Discount(bool isFamily,int quantity){
    if(isFamily){
        return new FamilyDiscount();
    }
    else if(quantity > 5){
        return new BulkDiscount();
    } 
    return new RegularPrice();
    
}



int main(){

    // Observers
    Observer* cust1 = new Customer();
    Observer* w1 = new Website();

    //Subjects
    Menus* pizzaMenu = new PizzaMenu();
    Menus* specialtyMenu = new SpecialsMenu();

    //i should be able to delete cust and it should delete menu
    cust1->setSubject(pizzaMenu);
    w1->setSubject(pizzaMenu);

    Pizza* p = new BasePizza("Plain",0.0); 
    pizzaMenu->addPizza(p);
    pizzaMenu->notifyObservers("Brand New Pizza on the menu");

    
    delete cust1;
    delete w1;
    delete pizzaMenu;
    delete specialtyMenu;
    delete p;

    
    return 0;
}