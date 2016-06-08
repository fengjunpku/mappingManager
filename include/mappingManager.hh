#ifndef mappingManager_HH
#define mappingManager_HH 1

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <cstdlib>

#include "DSSDmapping.hh"
using namespace std;

class mappingManager
{
public:
  mappingManager(const char* parFile);
  virtual ~mappingManager();
  DSSDmapping *DSSD[2];
private:
  void newDSSD(string dssdName,int numOfFrontStrips, int numOfBackStrips);
  void setDSSD(string dssdName,string side,int geo,string disChannel,string disStrip);
  map<string,DSSDmapping*> mDSSD;
};
#endif
