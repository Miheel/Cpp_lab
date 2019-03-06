#undef new

#include "UniquePointer.hpp"
#include "MemoryLeakChecker.hpp"

UniqPtr::UniqPtr()
{
	this->internalAttptr = nullptr;
}

UniqPtr::UniqPtr(Attack * attptr)
{
	this->internalAttptr = attptr;
}

UniqPtr::UniqPtr(UniqPtr && other):internalAttptr(other.internalAttptr)
{
	other.internalAttptr = nullptr;   
}

UniqPtr & UniqPtr::operator=(UniqPtr && other)
{
	if (this != &other)
	{
		delete[] this->internalAttptr;
		this->internalAttptr = other.internalAttptr;
		other.internalAttptr = nullptr;
	}
	return *this;
}

Attack & UniqPtr::operator*()
{
	return *internalAttptr;
}

Attack * UniqPtr::Get() const
{
	return this->internalAttptr;
}

bool UniqPtr::Check() const
{
	return this->internalAttptr != nullptr;
}

void UniqPtr::reset(Attack * attptr)
{
	delete[] this->internalAttptr;
	this->internalAttptr = attptr;
}

UniqPtr::~UniqPtr()
{
	delete[] this->internalAttptr;
}
