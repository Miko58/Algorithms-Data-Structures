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
};

int main() {
    List<int> *list = new List<int>();
    list->push_front(1);
    list->push_front(2);
    list->push_front(3);
    list->push_front(4);
    list->push_front(5);

    std::cout << "List size: " << list->size();
    std::cout << "\n\nList of all elements:\n"; 
    list->print();

    
    list->insert(6, 2); // This goes to position 3 after the insertion of 9
    list->insert(9, 0);
    list->insert(7, 7);
    std::cout << "\nThe list after inserting some elements:\n";
    list->print();

    list->remove(0);
    list->remove(4);
    list->remove(5);
    std::cout << "\nThe list after deleting some elements:\n";
    list->print();

    std::cout << "\nChecking if the data 5 is in the list: " << list->check(5);

    list->reverse();
    std::cout << "\n\nThe list is now reversed!:\n";
    list->print();

    delete list;

    return 0;
}