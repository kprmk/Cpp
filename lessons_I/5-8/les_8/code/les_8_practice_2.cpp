#include <iostream>
using namespace std;
 
class fraction
{
private:
    int     first;
    int     second;
    int     nod(int a, int b)
    {
        // Алгоритм Евклида
        while (a && b)
        {
            if (a > b)
                a = a % b;
            else
                b = b % a;
        }
        return (a + b);
    }
public:
    fraction()
    {
        first = 1;
        second = 1;
    }
    fraction(int a, int b)
    {
        int     del;

        first = a;
        second = b;
        do
        {
            del = nod(first, second);
            first /= del;
            second /= del;
        }while (del != 1);
    }
    void    set_Data(int a, int b)
    {
        first = a;
        second = b;
    }
    void    get_Data_origin()
    {
        cout << first << " / "  << second << endl; 
    }
    void    get_Data_dec()
    {
        cout << endl;
        cout << this->first << " " << this->second << endl;
         cout << first / (float)second << endl; 
    }
    fraction    operator+(fraction b)
    {
        this->first = this->first * b.second + this->second * b.first;
        this->second = this->second * b.second;
        return (*this);
    }
    fraction    operator-(fraction b)
    {
        this->first = this->first * b.second - this->second * b.first;
        this->second = this->second * b.second;
        return (*this);
    }
    fraction    operator*(fraction b)
    {
        this->first = this->first * b.first;
        this->second = this->second * b.second;
        return (*this);
    }
    fraction    operator/(fraction b)
    {
        this->first = this->first * b.second;
        this->second = this->second * b.first;
        return (*this);
    }
};
 
int main()
{ 
    fraction    first(5, 25);
    fraction    second(100, 100);
    fraction    *pointer;
 
    first.get_Data_origin();
    first.get_Data_dec();

    pointer = &second;
    pointer->get_Data_origin();
    pointer->get_Data_dec();

    cout << "Sum: ";
    (first + second).get_Data_dec();

    return (0);
}