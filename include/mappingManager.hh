#ifndef mappingManager_h
#define mappingManager_h 1

#include "DSSDmapping.hh"

class mappingManager
{
public:
	mappingManager();
	mappingManager(char* parFile);
	virtual ~mappingManager();
	DSSDmapping *DSSD[2];
};
#endif
