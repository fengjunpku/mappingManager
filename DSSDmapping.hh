#ifndef DSSDmapping_h
#define DSSDmapping_h 1

#include <iostream>
#include <vector>
#include <string>
using namespace std;
//geo=2,ch=1 => geoch=geo*1000+ch=2001
class DSSDmapping
{
public:
	DSSDmapping(int numOfFrontStrips, int numOfBackStrips);
	virtual ~DSSDmapping();
	int GetGeo(string side,int strip=0);
	int GetCh(string side,int strip);
	void SetGeoCh(string side,int strip,int geo,int ch);
	void SetGeoCh(string side,int strip,int geoch);
private:
	vector <int> fstrip;
	vector <int> bstrip;
};
#endif