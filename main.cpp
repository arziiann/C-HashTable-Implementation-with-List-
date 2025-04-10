#include <iostream>

#include "HashTable.hpp"

int main() {
    // Create a HashTable object
    HashTable hashTable;

    // Check if the hash table is empty
    if (hashTable.isEmpty()) {
        std::cout << "The hash table is empty." << std::endl;
    } else {
        std::cout << "The hash table is not empty." << std::endl;
    }

    // Insert elements into the hash table
    hashTable.insertItem(905, "John");
    hashTable.insertItem(201, "Jane");
    hashTable.insertItem(303, "Bob");
    hashTable.insertItem(405, "Alice");
    hashTable.insertItem(999, "Eve");

    // Print the hash table after insertion
    std::cout << "\nHash Table after inserting elements:" << std::endl;
    hashTable.printTable();

    // Search for a value with a specific key
    std::string value = hashTable.searchTable(201);
    if (!value.empty()) {
        std::cout << "\nSearch result for key 201: " << value << std::endl;
    } else {
        std::cout << "\nKey 201 not found!" << std::endl;
    }

    // Remove an item by key
    hashTable.removeItem(405);
    std::cout << "\nHash Table after removing key 405:" << std::endl;
    hashTable.printTable();

    // Check if the hash table is empty again
    if (hashTable.isEmpty()) {
        std::cout << "The hash table is empty." << std::endl;
    } else {
        std::cout << "The hash table is not empty." << std::endl;
    }

    return 0;
}
