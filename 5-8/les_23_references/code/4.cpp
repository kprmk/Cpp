// #include <iostream>
// #include <string>
// using namespace std;

// int askNumber(int high = 30, int low = 1);

// int number = 10000000;
	
// int main()
// {
// 	int counter = 1; // create

// 	number = -10;
// 	askNumber(10, 1, counter);
// 	cout << number << endl;
//     return 0;
// }

// int askNumber(int high, int low, int counter)
// {
//     int num;

// 	cout << counter << endl;
// 	// cout << number << endl;
// 	// цикл с постусловием
//     do
//     {
//         cout << "Please enter a number";
// 		cout << " (" << low << " - " << high << "): ";
//         cin >> num;
//     } while (num > high || num < low);

//     return num;
// }



#include <iostream>
using namespace std;

void swap (int &a, int &b)
{
	int temp; // временный
	
	cout << "Inside swap() " << a << " <-> " << b << endl;
	
	temp = a;
	a = b;
	b = temp;
	
	cout << "Inside swap() " << a << " <-> " << b << endl;
}

int main()
{
	int score_Gr;
	int score_Pt;

	cin >> score_Gr;
	cin >> score_Pt;
 
	cout << "In main() " << score_Gr << " <-> " << score_Pt << endl;
	swap(score_Gr, score_Pt);
	cout << "In main() " << score_Gr << " <-> " << score_Pt << endl;

	return 0;
}