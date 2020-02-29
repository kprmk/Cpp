#include <vector>
#include <iostream>
 
using namespace std;
 
int main()
{
	int Arr[10] = {1,2,3,4,5,6,7,8,9,10};               
	//Инициализируем массив значениями
	vector<int> v(Arr, Arr + 10);                           
	//Копирование массива в Вектор
	vector<int>::iterator it;  //Объявляем итератор  
	//(тип итератора должен соответствовать типу объекта, который обходится)
 
	for (it = v.begin(); it != v.end(); it++) 
		cout << *it << " ";    
		//с помощью итератора выводим элементы вектора на экран
 
	cout << '\n';
	return (0);
}

