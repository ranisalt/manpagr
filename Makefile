CXX=clang++

INCLUDE=-Iinclude
CXXFLAGS=-Wall -std=c++11 $(INCLUDE)

EXEC=manpagr
EXEC_GEN=manpagr-gen

SRC=$(shell find src search -iname '*.cpp')
SRC_GEN=$(shell find src gen -iname '*.cpp')

all:: build

build::
	$(CXX) -o $(EXEC_GEN) $(SRC_GEN) $(CXXFLAGS)
	$(CXX) -o $(EXEC) $(SRC) $(CXXFLAGS)

clean::
	@$(RM) -rf $(EXEC) $(EXEC_GEN)
