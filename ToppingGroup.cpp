#include "ToppingGroup.h"

ToppingGroup::ToppingGroup(std::string name, double price)
    : PizzaComponent(name, price) {}

void ToppingGroup::add(PizzaComponent* component) {
    toppings.push_back(component);
}

std::string ToppingGroup::getName() {
    std::ostringstream os; //using ostream print required screen
    os << name << " (";
    for (int i = 0; i < (int)toppings.size(); ++i) {
        os << toppings[i]->getName();
        if (i < (int)toppings.size() - 1) os << ", ";
    }
    os << ")";
    return os.str();
}

double ToppingGroup::getPrice() {
    double total = price;
    for (auto* t : toppings) {
        total += t->getPrice();
    }
    return total;
}

ToppingGroup::~ToppingGroup() {
    for (auto* t : toppings) {
        delete t; //if anonymous clear
    }
}
