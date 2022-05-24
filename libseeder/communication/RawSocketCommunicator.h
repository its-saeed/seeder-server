#ifndef RawSocketCommunicator_h__
#define RawSocketCommunicator_h__

#include "../utils/Thread.h"

class RawSocketCommunicator : public Thread
{
public:
	void run() override;
};

#endif // RawSocketCommunicator_h__
