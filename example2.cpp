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
    int c;
    B b;
    A a;

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