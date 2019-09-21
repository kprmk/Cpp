#pragma once
#include<iostream>

class String
{
private:
	char * str;
	unsigned len;
public:
	String();
	String(const char * s);
	String(const String &s);
	~String();

	unsigned length() { return len; };

	String& operator= (const String & s);
	String& operator= (const char * s);

	const String operator+(const String &s)const;
	const String operator+(const char *s)const;
	friend const String operator+(const char* s, const String& a);

	const char& operator[](const int i)const;

	String& operator+=(const String& s);
	String& operator+=(const char* s);

	bool operator==(const String& s);
	bool operator==(const char* s);
	bool operator!=(const String& s);
	bool operator!=(const char *s);

	bool operator>=(const String& s);
	bool operator>=(const char* s);
	bool operator<=(const String& s);
	bool operator<=(const char* s);

	bool operator>(const String& s);
	bool operator>(const char* s);
	bool operator<(const String& s);
	bool operator<(const char* s);

	friend bool operator==(const char* s, const String& a);
	friend bool operator!=(const char* s, const String& a);
	friend bool operator>=(const char* s, const String& a);
	friend bool operator<=(const char* s, const String& a);
	friend bool operator>(const char* s, const String& a);
	friend bool operator<(const char* s, const String& a);

	bool is_empty();
	void clear();

	char * substring(unsigned begin, unsigned end);
	char *  left(unsigned i);
	char *  right(unsigned i);

	int has_simbol(char ch);
	char * has_substring(const String& s);
	char * has_substring(const char* s);

	char * remove_substr(unsigned begin, unsigned end);
	char * remove_substr(const String& s);
	char * remove_substr(const char* s);

	friend std::ostream& operator<<(std::ostream&os, const String& f);
};

