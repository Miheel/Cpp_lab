#ifndef QUEUE_H
#define QUEUE_H

#undef new

#include "DataContainer.hpp"
#include "MemoryLeakChecker.hpp"

template <typename T>
class Queue : public DataContainer<T>
{
public:
	Queue();
	~Queue();
	void Push(T data);
	const T& Peek() const;
	void Pop();
};
#endif // QUEUE_H

template<typename T>
inline Queue<T>::Queue()
{
}

template<typename T>
inline Queue<T>::~Queue()
{
}

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
inline const T & Queue<T>::Peek() const
{
	if (this->Size() == 0)
	{
		throw this->empty;
	}
	return this->element[0];
}

template<typename T>
inline void Queue<T>::Pop()
{
	if (this->Size() == 0)
	{
		throw this->empty;
	}
	for (unsigned int i = 0; i < this->Size() - 1; i++)
	{
		this->element[i] = this->element[i + 1];
	}
	this->NrOfElem--;
}