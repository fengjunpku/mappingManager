#include <iostream>
#include "DSSDmapping.hh"
#include "mappingManager.hh"
using namespace std;

int main()
{
  mappingManager *map = new mappingManager("SetMap.par");
  DSSDmapping* thisone = map->GetMap("T1D1");
  cout<<"front: "<<thisone->GetGeo("front")<<endl;
  int fnum = thisone->GetFStrips();
  for(int i=0;i<fnum;i++)
    cout<<thisone->GetCh("front",i)<<" ";
  cout<<endl;
  cout<<"back: "<<thisone->GetGeo("back")<<endl;
  int bnum = thisone->GetBStrips();
  for(int i=0;i<bnum;i++)
    cout<<thisone->GetCh("back",i)<<" ";
  cout<<endl;
}
