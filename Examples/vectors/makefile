C = g++

FLAGS0 = -std=c++11 -fopenmp 
FLAGS = -O3 -unroll -Wall -Wextra -pedantic -Wfatal-errors -Werror

dirLib = $(PWD)/../../
dirH = $(dirLib)Headers/Lib/
dirHO = $(dirLib)Headers/Objects/
dirCUBA = $(dirLib)External/Cuba-4.2/
dir_CCfits = $(dirLib)External/CCfits/include
dir_Eigen = $(dirLib)External/eigen-3.3.4/

varDIR = -DDIRCOSMO=\"$(dirLib)\" -DDIRL=\"$(PWD)/\"

FLAGS_LIB = -Wl,-rpath,$(HOME)/lib/ -Wl,-rpath,$(dirLib) -L$(dirLib) -lFUNC
FLAGS_INC = -I$(HOME)/include/ -I/usr/local/include/ -I$(dirH) -I$(dirHO) -I$(dirCUBA) -I$(dir_Eigen) -I$(dir_CCfits)

OBJ = vectors.o

ES = so

SYS:=$(shell uname -s)

ifeq ($(SYS),Darwin)
        ES = dylib
endif

vectors: $(OBJ) 
	$(C) $(OBJ) -o vectors $(FLAGS_LIB) 

clean:
	rm -f *.o vectors *~ \#* temp* core*

vectors.o: vectors.cpp makefile $(dirLib)*.$(ES)
	$(C) $(FLAGS0) $(FLAGS) $(FLAGS_INC) $(varDIR) -c vectors.cpp 
