|Katelyn West|
| :---          	|
| S218002   |
|Code Design and Data Structures|
|   Dictionary Test Application|

## I. Requirements

1. **Input information**
    - 1 key: Adds an item to the dictionary.
    - 2 key: Removes an item from the dictionary through a key
    - 3 key: Removes an item from the dictionary through a value
    - 4 key: Checks for a specific key is inside the dictionary.
    - 5 key: Checks for a specific value inside the dictionary.
    - 6 key: Returns a specific value inside the dictionary
    - 7 key: Clears the dictionary from all it's value.
    - 8 key: Sets the current dictionary to a new, empty dictionary
2. **Output Information**
    - If the user decides to remove or add an item to the dictionary, the dictionary is altered to include or not include whatever was attempted to be removed or added, then it will display the current list of values in the dictionary on the screen. If the other wishes to find an item in the dictionary of a certain key or value, the dictionary is searched though and the value is found if the item exists inside of it. A prompt is then displayed on the screen indicating what was found. If the value or key does not exist in the dictionary a string is returned indicating the value or key could not be found.
3. **User Interface Information**
    - The interface displays printed values of the dictionary and a string contianing the current number of items in the dictionary as well as a list of inputs the user can call. As the user calls the inputs on the screen the dictionary will either change according to what the user does to the array or will return either a key or value the user is trying to search for.

## II. Design

1. _System Architecture_
    - The dictionary class is a template class that has typenames of TKey and TValue, with these typenames the class is more accessible to multiple types such as characters, integers, and floats. Each item in the Dictionary is created with a struct, this struct contains a TKey variable where the item key is stored and a TValue variable storing the items key. These items are then stored into a pointer in the dictionary class that points to a Items array.  From there, the dictionary is capable of iterating through the Item array as well as accessing and reading its items. This allows the dictionary class to be the sole responsible class for accessing and reading all the items in the list. There is also an integer value indicating the dictionaries length that increments as items are added to the item array, and decrements as items are removed from the item array.
    
2. _Object Information_
    - **FileName**: Dictionary.h
        - **Class Name**: Dictionary
            - Name: Dictionary\<TKey, Tvalue>()
            - Description: The base constructor for the dictionary class.Sets the count to 0 and the items to be a null pointer.
            - Visibility: public
            - Arguments: none

            - Name: Dictionary\<TKey, Tvalue>()
            - Description: The override constructor for the dictionary, sets the count to be equal to the count of the dictionary that was passed into the constructor, and the items to be equal to the items of the dictionary passed into the constructor.
            - Visibility: Public
            - Arguments: other (const Dictionary\<Tkey, TValue>&)

            - Name: ~Dictionary()
            - Description: The destructor of the Dictionary class, calls the clear method.
            - Visibility: public
            - Arguments: none

            - Name: clear()
            - Description: while the count is not equal to 0, the first item in the items array is passed into the remove method.
            - Visibility: public
            - Arguments: none

            - Name: containsKey()
            - Description: Iterates through the items array and if the item at the current index's key matched the key passed into the method, the method returned true. Returns false if the count of the array is equal to 0 or if no item key matches the key passed into the method
            - Visibility: public
            - Arguments: object (TKey)

            - Name: containsValue()
            - Description: Iterates through the items array and if the item at the current index's value matched the value passed into the method, the method returned true. Returns false if the count of the array is equal to 0 or if no item value matches the value passed into the method
            - Visibility: public
            - Arguments: object (TValue)

            - Name: tryGetValue()
            - Description: Tries to find an item that matches a certain key. Iterates through the item array and if the item at the current index's key matched the key passed into the method, the value passed into the method is set to be the current items value. 
            - Visibility: public
            - Arguments: key (TKey), value (TValue&)

            - Name: getCount()
            - Description: Returns the m_count variable, giving the length of the dictionary.
            - Visibility: public
            - Arguments: none

            - Name: operator=()
            - Description: clears the dictionary, then iterates through a for loop set to loop as many times as the count of the Dictionary being passed into the operator, for every loop the item at the index of i is added to the dictionary then after the for loop is completed the dictionary is returned in a de-refrenced state.
            - Visibility: public
            - Arguments: other ( const Dictionary\<TKey, TValue>)

            - Name: Operator[]
            - Description: creates an empty TValue variable and places it in the tryGetValue method along with the key passed into the operator. returns the variable which should contain the variable associated with that key.
            - Visibility: public
            - Arguments: key (const TKey)

            - Name: addItem()
            - Description: 
            - Visibility: public
            - Arguments: key (const TKey&), value (const TValue&)

            - Name: remove()
            - Description: Two booleans are created called "wasRemoved" and "wasFound" and are set to false. If the count of the dictionary is not equal to zero, a new item list is created and is set to be one value smaller than the current dictionary. A for loop iterates through the item array and if that item's key is not equal to the key passed into the method it is added to the new item list. If the current items key is equal to the item key passed into the method "wasFound" is set to true. After the loop is exited if wasfound is true the items list is set to the new item list and the count decrements and "wasRemoved" is set to true. The method returns the value of "wasRemoved"
            - Visibility: public
            - Arguments: key (const TKey)

            - Name: remove()
            - Description: A for loop iterates through the item list and if the item at the current index has a key that matches the key passed into the method the value passed into the method is set to the items value, then the remove function is called with the key passed into the method as a parameter.
            - Visibility: public
            - Arguments: key (const TKey), value (TValue&)

            