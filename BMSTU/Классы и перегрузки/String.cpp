#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include <cstring>

String::String()
{
	len = 0;
	str = new char[1];
	*str = '\0';
}

String::String(const char *s)
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
}

String:: String(const String &s)
{
	len = s.len;
	str = new char[s.len + 1];
	strcpy(str, s.str);
}

String::~String()
{
	delete[] str;
}

String& String:: operator= (const String& s)
{
	len = s.len;
	delete[] str;
	str = new char[len + 1];
	strcpy(str,s.str);
	return *this;
}

String& String:: operator= (const char * s)
{
	len = strlen(s);
	delete[] str;
	str = new char[len + 1];
	strcpy(str, s);
	return *this;
}

const String String::operator+(const String &s)const
{
	String a;
	a.len = len + s.len;
	delete[] a.str;
	a.str = new char[a.len + 1];
	strcpy(a.str, str);
	strcat(a.str, s.str);
	return a;
}

const String String::operator+(const char *s)const
{
	String a;
	a.len = len + strlen(s);
	delete[]a.str;
	a.str = new char[a.len + 1];
	strcpy(a.str, str);
	strcat(a.str, s);
	return a;
}

const char& String::operator[](const int i)const
{
	return str[i];
}

String& String::operator+=(const String& s)
{
	char* n = new char[len + 1];
	strcpy(n, str);
	delete[]str;
	len += s.len;
	str = new char[len + 1];
	strcpy(str, n);
	delete[]n;
	strcat(str, s.str);
	return *this;
}

String& String::operator+=(const char* s)
{
	char* n = new char[len + 1];
	strcpy(n, str);
	len += strlen(s);
	delete[]str;
	str = new char[len + 1];
	strcpy(str, n);
	delete[]n;
	strcat(str, s);
	return *this;
}

bool String::operator==(const String& s)
{
	if (strcmp(str, s.str) == 0)
		return true;
	else
		return false;
}

bool String::operator==(const char *s)
{
	if (strcmp(str, s) == 0)
		return true;
	else
		return false;
}

bool String:: operator!=(const String& s)
{
	if (strcmp(str, s.str) == 0)
		return false;
	else
		return true;
}

bool String:: operator!=(const char *s)
{
	if (strcmp(str, s) == 0)
		return false;
	else
		return true;
}

bool String::operator>=(const String& s)
{
	if (strcmp(str, s.str) >= 0)
		return true;
	else
		return false;
}

bool String::operator>=(const char* s)
{
	if (strcmp(str, s) >= 0)
		return true;
	else
		return false;
}

bool String::operator<=(const String& s)
{
	if (strcmp(str, s.str) <= 0)
		return true;
	else
		return false;
}

bool String::operator<=(const char* s)
{
	if (strcmp(str, s) <= 0)
		return true;
	else
		return false;
}

bool String::operator>(const String& s)
{
	if (strcmp(str, s.str) > 0)
		return true;
	else
		return false;
}

bool String::operator>(const char* s)
{
	if (strcmp(str, s) > 0)
		return true;
	else
		return false;
}

bool String::operator<(const String& s)
{
	if (strcmp(str, s.str) < 0)
		return true;
	else
		return false;
}

bool String::operator<(const char* s)
{
	if (strcmp(str, s) < 0)
		return true;
	else
		return false;
}

const String operator+(const char* s, const String& a)
{
	String n;
	delete[]n.str;
	n.len = a.len + strlen(s);
	n.str = new char[n.len + 1];
	strcpy(n.str, s);
	strcat(n.str, a.str);
	return n;
}

bool operator==(const char* s, const String& a)
{
	if (strcmp(a.str, s) == 0)
		return true;
	else
		return false;
}

bool operator!=(const char* s, const String& a)
{
	if (strcmp(a.str, s) == 0)
		return false;
	else
		return true;
}

bool operator>=(const char* s, const String& a)
{
	if (strcmp(s, a.str) >= 0)
		return true;
	else
		return false;
}

bool operator<=(const char* s, const String& a)
{
	if (strcmp(s, a.str) <= 0)
		return true;
	else
		return false;
}

bool operator>(const char* s, const String& a)
{
	if (strcmp(s, a.str) > 0)
		return true;
	else
		return false;
}

bool operator<(const char* s, const String& a)
{
	if (strcmp(s, a.str) < 0)
		return true;
	else
		return false;
}

bool String::is_empty()
{
	if (len)
		return false;
	else
		return true;
}

void String::clear()
{
	len = 0;
	delete[]str;
	str = new char[1];
	*str = '\0';
}

char * String::substring(unsigned begin, unsigned end)
{
	char * s;
	s = new char[end - begin + 1];
	int i = 0;
	while (begin <= end)
	{
		s[i++] = str[begin++];
	}
	s[i] = '\0';
	return s;
}

char * String::left(unsigned i)
{
	unsigned q = 0;
	char * s;
	s = new char[i + 1];
	for(; q <= i; ++q)
	{
		s[q] = str[q];
	}
	s[q] = '\0';
	return s;
}

 char * String::right(unsigned i)
{
	unsigned q = 0;
	char * s;
	s = new char[i + 1];
	for(; i > 0 ; q++ , i--)
	{
		s[q] = str[len - i];
	}
	s[q] = '\0';
	return s;
}

int String::has_simbol(char ch)
{
	int i = -1;
	while (i++ < (int)len)
	{
		if (ch == str[i])
			return i;
	}
	return -1;
}

char * String::has_substring(const String& s)
{
	if (strstr(str, s.str))
	{
		char * a = new char[s.len + 1];
		strcpy(a, s.str);
		a[s.len + 1] = '\0';
		return a;
	}
	else
		return NULL;
}

char * String::has_substring(const char* s)
{
	if (strstr(str, s))
	{
		char * a = new char[strlen(s) + 1];
		strcpy(a, s);
		a[strlen(s) + 1] = '\0';
		return a;
	}
	else
		return NULL;
}

char * String::remove_substr(unsigned begin, unsigned end)
{
	if(begin < end && end < len)
	{
		char * ss = new char[len + 1];
		strcpy(ss, str);
		char * s = new char[end - begin + 1];
		while (end != len)
		{
			ss[begin++] = ss[++end];
			//std::cout << str << std::endl;
		}
		ss[begin] = '\0';
		strcpy(s, ss);
		delete[] ss;
		return s;
	}
	return NULL;
}

char * String::remove_substr(const String& s)
{
	if (this->has_substring(s.str))
	{
		char * q = new char[len - s.len - 1];
		int a = has_simbol(*s.str);
		int b = has_simbol(*(s.str + s.len - 1));
		q = (*this).remove_substr(a, b);

		q[s.len + 1] = '\0';
		return q;
	}
	return NULL;
}

char * String::remove_substr(const char* s)
{
	if (this->has_substring(s))
	{
	char * q = new char[len - strlen(s) - 1];
	int a = has_simbol(*s);
	int b = has_simbol(*(s + strlen(s) - 1));
	q = (*this).remove_substr(a, b);
	q[strlen(s) + 1] = '\0';
	return q;
}
return NULL;
}

//char* string::removeleft(int L)
//{
//	if (L <= len)
//	{
//		char* s = new char[len + 1];
//		strcpy(s, str);
//		delete[] str;
//		len -= L;
//		str = new char[len + 1];
//		int a = L;
//		int i = 0;
//		for (i; i < len; i++)
//		{
//			str[i] = s[a];
//			a++;
//		}
//		str[i] = '\0';
//		delete[] s;
//		return str;
//	}
//	return str;
//}
//char* string::removelefr(int L)
//{
//	if (L <= len)
//	{
//		char* s = new char[len + 1];
//		strcpy(s, str);
//		delete[] str;
//		len -= L;
//		str = new char[len + 1];
//		int i = 0;
//		for (i; i < len; i++)
//		{
//			str[i] = s[i];
//		}
//		str[i] = '\0';
//		delete[] s;
//		return str;
//	}
//	return str;
//}
//char* string::getfirstword(const string& delimiters)
//{
//	int i = 0;
//	for (i; (!(strchr(delimiters.str, str[i])) && (i < len)); i++) {}
//	if (i == len - 1)
//	{
//		return str;
//	}
//	char* s = new char[i + 1];
//	for (int a = 0; a < i; a++)
//	{
//		s[a] = str[a];
//	}
//	s[i] = '\0';
//	return s;
//}
//
//
//
//char* string::getlastword(const string& delimiters)
//{
//	int i = len - 1;
//	int a = 0;
//	for (i; !(strchr(delimiters.str, str[i])) && (i >= 0); i--) { a++; }
//	if (i == 0)
//	{
//		return str;
//	}
//	i++;
//	char* s = new char[a + 1];
//	int b = 0;
//	for (b; b <= a; b++)
//	{
//		s[b] = str[i];
//		i++;
//	}
//	s[b] = '\0';
//	return s;
//}

std::ostream& operator<<(std::ostream&os, const String& f)
{
	os << f.str << std::endl;
	return os;
}