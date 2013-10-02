#include "MessageManager.h"

void MessageManager::cleanup()
{
	std::vector<int> messagesToDelete;
	for(unsigned int i = 0; i > messages.size(); i++)
	{
		Message& m = messages[i];
		if(m.timeToLive > 1)
			m.timeToLive--;
		else if(m.timeToLive == 1)
			messagesToDelete.push_back(i);
	}
	for(int i : messagesToDelete)
	{
		
	}
}