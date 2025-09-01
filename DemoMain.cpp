#include <iostream>
#include "BasePizza.h"
#include "StuffedCrust.h"
#include "ExtraCheese.h"
#include "Topping.h"
#include "ToppingGroup.h"
#include "PizzaOrder.h"
#include "RegularPrice.h"
#include "BulkDiscount.h"
#include "FamilyDiscount.h"
#include "PizzaStateContext.h"
#include "InOven.h"
#include "Plated.h"
#include "Boxed.h"

int main() {
    // -------------------
    // Composite Pizzas
    // -------------------
    ToppingGroup* pepperoniPizza = new ToppingGroup("Meat Lovers", 0);
    pepperoniPizza->add(new Topping("Salami", 22.0));
    pepperoniPizza->add(new Topping("Beef Sausage", 25.0));

    ToppingGroup* veggiePizza = new ToppingGroup("Veggie", 0);
    veggiePizza->add(new Topping("Mushrooms", 12.0));
    veggiePizza->add(new Topping("Green Peppers", 10.0));

    std::cout << "Meat Lovers Pizza: " 
              << pepperoniPizza->getName() 
              << " costs R" << pepperoniPizza->getPrice() << std::endl;

    std::cout << "Veggie Pizza: " 
              << veggiePizza->getName() 
              << " costs R" << veggiePizza->getPrice() << std::endl;

    // -------------------
    // Decorator Pizzas
    // -------------------
    Pizza* base = new BasePizza("Plain Pizza", 60.0);
    Pizza* stuffed = new StuffedCrust(base);
    Pizza* cheesy = new ExtraCheese(stuffed);

    std::cout << "Plain Pizza (Dough, Tomato Sauce, Cheese) with Stuffed Crust and Extra Cheese costs R" 
              << cheesy->getPrice() << std::endl;

    // -------------------
    // Strategy Discounts
    // -------------------
    PizzaOrder* order1 = new PizzaOrder(new RegularPrice());
    std::cout << "Regular: R" << order1->useAlgorithm(cheesy) << std::endl;

    PizzaOrder* order2 = new PizzaOrder(new BulkDiscount());
    std::cout << "Bulk discount: R" << order2->useAlgorithm(cheesy) << std::endl;

    PizzaOrder* order3 = new PizzaOrder(new FamilyDiscount());
    std::cout << "Family discount: R" << order3->useAlgorithm(cheesy) << std::endl;

    // -------------------
    // State Pattern Demo
    // -------------------
    PizzaStateContext* context = new PizzaStateContext(cheesy);
    context->setState(new InOven());
    context->displayCurrentState();

    context->setState(new Plated());
    context->displayCurrentState();

    context->setState(new Boxed());
    context->displayCurrentState();

    // -------------------
    // Cleanup Composite
    // -------------------
    delete pepperoniPizza;
    delete veggiePizza;

    // Decorators clean up internally
    delete cheesy;

    // Cleanup strategies and orders
    delete order1;
    delete order2;
    delete order3;

    // Cleanup state context
    delete context;

    return 0;
}
