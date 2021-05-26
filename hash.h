using namespace std;

#ifndef HASH_H
#define HASH_H

class hashClass{

private:
	static const int tableSize = 4;
	struct item {
		string name;
		string drink;
		item* next;
	};
	
	item* HashTable[tableSize];	//Array of item* pointers

public:
	hashClass();
	int HashFunc(string key);
	void AddItem(string name, string drink);
	int numberOfItemsInIndex(int index);
	void PrintTable();
	void PrintItemsInIndex(int index);
	void findDrink(string name);
	void removeItem(string name);
};

#endif // !HASH_H