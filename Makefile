all: world

CXX?=g++
CXXFLAGS?=--std=c++17 -Wall -fPIC -g

OBJS:= \
	objs/main.o

THROWS_DIR:=.
include Makefile.inc

world: example

$(shell mkdir -p objs)

objs/main.o: main.cpp
	 $(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<;

example: $(THROWS_OBJS) objs/main.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@;

.PHONY: clean

clean:
	@rm -rf objs example
