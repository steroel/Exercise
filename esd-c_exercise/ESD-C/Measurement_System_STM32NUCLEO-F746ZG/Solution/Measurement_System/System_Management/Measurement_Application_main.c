#include "SystemManager.h"

sint32_t main (void)
{
	SystemManager objSystemManager;
	//static SystemManager objSystemManager;
	
	SystemManager_construct(&objSystemManager);
	
	SystemManager_run(&objSystemManager);
	
	return(0);
}
