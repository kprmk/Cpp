#include <iostream>

using namespace std;

void    print_bits(int num, int size_in_byte)
{ 
    for (int i = (size_in_byte * 8 - 1); i >= 0; i--)
    {
        if ((1 << i) & num)
            cout << 1;
        else
            cout << "0";
    }
    cout << endl;
}

int     put_bit(int num, int pos)
{
    return (num | 1 << pos);
}

int     del_bit(int num, int pos)
{
    return (num & ~(1 << pos));
}

int     rev_bit(int num, int pos)
{
    return (num ^ (1 << pos));
}

int main()
{
    int     a = 0;
    print_bits(rev_bit(rev_bit(a, 2), 2), sizeof(int));
    return (0);
}