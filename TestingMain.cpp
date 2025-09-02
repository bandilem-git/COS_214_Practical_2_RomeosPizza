#include <iostream>
#include "BasePizza.h"
#include "Customer.h"
#include "Decker.h"
#include "Ordered.h"
#include "SpecialsMenu.h"
#include "StuffedCrust.h"
#include "ExtraCheese.h"
#include "Topping.h"
#include "ToppingGroup.h"
#include "PizzaOrder.h"
#include "RegularPrice.h"
#include "BulkDiscount.h"
#include "FamilyDiscount.h"
#include "PizzaStateContext.h"
#include "PizzaMenu.h"
#include "Observer.h"
#include "Website.h"

int main()
{
    std::cout << "=== Romeo's Pizza Full Test ===\n\n";

    // ------------------- Composite Pizzas -------------------
    ToppingGroup *meatPizza = new ToppingGroup("Meat Lovers", 0);
    meatPizza->add(new Topping("Salami", 22.0));
    meatPizza->add(new Topping("Beef Sausage", 25.0));

    ToppingGroup *veggiePizza = new ToppingGroup("Veggie", 0);
    veggiePizza->add(new Topping("Mushrooms", 12.0));
    veggiePizza->add(new Topping("Green Peppers", 10.0));

    std::cout << meatPizza->getName() << " costs R" << meatPizza->getPrice() << std::endl;
    std::cout << veggiePizza->getName() << " costs R" << veggiePizza->getPrice() << std::endl;

    // ------------------- Decorator Pizzas -------------------
    Pizza *base = new BasePizza("Plain Pizza", 60.0);
    base->printPizza();
    cout << endl;

    Pizza *stuffed = new StuffedCrust(base);
    stuffed->printPizza();
    cout << endl;

    Pizza *cheesy = new ExtraCheese(stuffed);
    cheesy->printPizza();
    cout << endl;

    std::cout << cheesy->getName() << " costs R" << cheesy->getPrice() << std::endl;

    // ------------------- Decorator & Composite -------------------

    Pizza *SweetChilli = new BasePizza("Sweet Chilli", 20.0);
    cout << "Base: " << endl;

    SweetChilli->printPizza();
    cout << "StuffingCrust: " << endl;

    SweetChilli = new StuffedCrust(SweetChilli);
    SweetChilli->printPizza();

    cout << "Adding Meaty toppings: " << endl;

    SweetChilli->addToToppings(meatPizza);
    SweetChilli->printPizza();

    cout << "Cram Decker Maker: " << endl;

    SweetChilli = new Decker(SweetChilli);
    SweetChilli->printPizza();

    // ------------------- Strategy Discounts -------------------
    cout << "Original price of " << cheesy->getName() << " " << cheesy->getPrice() << endl;
    // PizzaOrder* regularOrder = new PizzaOrder(new RegularPrice());
    // PizzaOrder* bulkOrder    = new PizzaOrder(new BulkDiscount());
    // PizzaOrder* familyOrder  = new PizzaOrder(new FamilyDiscount());
    PizzaOrder *order = new PizzaOrder();

    // std::cout << "[Strategy] RegularPrice: " << regularOrder->useAlgorithm(cheesy) << std::endl;
    // std::cout << "[Strategy] BulkDiscount: " << bulkOrder->useAlgorithm(cheesy) << std::endl;
    // std::cout << "[Strategy] FamilyDiscount: " << familyOrder->useAlgorithm(cheesy) << std::endl;

    order->regularStrategy();
    std::cout << "[Strategy] RegularPrice: " << order->useAlgorithm(cheesy) << std::endl;
    order->bulkStrategy();
    std::cout << "[Strategy] BulkDiscount: " << order->useAlgorithm(cheesy) << std::endl;
    order->familyStrategy();
    std::cout << "[Strategy] FamilyDiscount: " << order->useAlgorithm(cheesy) << std::endl;

    // ------------------- State Pattern Workflow -------------------
    PizzaStateContext *stateContext = new PizzaStateContext(cheesy);

    std::cout << "\n[State] Ordered → InOven → Plated → InOven → Plated → Boxed\n";

    // First state: Ordered
    stateContext->setState(new Ordered());
    stateContext->displayCurrentState();

    // Second state: InOven
    stateContext->request();
    stateContext->displayCurrentState();

    // Third state: Plated
    stateContext->request();
    stateContext->displayCurrentState();
    stateContext->reversePlate();

    // Fourth state: InOven
    stateContext->request();
    stateContext->displayCurrentState();

    // Fifth state: Plated
    stateContext->request();
    stateContext->displayCurrentState();

    // Sixth state: Boxed
    stateContext->request();
    stateContext->displayCurrentState();

    // ------------------- Menu & Observer -------------------

    Menus *menu = new PizzaMenu();
    Observer *customer1 = new Customer();
    Observer *customer2 = new Website();

    menu->addObserver(customer1);
    menu->addObserver(customer2);

    menu->addPizza(cheesy);

    Menus *specialMenu = new SpecialsMenu();
    Observer *customer3 = new Customer();
    Observer *customer4 = new Website();

    specialMenu->addObserver(customer3);
    specialMenu->addObserver(customer4);

    specialMenu->addPizza(SweetChilli);
    specialMenu->notifyObservers("Sweet Chilli special");

    specialMenu->addPizza(stuffed);
    specialMenu->notifyObservers("Stuffed Special special");
    specialMenu->removeAllObservers();

    specialMenu->removePizza(stuffed);
    specialMenu->removePizza(SweetChilli);

    menu->removeAllObservers();
    menu->removePizza(cheesy);

    // ------------------- Cleanup -------------------
    delete meatPizza;
    delete veggiePizza;
    delete cheesy;
    delete order;
    // delete regularOrder;
    // delete bulkOrder;
    // delete familyOrder;
    delete stateContext;
    delete menu;
    delete customer1;
    delete customer2;
    delete customer3;
    delete customer4;
    delete specialMenu;
    delete SweetChilli;

    std::cout << "\nProgram finished successfully.\n";
    return 0;
}
