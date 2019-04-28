#ifndef STACK_H
#define STACK_H

#undef new

#include "MemoryLeakChecker.hpp"

template <typename T>
class Stack : public DataContainer<T>
{
public:
	Stack();
	~Stack();
	void Push(T data);
	const T& Peek() const;
	void Pop();
};
#endif // STACK_H

template<typename T>
inline Stack<T>::Stack()
{
}

template<typename T>
inline Stack<T>::~Stack()
{
}

template<typename T>
inline void Stack<T>::Push(T data)
{
	if (this->Size() == this->capacity)
	{
		this->expand();
	}
	this->element[this->NrOfElem++] = data;
}

template<typename T>
inline const T & Stack<T>::Peek() const
{
	if (this->Size() == 0)
	{
		throw this->empty;
	}
	return this->element[this->NrOfElem - 1];
}

template<typename T>
inline void Stack<T>::Pop()
{
	if (this->Size() == 0)
	{
		throw this->empty;
	}
	this->NrOfElem--;
}