#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class HashTable {
protected:
    size_t capacity = 7; 
    std::vector<std::vector<int>> table; 

public:
    HashTable() : table(capacity) {}
    virtual int hashFunction(int x) = 0;
    virtual void insertItem(int key) = 0;
    virtual void deleteItem(int key) = 0;
    virtual void print() = 0;
};

class Chaining : HashTable {
public:
    Chaining() : HashTable() {}

    int hashFunction(int x) {
        return (x % capacity);
    }

    void insertItem(int key) override {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void deleteItem(int key) override {
        int index = hashFunction(key);
        auto it = find(table[index].begin(), table[index].end(), key); 
        if (it != table[index].end()) {
            table[index].erase(it);
        }
    }

    void print() override {
        for (int i{}; i < capacity; i++) {
            std::cout << i;
            for (auto it = table[i].begin(); it != table[i].end(); it++) {
                std::cout << " --> " << *it;
            }
            std::cout << std::endl;
        }
    }
};

class LinearProbing :HashTable {
public:
    LinearProbing() : HashTable() {}

    int hashFunction(int x) {
        return (x % capacity);
    }

    void insertItem(int key) override {
        int index = hashFunction(key);

        // Linear probing with wrapping
        for (int i = 0; i < capacity; i++) {
            int probingIndex = (index + i) % capacity; // Wrap around
            if (table[probingIndex].empty()) {
                table[probingIndex].push_back(key);
                return;
            }
        }
        // If we complete the loop, the table is full
        std::cout << "Table is full, cannot insert item\n";
    }

    void deleteItem(int key) override {
        int index = hashFunction(key);

        // Search for the key using linear probing
        for (int i = 0; i < capacity; i++) {
            int probingIndex = (index + i) % capacity; // Wrap around the table

            if (table[probingIndex].empty()) {
                // Stop if an empty slot is found (key doesn't exist)
                return;
            }

            if (!table[probingIndex].empty() && table[probingIndex].front() == key) {
                // Found the key; remove it
                table[probingIndex].clear();
                return;
            }
        }
        // If we complete the loop, the key was not found
        std::cout << "Key not found in the table\n";
    }

    void print() override {
        for (int i{}; i < capacity; i++) {
            std::cout << i;
            if (table[i].empty()) continue;
            std::cout << " --> " << table[i].front() << std::endl;
        }
    }  
};

class QuadradicProbing : HashTable {
public:
    QuadradicProbing() : HashTable() {}

    int hashFunction(int x) {
        return (x % capacity);
    }

    void insertItem(int key) override {
        int index = hashFunction(key);

        // Quadratic probing with wrapping
        for (int i = 0; i < capacity; i++) {
            int probingIndex = (index + i * i) % capacity; // Wrap around
            if (table[probingIndex].empty()) {
                table[probingIndex].push_back(key);
                return;
            }
        }
        // If we complete the loop, the table is full
        std::cout << "Table is full, cannot insert item\n";
    }

    void deleteItem(int key) override {
        int index = hashFunction(key);

        // Search for the key using quadratic probing
        for (int i = 0; i < capacity; i++) {
            int probingIndex = (index + i * i) % capacity;  // Wrap around the table

            if (table[probingIndex].empty()) {
                // Stop if an empty slot is found (key doesn't exist)
                return;
            }

            if (!table[probingIndex].empty() && table[probingIndex].front() == key) {
                // Found the key; remove it
                table[probingIndex].clear();
                return;
            }
        }
        // If we complete the loop, the key was not found
        std::cout << "Key not found in the table\n";
    }

    void print() override {
        for (int i{}; i < capacity; i++) {
            std::cout << i;
            if (table[i].empty()) continue;
            std::cout << " --> " << table[i].front() << std::endl;
        }
    }  
};

int main() {
    Chaining HT;    
    // In this case, the load factor of chaining is 1.0, but it can exceed 1.0 because 
    // multiple elements can be stored at the same index using linked lists.

    HT.insertItem(5);
    HT.insertItem(28);
    HT.insertItem(19);
    HT.insertItem(15);
    HT.insertItem(20); 
    HT.insertItem(33);
    HT.insertItem(10);

    HT.print();

    std::cout << "\n\n";

    LinearProbing lpHT;
    // Linear probing reaches a load factor of 1.0 when the table is full, as demonstrated in this case. 
    // It fills sequential slots in the table, which can lead to primary clustering and longer search times 
    // as the load factor approaches 1.0.

    lpHT.insertItem(5); // place 5
    lpHT.insertItem(28); // place 0
    lpHT.insertItem(19); // place 5->6
    lpHT.insertItem(15); // place 1
    lpHT.insertItem(20); // place 6->0->1->2
    lpHT.insertItem(33); // place 5->6->0->1->2->3
    lpHT.insertItem(10); // place3->4

    lpHT.print();

    std::cout << "\n\n";

    QuadradicProbing qpHT;
    // Quadratic probling reaches 1.0 when the table is full hust like in this case. 
    // Unlike linear probing, it effectively reduces primary clustering by using a non-linear probing sequence. 
    // However, it cannot completely eliminate secondary clustering, as elements with the same hash value still 
    // follow the same quadratic probe pattern.

    qpHT.insertItem(5);
    qpHT.insertItem(28);
    qpHT.insertItem(19);
    qpHT.insertItem(15);
    qpHT.insertItem(20);
    qpHT.insertItem(33);
    qpHT.insertItem(10);

    qpHT.print();
}