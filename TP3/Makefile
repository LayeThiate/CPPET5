CXX = g++
CXX_FLAGS = -Wall -Wextra -std=c++17
EXEC = test test_array

all : $(EXEC)

#SRC_OBJ = 
SRC_PROG = test.cpp test_array.cpp

#OBJ_O = $(SRC_OBJ:.cpp=.o)
OBJ_PROG = $(SRC_PROG:.cpp=.o)

test : test.o
	$(CXX) $(CXX_FLAGS) -o $@ $^

test_array : test_array.o
	$(CXX) $(CXX_FLAGS) -o $@ $^

%.o : %.cpp
	$(CXX) $(CXX_FLAGS) -c -o $@ $^

clean :
	rm -f $(OBJ_PROG)  $(EXEC) 

.PHNONY : all clean