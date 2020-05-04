#include <iostream>
using namespace std;
 
class Human
{
private:
    string      name;
    string      surname;
    const int   age; 
public:
    Human() : name("name"), surname("surname"), age(0) {}
    Human(string name, string surname, int age) : name(name), surname(surname), age(age) {}
    void    get_Data()
    {
        cout << "Name:\t\t" << this->name << endl;
        cout << "Surname:\t" << this->surname << endl;
        cout << "Age:\t\t" << this->age << endl; 
    }
};

class Pupil
{
private:
    Human       someone;
    const int   num_of_sch;
    int         average;
public:
    Pupil() : someone(), num_of_sch(0), average(0) {}

    Pupil(string name, string surname, int age, int school, int ave) : 
    someone(name, surname, age), num_of_sch(school), average(ave) {}
    
    void    get_Data()
    {
        this->someone.get_Data();
        cout << "Num of school:\t" << this->num_of_sch << endl;
        cout << "Average:\t" << this->average << endl; 
    }
};

int main()
{
    Human   no_name();
    Human   Andrey("Andrey", "Smirnov", 15);
    Pupil   no_name_pupil();
    Pupil   Pupil_Andrey = Pupil("Andrey", "Smirnov", 15, 2002, 4);

    Andrey.get_Data();
    cout << endl;
    Pupil_Andrey.get_Data();
    cout << endl;


    return (0);
}