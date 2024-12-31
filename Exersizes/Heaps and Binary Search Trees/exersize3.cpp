#include "exersize2.cpp"

template<class T>
class PriorityQueue
{
private:
    MinHeap<T> heap;
public:
	void push(const T& x) {
        heap.insert(x); 
    }
	void pop() {
        heap.remove();
    }
	T top() {
        return heap.peek();
    }

	bool empty() {
        return heap.isEmpty();
    }
};

int main() {
    PriorityQueue<int> heap;

    heap.push(3);
    heap.push(23);
    heap.push(67);
    heap.push(12);
    heap.push(23);
    heap.push(324);
    heap.push(45);

    std::cout << heap.top() << std::endl;
    heap.pop();
    std::cout << heap.top() << std::endl;
    heap.pop();
    std::cout << heap.top() << std::endl;
    heap.pop();
    std::cout << heap.top() << std::endl;
    heap.pop();
    std::cout << heap.top() << std::endl;
    heap.pop();
    std::cout << heap.top() << std::endl;
    heap.pop();
    std::cout << heap.top() << std::endl;

    return 0;
}
