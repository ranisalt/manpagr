CXX=clang++

INCLUDE=-Iinclude
CXXFLAGS=-g -Wall -std=c++11 $(INCLUDE)

EXEC=manpagr
TEST=$(EXEC)_test

SRC=$(shell find src -iname '*.cpp') main.cpp
SRC_TEST=$(shell find src tests -iname '*.cpp') main_test.cpp

all:: build

build::
	$(CXX) -o $(EXEC) $(SRC) $(CXXFLAGS)

test::
	$(CXX) -o $(TEST) $(SRC_TEST) $(CXXFLAGS) -lgtest -pthread
	@./$(TEST)

clean::
	@$(RM) -rf $(EXEC) $(TEST)
