CXX=g++
CXXFLAGS=-std=c++11 -Wall -pedantic -g
ODIR=build
SRC=src
LIB=-lsfml-graphics -lsfml-window -lsfml-system

_DEPS = function.hpp graphical.hpp
DEPS = $(patsubst %,$(SRC)/%,$(_DEPS))

_OBJ = main.o function.o graphical.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SRC)/%.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

bin/grapher: $(OBJ)
	g++ -o $@ $^ $(CFLAGS) $(LIB)

clean:
	@rm -rf build/*.o
