#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
template<typename T>
class IPriorityQueue
{
public:
	virtual ~IPriorityQueue() = 0 {};
	virtual void enqueue(const T& element) = 0;
	virtual T dequeue()throw(...) = 0;
	virtual T front() const throw(...) = 0;
	virtual bool isEmpty() const = 0;
};
#endif // !PRIORITYQUEUE_H