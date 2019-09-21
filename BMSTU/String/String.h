#pragma once	

#include <iostream>
#include <cstring>

class String
{
	private:
		char* str;
		int len;
	
	public:
		// конструкторы
		String(const char* s = "");	// по умолчанию
		String(const String& s); // копирования

		// деструктор
		~String() { if (str) delete[](str); }

		// операторы
		char& operator[](const int i);
		const char& operator[](const int i) const;
		String& operator=(const String& s);
		String& operator=(const char* s);
		String operator+(const String& s) const;
		String operator+(const char* s) const;
		String& operator+=(const String& s);
		String& operator+=(const char* s);
		bool operator==(const String& s) const;
		bool operator==(const char* s) const;
		bool operator!=(const String& s) const;
		bool operator!=(const char* s) const;
		bool operator<(const String& s) const;
		bool operator<(const char* s) const;
		bool operator<=(const String& s) const;
		bool operator<=(const char* s) const;
		bool operator>(const String& s) const;
		bool operator>(const char* s) const;
		bool operator>=(const String& s) const;
		bool operator>=(const char* s) const;

		// методы
		bool isEmpty() const { return !len; }
		int length() const { return len; }
		String& clear();
		String substring(int begin, int end) const;
		String left(int count) const;
		String right(int count) const;
		bool hasSubstring(const String& s) const;
		bool hasSubstring(const char* s) const;
		bool hasSymbol(const char symbol) const;
		//String removeSubstring(int begin, int end) const;
		String& removeSubstring(int begin, int end);
		//String removeSubstring(const String& s) const;
		//String removeSubstring(const char* s) const;
		String& removeSubstring(const String& s);
		String& removeSubstring(const char* s);
		//String removeLeft(int count) const;
		//String removeRight(int count) const;
		String& removeLeft(int count);
		String& removeRight(int count);
		String getFirstWord(const String& separator) const;
		String getLastWord(const String& separator) const;

		// дружественная перегрузка операторов (если слева char*)
		friend String operator+(const char* s1, const String& s2);
		friend bool operator==(const char* s1, const String& s2);
		friend bool operator!=(const char* s1, const String& s2);
		friend bool operator>(const char* s1, const String& s2);
		friend bool operator<(const char* s1, const String& s2);
		friend bool operator>=(const char* s1, const String& s2);
		friend bool operator<=(const char* s1, const String& s2);

		//перегрузка вывода
		friend std::ostream& operator<<(std::ostream& os, const String& s);
};
