// This code has examples for scope operator
#include <iostream>
#include <cstddef>

int a = 10; // This is a global variable


class B
{
public:
    void func();

};

void B::func(){
    std::cout << "function from class B declared outside the class using the scope operator" << std::endl;
}

int main()
{
    int a = 20;

    std::cout << "global a: " << ::a << std::endl;  //orints 10 which is present inside the global a
    std::cout << " local a: " << a << std::endl;    // prints 20 which is present inside the local a
    B b;
    b.func();
    return 0;
}
