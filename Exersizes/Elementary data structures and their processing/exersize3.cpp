#include <iostream>
#include <cassert>

// Stack class from exersize 2
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
    int pop() {
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

template <typename Object>
class Queue {
  private:
    Stack<Object> *queue1; // holds the stack elements 
    Stack<Object> *queue2; // holds the popped elements of queue1 
  public:
	Queue() { 
        queue1 = new Stack<Object>(); 
        queue2 = new Stack<Object>(); 
    }

	~Queue() { delete queue1; delete queue2; }
    bool empty() { return queue1->empty() && queue2->empty(); }

    // Transform by popping from queue1 and pushing to queue2
    void transformStackToQueue() {
		if (queue2->empty()){
			while (!queue1->empty()){
				queue2->push(queue1->pop());
			}
		}
    }

    Object front() {
		assert(!empty());
		transformStackToQueue();
		assert(!queue2->empty());
		return queue2->top(); 
	};

    // Push new values to the queue
    void push(const Object& value) {
        queue1->push(value);
    }

    Object pop() {
        if (queue2->empty()) {
            transformStackToQueue();
        }

        if (!queue2->empty()) {
            return queue2->pop();
        } else {
            std::cerr << "Queue is empty!" << std::endl;
            return 0;
        }
    }

    void print() {
        // First, print elements in queue2 (already popped from queue1)
        for (int i = queue2->size() - 1; i >= 0; i--) {
            std::cout << queue2->top() << std::endl;
            queue2->pop();
        }
        // Then, print elements in queue1 in their order of insertion
        queue1->print();
    }
};

int main() {
    Queue<int> queue;

    queue.push(10);
    queue.push(20);
    queue.push(30);

    std::cout << "Queue contents:\n";
    queue.print();

    std::cout << "Front element: " << queue.front() << std::endl;
    std::cout << "Popped element: " << queue.pop() << std::endl;

    std::cout << "Queue content after popped element:\n";
    queue.print();

    return 0;
}