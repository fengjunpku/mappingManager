#include "mappingManager.hh"

mappingManager::mappingManager()
{
	//dssd 0 0-15 :: adc 0 0-15
	DSSD[0] = new DSSDmapping(16,0);
	for(int i=0;i<16;++i)
	{
		DSSD[0]->SetGeoCh("front",i,1000+i);
	}
}

mappingManager::~mappingManager()
{}