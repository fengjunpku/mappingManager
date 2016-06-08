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
    if(str1 == "name")
    {
      string dssdName = str2;
      int numOfFrontStrips = atoi(str3.c_str());
      int numOfBackStrips = atoi(str4.c_str());
    }
  }
  //dssd 0 0-15 :: adc 0 0-15
  DSSD[0] = new DSSDmapping(16,0);
  for(int i=0;i<16;++i)
  {
    DSSD[0]->SetGeoCh("front",i,1000+i);
  }
}

mappingManager::~mappingManager()
{}