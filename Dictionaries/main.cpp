#include "Dictionary.h"
#include <iostream>

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
	int valueInput;
	int keyInput;

	Dictionary<int, int>* dictionary = new Dictionary<int, int>();

	dictionary->addItem(1, 826);
	dictionary->addItem(2, 748);
	dictionary->addItem(3, 126);
	dictionary->addItem(4, 674);
	dictionary->addItem(5, 754);

	while (playerInput != -1)
	{
		valueInput = NULL;
		keyInput = NULL;

		countDictionary(dictionary);
		std::cout << "[1] Add Item \n[2] Remove Item \n[3]Check for Key \n[4]Check for Value\n[5] Clear Dictionary"<<std::endl;
		std::cin >> playerInput;

		switch (playerInput)
		{
		case 1:
			while (valueInput == NULL)
			{
				std::cout << "What will be the value put into the dictionary?" << std::endl;
				std::cin >> valueInput;
			}

			while (keyInput == NULL)
			{
				std::cout << "What will be the key associated with that value?" << std::endl;
				std::cin >> keyInput;
			}

			dictionary->addItem(keyInput, valueInput);
			break;
		case 2:
			while (keyInput == NULL)
			{
				std::cout << "What is the key of the item you want to remove from the dictionary?" << std::endl;
				std::cin >> keyInput;
			}
			dictionary->remove(keyInput);
			break;

		case 3:
			while (keyInput == NULL)
			{
				std::cout << "What is the key you want to search for?" << std::endl;
				std::cin >> keyInput;
			}

			if (dictionary->containsKey(keyInput))
				std::cout << "Key found" << std::endl;
			else
				std::cout << "Key not found" << std::endl;
			break;

		case 4:
			while (valueInput == NULL)
			{
				std::cout << "What is the value you want to search for?" << std::endl;
				std::cin >> valueInput;
			}

			if (dictionary->containsValue(valueInput))
				std::cout << "Value found"<< std::endl;
			else
				std::cout << "Value not found" << std::endl;
			break;

		case 5:
			dictionary->clear();
			std::cout << "Dictionary cleared";
			break;
		}
	}
}