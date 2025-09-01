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
#include "Ordered.h"
#include "InOven.h"
#include "Plated.h"
#include "Boxed.h"

int main() {
    std::cout << "=== Creating Composite Pizzas ===" << std::endl;
    ToppingGroup* pepperoniPizza = new ToppingGroup("Meat Lovers", 0);
    pepperoniPizza->add(new Topping("Salami", 22.0));
    pepperoniPizza->add(new Topping("Beef Sausage", 25.0));

    ToppingGroup* veggiePizza = new ToppingGroup("Veggie", 0);
    veggiePizza->add(new Topping("Mushrooms", 12.0));
    veggiePizza->add(new Topping("Green Peppers", 10.0));

    std::cout << "Meat Lovers Pizza: " << pepperoniPizza->getName() 
              << " costs R" << pepperoniPizza->getPrice() << std::endl;
    std::cout << "Veggie Pizza: " << veggiePizza->getName() 
              << " costs R" << veggiePizza->getPrice() << std::endl;

    std::cout << "\n=== Creating Decorator Pizza ===" << std::endl;
    Pizza* base = new BasePizza("Plain Pizza", 60.0);
    Pizza* stuffed = new StuffedCrust(base);
    Pizza* cheesy = new ExtraCheese(stuffed);
    std::cout << cheesy->getName() <<" R" << cheesy->getPrice() << std::endl;

    std::cout << "\n=== Applying Discount Strategies ===" << std::endl;
    PizzaOrder* order1 = new PizzaOrder(new RegularPrice());
    std::cout << "[Strategy] RegularPrice applied: R" << order1->useAlgorithm(cheesy) << std::endl;

    PizzaOrder* order2 = new PizzaOrder(new BulkDiscount());
    std::cout << "[Strategy] BulkDiscount applied: R" << order2->useAlgorithm(cheesy) << std::endl;

    PizzaOrder* order3 = new PizzaOrder(new FamilyDiscount());
    std::cout << "[Strategy] FamilyDiscount applied: R" << order3->useAlgorithm(cheesy) << std::endl;

    std::cout << "\n=== State Pattern Demo ===" << std::endl;
    PizzaStateContext* context = new PizzaStateContext(cheesy);

    std::cout << "[State] Transition to Ordered" << std::endl;
    context->setState(new Ordered());
    context->displayCurrentState();

    std::cout << "[State] Transition to InOven" << std::endl;
    context->setState(new InOven());
    context->displayCurrentState();

    std::cout << "[State] Transition to Plated" << std::endl;
    context->setState(new Plated());
    context->displayCurrentState();

    std::cout << "[State] Transition to Boxed" << std::endl;
    context->setState(new Boxed());
    context->displayCurrentState();

    std::cout << "\n=== Cleaning up ===" << std::endl;
    delete pepperoniPizza;
    delete veggiePizza;
    delete cheesy;
    delete order1;
    delete order2;
    delete order3;
    delete context;

    std::cout << "Program finished successfully." << std::endl;
    return 0;
}
