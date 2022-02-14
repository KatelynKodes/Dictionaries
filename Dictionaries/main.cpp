#include "Dictionary.h"
#include <iostream>

template <typename Tkey, typename Tval>
void printDictionary(Dictionary<Tkey, Tval>* dictionary)
{
	for (int i = 0; i < dictionary->getCount(); i++)
	{

	}

	std::endl;
}

template <typename Tkey, typename Tval>
void countDictionary(Dictionary<Tkey, Tval>* dictionary)
{
	int numOfItems = 0;
	for (int i = 0; i < dictionary->getCount(); i++)
	{
		numOfItems++;
	}

	std::cout << "There are currently " << numOfItems << " items in your dictionary" << std::endl;
}

int main()
{
	int playerInput = 0;
	const char* KeyInput = "";
	int valueInput = 0;

	Dictionary<const char*, int>* inventory = new Dictionary<const char*, int>();

	while (playerInput != 9)
	{
		std::cout << "[1] Add Item \n[2] Remove Item \n[3]Check for Key \n[4]Check for Value\n[5] Clear Dictionary";
		std::cin >> playerInput;
	}
}