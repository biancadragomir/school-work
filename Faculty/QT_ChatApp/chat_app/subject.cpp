#include "subject.h"

void Subject::register_observer(Observer * obs)
{
	observers.push_back(obs);
}

void Subject::unregister_observer(Observer* obs)
{
	this->observers.erase(std::find(observers.begin(), observers.end(), obs));
}

void Subject::notify()
{
	for (auto o : observers)
	{
		o->update();
	}
}
