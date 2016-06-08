####
OBJ = maptest.exe
MainFile = main.cc
###
SourceFile := $(wildcard $(shell pwd)/src/*.cc)
IncludeFile := $(wildcard $(shell pwd)/include/*.hh)
DIR_INC = -I$(ROOTSYS)/include -I$(shell pwd)/include
MainFile += $(SourceFile)
#-I$(TARTSYS)/include
####
ROOTCFLAGS  = $(shell root-config --cflags)
ROOTLIBS    = $(shell root-config --libs)
#ROOTGLIBS = $(shell root-config --glibs)
#glibs = -lGui + libs

########################
#CFLAGS = -Wall -O2 -fopenmp
#CFLAGS = -fopenmp
CFLAGS = -Wall -O -std=c++0x $(DIR_INC)
#-lMathCore -l MathMore
#-L$(TARTSYS)/lib
#-lXMLParser -lanacore -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64
GXX = g++ 

all:$(OBJ)

$(OBJ): $(MainFile)
	$(GXX) $(CFLAGS) $(ROOTCFLAGS) $(ROOTLIBS) -o $@ $(MainFile)
	@echo "================================"
	@echo "Compile $@ done !"
	@echo "================================"
##################
clean:
	rm -f *~ *.o $(OBJ)
###################