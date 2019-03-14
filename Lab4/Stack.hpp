#ifndef STACK_H
#define STACK_H
#include "DataContainer.hpp"


#undef new

#include "MemoryLeakChecker.hpp"

template <typename T>
class Stack : public Datacontainer<T>
{
public:
	Stack();
	~Stack();
	void Push(T data);
	const T& Peek();
	void Pop();
	void Print();
private:
	T* element;
	void freeMem() const;
	void expand();
};
#endif // STACK_H

template<typename T>
inline Stack<T>::Stack():Datacontainer()
{
	this->element = new T[capacity];
}

template<typename T>
inline Stack<T>::~Stack()
{
	this->freeMem();
}

template<typename T>
inline void Stack<T>::Push(T data)
{
	if (this->NrOfElem == capacity)
	{
		this->expand();
	}
	this->element[NrOfElem++] = data;
}

template<typename T>
inline const T & Stack<T>::Peek()
{
	return this->element[NrOfElem-1];
}

template<typename T>
inline void Stack<T>::Pop()
{
	this->element[NrOfElem--];
}

template<typename T>
inline void Stack<T>::Print()
{
	for (unsigned int i = 0; i < Size(); i++)
	{
		std::cout << element[i] << ", ";
	}
	std::cout << "cap" << this->capacity;
	std::cout << "\n";
}

template<typename T>
inline void Stack<T>::freeMem() const
{
	delete[] this->element;
}

template<typename T>
inline void Stack<T>::expand()
{
	capacity *= 2;
	T* temp = new T[capacity];
	for (unsigned int i = 0; i < Size(); i++)
	{
		temp[i] = this->element[i];
	}
	this->freeMem();
	this->element = temp;
}
