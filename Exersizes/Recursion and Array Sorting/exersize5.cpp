#include <iostream>
#include <cassert>

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

     // Helper function to perform recursion with index
    int search(const Object& x, Node* p, int index) const {
        if (p == tail) {
            return -1;  // Base case: Reached the end of the list, element not found
        }
        if (x == p->data) {
            return index;  // Found the element, return its index
        }
        return search(x, p->next, index + 1);  // Recurse with the next node and increment the index
    }

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

    // Search function using recursion
    int search(const Object x) {
        return search(x, head->next, 0);
    }
};

int main() {
    List<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    list.push_front(5);

    std::cout << "\nList of all elements:\n";
    list.print();

    // Test search function
    int result = list.search(3);
    std::cout << "Search result for 3: " << result << std::endl;  // Should return the index of 3

    result = list.search(6);  // Not in the list
    std::cout << "Search result for 6: " << result << std::endl;  // Should return -1

    return 0;
}