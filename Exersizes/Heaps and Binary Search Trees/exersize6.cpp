#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template<typename Comparable>
class BinarySearchTree {
  private:
	struct BinaryNode {
		Comparable element;
		BinaryNode *left;
		BinaryNode *right;
		BinaryNode *parent;

		BinaryNode(const Comparable& theElement, BinaryNode* lt, BinaryNode* rt, BinaryNode* p) :
			element {theElement}, left {lt}, right {rt}, parent(p) { }
	};

	BinaryNode *root;

	/**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
	BinaryNode *insert(const Comparable& x, BinaryNode* &t, BinaryNode* parent) {
		if (t == nullptr) {
			t = new BinaryNode{x, nullptr, nullptr, parent};
			return t;
		} else {
			if (x < t->element)
				return insert(x, t->left, t);
			else if (t->element < x)
				return insert(x, t->right, t);
			else {
				return t;
			}
		}
	}

	/**
     * Internal method to remove from a subtree.
     * x is the item to remove.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
	void remove(const Comparable& x, BinaryNode* &t) {
		if (t == nullptr)
			return;				// Item not found; do nothing
		if (x < t->element)
			remove(x, t->left);
		else if (t->element < x)
			remove(x, t->right);
		else if (t->left != nullptr && t->right != nullptr)	// Two children
		{
			t->element = findMin(t->right)->element;
			remove(t->element, t->right);
		} else {
			BinaryNode* oldNode = t;
			BinaryNode *p = t->parent;
			if (t->left != nullptr) {
				t = t->left;
			} else {
				t = t->right;
			}
			if (t != nullptr)
				t->parent = p;
			delete oldNode;
		}
	}

	/**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     */
	BinaryNode *findMin(BinaryNode* t) const {
		if (t == nullptr)
			return nullptr;
		if (t->left == nullptr)
			return t;
		return findMin(t->left);
	}

	/**
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item.
     */
	BinaryNode *findMax(BinaryNode* t) const {
		if (t != nullptr)
			while (t->right != nullptr)
				t = t->right;
		return t;
	}

	/**
     * Internal method to test if an item is in a subtree.
     * x is item to search for.
     * t is the node that roots the subtree.
     */
	BinaryNode *contains(const Comparable& x, BinaryNode* t) const {
		if (t == nullptr)
			return nullptr;
		else if (x < t->element)
			return contains(x, t->left);
		else if (t->element < x)
			return contains(x, t->right);
		else
			return t;	// Match
	}

	/**
     * Internal method to make subtree empty.
     */
	void makeEmpty(BinaryNode* &t) {
		if (t != nullptr) {
			makeEmpty(t->left);
			makeEmpty(t->right);
			delete t;
		}
		t = nullptr;
	}

	/**
     * Internal method to print a subtree rooted at t in sorted order.
     */
	void printTree(BinaryNode* t, ostream & out) const {
		if (t != nullptr) {
			printTree(t->left, out);
			std::cout << t->element << std::endl;
			printTree(t->right, out);
		}
	}

	/**
     * Internal method to clone subtree.
     */
	BinaryNode *clone(BinaryNode* t) const {
		if (t == nullptr)
			return nullptr;
		else
			return new BinaryNode{t->element, clone(t->left), clone(t->right), t};
	}

  public:
	BinarySearchTree() : root {nullptr} {}

	BinarySearchTree(const BinarySearchTree& rhs) : root {nullptr} {
		root = clone(rhs.root);
	}

	~BinarySearchTree() { makeEmpty(); }

	BinarySearchTree& operator=(const BinarySearchTree& rhs) {
		BinarySearchTree copy(rhs);
		std::swap(*this, copy);
		return *this;
	}

	class iterator {
	private:
		BinaryNode *node;

	public:
		friend class BinarySearchTree<Comparable>;

		iterator() : node(nullptr) {}

		iterator(BinaryNode *newNode) : node(newNode) {}

		bool operator ==(iterator it) const {
			return node == it.node;
		}

		bool operator !=(iterator it) const {
			return node != it.node;
		}

        iterator& operator++() {
            if (node == nullptr) return *this;  // If the iterator is already at nullptr, do nothing
            if (node->right != nullptr) {
                // Find the leftmost node in the right subtree
                node = node->right;
                while (node->left != nullptr) {
                    node = node->left;
                }
            } else {
                // Move up the tree until we find a node that is a left child
                BinaryNode* parent = node->parent;
                while (parent != nullptr && node == parent->right) {
                    node = parent;
                    parent = parent->parent;
                }
                node = parent; // If parent is null, we've reached the end
            }
            return *this;
        }


		iterator operator ++(int) {
			iterator it(*this);
			++(*this);
			return it;
		}

		Comparable& operator*() {
			return node->element;
		}

		Comparable *operator->() {
			return& node->element;
		}

		iterator& operator=(iterator it) {
			node = it.node;
			return *this;
		}
	};

	const iterator findMin() const;
	const iterator findMax() const;
	bool isEmpty() const; // test for emptiness
	void printTree(ostream& out = cout) const;
	void makeEmpty(); // empty tree
	bool contains(const Comparable& x) const; // look for item
	void remove(const Comparable& x); // remove item
	iterator insert(const Comparable& x); // insert item
	iterator find(const Comparable& x); // insert item
	iterator erase(iterator& itr);
};




template<typename Comparable>
class OrderedSet {
  private:
	size_t theSize;
	BinarySearchTree<Comparable> tree;

  public:
	OrderedSet() { }

	~OrderedSet() { clear(); }

	OrderedSet(const OrderedSet& s) {
		theSize = s.theSize;
        tree = s.tree;
	}

    void clear() {
        theSize = 0;
        tree.makeEmpty();
    }

	size_t size() const {
		return theSize;
	}

	bool empty() const {
        return theSize == 0;
	}

    void push(const Comparable& t) {
        if (tree.contains(t)) {
            return; // No duplicates allowed
        }
        tree.insert(t);
        ++theSize;
    }

	friend class BinarySearchTree<Comparable>;
	typedef typename BinarySearchTree<Comparable>::iterator iterator;

	iterator begin() const {
        return iterator(tree.findMin());
	}

	iterator end() const {
		return iterator(nullptr);
	}

	iterator insert(const Comparable& t) {
        iterator found = tree.find(t);

        // If the element is found, return the existing iterator
        if (found != nullptr) {
        return found;  // Return iterator to the existing element
        }   
     
        // Element not found, insert it
        found = tree.insert(t);  // Insert and get iterator to the newly inserted element
        ++theSize;                // Increment size

        return found;
    }

    iterator find(const Comparable& t) {
        auto itr = tree.find(t);
        return itr == nullptr ? end() : itr;
    }

	iterator erase(iterator& itr) {
		if (itr == end()) {
			return itr; // Cannot erase the end iterator (max element)
		}

		// Save the current iterator value and increment to get the next element
		iterator next = iterator(itr);

		// Remove the element pointed to by 'itr'
		Comparable valueToRemove = *itr; // Value to remove
		tree.remove(valueToRemove);      // Remove the element from the tree
		--theSize;                       // Decrease the size of the set

		// Invalidate the original iterator by setting it to `nullptr`

		// Return the iterator pointing to the next element after the removed one

		itr = nullptr;
		return next++;
	}
};





int main() {
	OrderedSet<int> set;
	set.push(4);
	set.push(0);
	set.push(2);
	set.push(7);
	set.push(0);
	set.push(2);
	set.push(6);
	set.push(4);
	set.push(12);
	set.push(11);
	set.push(8);
	set.push(1);
	set.push(5);
	set.push(0);
	set.push(3);
	set.push(2);
	set.push(7);
	set.push(1);
	set.push(1);
	set.push(1);
	set.push(9);
	set.push(7);
	set.push(11);
	set.push(1);

	// Test copy constructor
	OrderedSet<int> set2 = set;

	// Insert new smallest element
	OrderedSet<int>::iterator it = set2.insert(-1);
	cout << *it << endl;

	// Use ++ operator to iterate through the ordered set
	if (++it != set2.end())
		cout << *it << endl;

	// Insert duplicate and print succ to prove that no new node is inserted
	it = set2.insert(4);
	cout << *it << endl;
	if (++it != set2.end())
		cout << *it << endl;

	it = set2.insert(20);
	cout << *it << endl;
	if (++it != set2.end())
		cout << *it << endl;

	it = set2.find(15);
	if (++it != set2.end())
		cout << *it << endl;
	it = set2.find(12);
	cout << *it << endl;
	if (++it != set2.end())
		cout << *it << endl;
	it = set2.erase(it);
	if (it != set2.end())
		cout << *it << endl;

	it = set2.find(4);
	it = set2.erase(it);
	if (it != set2.end())
		cout << *it << endl;

	for (OrderedSet<int>::iterator it = set2.begin(); it != set2.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;
}

