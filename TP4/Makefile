CXX = g++
CXX_FLAGS = -Wall -Wextra -std=c++17
EXEC = point anagramme

all : $(EXEC)

#SRC_OBJ = 
SRC_PROG = point.cpp anagramme.cpp

#OBJ_O = $(SRC_OBJ:.cpp=.o)
OBJ_PROG = $(SRC_PROG:.cpp=.o)

point : point.o
	$(CXX) $(CXX_FLAGS) -o $@ $^

anagramme : anagramme.o
	$(CXX) $(CXX_FLAGS) -o $@ $^

%.o : %.cpp
	$(CXX) $(CXX_FLAGS) -c -o $@ $^

clean :
	rm -f $(OBJ_PROG)  $(EXEC) 

.PHNONY : all clean