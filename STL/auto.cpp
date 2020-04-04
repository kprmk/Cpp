#include <iostream>
#include <map>
using namespace std;

int main() 
{
    map <int, int> mp;
    cout << "Enter amount of elements: "; 
    int n; 
    cin >> n;

    for (int i = 0; i < n; i++) 
    {
        cout << i << ") "; int a; cin >> a;
        mp[a] = i;  // добавляем новые элементы
    }
 
    map <int, int> :: iterator it = mp.begin();
    for (int i = 0; it != mp.end(); it++, i++) 
    {  
        cout << i << ") Key " << it->first 
        << ", value " << it->second << endl;
    }
    return 0;
}

