#include <iostream>
using namespace std;
 
class Child
{
private:
    string  name;
    string  surname;
    int     age;
public:
    Child()
    {
        name = "name";
        surname = "surname";
        age = 0;
    }
    Child(string first, string second, int age_input)
    {
        set_Data(first, second, age_input);
    }
    void set_Data(string first, string second, int age_input)
    {
        name = first;
        surname = second;
        age = age_input;
    }
    void get_Data()
    {
        cout << name << " " << surname << " is " << age << endl; 
    }
};
 
int main()
{ 
    Child   first_child;
    Child   second_child("Pavel", "Petrov", 16);
    Child   *pointer;

    first_child.get_Data();
    second_child.get_Data();

    pointer = &second_child;
    pointer->set_Data("Dima", "Ivanov", 18);
    pointer->get_Data();
    
    return (0);
}