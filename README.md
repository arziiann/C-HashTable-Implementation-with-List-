# HashTable C++ Implementation

This project is a simple implementation of a hash table in C++, utilizing **chaining** for collision resolution. The hash table uses **`std::list`** to store multiple key-value pairs that hash to the same index in the table. This is just one approach to resolving collisions; other common methods include open addressing and double hashing. This project demonstrates basic hash table operations, including inserting, removing, and searching for elements, as well as checking if the table is empty and printing its contents.

## Features

- **Insert** key-value pairs into the table.
- **Search** for values by their associated key.
- **Remove** key-value pairs from the table.
- **Print** the entire hash table.
- **Check** if the hash table is empty.
- **Collision resolution** through chaining with `std::list`.

## Files

- **`main.cpp`**: Contains the main implementation and testing code for the HashTable.
- **`HashTable.hpp`**: Header file that defines the HashTable class and its public methods.
- **`HashTable.cpp`**: Contains the implementation of the HashTable class's functions.

## Data Structure

The hash table uses an **array of linked lists** (separate chaining) for collision resolution. Each index in the array holds a `std::list` that stores multiple key-value pairs in case two or more keys hash to the same index. This is a **dynamic and flexible approach**, but other approaches, such as **open addressing**, **linear probing**, or **double hashing**, could also be used for collision resolution.

## Compilation and Running

### Clone the Repository

To clone this project, run the following command in your terminal:

```bash
git clone https://github.com/arziiann/Cpp-HashTable-Implementation-with-List.git
```

### Build the Project

Navigate to the project directory:

```bash
cd hashtable
```

Now compile the program using `g++`:

```bash
g++ -o hashtable main.cpp HashTable.cpp
```

### Run the Program

Once compiled, you can run the program with the following command:

```bash
./hashtable
```

### Example Output

```
The hash table is empty.
Hash Table after inserting elements:
Key: 905  Value: John
Key: 201  Value: Jane
Key: 303  Value: Bob
Key: 405  Value: Alice
Key: 999  Value: Eve

Search result for key 201: Jane

Hash Table after removing key 405:
Key: 905  Value: John
Key: 201  Value: Jane
Key: 303  Value: Bob
Key: 999  Value: Eve

The hash table is not empty.
```

## How it Works

The hash table is implemented using an array of linked lists (separate chaining) to handle collisions. Each key is hashed using the modulo operation to determine its index in the array. If two keys hash to the same index, the key-value pairs are stored in a linked list at that index.

- **Chaining with `std::list`**: Each index in the hash table stores a `std::list` that can hold multiple key-value pairs, making the hash table flexible and scalable in handling collisions.
- **Insert Operation**: The key is hashed, and the value is inserted into the corresponding list at that index.
- **Remove Operation**: The key is hashed, and the key-value pair is removed from the corresponding list at that index.
- **Search Operation**: The key is hashed, and the corresponding list is searched for the key. If the key exists, the associated value is returned.
- **Print Operation**: The entire hash table is printed, showing all key-value pairs.

### Collision Resolution Techniques

This hash table uses **separate chaining** (with linked lists) for collision resolution. Other approaches could be used, such as:

- **Open Addressing**: In this approach, when a collision occurs, the algorithm looks for the next available slot in the array.
- **Linear Probing**: This is a type of open addressing where the next available slot is searched for sequentially.
- **Double Hashing**: A more advanced technique where a second hash function is used when a collision occurs.

This project implements a simpler, more intuitive approach (separate chaining) using `std::list` to resolve collisions.
