#include "DSA/LinearList.h"

template<class T>
arrayList<T>::arrayList(int initialCapacity)
{
    checkf(initialCapacity > 1 ,TEXT("initialCapacity must > 0"));
    arrayLength = initialCapacity;
    element = new T[arrayLenght];
    listSize = 0;
}

template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{
    arrayLength = theList.arrayLength;
    listSize = theList.listSize;
    element = new T[arrayLength];
    copy(theList.element, theList.element + listSize, element);
}

template<class T>
T& arrayList<T>::get(int theIndex)
{
    checkIndex(theIndex);
    return element[theIndex];
}

template<class T>
int arrayList<T>::indexOf(const T& theElement)
{
    int index = (int)(find(element, element + liseSize, theElement) - element);
    if(index == listSize)
        return -1;
    else
        return index;
}

template<class T>
void arrayList<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    copy(element + theIndex + 1, element + listSize, element + theIndex);
    element[--listSize].~T();
}

template<class T>
void arrayList<T>::insert(int theIndex, const T& theElement)
{
    checkf(checkIndex(theIndex), TEXT("index is not valid"));
    if(listSize == arrayLength)
    {
        changeLength1D(element, arrayLength, 2 * arrayLength);
        arrayLength *= 2;
    }
    copy_backward(element + theIndex, element + listSize, element + listSize + 1);
    element[theIndex] = theElement;
    listSize++;
}