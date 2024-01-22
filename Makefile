all: world

CXX?=g++
CXXFLAGS?=--std=c++20 -Wall -fPIC -g
LDFLAGS?=-L/lib -L/usr/lib
INCLUDES+= -I.

THROWS_DIR:=.
include Makefile.inc

world: example

objs/main.o: main.cpp
	 $(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<;

example: $(THROWS_OBJS) objs/main.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -L. $(LIBS) $^ -o $@;

clean:
	rm -f objs/*.o example
