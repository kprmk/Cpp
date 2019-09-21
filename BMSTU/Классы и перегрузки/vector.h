#pragma once
#include<iostream>
#include<cstdio>

class vector
{
private:
	float * mas;
	int space;
public:
	vector(int N, char a);
	vector(int N, int a);
	vector(int N);
	vector(const vector &a);
	vector(int N, float * a);
	~vector();



	void zapolny(int N);

	int get_space(){ return space; };
	friend std::ostream& operator<<(std:: ostream &os, const vector & v);

	vector operator+(const vector & a);
	vector operator-(const vector & a);

	vector& operator=(const vector & a);
	double & operator*(const vector & a);
	vector operator*(int a);

	const float operator[](const int i)const;
};

