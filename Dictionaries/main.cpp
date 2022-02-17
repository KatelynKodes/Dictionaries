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

template <typename K>
void inputKey(K& key, const char* string)
{
	while (key == NULL)
	{
		std::cout << string << std::endl;
		std::cin >> key;
	}
}

template <typename V>
void inputValue(V& value, const char* string)
{
	while (value == NULL)
	{
		std::cout << string << std::endl;
		std::cin >> value;
	}
}

template <typename Tkey, typename Tval>
void print(Dictionary<Tkey, Tval>* dict)
{
	for (int i = 0; i <= dict->getCount(); i++)
	{
		std::cout << (*dict)[i] << std::endl;
	}
}

int main()
{
	int playerInput = 0;
	int valueInput;
	int keyInput;

	Dictionary<int, int>* dictionary = new Dictionary<int, int>();
	Dictionary<int, int>* dictionary2 = new Dictionary<int, int>();

	dictionary2->addItem(1, 73482);
	dictionary2->addItem(2, 38284);
	dictionary2->addItem(3, 32478);
	dictionary2->addItem(4, 37238);
	dictionary2->addItem(5, 49309);


	dictionary->addItem(0, 826);
	dictionary->addItem(1, 748);
	dictionary->remove(1);
	dictionary->addItem(2, 126);
	dictionary->addItem(3, 674);
	dictionary->addItem(4, 754);

	while (playerInput != -1)
	{
		valueInput = NULL;
		keyInput = NULL;

		print(dictionary);
		countDictionary(dictionary);
		std::cout << "[1] Add Item \n[2] Remove Item \n[3] Remove Value \n[4] Check for Key \n[5] Check for Value\n"<<
					 "[6] Get Value\n[7] Clear Dictionary \n[8] Set to new Dictionary" <<std::endl;
		std::cin >> playerInput;

		switch (playerInput)
		{
		case 1:
			inputValue(valueInput, "What will be the value put into the dictionary?");

			inputKey(keyInput, "What will be the key associated with that value?");

			dictionary->addItem(keyInput, valueInput);

			std::cin.get();
			break;
		case 2:

			inputKey(keyInput, "What is the key of the item you want to remove from the dictionary?");

			if (dictionary->remove(keyInput))
				std:: cout << "Item with the key " << keyInput <<" was successfully removed" << std::endl;
			else
				std::cout << "Item with the key " << keyInput << " was unable to be removed" << std::endl;

			std::cin.get();
			break;

		case 3:
			inputValue(valueInput, "What value do you want to remove from the dictionary?");
			inputKey(keyInput, "What key is the value associated with?");

			dictionary->remove(keyInput, valueInput);

			std::cin.get();
			break;
		case 4:
			inputKey(keyInput, "What is the key you want to search for?");

			if (dictionary->containsKey(keyInput))
				std::cout << "Key found, " << keyInput << " contains a value of " << dictionary->operator[](keyInput) << std::endl;
			else
				std::cout << "Key not found" << std::endl;

			std::cin.get();
			break;

		case 5:
			inputValue(valueInput, "What is the value you want to search for?");

			if (dictionary->containsValue(valueInput))
				std::cout << "Value found"<< std::endl;
			else
				std::cout << "Value not found" << std::endl;

			std::cin.get();
			break;

		case 6:
			inputValue(valueInput, "What is the value you want to get?");
			inputKey(keyInput, "What is the key associated with this value?");

			if (dictionary->tryGetValue(keyInput, valueInput))
				std::cout << "Value found" << std::endl;
			else
				std::cout << "Value not found" << std::endl;

			std::cin.get();
			break;

		case 7:
			dictionary->clear();
			std::cout << "Dictionary cleared";
			std::cin.get();
			break;

		case 8:
			Dictionary<int, int>* newDictionary = new Dictionary<int,int>();

			dictionary = newDictionary;
			std::cout << "The dictionary has been replaced"<< std::endl;
			std::cin.get();
			break;
		}
	}
}