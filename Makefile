CXX=g++
CXXFLAGS=-std=c++11 -Wall -pedantic -g
ODIR=build
SRC=src
LIB=-lsfml-graphics -lsfml-window -lsfml-system

_DEPS = function.hpp graphical.hpp camera.hpp geometry/point.hpp
DEPS = $(patsubst %,$(SRC)/%,$(_DEPS))

_OBJ = main.o function.o graphical.o camera.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all:bin/grapher

$(ODIR)/%.o: $(SRC)/%.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(ODIR)/point.o: $(SRC)/geometry/point.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

bin/grapher: $(OBJ) $(ODIR)/point.o
	g++ -o $@ $^ $(CXXFLAGS) $(LIB)

clean:
	@rm -rf build/*.o
