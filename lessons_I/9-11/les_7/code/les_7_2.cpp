#include <iostream>
using namespace std;

// объявление класса
class Human // имя класса
{
private: // спецификатор доступа private
    string  name;
public: // спецификатор доступа public
    Human() // конструктор по умолчанию 
    {
        cout << "You have created obj here\n";
    }
    Human(string str) // конструктор
    {
        cout << "You have created obj with name " << str << endl;
        set_name(str); // name = str
    }
    void set_name(string str) // setter
    {
        name = str;
    }
    string get_name() // getter
    {
        return (name);
    }
};

int main()
{
    cout << "Output:\n";
    Human someone;
    Human Kirill = Human("Kirill");
    Human Denis("Denis");
    return (0);
}