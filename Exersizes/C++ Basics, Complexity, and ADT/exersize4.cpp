#include <vector>
#include <iostream>
#include <list>

class MaxHeap
{
    public:
    //is the heap empty?
    virtual bool isEmpty() const = 0;

    //number of elements in the heap
    virtual int size() = 0;

    //add an element to the heap
    virtual void insert(const int x) = 0;

    //find the maximum element in the heap
    virtual const int findMax() const = 0;

    // delete and return the maximum element of the heap
    virtual int deleteMax() = 0;
};

class MaxHeap1 : public MaxHeap {
    private:
        std::vector<int> heap;
        
    public:
        bool isEmpty() const override {
            return heap.empty();
        }

        int size() override {
            return heap.size();
        }

        void insert(const int x) override {
            heap.push_back(x);
            int index = size() - 1;

            // Heapify up
            while(index > 0) {
                int parent = (index - 1) / 2;
                if (heap[index] > heap[parent]) {  
                    std::swap(heap[index], heap[parent]); 
                    index = parent;
                } else {
                    break;
                }
            }
        }

        const int findMax() const override {
            return heap[0];
        }

        int deleteMax() override {
            int maxElement = heap[0];
            heap[0] = heap.back();
            heap.pop_back();

            // Heapify down
            int index = 0;
            while (true) {
                int left = 2 * index + 1;
                int right = 2 * index + 2;
                int largest = index;

                if(left < size() && heap[left] > heap[largest]) {
                    largest = left; 
                }
                if (right < size() && heap[right] > heap[largest]) {
                    largest = right; 
                }

                if (largest != index) {
                    std::swap(heap[index], heap[largest]);
                    index = largest;
                } else {break;}
            }
            
            return maxElement;  
        }
};

class MaxHeapList : MaxHeap {
    private:
        std::list<int> heap;
        
    public:
        bool isEmpty() const override {
            return heap.empty();
        }

        int size() override {
            return heap.size();
        }

        void insert(const int x) override {
            heap.push_back(x);
            auto it = std::prev(heap.end());

            // Heapify up
            while(it != heap.begin()) {
                auto parent = std::prev(it);
                if (*it > *parent) {  
                    std::swap(*it, *parent); 
                    it = parent; 
                } else {
                    break;
                }
            }
        }

        const int findMax() const override {
            return heap.front();
        }

        int deleteMax() override {
            if (heap.empty()) {
                throw std::out_of_range("Heap is empty.");
            }
            int maxElement = heap.front();     
            heap.front() = heap.back();
            heap.pop_back();

            // Heapify down
            auto it = heap.begin();
            while (1) {
                auto left = std::next(it);
                auto right = std::next(left);
                auto largest = it;

                if (left != heap.end() && *left > *largest) {
                    largest = left; 
                }
                if (right != heap.end() && *right > *largest) {
                    largest = right; 
                }

                if (largest != it) {
                    std::swap(*it, *largest);
                    it = largest; 
                } else {break;}

                // If no child exists or both children are smaller, we break out
                if (left == heap.end() || right == heap.end()) {
                    break;
                }
            }
            
            return maxElement;  
        }
};

int main() {
    MaxHeap1 heap;

    std::cout << "Inserting elements into the heap:\n";
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(30);
    heap.insert(15);
    heap.insert(12);
    heap.insert(28);
    
    std::cout << "The max element after insertions: " << heap.findMax() << std::endl;
    std::cout << "Heap size after insertions: " << heap.size() << std::endl;

    std::cout << "\nDeleting the max element:" << std::endl;
    std::cout << "Deleted max: " << heap.deleteMax() << std::endl;
    std::cout << "New max element: " << heap.findMax() << std::endl;
    std::cout << "Heap size after deletion: " << heap.size() << std::endl;

    std::cout << "\nDeleting the max element again:" << std::endl;
    std::cout << "Deleted max: " << heap.deleteMax() << std::endl;
    std::cout << "New max element: " << heap.findMax() << std::endl;
    std::cout << "Heap size after second deletion: " << heap.size() << std::endl;

    std::cout << "\nInserting more elements into the heap:" << std::endl;
    heap.insert(25);
    heap.insert(35);
    heap.insert(40);

    std::cout << "Max element after more insertions: " << heap.findMax() << std::endl;
    std::cout << "Heap size after more insertions: " << heap.size() << std::endl;

    std::cout << "\n\n\n";

    MaxHeapList heaplist;

    std::cout << "Inserting elements into the heap using LIST:\n";
    heaplist.insert(10);
    heaplist.insert(20);
    heaplist.insert(5);
    heaplist.insert(30);
    heaplist.insert(15);
    heaplist.insert(12);
    heaplist.insert(28);
    
    std::cout << "Max element after insertions: " << heaplist.findMax() << std::endl;
    std::cout << "Heap size after insertions: " << heaplist.size() << std::endl;

    std::cout << "\nDeleting the max element:\n";
    std::cout << "Deleted max: " << heaplist.deleteMax() << std::endl;
    std::cout << "New max element: " << heaplist.findMax() << std::endl;
    std::cout << "Heap size after deletion: " << heaplist.size() << std::endl;

    std::cout << "\nDeleting the max element again:\n";
    std::cout << "Deleted max: " << heaplist.deleteMax() << std::endl;
    std::cout << "New max element: " << heaplist.findMax() << std::endl;
    std::cout << "Heap size after second deletion: " << heaplist.size() << std::endl;

    std::cout << "\nInserting more elements into the heap:\n";
    heaplist.insert(25);
    heaplist.insert(35);
    heaplist.insert(40);

    std::cout << "Max element after more insertions: " << heaplist.findMax() << std::endl;
    std::cout << "Heap size after more insertions: " << heaplist.size() << std::endl;

    return 0; 
}


/*
The isEmpty() function has a time complexity of O(1) because 
it simply checks if the heap is empty, which is done in constant time.

The size() function also has a time complexity of O(1) aswell, beacuse it returns the
size of the heap, which is stored and can be accessed in constant time.

The insert(X) function has a time complexity of O(log n), because it requires 
"heapifying up", which takes O(log n) in the worst case.

The findMax function has a time complexity of O(1) because 
the maximum element is at the root (index 0), so it can be accessed in constant time.

The deleteMax() function has a time complexity of O(log n) for a similar reason to 
insert(x). Removing the maximum element involves replacing it with the 
last element (O(1)), followed by "heapifying down," which takes O(log n) time.
*/