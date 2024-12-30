#include <iostream>
#include <vector>

template<typename Object>
class HashTable {
private:
    size_t capacity;
    size_t size; // number of elements in the table
    std::vector<std::vector<int>> hashtable;

    void resize() {
        // Double the capacity
        capacity *= 2;
        std::vector<std::vector<int>> newTable(capacity);

        // Rehash all existing elements into the new table
        for (size_t i = 0; i < hashtable.size(); i++) {
            for (auto& key : hashtable[i]) {
                int index = key % capacity;
                // Quadratic probing with wrapping
                for (int j = 0; j < capacity; j++) {
                    int probingIndex = (index + j * j) % capacity; // Wrap around
                    if (newTable[probingIndex].empty()) {
                        newTable[probingIndex].push_back(key);
                        break;
                    }
                }
            }
        }
        // Assign the new table to the hashtable
        hashtable = std::move(newTable);
    }

public:
    HashTable() : capacity(11), hashtable(capacity) {}

    int hashFunction(int key) {
        return (key % capacity);
    }

    void insert(Object key) {
        if (size >= 0.7 * capacity) {
            resize();  // Resize the table if the load factor exceeds 0.7
        }
        
        int index = hashFunction(key);

        // Quadradic probing with wrapping
        for (int i = 0; i < capacity; i++) {
            int probingIndex = (index + i * i) % capacity; // Wrap around
            if (hashtable[probingIndex].empty()) {
                hashtable[probingIndex].push_back(key);
                size++;
                return;
            }
        }
        std::cout << "Table is full, cannot insert item\n";
    }

    void deleteItem(Object key) {
        int index = hashFunction(key);

        // Search for the key
        for (int i = 0; i < capacity; i++) {
            int probingIndex = (index + i * i) % capacity; // Wrap around

            if (hashtable[probingIndex].empty()) {
                // Stop if an empty slot is found (key doesn't exist)
                return;
            }

            if (!hashtable[probingIndex].empty() && hashtable[probingIndex].front() == key) {
                // Found the key; remove it
                hashtable[probingIndex].clear();
                size--;
                return;
            }
        }
        // If we complete the loop, the key was not found
        std::cout << "Key not found in the table\n";
    }

    void print() {
        for (int i{}; i < capacity; i++) {
            std::cout << i;
            if (hashtable[i].empty()) {
                std::cout << " --> [empty]" << std::endl;
            } else {
                std::cout << " --> " << hashtable[i].front() << std::endl;
            }
        }
    }  
};

int main() {
    HashTable<int> ht;

    ht.insert(22); // Placed at 0 since empty
    ht.insert(5); // PLaced at 5 since empty
    ht.insert(16); // since 5 is full we go 5 + i^2 once which gives 6 
    ht.insert(27); // placed at 9 since we went through 5 + i^2 twice
    ht.print();

    std::cout << "\n\n";

    ht.insert(1); // placed at 1 since it was empty
    ht.insert(12); // placed at 2 since we went through 1 + i^2 once
    ht.insert(20); // placed at 10 since we went through 9 + i^2 once
    ht.insert(20457183); // Placed at 3 since we went through 10 + i^2 % cap twice

    ht.print();
}