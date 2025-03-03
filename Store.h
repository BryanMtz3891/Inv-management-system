#ifndef STORE_H
#define STORE_H

#include "Product.h"
#include <vector>

template <typename T>
class Store {
private:
    Product<T>* inventory;
    int numProducts;
    int capacity;

    void resize();

public:
    Store();
    ~Store();

    void addProduct(const Product<T>& product);
    void printInventory() const;
};

// Constructor
template <typename T>
Store<T>::Store() : numProducts(0), capacity(10) {
    inventory = new Product<T>[capacity];
}

// Destructor
template <typename T>
Store<T>::~Store() {
    delete[] inventory;
}

// Resize the inventory array
template <typename T>
void Store<T>::resize() {
    capacity *= 2;
    Product<T>* newInventory = new Product<T>[capacity];
    for (int i = 0; i < numProducts; ++i) {
        newInventory[i] = inventory[i];
    }
    delete[] inventory;
    inventory = newInventory;
}

// Add a product to the inventory
template <typename T>
void Store<T>::addProduct(const Product<T>& product) {
    if (numProducts == capacity) {
        resize();
    }
    inventory[numProducts++] = product;
}

// Print the inventory
template <typename T>
void Store<T>::printInventory() const {
    for (int i = 0; i < numProducts; ++i) {
        std::cout << inventory[i];
    }
}

#endif
