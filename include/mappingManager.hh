#ifndef mappingManager_HH
#define mappingManager_HH 1

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <cstdlib>

#include "DSSDmapping.hh"
using namespace std;

class mappingManager
{
public:
  mappingManager(const char* parFile);
  virtual ~mappingManager();
  map<string,DSSDmapping*> mapDSSD;
private:
  void newDSSD(string dssdName,int numOfFrontStrips, int numOfBackStrips);
  void setDSSD(string dssdName,string side,int geo,string disStrip,string disChannel);
  vector<string> split(string str,string pattern);
};
#endif
