#include <iostream>
#include "mappingManager.hh"
using namespace std;

int main()
{
  mappingManager *map = new mappingManager("SetMap.par");
  cout<<map->mapDSSD["T1D1"]->GetGeo("front")<<endl;
}
