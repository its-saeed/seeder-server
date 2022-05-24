#ifndef RawSocketCommunicator_h__
#define RawSocketCommunicator_h__

#include "Communicator.h"

class RawSockerCommunicator : public Communicator
{
public:
	void start() override
	{
		throw std::logic_error("The method or operation is not implemented.");
	}
};

#endif // RawSocketCommunicator_h__
