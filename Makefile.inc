THROWS_DIR?=./throws
INCLUDES += -I$(THROWS_DIR)/include

THROWS_OBJS:= \
	objs/throws.o

objs/throws.o: $(THROWS_DIR)/src/throws.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<;
