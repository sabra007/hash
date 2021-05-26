#include "hash.cpp"

using namespace std;

void populateTheTable(hashClass Hashy)
{
	Hashy.AddItem("Paul", "Locha");
	Hashy.AddItem("Kim", "Iced Mocha");
	Hashy.AddItem("Emma", "Strawberry Smoothy");
	Hashy.AddItem("Annie", "Hot Chocolate");
	Hashy.AddItem("Sarah", "Passion Tea");
	Hashy.AddItem("Pepper", "Caramel Mocha");
	Hashy.AddItem("Mike", "Chai Tea");
	Hashy.AddItem("Steve", "Apple Cider");
	Hashy.AddItem("Bill", "Root Bill");
	Hashy.AddItem("Marie", "Skinny Latte");
	Hashy.AddItem("Susan", "Water");
	Hashy.AddItem("Joe", "Green Tea");
}

int main() {

	string name = "";
	hashClass Hashy;

	populateTheTable(Hashy);

	Hashy.PrintTable();
	
	Hashy.PrintItemsInIndex(2);
	
	return 0;
}
