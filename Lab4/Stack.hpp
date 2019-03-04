#ifndef STACK_H
#define STACK_H
#include "DataContainer.hpp"

template <typename T>
class Stack :Datacontainer<T>
{
public:
	Stack();
	~Stack();
	void Push(T data);
	const T& Peek();
	void Pop()const;
private:
	T* element;
	int capacity;
	void freeMem() const;
	void expand();
	void copy(const T& other);

};
#endif // STACK_H