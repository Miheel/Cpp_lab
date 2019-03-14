#ifndef DATACONTAINER_H
#define DATACONTAINER_H

template<typename T>
class Datacontainer
{
protected:
	int capacity;
	int NrOfElem;
public:
	Datacontainer() {
		this->capacity = 1;
		this->NrOfElem = 0;
	}
	virtual ~Datacontainer() = 0 {};
	virtual void Push(T data) = 0;
	virtual const T& Peek() = 0;
	virtual void Pop() = 0;
	unsigned int Size() {
		return this->NrOfElem;
	}
};
#endif // DATACONTAINER_H
