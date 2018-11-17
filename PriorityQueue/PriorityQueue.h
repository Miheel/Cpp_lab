#ifndef IPRIORITYQUEUE_H
#define IPRIORITYQUEUE_H
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#include "IProrityQueue.h"

template<typename T>
class PriorityQueue :public IPriorityQueue<T>
{
public:
	PriorityQueue();
	PriorityQueue(PriorityQueue const& origObj);
	PriorityQueue<T>& operator=(PriorityQueue<T> const& origObj);
	~PriorityQueue();
	void enqueue(const T& element);
	T dequeue()throw(...);
	T front() const throw(...);
	bool isEmpty()const;

private:
	T* element;
	int nrOfElements;
	int capacity;
	void expand();
	void sort(T arr[], int size);
	void swap(T *arr1, T *arr2);
	int search(T arr[], int size);
	void copy(PriorityQueue<T> const &origObj);
	void freeMemory() const;
};
#endif // !IPRIORITYQUEUE_H

template<typename T>
inline PriorityQueue<T>::PriorityQueue()
{
	this->capacity = 4;
	this->nrOfElements = 0;
	this->element = new T[this->capacity];
}

template<typename T>
inline PriorityQueue<T>::PriorityQueue(PriorityQueue const  & origObj)
{
	copy(origObj);
}

template<typename T>
inline PriorityQueue<T> & PriorityQueue<T>::operator=(PriorityQueue<T> const & origObj)
{
	if (this != &origObj)
	{
		this->freeMemory();
		copy(origObj);
	}
	return *this;
}

template<typename T>
inline PriorityQueue<T>::~PriorityQueue()
{
	this->freeMemory();
}

template<typename T>
inline void PriorityQueue<T>::enqueue(const T & element)
{
	if (this->nrOfElements == this->capacity)
	{
		this->expand();
	}

	this->element[this->nrOfElements++] = element;
	this->sort(this->element, this->nrOfElements);
}

template<typename T>
inline T PriorityQueue<T>::dequeue() throw(...)
{
	if (this->isEmpty() == true)
	{
		throw "Empty Queue";
	}
	this->search(this->element, this->nrOfElements);
	return this->element[--this->nrOfElements];
}

template<typename T>
inline T PriorityQueue<T>::front() const throw(...)
{
	if (this->isEmpty() == true)
	{
		throw "Empty Queue";
	}

	return this->element[this->nrOfElements - 1];
}

template<typename T>
inline bool PriorityQueue<T>::isEmpty()const
{
	bool empty = false;
	if (this->nrOfElements == 0)
	{
		empty = true;
	}
	return empty;
}

template<typename T>
inline void PriorityQueue<T>::expand()
{
	this->capacity += 10;
	T* temp = new T[this->capacity];
	for (int i = 0; i < this->nrOfElements; i++)
	{
		temp[i] = this->element[i];
	}
	this->freeMemory();
	this->element = temp;
}

template<typename T>
inline void PriorityQueue<T>::sort(T arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - (i + 1); j++)
		{
			if (arr[j + 1] > arr[j])
			{
				this->swap(&arr[j + 1], &arr[j]);
			}
		}
	}
}

template<typename T>
inline void PriorityQueue<T>::swap(T *arr1, T *arr2)
{
	T temp = *arr1;
	*arr1 = *arr2;
	*arr2 = temp;
}

template<typename T>
inline int PriorityQueue<T>::search(T arr[], int size)
{
	int biggest = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[biggest] < arr[i])
		{
			biggest = arr[i];
		}
	}
	return biggest;
}

template<typename T>
inline void PriorityQueue<T>::copy(PriorityQueue<T> const & origObj)
{
	this->capacity = origObj.capacity;
	this->nrOfElements = origObj.nrOfElements;
	this->element = new T[origObj.capacity];

	for (int i = 0; i < origObj.nrOfElements; i++)
	{
		this->element[i] = origObj.element[i];
	}
}

template<typename T>
inline void PriorityQueue<T>::freeMemory() const
{
	delete[] this->element;
}