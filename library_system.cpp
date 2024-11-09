#include <iostream>
#include <vector>
#include <fstream>
#include <string>

// Book class definition
class Book {
public:
    int id;
    std::string title;
    std::string author;
    bool isLent;

    // Constructor
    Book(int id, std::string title, std::string author)
        : id(id), title(title), author(author), isLent(false) {}

    // Display book details
    void display() const {
        std::cout << "ID: " << id << " | Title: " << title
                  << " | Author: " << author
                  << " | Status: " << (isLent ? "Lent out" : "Available") << '\n';
    }
};

// Function to add a book to the library
void addBook(std::vector<Book>& library) {
    int id;
    std::string title, author;
    std::cout << "Enter book ID: ";
    std::cin >> id;
    std::cin.ignore(); // Ignore newline character left in the buffer
    std::cout << "Enter book title: ";
    std::getline(std::cin, title);
    std::cout << "Enter author name: ";
    std::getline(std::cin, author);
    
    library.push_back(Book(id, title, author));
    std::cout << "Book added successfully.\n";
}

// Function to view all books in the library
void viewBooks(const std::vector<Book>& library) {
    if (library.empty()) {
        std::cout << "No books in the library.\n";
        return;
    }
    for (size_t i = 0; i < library.size(); ++i) {
        library[i].display();
    }
}

// Function to lend a book
void lendBook(std::vector<Book>& library) {
    int id;
    std::cout << "Enter book ID to lend: ";
    std::cin >> id;
    
    for (size_t i = 0; i < library.size(); ++i) {
        if (library[i].id == id) {
            if (!library[i].isLent) {
                library[i].isLent = true;
                std::cout << "Book lent successfully.\n";
                return;
            } else {
                std::cout << "Book is already lent out.\n";
                return;
            }
        }
    }
    std::cout << "Book not found.\n";
}

// Function to return a book
void returnBook(std::vector<Book>& library) {
    int id;
    std::cout << "Enter book ID to return: ";
    std::cin >> id;
    
    for (size_t i = 0; i < library.size(); ++i) {
        if (library[i].id == id) {
            if (library[i].isLent) {
                library[i].isLent = false;
                std::cout << "Book returned successfully.\n";
                return;
            } else {
                std::cout << "Book was not lent out.\n";
                return;
            }
        }
    }
    std::cout << "Book not found.\n";
}

// Function to save the library state to a file
void saveLibraryToFile(const std::vector<Book>& library, const std::string& filename) {
    std::ofstream file(filename.c_str());
    if (!file) {
        std::cerr << "Error saving to file.\n";
        return;
    }
    for (size_t i = 0; i < library.size(); ++i) {
        file << library[i].id << '\n' << library[i].title << '\n' 
             << library[i].author << '\n' << library[i].isLent << '\n';
    }
    file.close();
    std::cout << "Library saved to " << filename << ".\n";
}

// Function to load the library state from a file
void loadLibraryFromFile(std::vector<Book>& library, const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file) {
        std::cerr << "Error loading from file.\n";
        return;
    }
    int id;
    std::string title, author;
    bool isLent;
    while (file >> id) {
        file.ignore(); // Ignore the newline after the ID
        std::getline(file, title);
        std::getline(file, author);
        file >> isLent;
        library.push_back(Book(id, title, author));
        library.back().isLent = isLent;
    }
    file.close();
    std::cout << "Library loaded from " << filename << ".\n";
}

// Main function
int main() {
    std::vector<Book> library;
    std::string filename = "library.txt";

    // Load library from file
    loadLibraryFromFile(library, filename);

    int choice;
    do {
        std::cout << "\n--- Library Management System ---\n";
        std::cout << "1. Add Book\n2. View Books\n3. Lend Book\n4. Return Book\n5. Save and Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addBook(library);
                break;
            case 2:
                viewBooks(library);
                break;
            case 3:
                lendBook(library);
                break;
            case 4:
                returnBook(library);
                break;
            case 5:
                saveLibraryToFile(library, filename);
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
