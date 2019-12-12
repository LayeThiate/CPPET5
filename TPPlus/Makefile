GG = g++
GG_FLAGS = -Wall -Wextra -std=c++17
EXEC = test_full_matrix

all : $(EXEC)

SRC_OBJ = full_matrix.cpp
SRC_PROG = test_full_matrix.cpp

OBJ_O = $(SRC_OBJ:.cpp=.o)
OBJ_PROG = $(SRC_PROG:.cpp=.o)

test_full_matrix : test_full_matrix.o full_matrix.o
	$(GG) $(GG_FLAGS) -o $@ $^

%.o : %.c
	$(GG) ${GG_FLAGS} -c -o $@ $<

clean :
	rm -f $(OBJ_O) $(OBJ_PROG) $(EXEC)

.PHNONY : all clean