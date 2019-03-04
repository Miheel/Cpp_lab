#ifndef QUEUE_H
#define QUEUE_H
#include <string>
#include "DataContainer.hpp"
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
template <typename T>
class Queue : public Datacontainer<T>
{
public:
	Queue();
	~Queue();
	void Push(T data);
	const T& Peek();
	void Pop();
	unsigned int Size();
	void Print();
private:
	T* element;
	int capacity;
	int NrOfelem;
	void freeMem() const;
	void expand();
	void copy(const T& other);

};
#endif // QUEUE_H

template<typename T>
inline Queue<T>::Queue()
{
	this->capacity = 1;
	this->NrOfelem = 0;
	this->element = new T[this->capacity];
}

template<typename T>
inline Queue<T>::~Queue()
{
	this->freeMem();
}

template<typename T>
inline void Queue<T>::Push(T data)
{
	if (this->Size() == this->capacity)
	{
		this->expand();
	}
	this->element[this->NrOfelem++] = data;
}

template<typename T>
inline const T & Queue<T>::Peek()
{
	return this->element[this->Size()-1];
}

template<typename T>
inline void Queue<T>::Pop()
{
	--this->NrOfelem;
}

template<typename T>
inline unsigned int Queue<T>::Size()
{
	return this->NrOfelem;
}

template<typename T>
inline void Queue<T>::freeMem() const
{
	delete[] this->element;
}

template<typename T>
inline void Queue<T>::expand()
{
	this->capacity *= 2;
	T* temp = new T[this->capacity];

	for (unsigned int i = 0; i < this->Size(); i++)
	{
		temp[i] = this->element[i];
	}

	this->freeMem();
	this->element = temp;
}

template<typename T>
inline void Queue<T>::Print()
{
	for (unsigned int i = 0; i < this->Size(); i++)
	{
		std::cout << this->element[i] << ", ";
	}
	//std::cout << this->capacity;
	std::cout << "\n";
}
