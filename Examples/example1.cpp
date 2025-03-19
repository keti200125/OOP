#include <iostream>

class Example
{
public:
    Example()
    {
        std::cout << "Constructor" << "\n";
    }

    ~Example()
    {
        std::cout << "Destructor" << "\n";
    }
};

int main()
{
    Example ex1;
    {
        Example ex2;
    }
    Example ex3;

    return 0;
}