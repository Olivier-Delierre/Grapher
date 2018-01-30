CXX=g++
CXXFLAGS=-std=c++11 -Wall -pedantic
ODIR=build
SRC=src

_DEPS = function.hpp 
DEPS = $(patsubst %,$(SRC)/%,$(_DEPS))

_OBJ = main.o function.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SRC)/%.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

bin/grapher: $(OBJ)
	g++ -o $@ $^ $(CFLAGS)

clean:
	@rm -rf build/*.o
