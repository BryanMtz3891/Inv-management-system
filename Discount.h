#ifndef DISCOUNT_H
#define DISCOUNT_H

#include "Product.h"

template <typename T>
void applyDiscount(Product<T>& p, double percentage) {
    T discount = p.getPrice() * (percentage / 100.0);
    p.setPrice(p.getPrice() - discount);
}

#endif
