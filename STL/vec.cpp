#include <iostream>
#include <vector>

using namespace std;

void    print_vec_about(vector<int> *input)
{
    cout << "Size ==\t\t" << input->size() << endl;
    cout << "Capacity ==\t" << input->capacity() << endl;
    cout << "Elements:" << endl;
    for (vector<int>::iterator i = input->begin(); i < input->end(); i++)
        cout << *i << " ";
    cout << endl;
}

int main()
{
    vector<int> v;
    v.reserve(100);
    print_vec_about(&v);
    v.resize(3);
    print_vec_about(&v);
    v.resize(10, 7);
    print_vec_about(&v);
    v.shrink_to_fit();
    print_vec_about(&v);

    return (0);
}
