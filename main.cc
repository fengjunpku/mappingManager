#include <iostream>
#include "mappingManager.hh"
using namespace std;

int main()
{
	mappingManager *map = new mappingManager("SetMap.par");
	cout<<map->DSSD[0]->GetGeo("front")<<endl;
	cout<<map->DSSD[0]->GetCh("f",10)<<endl;
}
