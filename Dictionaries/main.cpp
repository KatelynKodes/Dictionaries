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

int main()
{
	Dictionary<const char*, int>* inventory = new Dictionary<const char*, int>();


}