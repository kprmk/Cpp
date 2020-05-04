#include <iostream>
using namespace std;

const int glob = 10;  // global variable
// constant - постоянный 

void access_global();
void hide_global();
void change_global();

int main()
{
    glob = 100;

    return 0;
}

void access_global()
{
    cout << "In access_global() glob is: " << glob << "\n\n";
}

void hide_global()
{
    int glob = 0;  // hide global variable glob
    cout << "In hide_global() glob is: " << glob << "\n\n";
}

void change_global()
{
    glob = -10;  // change global variable glob
    cout << "In change_global() glob is: " << glob << "\n\n";
}

