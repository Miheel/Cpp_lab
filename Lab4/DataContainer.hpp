#ifndef DATACONTAINER_H
#define DATACONTAINER_H

#undef new

#include "MemoryLeakChecker.hpp"

template<typename T>
class DataContainer
{
protected:
	int capacity;
	int NrOfElem;
	T* element;
	
	class exEmpty: public std::exception
	{
	  virtual const char* what() const throw()
	  {
		return "Empty arr";
	  }
	}empty;

	void freeMem() const { delete[] this->element; }
	void expand() {
		capacity *= 2;
		T* temp = new T[capacity];
		for (unsigned int i = 0; i < Size(); i++)
		{
			temp[i] = this->element[i];
		}
		this->freeMem();
		this->element = temp;
	}
public:
	DataContainer() {
		this->capacity = 1;
		this->NrOfElem = 0;
		this->element = new T[this->capacity];
	}
	~DataContainer() { this->freeMem(); }
	virtual void Push(T data) = 0;
	virtual const T& Peek() = 0;
	virtual void Pop() = 0;
	unsigned int Size() {
		return this->NrOfElem;
	}
};
#endif // DATACONTAINER_H