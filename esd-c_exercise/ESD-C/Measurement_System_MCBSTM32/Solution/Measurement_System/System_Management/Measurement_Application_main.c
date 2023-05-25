#include "SystemManager.h"

sint32_t main (void)
{
	SystemManager objSystemManager;
	SystemManager_construct(&objSystemManager);
	SystemManager_run(&objSystemManager);
	
	return(0);
}
