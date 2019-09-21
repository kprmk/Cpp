#include "String.h"

int main()
{
	char s[] = "Ha-ha-ha!";
	String s1, s2("Hello"), s3(s);

	std::cout << s1 << " ; " << s2 << " ; " << s3 << std::endl;
	std::cout << "Symbol #" << 2 << " in " << s2 << " is " << s2[2] << std::endl;

	s1 = s2;
	std::cout << s1 << std::endl;
	s1 = s;
	std::cout << s1 << std::endl;

	std::cout << s1 + s2 << std::endl;
	std::cout << s2 + s << std::endl;
	std::cout << s + s2 << std::endl;
	s1 += s;
	s1 += s1;
	std::cout << s1 << std::endl;

	std::cout << std::boolalpha;
	std::cout << (s2 == s3) << ' ' << (s2 != s3) << ' ' << (s3 == s) << ' ';
	std::cout << (s < s3) << ' ' << (s <= s3) << std::endl;

	s1.clear();
	std::cout << s1.isEmpty() << ' ' << s2.length() << std::endl;

	s1 = s + s2;
	std::cout << s1.substring(3, 7) << std::endl;
	std::cout << s1.left(4) << s1.right(0) << s1.right(2) << std::endl;
	std::cout << s1.hasSubstring("ha-ah") << ' ' << s1.hasSubstring(s1) << ' ' << s1.hasSymbol('H') << std::endl;

	s1 += (s1 + s1);
	std::cout << s1 << std::endl;
	s1.removeSubstring(3, 10);
	std::cout << s1 << std::endl;
	s1.removeSubstring(s2);
	std::cout << s1 << std::endl;
	s1.removeSubstring("Ha");
	std::cout << s1 << std::endl;

	s1.removeLeft(2);
	std::cout << s1 << std::endl;
	s1.removeRight(3);
	std::cout << s1 << std::endl;

	getchar();
	return 0;
}