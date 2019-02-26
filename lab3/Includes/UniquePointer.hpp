#include "Attack.hpp"

class UniqPtr
{
public:
	//default constructor
	UniqPtr();
	UniqPtr(Attack *attptr);
	//copy contructor
	UniqPtr(const UniqPtr &other) = delete;
	//copy assignement operator
	UniqPtr& operator=(const UniqPtr &other) = delete;
	//move constructor
	UniqPtr(UniqPtr && other);
	//move assignement
	UniqPtr& operator=(UniqPtr &&other);
	
	Attack& operator*();
	Attack* Get()const;
	bool check() const;
	void reset(Attack* attptr = nullptr);

	~UniqPtr();

private:
	Attack* internalAttptr;
};
