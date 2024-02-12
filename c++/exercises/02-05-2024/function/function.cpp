#include <iostream>
using namespace std;

void swap(int &a, int &b);

int main()
{
    int a = 0;
    int b = 1;
    swap(b, a);
    return 0;
}

void swap(int &a, int &b)
{
    cout << "a: " << a << " b: " << b << "\n";
    int temporary_variable = a;
    a = b;
    b = temporary_variable;
    cout << "a: " << a << " b: " << b << "\n";
}