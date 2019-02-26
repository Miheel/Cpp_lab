#include "UniquePointer.hpp"

UniqPtr::UniqPtr()
{
}

UniqPtr::UniqPtr(Attack * attptr)
{
	this->internalAttptr = attptr;
}

UniqPtr::UniqPtr(UniqPtr && other)
{
	this->internalAttptr = other.internalAttptr;
}

UniqPtr & UniqPtr::operator=(UniqPtr && other)
{
	if (this != &other)
	{
		delete this->internalAttptr;
		this->internalAttptr = other.internalAttptr;
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

bool UniqPtr::check() const
{
	bool check = true;
	if (this->internalAttptr != nullptr)
	{
		check = true;
	}
	else
	{
		check = false;
	}

	return check;
}

void UniqPtr::reset(Attack * attptr)
{
	delete this->internalAttptr;
	this->internalAttptr = attptr;
}

UniqPtr::~UniqPtr()
{
	delete internalAttptr;
}
