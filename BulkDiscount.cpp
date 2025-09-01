#include "BulkDiscount.h"

double BulkDiscount::applyDiscount(Pizza *pizza)
{ // returns amount post discount
    double discountedAmount = -1;
    if (pizza != nullptr)
    {
        std::cout << "BulkDiscount strategy being used" << std::endl;
        double price = pizza->getPrice();
        discountedAmount = price * (1 - discount);
    }
    return discountedAmount;
}