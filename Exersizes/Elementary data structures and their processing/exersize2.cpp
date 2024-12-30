#include <iostream>

template<typename Object>
class Stack {
  private:
	Object * array;
	size_t capacity;
	size_t currentSize;

  public:
	Stack() {
		capacity = 100;
		array = new Object[capacity];
		currentSize = 0;
	}
	Stack(size_t cap) {
		capacity = cap;
		array = new Object[capacity];
		currentSize = 0; 
	}

	~Stack() { delete[] array; }

	bool empty() { return currentSize == 0; }

    size_t size() { return currentSize; } 

    Object top() { return array[currentSize - 1]; }


    // Pushes a new value onto the stack
    void push(int value) {
        if (currentSize == capacity) {
            Object *newArray = new Object[2 * capacity];

            // copy old elements to the new array
            for (int i = 0; i < currentSize; i++) {
                newArray[i] = array[i];
            }

            delete []array;
            array = newArray;
            capacity = 2 * capacity;
        }
        array[currentSize++] = value;
    }

    // Pops the top element
    Object pop() {
        if (currentSize > 0) {
            return array[--currentSize];
        } else {
            std::cerr << "Stack is empty!" << std::endl;
            return -1;
        }
    }

    // Prints all elements given (not the 0's)
    void print() {
        for (int i = 0; i < currentSize; i++) {
            std::cout << array[i] << std::endl;
        }
    }
};

int main() {
    Stack<int> stack;
    
    for (int i = 1; i <= 10; i++) {
        stack.push(i);
    }
    
    std::cout << "The stack:\n";
    stack.print();

    std::cout << "Popped element: " << stack.pop() << std::endl;
    std::cout << "The size of the stack: " << stack.size();
    std::cout << "\nThe next element in line to be popped: " << stack.top();

    return 0;
}
