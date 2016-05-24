#include "DSSDmapping.hh"

DSSDmapping::DSSDmapping(int numOfFrontStrips, int numOfBackStrips)
{
	for(int i=0;i<numOfFrontStrips;++i)
	{
		fstrip.push_back(-1);
	}
	for(int j=0;j<numOfFrontStrips;++j)
	{
		bstrip.push_back(-1);
	}
}

DSSDmapping::~DSSDmapping()
{}

int DSSDmapping::GetGeo(string side,int strip)
{
	if(side=="f"||side=="front")
	{
		return fstrip[strip]/1000;
	}
	else if(side=="b"||side=="back")
	{
		return bstrip[strip]/1000;
	}
	else
	{
		return -1;
	}
}

int DSSDmapping::GetCh(string side,int strip)
{
	if(side=="f"||side=="front")
	{
		return fstrip[strip]%1000;
	}
	else if(side=="b"||side=="back")
	{
		return bstrip[strip]%1000;
	}
	else
	{
		return -1;
	}
}

void DSSDmapping::SetGeoCh(string side,int strip,int geo,int ch)
{
	SetGeoCh(side,strip,geo*1000+ch);
}

void DSSDmapping::SetGeoCh(string side,int strip,int geoch)
{
	if(side=="f"||side=="front")
	{
		fstrip[strip]=geoch;
	}
	else if(side=="b"||side=="back")
	{
		bstrip[strip]=geoch;
	}
	else
	{
		cout<<"bad input!"<<endl;
	}
}