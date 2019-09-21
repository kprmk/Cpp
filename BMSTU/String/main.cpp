#include <iostream>

class O
{
	public:
		O() { std::cout << "Constructor O" << std::endl; }
		~O() { std::cout << "Destructor O" << std::endl; }
};

class A
{
	public:
		A() { std::cout << "Constructor A" << std::endl; }
		virtual void f() { std::cout << "Method A" << std::endl; }
		virtual ~A() { std::cout << "Destructor A" << std::endl; }
};

class B : public A
{
	private:
		O o1;
	public:
		B() { std::cout << "Constructor B" << std::endl; }
		void f() { std::cout << "Method B" << std::endl; }
		~B() { std::cout << "Destructor B" << std::endl; }
};

class C : public B
{
	public:
		C() { std::cout << "Constructor C" << std::endl; }
		void f() { std::cout << "Method C" << std::endl; }
		~C() { std::cout << "Destructor C" << std::endl; }
};

int main()
{
	A *pA = new C;
	pA->f();
	delete(pA);

	std::cin.get();
	return 0;
}