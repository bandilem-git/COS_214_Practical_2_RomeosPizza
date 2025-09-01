#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>

#include "Topping.h"
#include "ToppingGroup.h"

#include "BasePizza.h"
#include "ExtraCheese.h"
#include "StuffedCrust.h"

#include "DiscountStrategy.h"
#include "FamilyDiscount.h"
#include "RegularPrice.h"
#include "BulkDiscount.h"

#include "Menus.h"
#include "PizzaMenu.h"
#include "SpecialsMenu.h"
#include "Customer.h"
#include "Website.h"

int main(){
    // Testing Composite
    // Testing
    // Testing Strategy
    ToppingGroup *toppingroup1 = new ToppingGroup("tomato", 10.50);
    // toppingroup1->add(new Topping("BBQ sauce", 8.7));
    // toppingroup1->add(new Topping("Base",16.99));
    ToppingGroup *toppingroup2 = new ToppingGroup("BBQ", 10.50);
    ToppingGroup *toppingroup3 = new ToppingGroup("BBQ", 10.50);
    ToppingGroup *toppingroup4 = new ToppingGroup("BBQ", 10.50);
    ToppingGroup *toppingroup5 = new ToppingGroup("BBQ", 10.50);
    Pizza *p1 = new BasePizza("Chicken", 100, toppingroup1);
    Pizza *p2 = new BasePizza("Beef", 120, toppingroup2);
    Pizza *p3 = new BasePizza("Beef", 120, toppingroup3);
    Pizza *p4 = new BasePizza("Beef", 120, toppingroup4);
    Pizza *p5 = new BasePizza("Beef", 120, toppingroup5);
    std::vector<Pizza*> pizzas;
    pizzas.push_back(p1);
    pizzas.push_back(p2);
    pizzas.push_back(p3);
    pizzas.push_back(p4);
    pizzas.push_back(p5);
    bool family = false;
    DiscountStrategy* strategy = nullptr;

    if (family)
    {
        strategy = new FamilyDiscount();
    } else if (pizzas.size() >= 5)
    {
        strategy = new BulkDiscount();
    }else{
        strategy = new RegularPrice();
    }

    double discount = strategy->applyDiscount(pizzas[0]);
    std::cout << "Old price: " << pizzas[0]->getPrice() << " and newPrice: " << discount << std::endl;

    // clear memory
    pizzas.clear();
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
    delete strategy;
    
    // Testing Observer
    // ToppingGroup *toppingroup1 = new ToppingGroup("tomato", 10.50);
    // ToppingGroup *toppingroup2 = new ToppingGroup("BBQ", 10.50);
    // Pizza *p1 = new BasePizza("Chicken", 100, toppingroup1);
    // Pizza *p2 = new BasePizza("Beef", 120, toppingroup2);

    // Menus *menu[2];
    // menu[0] = new PizzaMenu();
    // menu[1] = new SpecialsMenu();

    // Observer *observer[2];
    // observer[0] = new Customer();
    // observer[1] = new Website();

    // menu[0]->addObserver(observer[0]);
    // menu[0]->addObserver(observer[1]);
    // menu[1]->addObserver(observer[0]);
    // menu[1]->addObserver(observer[1]);

    // menu[0]->addPizza(p1);
    // menu[0]->addPizza(p2);
    // menu[1]->addPizza(p1);
    // menu[1]->addPizza(p2);

    // menu[0]->removePizza(p1);
    // menu[0]->removePizza(p2);
    // menu[1]->removePizza(p1);
    // menu[1]->removePizza(p2);

    // menu[0]->removeObserver(observer[0]);
    // menu[0]->removeObserver(observer[1]);
    // menu[1]->removeObserver(observer[0]);
    // menu[1]->removeObserver(observer[1]);

    // // Free up memory
    // delete menu[0];
    // delete menu[1];
    // delete observer[0];
    // delete observer[1];
    // delete p1;
    // delete p2;
    return 0;
}
