# 2122-mbp-07-SetDinamicArray-11v
HomeWork 21:30-21:50

Реализирайте методите от класа Set.

class Set

{
	int size = 0;
	
	int DEFAULTSIZE = 10;
	
	int* elements = new int[size];
	

public:

	// Default constructor
	
	Set(int s);
		
	// Destructor
	
	~Set();

	bool contains(int n);
	Set unionWith(Set& Y);
	Set intersectWith(Set& Y);
	Set complementWith(Set& Y);
	Set complimentSimetric(Set& X, Set& Y);

	void sort();
	int calcDegree();
	void enterFromKeyboard();
	void display();

};
