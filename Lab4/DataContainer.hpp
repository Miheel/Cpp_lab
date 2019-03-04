#ifndef DATACONTAINER_H
#define DATACONTAINER_H

template<typename T>
class Datacontainer
{
public:
	virtual ~Datacontainer() = 0 {};
	virtual void Push(T data) = 0;
	virtual const T& Peek() = 0;
	virtual void Pop() = 0;
	virtual unsigned int Size() = 0;
};
#endif // DATACONTAINER_H
