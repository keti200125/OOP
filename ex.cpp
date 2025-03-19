// #include <iostream>

// class MyClass
// {
//     int *data;

// public:
//     MyClass(int val)
//     {
//         data = new int(val);
//         std::cout << "default " << *data << std::endl;
//     }

//     void print()
//     {
//         std::cout << "Value: " << *data << std::endl;
//     }

//     ~MyClass()
//     {
//         std::cout << "Destructor " << *data << std::endl;
//         delete data;
//     }
// };

// int main()
// {
//     MyClass a1(42);
//     MyClass a2 = a1;
//     a1.print();
//     a1.~MyClass();
//     a2.print();

//     std::cout << "END";
//     return 0;
// }

#include <iostream>
#include <cstring>

class Book
{
    char *title;

    void free()
    {
        delete[] title;
        title = nullptr;
    }

    void copyFrom(const Book &other)
    {
        title = new char[strlen(other.title) + 1];
        strcpy(title, other.title);
    }

public:
    Book(const char *bookTitle)
    {
        title = new char[strlen(bookTitle) + 1];
        strcpy(title, bookTitle);
    }

    ~Book()
    {
        std::cout << "[Destructor] Destroying Book: " << title << std::endl;
        free();
    }

    void print() const
    {
        std::cout << "Book Title: " << title << std::endl;
    }
};

int main()
{
    Book b1("1984");
    Book b2 = b1; // Неявен (implicit) copy constructor -> shallow copy (повърхностно копиране)

    b1.print();

    b2.print();
    return 0;
}
