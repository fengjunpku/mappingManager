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
}

void mappingManager::newDSSD(string dssdName,int numOfFrontStrips, int numOfBackStrips)
{
  mapDSSD[dssdName] = new DSSDmapping(numOfFrontStrips,numOfBackStrips);
}

void mappingManager::setDSSD(string dssdName,string side,int geo,string disStrip,string disChannel)
{
  vector<string> vDisSt = split(disStrip,"-");
  vector<string> vDisCh = split(disChannel,"-");
  if(vDisCh.size() != 2|| vDisSt.size() != 2) 
  {cout<<"Miao! Error: Set the channels and strips like '0-15', '16-31' etc."<<endl;exit(0);}
  int ch_start = atoi(vDisCh[0].c_str());
  int ch_end = atoi(vDisCh[1].c_str());
  int st_start = atoi(vDisSt[0].c_str());
  int st_end = atoi(vDisSt[1].c_str());
  int clen = abs(ch_start-ch_end);
  if(clen != abs(st_start-st_end))
  {cout<<"Miao! Error: Set the lengh of channels and strips should be equal."<<endl;exit(0);}
  int ch_step,st_step;
  if(ch_start<=ch_end) ch_step = 1;
  else ch_step = -1;
  if(st_start<=st_end) st_step = 1;
  else st_step = -1;
  for(int i=0;i<clen+1;i++)
  {
    int _strip = st_start+i*st_step;
    int _ch = ch_start+i*ch_step;
    mapDSSD[dssdName]->SetGeoCh(side,_strip,geo,_ch);
  }
}

vector<string> mappingManager::split(string str,string pattern)
{
  vector<string> result;
  size_t pos;
  str+=pattern;
  size_t len= str.length();
  for(size_t i=0;i<len;i++)
  {
    pos=str.find(pattern,i);
    if(pos<len)
    {
      string s = str.substr(i,pos-i);
      result.push_back(s);
      i = pos+pattern.length()-1;
    }
  }
  return result;
}
mappingManager::~mappingManager()
{}