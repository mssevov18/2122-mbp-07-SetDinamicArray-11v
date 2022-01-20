#pragma once

// Dynamic - не Dinamic!
// Не е добра идея да са слагат default стойности в дефиницията
// Има конвенция за имената на променливи!
// Когато се създава конструктор с параметри е задължително да се имплементира и конструктор без параметри
//Защо DEFAULTSIZE е в All caps
//Защо DEFAULTSIZE не е static? DEFAULTSIZE се използва само при празен конструктор

class Set
{
	int size;
	static const int DEFAULTSIZE = 10;
	int* elements;

public:
	// Default constructor
	Set(int s);
	Set(int* arr, int size);

	// True Default constructor
	Set();

	// Destructor
	~Set();

	bool contains(int n);
	Set unionWith(Set& Y);
	Set intersectWith(Set& Y);
	Set complementWith(Set& Y);
	// Множествата се харесват и затова си дават комлименти :|
	// Това е тристранен комплимент...
	// Симетрик е нова марка вафли
	Set complimentSimetric(Set& X, Set& Y);

	void sort();
	int calcDegree();
	void enterFromKeyboard(int& count);
	void display();
};