#pragma once
#include <iostream>

template <typename T>
void printArray(T *mass, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << mass[i] << ' ';
	}
	std::cout << std::endl;
}

template <typename T>
void swap(T *left, T *right)
{
	T temp = *left;
	*left = *right;
	*right = temp;
}

template <typename T>
void rightShift(T *mass, int left, int right)
{
	T temp = mass[right];
	for (int i = right; i > left; i--)
	{
		mass[i] = mass[i - 1];
	}
	mass[left] = temp;
}

template <typename T>
void merge(T *mass, int left, int right)
{
	int l = 0, r = left;
	while (l < r && r < (left + right))
	{
		if (mass[l] >= mass[r])
		{
			rightShift<T>(mass, l, r);
			++r;
		}
		++l;
	}
}

template <typename T>
void mergeSort(T *mass, int size)
{
	if (size == 1) return;

	if (size == 2)
	{
		if (mass[0] > mass[1]) swap<T>(mass, mass + 1);
		return;
	}

	int left = size / 2, right = size - left;
	mergeSort<T>(mass, left);
	mergeSort<T>(mass + left, right);

	merge<T>(mass, left, right);

}