#ifndef DSSDmapping_HH
#define DSSDmapping_HH 1

#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "JunErrors.hh"
//geo=2,ch=1 => geoch=geo*1000+ch=2001
class DSSDmapping
{
public:
  DSSDmapping(int numOfFrontStrips, int numOfBackStrips);
  virtual ~DSSDmapping();
  int GetGeo(string side,int strip=0);
  int GetCh(string side,int strip);
  inline int GetFStrips(){return fsNum;}
  inline int GetBStrips(){return bsNum;}
  void SetGeoCh(string side,int strip,int geo,int ch);
  void SetGeoCh(string side,int strip,int geoch);
private:
  int fsNum,bsNum;
  vector <int> fstrip;
  vector <int> bstrip;
};
#endif