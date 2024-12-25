#include <iostream>
#include <vector>

class Book {
private:
    int id;
    int category;
    bool isBorrowed;
public:
    // Constructor
    Book(int id, int category) 
    : id(id), category(category), isBorrowed(false) {};

    // Accessors
    int getId() const { return id; }
    int getCategory() const { return category; }
    bool getIsBorrowed() const { return isBorrowed; };

    // Borrow and return functions
    void borrowBook() { isBorrowed = true; };
    void returnBook() { isBorrowed = false; };

    // Display function
    void display() const {
        std::cout 
            << "Book ID: " << id << ", Category: " << category
            << ", Borrowed: " << (isBorrowed ? "Yes" : "No") << std::endl;
    };
};

class Library {
private:
    
    // Use a standard vector to hold the books. Rationale: we only need to iterate on the vector for most operations.
    std::vector<Book> books;

    int categoryHistogram[16] = { 0 };  // Array to track book count per category

    // Helper function to check for balance in book categories
    // Complexity: O(C) with C being the number of categories.
    void checkCategoryBalance() {
        int totalBooks = books.size();
        int activeCategories = 0;

        // Count active categories. Complexity: O(C)
        for (int i = 0; i < 16; ++i) {
            if (categoryHistogram[i] > 0) {
                activeCategories++;
            }
        }

        if (activeCategories == 0) return;  // Avoid division by zero

        double average = totalBooks / (double)activeCategories;
        int x = 2 * average;
        for (int i = 0; i < 16; ++i) { // Complexity: O(C)
            if (categoryHistogram[i] > x) {
                std::cout << "Warning: Category " << i
                    << " has more than twice the average number of books!" << std::endl;
            }
        }

        // Total Complexity: O(C) + O(C) = O(C)
    }

public:
    // Add a new book to the library
    // Total complexity O(N)
    void addBook(int id, int category) {
        if (category < 0 || category > 15) {
            std::cout << "Invalid category. Please provide a category between 0 and 15." << std::endl;
            return;
        }
        
        books.push_back(Book(id, category)); // Complexity: O(N) with N books, because in the worst case reallocation may happen. Most of the times it's O(1)
        categoryHistogram[category]++;  // Increment the count for this category

        checkCategoryBalance();  // Check for category balance after adding a book. Complexity O(C)

        // Total complexity O(N) + O(C) = O(N), since we expect N much larger than C.
    }

    // Borrow a book by ID
    // Complexity: O(N)
    bool borrowBook(int id) {
        for (Book& book : books) {
            if (book.getId() == id && !book.getIsBorrowed()) {
                book.borrowBook();
                return true;
            }
        }
        return false;  // Book not found or already borrowed
    }

    // Return a borrowed book by ID
    // Complexity: O(N)
    bool returnBook(int id) {
        for (Book& book : books) {
            if (book.getId() == id && book.getIsBorrowed()) {
                book.returnBook();
                return true;
            }
        }
        return false;  // Book not found or not borrowed
    }

    // Display all books
    // Complexity: O(N)
    void displayAllBooks() const {
        for (const Book& book : books) {
            book.display();
        }
    }

    // Display available books
    // Complexity: O(N)
    void displayAvailableBooks() const {
        for (const Book& book : books) {
            if (!book.getIsBorrowed()) {
                book.display();
            }
        }
    }

    // Display borrowed books
    // Complexity: O(N)
    void displayBorrowedBooks() const {
        for (const Book& book : books) {
            if (book.getIsBorrowed()) {
                book.display();
            }
        }
    }

    // Get the number of books in a given category
    // Complexity: O(1)
    int countBooksInCategory(int category) const {
        if (category < 0 || category > 15) {
            return 0;  // Invalid category
        }
        return categoryHistogram[category];
    }
};


int main() {
    Library myLibrary;

    // Adding books to the library
    myLibrary.addBook(1, 3); // Book ID: 1, Category: 3
    myLibrary.addBook(2, 7); // Book ID: 2, Category: 7
    myLibrary.addBook(3, 3); // Book ID: 3, Category: 3
    myLibrary.addBook(4, 15); // Book ID: 4, Category: 15
    myLibrary.addBook(5, 3); // Book ID: 5, Category: 3
    myLibrary.addBook(6, 0); // Book ID: 6, Category: 0
    myLibrary.addBook(7, 3); // Book ID: 5, Category: 3 (Warning should trigger here)

    // Display all books in the library
    std::cout << "\nAll books in the library:\n";
    myLibrary.displayAllBooks();

    // Display available books in the library
    std::cout << "\nAvailable books in the library:\n";
    myLibrary.displayAvailableBooks();

    // Borrow a book by ID
    std::cout << "\nBorrowing Book ID 2:\n";
    if (myLibrary.borrowBook(2)) {
        std::cout << "Book ID 2 borrowed successfully.\n";
    } else {
        std::cout << "Failed to borrow Book ID 2.\n";
    }

    // Attempt to borrow the same book again
    std::cout << "\nAttempting to borrow Book ID 2 again:\n";
    if (myLibrary.borrowBook(2)) {
        std::cout << "Book ID 2 borrowed successfully.\n";
    } else {
        std::cout << "Failed to borrow Book ID 2.\n";
    }

    // Display borrowed books
    std::cout << "\nBorrowed books in the library:\n";
    myLibrary.displayBorrowedBooks();

    // Return a borrowed book by ID
    std::cout << "\nReturning Book ID 2:\n";
    if (myLibrary.returnBook(2)) {
        std::cout << "Book ID 2 returned successfully.\n";
    } else {
        std::cout << "Failed to return Book ID 2.\n";
    }

    // Display available books after returning a book
    std::cout << "\nAvailable books in the library after returning Book ID 2:\n";
    myLibrary.displayAvailableBooks();

    // Display the number of books in a specific category
    int categoryToCheck = 3;
    std::cout << "\nNumber of books in category " << categoryToCheck << ": "
              << myLibrary.countBooksInCategory(categoryToCheck) << std::endl;

    return 0;
}
