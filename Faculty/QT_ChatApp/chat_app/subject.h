#pragma once
#include <vector>


class Observer
{
public:
	virtual void update()=0;
	~Observer() {};
};

class Subject
{
public:
	std::vector<Observer*> observers;
	void register_observer(Observer *obs);
	void unregister_observer(Observer* obs);
	void notify();
};