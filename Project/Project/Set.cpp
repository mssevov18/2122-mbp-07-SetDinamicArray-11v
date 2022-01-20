#include <iostream>
#include <vector>
#include "Set.h"

Set::Set(int s)
{
	this->size = s;
	elements = new int[size];

	int count = 0;
	for (int i = 0; i < size; i++)
		enterFromKeyboard(count);
}

Set::Set(int* arr, int size)
{
	this->size = size;
	this->elements = arr;
}

Set::Set()
{
	this->size = Set::DEFAULTSIZE;
	elements = new int[size];

	//int count = 0;
	//for (int i = 0; i < size; i++)
	//	enterFromKeyboard(count);
}

Set::~Set()
{
	delete[] this->elements;
	delete this;
}

bool Set::contains(int n)
{
	for (int i = 0; i < size; i++)
		if (elements[i] == n)
			return true;
	return false;
}

Set Set::unionWith(Set& Y)
{
	int* arr = new int[this->size + Y.size];
	int arrCount = 0;
	for (int i = 0; i < this->size; i++)
		arr[arrCount++] = this->elements[i];
	for (int i = 0; i < Y.size; i++)
		arr[arrCount++] = Y.elements[i];
	return Set(arr, this->size + Y.size);
}

Set Set::intersectWith(Set& Y)
{
	Set newSet;
	int count = 0;
	for (int i = 0; i < size; i++)
		if (Y.contains(elements[i]))
			newSet.elements[count++] = elements[i];
	return newSet;
}

Set relativeComplement(int arr1[], int arr2[], int n, int m)
{
	std::vector<int> mem;
	int i = 0, j = 0;
	while (i < n && j < m)
	{

		// If current element in arr2[] is
		// greater, then arr1[i] can't be
		// present in arr2[j..m-1]
		if (arr1[i] < arr2[j])
			mem.push_back(arr1[i++]);

			// Skipping smaller elements of
			// arr2[]
		else if (arr1[i] > arr2[j])
			j++;

			// Equal elements found (skipping
			// in both arrays)
		else if (arr1[i] == arr2[j])
		{
			i++;
			j++;
		}
	}

	// Printing remaining elements of
	// arr1[]
	while (i < n)
		mem.push_back(arr1[i]);

	int* arrOut = new int[mem.size()];
	for (int z = 0; z < mem.size(); z++)
		arrOut[z] = mem[z];
	return Set(arrOut, mem.size());
}

Set Set::complementWith(Set& Y)
{
	return relativeComplement(this->elements, Y.elements, this->size, Y.size);
}

Set symmDiff(int arr1[], int arr2[], int n, int m)
{
	std::vector<int> mem;
	// Traverse both arrays simultaneously.
	int i = 0, j = 0;
	while (i < n && j < m)
	{
	
		// Print smaller element and move
		// ahead in array with smaller element
		if (arr1[i] < arr2[j])
			mem.push_back(arr1[i++]);
		else if (arr2[j] < arr1[i])
			mem.push_back(arr2[j++]);

		// If both elements same, move ahead
		// in both arrays.
		else
		{
			i++;
			j++;
		}
	}
	while (i < n)
		mem.push_back(arr1[i++]);
	while (j < m)
		mem.push_back(arr2[j++]);
	int* arrOut = new int[mem.size()];
	for (int z = 0; z < mem.size(); z++)
		arrOut[z] = mem[z];
	return Set(arrOut, mem.size());
}

Set Set::complimentSimetric(Set& X, Set& Y)
{
	return symmDiff(X.elements, Y.elements, X.calcDegree(), Y.calcDegree());
}

void swap(int* lhs, int* rhs)
{
	int* tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

void Set::sort()
{
	for (int i = 0; i < this->size - 1; i++)
		for (int j = 0; j < this->size - i - 1; j++)
			if (this->elements[j] > this->elements[j + 1])
				swap(&this->elements[j], &this->elements[j + 1]);
}

int Set::calcDegree()
{
	return this->size;
}

void Set::enterFromKeyboard(int& count)
{
	std::cin >> elements[count++];
}


void Set::display()
{
	for (int i = 0; i < this->size; i++)
		std::cout << elements[i] << " ";
	std::cout << '\n';
}