#include <iostream>

#include <iostream>
#include <cassert>


// We will be using list from a previous exersize to implement a set
template<typename Object>
class List {
private:
    struct Node{
        Object data; 
        Node *next;
    };
    int theSize;  
    Node *head;  
    Node *tail; 

public:
    List() {
        theSize = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->next = nullptr;
    }

    ~List() {
        clear();
        delete head;
        delete tail;
    }

    int size() const {
	    return theSize; 
    }

    // Clears the list by deleting all nodes
    void clear() {
        Node *p = head->next;
        while (p != tail) {
            Node *t = p->next;
            delete p;
            p = t;
            head->next = t;
        }
    }

    // Insert a value to the start
    void push_front(Object x) {
        Node *p = new Node;
        p->data = x;
        p->next = head->next;
        head->next = p;
        theSize++;
    }

    // Insertion at the beginning, middle (given a position), and end of the list.
    void insert(Object value, int position) {
        assert(position >= 0 && position <= theSize);
        Node *p = head;
        for(int i = 0; i < position; i++) {
            p = p->next;
        }
        Node *q = new Node;
        q->data = value;
        q->next = p->next;
        p->next = q;
        theSize++; 
    }

    // Deletion of an element from the beginning, middle (given a position), and end of the list.
    void remove(int position) {
        assert(position >= 0 && position <= theSize);
        Node *p = head;
        for(int i = 0; i < position; i++) {
            p = p->next;
        }
        Node *q = p->next;
        p->next = q->next;
        delete q;
        theSize--;
    }

    // Check if a given element exists in the list.
    bool check(Object value) {
        Node *p = head->next;
        while(p != tail) {
            if(p->data == value) {
                return true;
            }
            p = p->next;
        }
        return false;
    }

    // Traverse the list to print all elements.
    void print() const {
        Node *p = head->next;
        while(p != tail) {
            std::cout << p->data << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }

    // Reverse the order of the list
    void reverse() {
        Node *prev = nullptr;
        Node *current = head->next;
        Node *next = nullptr;
        while (current != tail) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next; 
        }
        head->next = prev; 
    }
    
    // We will be adding a functio that retrieves the value of the node at a specific position.
    // This will be used to find the position of an element in the class Set to propperly use remove()
    int find_kth(int pos) {
        assert(pos >= 0 && pos < theSize);
        Node *p = head->next;
        while (pos > 0) {
            p = p->next;
            pos--;
        }
        return p->data;
    }
};


// Set implementation
template<typename Object>
class Set {
private:
    List<Object> *elements;

    // Finding the position to use remove()
	int find_pos(int x){
		int found = -1;
		for (int i = 0; i < elements->size(); i++){
			int it = elements->find_kth(i);
			if (it == x){
				found = i;
				break;
			}
		}
		return found;
	}

public:
    Set() : elements(new List<Object>()) {}
    ~Set() { delete elements; }

    bool add(Object value) {
        if (!elements->check(value)) {
            elements->push_front(value);
            return true;
        }
        return false;
    }

    bool remove(const Object& value) {
        int pos = find_pos(value); 
        if (pos != -1) {
            elements->remove(pos); // Remove the element at the found position
            return true;
        }
        return false;
    }

    bool contains(const Object& value) {
        return elements->check(value);
    }

    void print() {
        std::cout << "Set elements:\n";
        elements->print();
    }
};

int main() {
    Set<int> set1;

    set1.add(12);
    set1.add(12); // Dublicate wont be added
    set1.add(34);
    set1.add(26);
    set1.add(35);
    set1.add(34); // Dublicate

    set1.print();

    set1.remove(12);

    set1.print();

    std::cout << "Does the set contain 10?: " << set1.contains(10) << std::endl;
    std::cout << "Does the set contain 26?: " << set1.contains(26) << std::endl;

    return 0;
}