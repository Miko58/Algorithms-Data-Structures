#include <iostream>
#include <vector>
#include <utility> // for std::pair

template<typename Object>
class Dictionary {
private: 
    std::vector<std::pair<int, Object>> *dictionary; 
    size_t capacity;

    int find_pos(int key) {
	    int pos = 0;
        for (auto it = dictionary->begin(); it != dictionary->end(); it++){
            if (key == it->first) {
                return pos;
            }
            pos++;
        }
		return -1;
    }

public:
    Dictionary() {
        capacity = 100;
        dictionary = new std::vector<std::pair<int,Object>>(capacity);
    }

    void add(int key, Object value) {
        int pos = find_pos(key);
        auto newpair = std::pair<int,Object>(key, value);
        if (pos < 0) { // key doesnt exist
            dictionary->push_back(newpair);
        } else{
            dictionary->at(pos) = newpair; // changing the value of the already existing key
        }
    }

    void remove(int key) {
        int pos = find_pos(key);
        if (pos < 0) { // key doesnt exist
            std::cout << "[WARNING] The key doesn't exist\n";
        } else{
            dictionary->erase(dictionary->begin() + pos);
        }
    }

	bool contains(int key){
		int pos = find_pos(key);
		return (pos >= 0);
	}

    void print() {
        std::cout << "Elements of the dictionary:\n";
        for(auto it = dictionary->begin(); it != dictionary->end(); it++) {
            if (it->second != Object()) { // check if it isnt empty
                std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
            }
        }
    }
};

int main() {
    Dictionary<std::string> dict;

    dict.add(1,"Bob"); 
    dict.add(2,"Carsten"); 
    dict.add(3,"Camilla"); 
    dict.add(4,"Putin");
    dict.add(2,"Michael");

    dict.print();

    dict.remove(4);
    dict.remove(6); // nonexisting key

    dict.print();

    std::cout << "Does the dictionary contain the key 3?: " << dict.contains(3) << std::endl;
    std::cout << "Does the dictionary contain the key 4?: " << dict.contains(4) << std::endl;

    return 0;
}