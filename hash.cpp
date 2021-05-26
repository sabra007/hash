#include <iostream>
#include <cstdlib>
#include <string>
#include "hash.h"

using namespace std;
hashClass::hashClass()
{
	for (int i = 0; i < tableSize; i++) {
		HashTable[i] = new item;
		HashTable[i]->name = "empty";
		HashTable[i]->drink = "empty";
		HashTable[i]->next = NULL;
	}
}
int hashClass::HashFunc(string key)
{
	int hash = 0;
	int index;

	for (int i = 0; i < key.length(); i++)
	{
		hash = (hash + (int)key[i]) * 17;
	}
	index = hash % tableSize;
	return index;
}
void hashClass::AddItem(string name, string drink)
{
	int index = HashFunc(name);

	if (HashTable[index]->name == "empty")
	{
		HashTable[index]->name = name;
		HashTable[index]->drink = drink;
	}
	else
	{
		item* Ptr = HashTable[index];
		item* n = new item;
		n->name = name;
		n->drink = drink;
		n->next = NULL;

		while (Ptr->next != NULL)
		{
			Ptr = Ptr->next;
		}
		Ptr->next = n;
	}

}
int hashClass::numberOfItemsInIndex(int index) {

	int count = 0;

	if (HashTable[index]->name == "empty")
	{
		return count;
	}
	else
	{
		count++;
		item* Ptr = HashTable[index];
		while (Ptr->next != NULL)
		{
			Ptr = Ptr->next;
			count++;
		}
		return count;
	}
}

void hashClass::PrintTable()
{
	for (int i = 0; i < tableSize; i++)
	{
			cout << "---------------------------------\n";
		cout << "index: " << i << endl;
		cout << HashTable[i]->name << " " << HashTable[i]->drink << endl;
		cout << "Number of items: " << numberOfItemsInIndex(i) << endl;
		cout << "---------------------------------\n";
	}
}

void hashClass::PrintItemsInIndex(int index)
{
	item* Ptr = HashTable[index];

	if (Ptr->name == "empty")
	{
		cout << "Bucket " << index << " is empty.\n";
	}
	else
	{
		cout << "Index " << index << " contains the following items.\n";

		while (Ptr != NULL)
		{
			cout << "---------------------------------\n";
			cout << Ptr->name << " " << Ptr->drink << endl;
			cout << "---------------------------------\n";
			Ptr = Ptr->next;
		}
	}

}
void hashClass::findDrink(string name)
{
	int index = HashFunc(name);
	bool foundName = false;

	string drink;

	item* Ptr = HashTable[index];
	while (Ptr != NULL)
	{
		if (Ptr->name == name)
		{
			foundName = true;
			drink = Ptr->drink;
		}
		Ptr = Ptr -> next;
	}
	if (foundName)
	{
		cout << name <<"'s favorite drink is " << drink << "." << endl;
	}
	else
	{
		cout << name << "'s info was not found in the hash table. \n";
	}
}

void hashClass::removeItem(string name)
{
	int index = HashFunc(name);
	item* delPtr;
	item* p1;
	item* p2;

	//case 0 - bucket is empty
	if (HashTable[index]->name == "empty" && HashTable[index]->drink == "empty")
	{
		cout << name << " was not found in the hash table\n" ;
	}
	//case 1 - 1 item contained in bucket and has a matching name
	else if (HashTable[index]->name == name && HashTable[index]->next == NULL)
	{
		HashTable[index]->name = "empty";
		HashTable[index]->drink = "empty";
		cout << name << " was removed from the hash table\n";
	}
	//case 2 - match is located in the first item in the bucket but there are more items

	else if (HashTable[index]->name == name)
	{
		delPtr = HashTable[index];
		HashTable[index] = HashTable[index]->next;
		delete delPtr;

		cout << name << " was removed from the hash table\n";
	}
	//case 3 - bucket is not empty but first item isnt a match
	else
	{
		p1 = HashTable[index]->next;
		p2 = HashTable[index];  //trailing behind p1

		while (p1 != NULL && p1->name != name)
		{
			p2 = p1;
			p1 = p1->next;
		}
		// now either p1 is pointing to NULL or to match
		//case 3.1 - no match
		if (p1 == NULL)
		{
			cout << name << " was not found in the hash table\n";
		}
		//case 3.2 - match is somewhere inside
		else
		{
			delPtr = p1;
			p1 = p1->next;
			p2->next = p1;
			delete delPtr;
			cout << name << " was removed from the hash table\n";
		}
	}
}