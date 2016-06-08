#include "mappingManager.hh"

mappingManager::mappingManager(const char* parFile)
{
  ifstream fin;
  fin.open(parFile,ios::in);
  if(!fin)
  {cout<<"Miao! Error: Can not open "<<parFile<<endl;exit(0);}
  string buff;
  while(getline(fin,buff))
  {
    stringstream buffstream;
    buffstream.str(buff);
    string str0,str1,str2,str3,str4;
    if(buff[0] == '#') continue;
    buffstream>>str0>>str1>>str2>>str3>>str4;
    string _dssdName = str0;
    if(str1 == "define")
    {
      int _numOfFrontStrips = atoi(str2.c_str());
      int _numOfBackStrips = atoi(str3.c_str());
      newDSSD(_dssdName,_numOfFrontStrips,_numOfBackStrips);
      continue;
    }
    if(str1 == "face" || str1 == "back")
    {
      string _side = str1;
      int _geo = atoi(str2.c_str());
      setDSSD(_dssdName,_side,_geo,str3,str4);
    }
  }
  //dssd 0 0-15 :: adc 0 0-15
  DSSD[0] = new DSSDmapping(16,0);
  for(int i=0;i<16;++i)
  {
    DSSD[0]->SetGeoCh("front",i,1000+i);
  }
}

void mappingManager::newDSSD(string dssdName,int numOfFrontStrips, int numOfBackStrips)
{
  
  mDSSD[dssdName] = new DSSDmapping(numOfFrontStrips,numOfBackStrips);
}

void mappingManager::setDSSD(string dssdName,string side,int geo,string disChannel,string disStrip)
{
  cout<<disChannel<<endl;
  cout<<disStrip<<endl;
}

mappingManager::~mappingManager()
{}