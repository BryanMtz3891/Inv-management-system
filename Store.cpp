#include "Store.h"
#include <iostream>

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
