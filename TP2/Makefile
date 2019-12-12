GG = g++
GG_FLAGS = -Wall -Wextra -std=c++17
EXEC = testT testFile testNode

all : $(EXEC)

SRC_OBJ = T.cpp file.cpp node.cpp
SRC_PROG = testT.cpp testFile.cpp testNode.cpp

OBJ_O = $(SRC_OBJ:.cpp=.o)
OBJ_PROG = $(SRC_PROG:.cpp=.o)

testNode : testNode.o node.o
	$(GG) $(GG_FLAGS) -o $@ $^

testFile : testFile.o file.o
	$(GG) $(GG_FLAGS) -o $@ $^

testT : testT.o T.o
	$(GG) $(GG_FLAGS) -o $@ $^

%.o : %.c
	$(GG) ${GG_FLAGS} -c -o $@ $<

clean :
	rm -f $(OBJ_O) $(OBJ_PROG) $(EXEC)

.PHNONY : all clean