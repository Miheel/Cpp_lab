#ifndef QUEUE_H
#define QUEUE_H
#include "DataContainer.hpp"

#undef new

#include "MemoryLeakChecker.hpp"

template <typename T>
class Queue : public Datacontainer<T>
{
public:
	Queue();
	~Queue();
	void Push(T data);
	const T& Peek();
	void Pop();
	void Print();
private:
	T* element;
	int start;
	void freeMem() const;
	void expand();
};
#endif // QUEUE_H

template<typename T>
inline Queue<T>::Queue():Datacontainer()
{
	int start = 0;
	this->element = new T[capacity];
}

template<typename T>
inline Queue<T>::~Queue()
{
	this->freeMem();
}

template<typename T>
inline void Queue<T>::Push(T data)
{
	if (Size() == capacity)
	{
		this->expand();
	}
	this->element[NrOfElem++] = data;
}

template<typename T>
inline const T & Queue<T>::Peek()
{
	return this->element[this->start];
}

template<typename T>
inline void Queue<T>::Pop()
{
	this->element[this->start++];
	NrOfElem--;
}

template<typename T>
inline void Queue<T>::freeMem() const
{
	delete[] this->element;
}

template<typename T>
inline void Queue<T>::expand()
{
	capacity *= 2;
	T* temp = new T[capacity];

	for (unsigned int i = 0; i < Size(); i++)
	{
		temp[i] = element[this->start++];
	}
	this->start = 0;
	this->freeMem();
	this->element = temp;
}

template<typename T>
inline void Queue<T>::Print()
{
	int temp = this->start;
	for (unsigned int i = 0; i < Size(); i++)
	{
		std::cout << element[temp++] << ", ";
	}
	std::cout <<"cap"<< this->capacity;
	std::cout << "\n";
}
