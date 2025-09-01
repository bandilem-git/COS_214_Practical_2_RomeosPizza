#include "FamilyDiscount.h"

double FamilyDiscount::applyDiscount(Pizza* pizza){ // returns amount post discount
    double discountedAmount = -1;
    if (pizza != nullptr){
        std::cout << "FamilyDiscount strategy being used" << std::endl;
        double price = pizza->getPrice();
        discountedAmount = price * (1 - discount);
    }
    return discountedAmount;
}