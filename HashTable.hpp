#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <list>
#include <string>
#include <utility> 

// The HashTable class uses separate chaining (linked lists) to handle collisions
class HashTable {
public:
    // Constructor and Destructor
    HashTable();  // Constructor to initialize the hash table
    ~HashTable(); // Destructor to clean up any dynamically allocated resources if needed

    // Member functions
    int hashFunction(int key); // Hash function to map keys to indices in the table
    void insertItem(int key, const std::string& value); // Insert a key-value pair
    bool isEmpty() const; // Check if the table is empty
    void removeItem(int key); // Remove a key-value pair by key
    std::string searchTable(int key); // Search for a value by key
    void printTable() const; // Print all key-value pairs in the table

private:
    static const int HashGroup = 10; // Defines the number of buckets (linked lists) in the hash table
    std::list<std::pair<int, std::string>> table[HashGroup]; // Array of linked lists to handle collisions
};

// Constructor definition
HashTable::HashTable() {
    // You can initialize anything here if needed
}

// Destructor definition (optional in this case, as we are not dynamically allocating memory)
HashTable::~HashTable() {
    // Clean up code can be added here if dynamic memory is used
}

// Check if the hash table is empty
bool HashTable::isEmpty() const {
    int sum = 0;
    for (int i = 0; i < HashGroup; ++i) {
        sum += table[i].size(); // Summing the sizes of all linked lists
    }
    return sum == 0; // Return true if all lists are empty
}

// Hash function to map keys to an index
int HashTable::hashFunction(int key) {
    return key % HashGroup; // Modulo operation to distribute keys across the hash table
}

// Insert a key-value pair into the table
void HashTable::insertItem(int key, const std::string& value) {
    int hashValue = hashFunction(key); // Find the appropriate index for the key
    auto& cell = table[hashValue]; // Get the corresponding linked list
    auto beginIter = begin(cell); 
    bool keyExist = false;

    // Check if the key already exists in the linked list
    for (; beginIter != end(cell); ++beginIter) {
        if (beginIter->first == key) { // If key exists, update the value
            keyExist = true;
            beginIter->second = value; // Update the value for the existing key
            std::cout << "[WARNING] Key already exists. Value updated." << std::endl;
            break;
        }
    }

    // If the key does not exist, insert a new key-value pair at the end of the list
    if (!keyExist) {
        cell.emplace_back(key, value);
    }
}

// Remove a key-value pair from the table
void HashTable::removeItem(int key) {
    int hashValue = hashFunction(key); // Find the appropriate index
    auto& cell = table[hashValue]; // Get the corresponding linked list
    auto beginIter = begin(cell);
    bool keyExist = false;

    // Traverse the linked list to find and remove the key-value pair
    for (; beginIter != end(cell); ++beginIter) {
        if (beginIter->first == key) { // If key is found, remove the pair
            keyExist = true;
            beginIter = cell.erase(beginIter); // Erase the element
            std::cout << "[INFO] Pair removed." << std::endl;
            break;
        }
    }

    // If the key does not exist, print a warning
    if (!keyExist) {
        std::cout << "[WARNING] Key not found." << std::endl;
    }
}

// Print all key-value pairs in the hash table
void HashTable::printTable() const {
    for (int i = 0; i < HashGroup; ++i) {
        if (table[i].size() == 0) continue; // Skip empty lists

        // Print all pairs in the current linked list
        auto beginIter = table[i].begin();
        for (; beginIter != table[i].end(); ++beginIter) {
            std::cout << "Key: " << beginIter->first << "  Value: " << beginIter->second << std::endl;
        }
    }
}

// Search for a value by key in the table
std::string HashTable::searchTable(int key) {
    int hashValue = hashFunction(key); // Find the appropriate index
    auto& cell = table[hashValue]; // Get the corresponding linked list
    auto beginIter = begin(cell);

    // Traverse the linked list to find the value for the given key
    for (; beginIter != end(cell); ++beginIter) {
        if (beginIter->first == key) {
            return beginIter->second;  // Return the value if the key is found
        }
    }

    // Return an empty string if the key is not found
    return "";
}

#endif // HASHTABLE_HPP
