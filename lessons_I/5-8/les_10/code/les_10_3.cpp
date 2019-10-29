#include <iostream>
using namespace std;

template <class T>
class Pair {
    private:
        T first, second;
    public:
        Pair (T a, T b):
        first(a), second(b) { }
        T bigger();
};

template <class T>
T Pair<T>::bigger() {
    return (first>second ? first : second);
}

int main()
{
    cout << "Output:" << endl;
    Pair <int> obj_int(11, 22);
    Pair <double> obj_double(1.15, 100.25);
    cout << obj_int.bigger() << endl;
    cout << obj_double.bigger() << endl;
    return (0);
}

