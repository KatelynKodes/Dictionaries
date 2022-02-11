#pragma once

template <typename TKey, typename TValue>
class Dictionary
{
	struct Item
	{
		TKey itemKey;
		TValue itemValue;
	};

public:
	//Constructors and destructors

	Dictionary<TKey, TValue>();
	Dictionary<TKey, TValue>(const Dictionary<TKey,TValue>& other);
	~Dictionary<TKey, TValue>();

	///<summary> Deletes all items in dictionary </summary>
	void clear();

	///<summary> checks to see if an item that has the given key is in the dictionary </summary>
	///<param name = "object"> The key of the object trying to be found</param>
	bool containsKey(const TKey object) const;

	///<summary> checks to see if an item that has the given value is in the dictionary </summary>
	///<param name = "object"> The value of the object trying to be found</param>
	bool containsValue(const TValue object) const;

	///<summary> tries to find the item that matches the given key </summary>
	///<param name = "key"> The key of the object trying to be found</param>
	///<param name = "value"> The value of the object trying to be found</param>
	bool tryGetValue(const TKey key, const TValue& value);

	///<summary> tries to find the item that matches the given key </summary>
	///<returns> m_count integer indicating the number of </returns>
	int getCount() const { return m_count; }


	Dictionary<TKey, TValue> operator=(const Dictionary<TKey, TValue> other) const;

	///<summary> creates a new item with the given key and value and adds it to the dictionary </summary>
	///<param name = "key"> The key of the object trying to be added</param>
	///<param name = "value"> The value of the object trying to be added</param>
	void addItem(const TKey& key, const TValue& value);

	///<summary> removes the item that has the given key </summary>
	///<param name = "key"> The key of the object trying to be removed</param>
	bool remove(const TKey key);

	///<summary> removes the item that has the given key and gives back the value of the item that was removed </summary>
	///<param name = "key"> The key of the object trying to be removed</param>
	///<param name = "value"> The value of the object trying to be removed</param>
	bool remove(const TKey key, TValue& value);

private:
	Item* m_items = nullptr;
	int m_count = 0;
};

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::Dictionary()
{
	m_count = 0;
	m_items = new Item[m_count];
}

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::Dictionary(const Dictionary<TKey, TValue>& other)
{
	m_items = other.m_items;
	m_count = other.m_count;
}

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::~Dictionary()
{
	clear();
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::clear()
{

}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsKey(const TKey object) const
{
	if (m_count == 0)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < m_count; i++)
		{
			if (m_items[i].itemKey == object)
			{
				return true;
			}
		}

		return false;
	}
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsValue(const TValue object) const
{
	if (m_count == 0)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < m_count; i++)
		{
			if (m_items[i].itemValue == object)
			{
				return true;
			}
		}

		return false;
	}
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::tryGetValue(const TKey key, const TValue& value)
{
	return false;
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::addItem(const TKey& key, const TValue& value)
{
	Item* newItemList = new Item[m_count + 1];
	Item* item = Item{ key,value };

	for (int i = 0; i < m_count; i++)
	{
		newItemList[i] = m_items[i];
	}

	newItemList[m_count + 1] = item;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key)
{
	return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key, TValue& value)
{
	return false;
}
