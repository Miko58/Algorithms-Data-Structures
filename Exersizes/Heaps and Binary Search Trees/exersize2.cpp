#include <queue>
#include <iostream>

using namespace std;

template<typename T>
struct Node {
    T data;
    Node* parent;
    Node* left;
    Node* right;

    // constructor
    Node(T value) {
        data = value;
        left = right = nullptr;
    }
};

template<typename T>
class MinHeap
{
private:
    Node<T> *root;
    int nodeCount;

public:
	void insert(const T& x) 
	{
        Node<T>* newNode = new Node<T>(x);
        if (!root) root = newNode;
        else {
            std::queue<Node<T>*> traversalQueue;
            traversalQueue.push(root);

            while (!traversalQueue.empty()) {
                Node<T>* tempNode = traversalQueue.front();
                traversalQueue.pop();

                if (tempNode->left == nullptr) {
                    tempNode->left = newNode;
                    newNode->parent = tempNode;
                    break;
                }
                if (tempNode->right == nullptr) {
                    tempNode->right = newNode;
                    newNode->parent = tempNode;
                    break;
                }          
                else {
                    traversalQueue.push(tempNode->left);
                    traversalQueue.push(tempNode->right);
                }
            }

            // Adjust heap structure after insertion
            shiftUp(newNode);
        }
        ++nodeCount; 
	}
    
    void shiftUp(Node<T>* node) {
        while (node->parent && node->data < node->parent->data) {
            std::swap(node->data, node->parent->data);
            node = node->parent;
        }
    }

    void shiftDown(Node<T>* node) {
        while (node) {
            Node<T>* smallest = node;

            // Check if left child exists and is smaller
            if (node->left && node->left->data < smallest->data) {
                smallest = node->left;
            }

            // Check if right child exists and is smaller
            if (node->right && node->right->data < smallest->data) {
                smallest = node->right;
            }

            // If the smallest node is the current node, the heap property is restored
            if (smallest == node) break;

            // Swap data with the smallest child and continue
            std::swap(node->data, smallest->data);
            node = smallest;
        }
    }


    void remove() 
	{
        if (isEmpty()) {
         throw std::runtime_error("Heap is empty");
        }
        if (nodeCount == 1) {
            delete root;
            root = nullptr;
        }
        else {
            std::queue<Node<T>*> traversalQueue;
            traversalQueue.push(root);

            Node<T>* lastNode = nullptr;

            while (!traversalQueue.empty()) {
                lastNode = traversalQueue.front();
                traversalQueue.pop();

                if (lastNode->left) traversalQueue.push(lastNode->left);
                if (lastNode->right) traversalQueue.push(lastNode->right);             
            }
            root->data = lastNode->data;
            if (lastNode->parent) {
                if (lastNode->parent->left == lastNode) {
                    lastNode->parent->left = nullptr;
                } else if (lastNode->parent->right == lastNode) {
                    lastNode->parent->right = nullptr;
                }
            }


            delete lastNode;
            shiftDown(root);
        }
        --nodeCount; 
	}
    
    bool isEmpty() const
	{
		return nodeCount == 0;
	}
    
    T peek()
	{
		if (isEmpty()) {
            throw runtime_error("Heap is empty.");
        }
        return root->data;
	}
};


int main() {
    MinHeap<int> bt;

    bt.insert(3);
    bt.insert(23);
    bt.insert(67);
    bt.insert(12);
    bt.insert(23);
    bt.insert(324);
    bt.insert(45);

    std::cout << bt.peek() << std::endl;
    bt.remove();
    std::cout << bt.peek() << std::endl;
    bt.remove();
    std::cout << bt.peek() << std::endl;
    bt.remove();
    std::cout << bt.peek() << std::endl;
    bt.remove();
    std::cout << bt.peek() << std::endl;
    bt.remove();
    std::cout << bt.peek() << std::endl;
    bt.remove();
    std::cout << bt.peek() << std::endl;

    return 0;
}