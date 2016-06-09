# Discription
manager the mapping between DSSDs and electronics
# Usage
```
#include "mappingManager.hh"
...
mappingManager *map = new mappingManager(Parameter_File);
DSSDmapping* thisone = map->GetMap(dssdName);
```
# Format of parameter file
```
# <dssdname> define <front_strips> <back_strips> <total_strips>
# <dssdname> face <geo> <dssd_strip> <adc_channel>
# <dssdname> back <geo> <dssd_strip> <adc_channel>
# <total_strips> == <front_strips> + <back_strips>
T1D1 define 16 16 32
T1D1 face 3 0-15 0-15
T1D1 back 3 0-7 16-23
T1D1 back 3 15-8 24-31
```
# Require
[ROOT](https://root.cern.ch/)
