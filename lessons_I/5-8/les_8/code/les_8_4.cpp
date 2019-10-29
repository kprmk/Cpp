#include <iostream>
using namespace std;

class MyClass
{
    private:
        int regVar;
    public:
        MyClass() {
            regVar = 0;
        }

    friend void someFunc(MyClass &obj);
};

void someFunc(MyClass &obj) 
{
    obj.regVar = 42;
    cout << obj.regVar;
}

int main() {
    MyClass obj;
    someFunc(obj);
}
