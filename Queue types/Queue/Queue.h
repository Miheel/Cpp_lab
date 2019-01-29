#ifndef QUEUE_H
#define QUEUEH_H
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#include "IQueue.h"
template <typename T>
class Queue : public IQueue<T>
{
public:
	Queue();
	~Queue();
	Queue(Queue const& origObj);
	Queue<T>& operator=(Queue<T> const& origObj);
	void enqueue(const T& element);
	T dequeue()throw(...);
	T front()const throw(...);
	bool isEmpty()const;
private:
	T* element;
	int start;
	int end;
	int capacity;
	void freeMemory() const;
	void expand();
	void copy(Queue<T> const & origObj);
};
#endif // !QUEUE_H

template<typename T>
inline Queue<T>::Queue()
{
	this->capacity = 5;
	this->element = new T[this->capacity];
	this->start = -1;
	this->end = -1;
}

template<typename T>
inline Queue<T>::~Queue()
{
	this->freeMemory();
}

template<typename T>
inline Queue<T>::Queue(Queue const & origObj)
{
	this->copy(origObj);
}

template<typename T>
inline Queue<T>& Queue<T>::operator=(Queue<T> const & origObj)
{
	if (this != &origObj)
	{
		this->freeMemory();
		this->copy(origObj);
	}
	return *this;
}

template<typename T>
inline void Queue<T>::enqueue(const T & element)
{
	int count = (end + capacity - start) % capacity + 1;
	if (count == this->capacity)
	{
		this->expand();
	}
	if (this->isEmpty())
	{
		start = end = 0;
	}
	else
	{
		this->end = (this->end+1) % this->capacity;
	}
	this->element[this->end] = element;

}

template<typename T>
inline T Queue<T>::dequeue() throw(...)
{
	if (this->isEmpty() == true)
	{
		throw "The queue is empty";
	}

	int temp = this->element[this->start];
	this->start = (this->start + 1) % this->capacity;

	return temp;
}

template<typename T>
inline T Queue<T>::front() const throw(...)
{
	if (this->isEmpty() == true)
	{
		throw "The queue is empty";
	}
	return this->element[this->start];
}

template<typename T>
inline bool Queue<T>::isEmpty() const
{
	bool empty = false;
	if (this->end == -1 && this->start == -1)
	{
		empty = true;
	}
	return empty;
}

template<typename T>
inline void Queue<T>::freeMemory() const
{
	delete[] this->element;
}

template<typename T>
inline void Queue<T>::expand()
{
	int tempCap = this->capacity;
	int count = (end + tempCap - start) % tempCap + 1;
	this->capacity += 10;
	T* temp = new T[this->capacity];
	for (int i = 0; i < count; i++)
	{
		int index = (start + i) % tempCap;
		temp[i] = this->element[index];
		this->end = i;
	}
	this->freeMemory();
	this->element = temp;
	this->start = 0;
}

template<typename T>
inline void Queue<T>::copy(Queue<T> const & origObj)
{
	this->capacity = origObj.capacity;
	this->element = new T[origObj.capacity];
	this->end = origObj.end;
	this->start = origObj.start;
	for (int i = 0; i <= origObj.capacity; i++)
	{
		element[i] = origObj.element[i];
	}
}
