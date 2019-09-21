#define _CRT_SECURE_NO_WARNINGS
#include "String.h"

String::String(const char *s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
}

String::String(const String &s)
{
	len = s.len;
	str = new char[len + 1];
	std::strcpy(str, s.str);
}

char& String::operator[](const int i)
{
	if (i >= 0 && i < len)
	{
		return str[i];
	}
	else if (i < 0 && i >= -len)
	{
		return str[i + len];
	}
	else
	{
		return str[len];
	}
}

const char& String::operator[](const int i) const
{
	if (i >= 0 && i < len)
	{
		return str[i];
	}
	else if (i < 0 && i >= -len)
	{
		return str[i + len];
	}
	else
	{
		return str[len];
	}
}

String& String::operator=(const String &s)
{
	if (this == &s)
	{
		return *this;
	}

	if (str)
	{
		delete[](str);
	}
	len = s.len;
	str = new char[len + 1];
	std::strcpy(str, s.str);
	return *this;
}

String& String::operator=(const char *s)
{
	if (str)
	{
		delete[](str);
	}
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

String String::operator+(const String &s) const
{
	char* newS = new char[s.len + len + 1];
	std::strcpy(newS, str);
	//std::strcat(newS, s.str);
	std::strcpy(newS + len, s.str);
	return String(newS);
}

String String::operator+(const char *s) const
{
	char* newS = new char[std::strlen(s) + len + 1];
	std::strcpy(newS, str);
	//std::strcat(newS, s);
	std::strcpy(newS + len, s);
	return String(newS);
}

String& String::operator+=(const String &s)
{
	if (s.isEmpty())
	{
		return *this;
	}

	char* newS = new char[s.len + len + 1];
	std::strcpy(newS, str);
	//std::strcat(newS, s.str);
	std::strcpy(newS + len, s.str);
	
	if (str)
	{
		delete[](str);
	}
	str = newS;
	len += s.len;
	return *this;
}

String& String::operator+=(const char *s)
{
	int slen = std::strlen(s);
	if (!slen)
	{
		return *this;
	}

	char* newS = new char[slen + len + 1];
	std::strcpy(newS, str);
	//std::strcat(newS, s.str);
	std::strcpy(newS + len, s);

	if (str)
	{
		delete[](str);
	}
	str = newS;
	len += slen;
	return *this;
}

bool String::operator==(const String &s) const
{
	return !std::strcmp(str, s.str);
}

bool String::operator==(const char *s) const
{
	return !std::strcmp(str, s);
}

bool String::operator!=(const String &s) const
{
	return std::strcmp(str, s.str);
}

bool String::operator!=(const char *s) const
{
	return std::strcmp(str, s);
}

bool String::operator<(const String &s) const
{
	return (std::strcmp(str, s.str) < 0);
}

bool String::operator<(const char *s) const
{
	return (std::strcmp(str, s) < 0);
}

bool String::operator<=(const String &s) const
{
	return (std::strcmp(str, s.str) <= 0);
}

bool String::operator<=(const char *s) const
{
	return (std::strcmp(str, s) <= 0);
}

bool String::operator>(const String &s) const
{
	return (std::strcmp(str, s.str) > 0);
}

bool String::operator>(const char *s) const
{
	return (std::strcmp(str, s) > 0);
}

bool String::operator>=(const String &s) const
{
	return (std::strcmp(str, s.str) >= 0);
}

bool String::operator>=(const char * s) const
{
	return (std::strcmp(str, s) >= 0);
}

String& String::clear()
{
	if (str)
	{
		delete[](str);
	}
	str = new char[1];
	str[0] = '\0';
	len = 0;
	return *this;
}

String String::substring(int begin, int end) const
{
	if (begin >= end)
	{
		return String();
	}

	if (begin < 0)
	{
		begin = 0;
	}

	if (end >= len)
	{
		end = len - 1;
	}

	char *subS = new char[end - begin + 2];
	std::memcpy(subS, str + begin, sizeof(char) * (end - begin + 1));
	subS[end - begin + 1] = '\0';
	return String(subS);
}

String String::left(int count) const
{
	if (count <= 0)
	{
		return String();
	}

	if (count > len)
	{
		return String(str);
	}

	return this->substring(0, count - 1);
}

String String::right(int count) const
{
	if (count <= 0)
	{
		return String();
	}

	if (count > len)
	{
		return String(str);
	}

	return this->substring(len - count, len - 1);
}

bool String::hasSubstring(const String &s) const
{
	return std::strstr(str, s.str);
}

bool String::hasSubstring(const char *s) const
{
	return std::strstr(str, s);
}

bool String::hasSymbol(const char symbol) const
{
	return std::strchr(str, symbol);
}

String& String::removeSubstring(int begin, int end)
{
	if (end <= begin)
	{
		return *this;
	}

	if (begin < 0)
	{
		begin = 0;
	}

	if (end >= len)
	{
		end = len - 1;
	}

	char *newS = new char[len - (end - begin + 1) + 1];
	std::memcpy(newS, str, begin * sizeof(char));
	std::memcpy(newS + begin, str + end + 1, (len - end - 1) * sizeof(char));
	newS[len - (end - begin + 1)] = '\0';

	delete[](str);
	str = newS;
	len -= (end - begin + 1);
	return *this;
}

String& String::removeSubstring(const String &s)
{
	char *start = std::strstr(str, s.str);
	if (!start)
	{
		return *this;
	}

	char *newS = new char[len - s.len + 1];
	std::strcpy(newS, str);
	std::strcat(newS, start + s.len);

	delete[](str);
	str = newS;
	len -= (s.len - 1);
	return *this;
}

String& String::removeSubstring(const char *s)
{
	char *start = std::strstr(str, s);
	if (!start)
	{
		return *this;
	}

	int slen = std::strlen(s);
	char *newS = new char[len - slen + 1];
	std::strcpy(newS, str);
	std::strcat(newS, start + slen);

	if (str)
	{
		delete[](str);
	}
	str = newS;
	len -= (slen - 1);
	return *this;
}

String& String::removeLeft(int count)
{
	return this->removeSubstring(0, count - 1);
}

String& String::removeRight(int count)
{
	return this->removeSubstring(len - count, len - 1);
}

String String::getFirstWord(const String &separator) const
{
	int begin = 0, end;
	while (separator.hasSymbol(str[begin]) && begin < len)
	{
		++begin;
	}

	end = begin;
	while (!separator.hasSymbol(str[end]) && end < len)
	{
		++end;
	}

	return this->substring(begin, end - 1);
}

String String::getLastWord(const String &separator) const
{
	int begin, end = len;
	while (separator.hasSymbol(str[end]) && end > 0)
	{
		--end;
	}

	begin = end;
	while (!separator.hasSymbol(str[begin]) && begin >= 0)
	{
		--begin;
	}

	return this->substring(begin + 1, end);
}

String operator+(const char *s1, const String &s2)
{
	char* newS = new char[std::strlen(s1) + s2.len + 1];
	std::strcpy(newS, s1);
	//std::strcat(newS, s);
	std::strcpy(newS + std::strlen(s1), s2.str);
	return String(newS);
}

bool operator==(const char *s1, const String &s2)
{
	return !std::strcmp(s1, s2.str);
}

bool operator!=(const char *s1, const String &s2)
{
	return std::strcmp(s1, s2.str);
}

bool operator>(const char *s1, const String &s2)
{
	return (std::strcmp(s1, s2.str) > 0);
}

bool operator<(const char *s1, const String &s2)
{
	return (std::strcmp(s1, s2.str) < 0);
}

bool operator>=(const char *s1, const String &s2)
{
	return (std::strcmp(s1, s2.str) >= 0);
}

bool operator<=(const char *s1, const String &s2)
{
	return (std::strcmp(s1, s2.str) <= 0);
}

std::ostream& operator<<(std::ostream &os, const String &s)
{
	os << s.str;
	return os;
}
