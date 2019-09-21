#pragma once
#include <iostream>

class Fraction
{
private:
	int ch;
	int zn;
public:
	Fraction();
	Fraction(int ch, int zn);
	~Fraction();

	int get_ch(){ return ch; };
	int get_zn(){ return zn; };

	Fraction operator+(const Fraction &b)const;
	Fraction operator-(const Fraction &b)const;
	Fraction operator*(const Fraction &b)const;
	Fraction operator/(const Fraction &b)const;

	Fraction& operator+=(const Fraction &b);
	Fraction& operator-=(const Fraction &b);
	Fraction& operator*=(const Fraction &b);
	Fraction& operator/=(const Fraction &b);

	float to_decimal();

	bool operator!=(Fraction &b);
	bool operator==(Fraction &b);
	bool operator>(Fraction &b);
	bool operator<(Fraction &b);
	bool operator<=(Fraction &b);
	bool operator>=(Fraction &b);

	friend Fraction operator+(const Fraction &a, const int b);
	friend Fraction operator-(const Fraction &a, const int b);
	friend Fraction operator*(const Fraction &a, const int b);
	friend Fraction operator/(const Fraction &a, const int b);

	friend Fraction& operator+=(Fraction &a, const int b);
	friend Fraction& operator-=(Fraction &a, const int b);
	friend Fraction& operator*=(Fraction &a, const int b);
	friend Fraction& operator/=(Fraction &a, const int b);

	friend int NOD(int a, int b);
	Fraction simple();

	friend std::ostream& operator<<(std::ostream&os, const Fraction& f);
};

