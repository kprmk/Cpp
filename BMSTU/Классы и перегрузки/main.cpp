#include"String.h"

using namespace std;

int main(void)
{
	String a("HELLO");
	String b("I AM BIGIPAACKKK");

	cout << a;
	cout << b << endl;

	a = b;

	cout << a;
	cout << b << endl;

	a = "HELLO";
	b = "QWERTY|||YTREWQ";

	cout << a + b;
	cout << b + "   ```   EEE BOYYY";
	cout << "   ```   EEE BOYYY" + b << endl;

	cout << "a[1] == " << a[1] << endl;

	a += b;
	cout << a << endl;

	a += "   HELLOOOLEH";
	cout << a << endl;

	String c("qwerty");
	String d("qwerty");
	String w("qwerty1");
	bool q = c == d;
	cout << q  << ' ';
	q = c != w;
	cout << q << ' ';
	q = c == "qwerty";
	cout << q << ' ';
	q = c >= "qwerty";
	cout << q << ' ';
	q = c <= "qwerty";
	cout << q << ' ';
	q = c >= d;
	cout << q << ' ';
	q = c <= d;
	cout << q << ' ';
	q = c > "qwerty";
	cout << q << ' ';
	q = c < "qwerty";
	cout << q << ' ';
	q = c > d;
	cout << q << ' ';
	q = c < d;
	cout << q << ' ';
	q = "qwerty" == c;
	cout << q << ' ';

	cout << b << "SubSTR \n is " << b.substring(1, 3)  << '\n'<< endl;
	cout << b << "SubSTR LEFT \n is " << b.left(4) << '\n' << endl;
	cout << b << "SubSTR RIGHT \n is " << b.right(4) << '\n' << endl;

	cout << b.has_simbol('Q') << endl;
	cout << b.has_simbol('B') << endl;

	cout << '\n' << w.has_substring(d) << endl;
	cout << w.has_substring("wer") << '\n' << endl;
	
	String g("NARUTO");
	String p("NA");
	/*cout << g.has_simbol(p[0]) << endl;
	cout << g.has_simbol(p[1]) << endl;*/
	cout << g << g.remove_substr(2, 4) << endl;
	cout << g << g.remove_substr("NA") << endl;
	//cout << g << g.remove_substr(p) << endl;
	


	getchar();
	return 0;
}