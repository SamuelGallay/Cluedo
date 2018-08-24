CXX=g++
CXXFLAGS=-Wall -Wextra
RM=rm -f
EXEC=Cluedo

sources = cluedo.cpp main.cpp
entetes = cluedo.h
objets = $(sources:.cpp=.o)

default:all

all: $(objets)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(objets)

main.o: cluedo.h

.c.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	$(RM) *.o *~

mrproper: clean
	$(RM) $(EXEC)
