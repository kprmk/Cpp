#include "Fraction.h"
#include <iostream>
#include <cstdio>

Fraction::Fraction()
{
}

Fraction::Fraction(int ch, int zn)
{
	this->ch = ch;
	this->zn = zn;
}

Fraction::~Fraction()
{
}

Fraction Fraction::operator+(const Fraction &b)const
{
	Fraction r(this->ch * b.zn + b.ch * this->zn, this->zn * b.zn);
	return r;
}

Fraction Fraction::operator-(const Fraction &b)const
{
	Fraction r(this->ch * b.zn - b.ch * this->zn, this->zn * b.zn);
	return r;
}

Fraction Fraction::operator*(const Fraction &b)const
{
	Fraction r(this->ch *b.ch, this->zn * b.zn);
	return r;
}

Fraction Fraction::operator/(const Fraction &b)const
{
	Fraction r(this->ch * b.zn, this->zn * b.ch);
	return r;
}

Fraction& Fraction::operator+=(const Fraction &b)
{
	ch = ch * b.zn + b.ch * zn;
	zn = zn * b.zn;
	return *this;
}

Fraction& Fraction::operator-=(const Fraction &b)
{
	ch = ch * b.zn - b.ch * zn;
	zn = zn * b.zn;
	return *this;
}

Fraction& Fraction::operator*=(const Fraction &b)
{
	ch = ch * b. ch;
	zn = zn * b.zn;
	return *this;
}

Fraction& Fraction::operator/=(const Fraction &b)
{
	ch = ch * b.zn;
	zn = zn * b.ch;
	return *this;
}

float Fraction::to_decimal()
{
	float a = (float)ch;
	float b = (float)zn;
	return a / b;
}

bool Fraction:: operator!=(Fraction &b)
{
	if (zn == b.zn)
	{
		if (ch == b.ch)
			return false;
		else
			return true;
	}
	else
	{
		zn = zn * b.zn;
		b.zn = zn * b.zn;
		if (ch == b.ch)
			return false;
		else
			return true;
	}
}

bool Fraction::operator==(Fraction &b)
{
	if (zn == b.zn)
	{
		if (ch == b.ch)
			return true;
		else
			return false;
	}
	else
	{
		zn = zn * b.zn;
		b.zn = zn * b.zn;
		if (ch == b.ch)
			return true;
		else
			return false;
	}
}

bool Fraction::operator>(Fraction &b)
{
	if (zn == b.zn)
	{
		if (ch > b.ch)
			return true;
		else
			return false;
	}
	else
	{
		zn = zn * b.zn;
		b.zn = zn * b.zn;
		if (ch > b.ch)
			return true;
		else
			return false;
	}
}

bool Fraction::operator<(Fraction &b)
{
	if (zn == b.zn)
	{
		if (ch < b.ch)
			return true;
		else
			return false;
	}
	else
	{
		zn = zn * b.zn;
		b.zn = zn * b.zn;
		if (ch < b.ch)
			return true;
		else
			return false;
	}
}

bool Fraction::operator>=(Fraction &b)
{
	if (zn == b.zn)
	{
		if (ch >= b.ch)
			return true;
		else
			return false;
	}
	else
	{
		zn = zn * b.zn;
		b.zn = zn * b.zn;
		if (ch >= b.ch)
			return true;
		else
			return false;
	}
}

bool Fraction::operator<=(Fraction &b)
{
	if (zn == b.zn)
	{
		if (ch <= b.ch)
			return true;
		else
			return false;
	}
	else
	{
		zn = zn * b.zn;
		b.zn = zn * b.zn;
		if (ch <= b.ch)
			return true;
		else
			return false;
	}
}

Fraction operator+(const Fraction &a, const int b)
{
	Fraction r(a.ch + b * a.zn, a.zn);
	return r;
}

Fraction operator-(const Fraction &a, const int b)
{
	Fraction r(a.ch - b * a.zn, a.zn);
	return r;
}

Fraction operator*(const Fraction &a, const int b)
{
	Fraction r(a.ch * b, a.zn);
	return r;
}

Fraction operator/(const Fraction &a, const int b)
{
	Fraction r(a.ch, a.zn * b);
	return r;
}

Fraction& operator+=(Fraction &a, const int b)
{
	a.ch = a.ch + b * a.zn;
	return a;
}

Fraction& operator-=(Fraction &a, const int b)
{
	a.ch = a.ch - b * a.zn;
	return a;
}

Fraction& operator*=(Fraction &a, const int b)
{
	a.ch *= b;
	return a;
}

Fraction& operator/=(Fraction &a, const int b)
{
	a.zn *= b;
	return a;
}

Fraction Fraction::simple()
{
	int a;
	do
	{
		a = NOD(ch, zn);
		ch /= a;
		zn /= a;
	} while (a);
	return *this;
}

int NOD(int a, int b)
{
	if (a < b)
	{
		int d = a;
		a = b;
		b = a;
	}
	int c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

std::ostream& operator<<(std::ostream&os, const Fraction& f)
{
	os << f.ch << '/' << f.zn << std::endl;
	return os;
}