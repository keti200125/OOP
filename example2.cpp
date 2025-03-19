#include <iostream>

class A
{
private:
    int a;

public:
    A()
    {
        std::cout << "A()" << std::endl;
    }
    ~A()
    {
        std::cout << "~A()" << std::endl;
    }
};

class B
{
private:
    int b;

public:
    B()
    {
        std::cout << "B()" << std::endl;
    }
    ~B()
    {
        std::cout << "~B()" << std::endl;
    }
};

class C
{
private:
    A a;
    B b;
    int c;

public:
    C()
    {
        std::cout << "C()" << std::endl;
    }
    ~C()
    {
        std::cout << "~C()" << std::endl;
    }
};

int main()
{
    C obj;
}