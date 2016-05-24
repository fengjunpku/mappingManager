#
OBJ = maptest.exe
#sourcefile = main.cc mappingManager.cc mappingManager.hh DSSDmapping.cc DSSDmapping.hh
sourcefile = *.cc *.hh
 

#ROOTCFLAGS  = $(shell root-config --cflags)
#ROOTLIBS    = $(shell root-config --libs)

#CFLAGS = -Wall -O2 -fopenmp
#CFLAGS = -fopenmp
CFLAGS = -std=c++0x 
#-lMathCore -l MathMore
GXX = g++ 

all:$(OBJ)

$(OBJ): $(sourcefile)
	$(GXX) $(CFLAGS) -o $@ $(filter %.cc ,$(sourcefile))

clean:
	rm -f *~ *.o $(OBJ)
