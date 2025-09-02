#include <iostream>
#include <vector>
#include <string>
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


// std::vector<Pizza*> pizzas;   // global list of pizzas
// Menus* mainMenu = new PizzaMenu();
// Menus* specials = new SpecialsMenu();
// Observer* customer1 = new Customer();
// Observer* customer2 = new Website();

// void listPizzas() {
//     if (pizzas.empty()) {
//         std::cout << "No pizzas created yet.\n";
//         return;
//     }
//     std::cout << "\n=== Current Pizzas ===\n";
//     for (auto& p : pizzas) {
//         p->printPizza();
//         std::cout << " (R" << p->getPrice() << ")\n";
//     }
// }

// void createPizza() {
//     std::string name;
//     double basePrice;
//     std::cout << "Enter pizza name: ";
//     std::cin.ignore();
//     std::getline(std::cin, name);
//     std::cout << "Enter base price: ";
//     std::cin >> basePrice;

//     Pizza* newPizza = new BasePizza(name, basePrice);

//     int addTopping;
//     do {
//         std::cout << "Add a topping? (1=Yes, 0=No): ";
//         std::cin >> addTopping;
//         if (addTopping == 1) {
//             std::string tName;
//             double tPrice;
//             std::cout << "Topping name: ";
//             std::cin.ignore();
//             std::getline(std::cin, tName);
//             std::cout << "Topping price: ";
//             std::cin >> tPrice;
//             newPizza->addToToppings(new Topping(tName, tPrice));
//         }
//     } while (addTopping != 0);

//     // Let user decorate the pizza
//     int decorateChoice;
//     do {
//         std::cout << "Add decoration? (1=Extra Cheese, 2=Stuffed Crust, 3=Decker, 0=None): ";
//         std::cin >> decorateChoice;

//         if (decorateChoice == 1) {
//             newPizza = new ExtraCheese(newPizza);
//         } else if (decorateChoice == 2) {
//             newPizza = new StuffedCrust(newPizza);
//         } else if (decorateChoice == 3) {
//             newPizza = new Decker(newPizza);
//         }
//     } while (decorateChoice != 0);

//     pizzas.push_back(newPizza);
//     mainMenu->addPizza(newPizza);
//     std::cout << "Pizza created successfully!\n";
//     newPizza->printPizza();
//     std::cout << "Final price: R" << newPizza->getPrice() << "\n";
// }

// void generateGenericPizza() {
//     // --- Pepperoni ---
//     BasePizza* Pepperoni = new BasePizza("Pepperoni", 0.0);
//     ToppingGroup* pep = new ToppingGroup("", 0.0);
//     pep->add(new Topping("Pepperoni", 20.00));
//     Pepperoni->addToToppings(pep);
//     pizzas.push_back(Pepperoni);

//     // --- Vegetarian ---
//     BasePizza* Vegetarian = new BasePizza("Vegetarian", 0.0);
//     ToppingGroup* veg = new ToppingGroup("", 0.0);
//     veg->add(new Topping("Onions", 20.00));
//     veg->add(new Topping("Green Peppers", 20.00));
//     veg->add(new Topping("Mushrooms", 20.00));
//     Vegetarian->addToToppings(veg);
//     pizzas.push_back(Vegetarian);

//     // --- Meat Lover ---
//     BasePizza* Meat_Lover = new BasePizza("Meat Lover", 0.0);
//     ToppingGroup* m_Lover = new ToppingGroup("", 0.0);
//     m_Lover->add(new Topping("Pepperoni", 20.00));
//     Meat_Lover->addToToppings(m_Lover);
//     ToppingGroup* m_Lover_prep = new ToppingGroup("Meat Lover", 0.0);
//     m_Lover_prep->add(new Topping("Beef Sausage", 25.00));
//     m_Lover_prep->add(new Topping("Salami", 22.00));
//     Meat_Lover->addToToppings(m_Lover_prep);

//     pizzas.push_back(Meat_Lover);

    // --- Vegetarian Deluxe ---
    BasePizza* Veg_del = new BasePizza("Vegetarian Deluxe", 0.0);
    ToppingGroup* vegDel = new ToppingGroup("", 0.0);
    vegDel->add(new Topping("Onions", 8.00));
    vegDel->add(new Topping("Green Peppers", 10.00));
    vegDel->add(new Topping("Mushrooms", 12.00));
    Veg_del->addToToppings(vegDel);
    ToppingGroup* official_veg_del = new ToppingGroup("Vegetarian Deluxe", 0.0);
    official_veg_del->add(new Topping("Feta Cheese", 18.00));
    official_veg_del->add(new Topping("Olives", 15.00));
    Veg_del->addToToppings(official_veg_del);
    pizzas.push_back(Veg_del);
}


void applyDiscount() {
    if (pizzas.empty()) {
        std::cout << "No pizzas available.\n";
        return;
    }
    std::cout << "Choose discount: (1) Family (2) Bulk (3) Regular: ";
    int choice;
    std::cin >> choice;

    DiscountStrategy* strategy = nullptr;
    if (choice == 1) strategy = new FamilyDiscount();
    else if (choice == 2) strategy = new BulkDiscount();
    else strategy = new RegularPrice();

    PizzaOrder* order = new PizzaOrder(strategy);

    std::cout << "\n=== Discounted Prices ===\n";
    for (auto& p : pizzas) {
        cout << p->getName()<< " original Price: R"<<p->getPrice()<< endl;
        double price = order->useAlgorithm(p);
        std::cout << p->getName() << " discounted price: R" << price << "\n";
    }

    delete order;  // cleans strategy internally
}

// void simulateState() {
//     if (pizzas.empty()) {
//         std::cout << "Create a pizza first!\n";
//         return;
//     }

//     Pizza* target = pizzas.back(); // last created pizza
//     PizzaStateContext* context = new PizzaStateContext(target);

//     context->setState(new Ordered());
//     context->displayCurrentState();

//     context->request();  // InOven
//     context->displayCurrentState();

//     context->request();  // Plated
//     context->displayCurrentState();

//     context->request();  // Boxed
//     context->displayCurrentState();

//     delete context;
// }

// void notifyCustomers() {
//     mainMenu->notifyObservers("New pizza update available!");
//     specials->notifyObservers("Specials updated!");
// }

// void cleanup() {
//     for (auto pizza : pizzas) {
//         delete pizza; // finally delete the pizza
//     }
//     pizzas.clear();

//     delete mainMenu;
//     delete specials;
//     delete customer1;
//     delete customer2;
// }


// int main() {
//     mainMenu->addObserver(customer1);
//     mainMenu->addObserver(customer2);
//     specials->addObserver(customer1);
//     specials->addObserver(customer2);
//     generateGenericPizza();
//     int choice;
//     do {
//         std::cout << "\n=== Romeo's Pizza Admin Menu ===\n";
//         std::cout << "1. List Pizzas\n";
//         std::cout << "2. Create Pizza\n";
//         std::cout << "3. Apply Discount\n";
//         std::cout << "4. Simulate Pizza State\n";
//         std::cout << "5. Notify Customers\n";
//         std::cout << "0. Exit\n";
//         std::cout << "Choice: ";
//         std::cin >> choice;

//         switch (choice) {
//             case 1: listPizzas(); break;
//             case 2: createPizza(); break;
//             case 3: applyDiscount(); break;
//             case 4: simulateState(); break;
//             case 5: notifyCustomers(); break;
//             case 0: std::cout << "Exiting...\n"; break;
//             default: std::cout << "Invalid choice.\n";
//         }
//     } while (choice != 0);

//     cleanup();
//     return 0;
// }
