GXX = g++
CXXFLAGS = -std=c++11 -Wall -pedantic 
SRC = ../src
OBJ = build

bin/test_point: $(OBJ)/test_point.o $(OBJ)/point.o
	$(GXX) -o $@ $^ $(CXXFLAGS)

#========================================================

$(OBJ)/test_point.o: test_point.cpp
	$(GXX) -c -o $@ $<


#=========================================================

$(OBJ)/point.o: $(SRC)/geometry/point.cpp
	$(GXX) -c -o $@ $<

#=========================================================

clean:
	@rm -rf build/*.o
