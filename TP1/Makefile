GG = g++
GG_FLAGS = -Wall -Wextra -std=c++17
EXEC = testRectangle

all : $(EXEC)

SRC_OBJ = rectangle.cpp square.cpp
SRC_PROG = testRectangle.cpp

OBJ_O = $(SRC_OBJ:.cpp=.o)
OBJ_PROG = $(SRC_PROG:.cpp=.o)

testRectangle : testRectangle.o rectangle.o square.o
	$(GG) $(GG_FLAGS) -o $@ $^

%.o : %.c
	$(GG) ${GG_FLAGS} -c -o $@ $<

clean :
	rm -f $(OBJ_O) $(OBJ_PROG) $(EXEC)

.PHNONY : all clean