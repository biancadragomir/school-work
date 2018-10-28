#pragma once
#include <vector>

class Observer
{
public:
	~Observer(){}
	virtual void update() = 0;
};

class Subject
{
public:
	std::vector<Observer*> observers;
	void register_observer(Observer *obs);
	void unregister_observer(Observer *obs);
	void notify();

};