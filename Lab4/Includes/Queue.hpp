#ifndef QUEUE_H
#define QUEUE_H
#include "DataContainer.hpp"

#undef new

#include "MemoryLeakChecker.hpp"

template <typename T>
class Queue : public DataContainer<T>
{
public:
	Queue() {}
	~Queue() {}
	void Push(T data);
	const T& Peek();
	void Pop();
};
#endif // QUEUE_H

template<typename T>
inline void Queue<T>::Push(T data)
{
	if (this->Size() == this->capacity)
	{
		this->expand();
	}
	this->element[this->NrOfElem++] = data;
}

template<typename T>
inline const T & Queue<T>::Peek()
{
	if (this->NrOfElem == 0)
	{
		throw this->empty;
	}
	return this->element[0];
}

template<typename T>
inline void Queue<T>::Pop()
{
	if (this->NrOfElem == 0)
	{
		throw this->empty;
	}
	for (int i = 0; i < this->NrOfElem-1; i++)
	{
		this->element[i] = this->element[i + 1];
	}
	this->NrOfElem--;
}