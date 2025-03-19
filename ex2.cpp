#include <iostream>
#include <cstring>
#include<fstream>

class Book {
private:
    char* title;

    void free() {
        delete[] title;
        title = nullptr;
    }

    void copyFrom(const Book& other) {
        title = new char[strlen(other.title) + 1];
        strcpy(title, other.title);
    }

public:
    Book(const char* bookTitle) {
        title = new char[strlen(bookTitle) + 1];
        strcpy(title, bookTitle);
    }

    Book(const Book& other) {
        copyFrom(other);
    }

    Book& operator=(const Book& other) {
        if (this != &other) {
            free();
            copyFrom(other);
        }
        return *this;
    }

    ~Book() {
        std::cout << "[Destructor] Destroying Book: " << title << std::endl;
        free();
    }

    void print() const {
        std::cout << "[Print] Book Title: " << title << std::endl;
    }

    
};

int main() {
    Book b1("1984");   // Constructor
    Book b2 = b1;      // Copy Constructor
    Book b3("Brave New World"); // Constructor

    b3 = b1;  // Operator=
    // b1.~Book();
    b2.print();
    return 0;
}
