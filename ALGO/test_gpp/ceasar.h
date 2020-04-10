#include <iostream> // input output stream
using namespace std;

class ceasar
{
	private:
		string input;
		int shift; // сдвиг
	public:
		ceasar();
		ceasar(string input, int shift);
		void to_code();
		const string getter();
};