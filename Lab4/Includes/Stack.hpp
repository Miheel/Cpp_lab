#ifndef STACK_H
#define STACK_H
#include "DataContainer.hpp"

#undef new

#include "MemoryLeakChecker.hpp"

template <typename T>
class Stack : public DataContainer<T>
{
public:
	Stack() {}
	~Stack() {}
	void Push(T data);
	const T& Peek();
	void Pop();
};
#endif // STACK_H

template<typename T>
inline void Stack<T>::Push(T data)
{
	if (this->NrOfElem == this->capacity)
	{
		this->expand();
	}
	this->element[this->NrOfElem++] = data;
}

template<typename T>
inline const T & Stack<T>::Peek()
{
	if (this->NrOfElem == 0)
	{
		throw this->empty;
	}
	return this->element[this->NrOfElem-1];
}

template<typename T>
inline void Stack<T>::Pop()
{
	if (this->NrOfElem == 0)
	{
		throw this->empty;
	}
	this->NrOfElem--;
}