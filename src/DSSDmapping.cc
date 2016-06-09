#include "DSSDmapping.hh"

DSSDmapping::DSSDmapping(int numOfFrontStrips, int numOfBackStrips)
{
  fsNum = numOfFrontStrips;
  bsNum = numOfBackStrips;
  for(int i=0;i<numOfFrontStrips;++i)
    fstrip.push_back(-1);
  for(int j=0;j<numOfFrontStrips;++j)
    bstrip.push_back(-1);
}

DSSDmapping::~DSSDmapping()
{}

int DSSDmapping::GetGeo(string side,int strip)
{
  if(strip<0||strip>fsNum||strip>bsNum)
    return -1;
  if(side=="f"||side=="front"||side=="face")
    return fstrip[strip]/1000;
  else if(side=="b"||side=="back")
    return bstrip[strip]/1000;
  else
    return -1;
}

int DSSDmapping::GetCh(string side,int strip)
{
  if(strip<0||strip>fsNum||strip>bsNum)
    return -1;
  if(side=="f"||side=="front"||side=="face")
    return fstrip[strip]%1000;
  else if(side=="b"||side=="back")
    return bstrip[strip]%1000;
  else
    return -1;
}

void DSSDmapping::SetGeoCh(string side,int strip,int geo,int ch)
{
  SetGeoCh(side,strip,geo*1000+ch);
}

void DSSDmapping::SetGeoCh(string side,int strip,int geoch)
{
  if(strip<0||strip>fsNum||strip>bsNum)
  {
    char buff[128];
    sprintf(buff,"Can not set strip: %d to geoch: %d. Please check your par file.",strip,geoch);
    MiaoError(string(buff));
  }
  if(side=="f"||side=="front"||side=="face")
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