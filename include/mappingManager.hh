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
  //newDSSD(string name,int numOfFrontStrips, int numOfBackStrips);
  //setDSSD(string name,string side,string disChannel,string disStrip);
  map<string,DSSDmapping> mDSSD;
};
#endif
