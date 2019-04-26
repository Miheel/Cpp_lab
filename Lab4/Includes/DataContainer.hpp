#ifndef DATACONTAINER_H
#define DATACONTAINER_H

#undef new

#include "MemoryLeakChecker.hpp"

template<typename T>
class DataContainer
{
protected:
	unsigned int capacity;
	unsigned int NrOfElem;
	T* element;

	class exEmpty : public std::exception
	{
		virtual const char* what() const throw();
	}empty;

	void freeMem();
	void expand();

public:
	DataContainer();
	~DataContainer();
	virtual void Push(T data) = 0;
	virtual const T& Peek() const = 0;
	virtual void Pop() = 0;
	unsigned int Size() const;
};

template<typename T>
inline void DataContainer<T>::freeMem()
{
	delete[] this->element;
}

template<typename T>
inline void DataContainer<T>::expand()
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
inline DataContainer<T>::DataContainer()
{
	this->capacity = 1;
	this->NrOfElem = 0;
	this->element = new T[this->capacity];
}

template<typename T>
inline DataContainer<T>::~DataContainer()
{
	this->freeMem();
}

template<typename T>
inline unsigned int DataContainer<T>::Size() const
{
	return this->NrOfElem;
}

template<typename T>
inline const char * DataContainer<T>::exEmpty::what() const throw()
{
	return "Empty arr";
}
#endif // DATACONTAINER_H
