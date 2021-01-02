CXX:=g++
STD:=-std=c++17
CFLAGS:=-Wall -Werror -Wextra -Weffc++ -pedantic
DEFINITIONS:= -DFMT_HEADER_ONLY
DEBUG_FLAGS:=-O3

SRC:=$(wildcard *.cpp)
INC:=$(wildcard include/*.h)
OBJ:=$(SRC:%.cpp=obj/%.o)
DEP:=$(SRC:%.cpp=dep/%.d)
TRGT:=main.exe

ifeq ($(SRC),)
$(error No source files found, there is nothing to build!)
endif

INCLUDES:=-I../include -I include

$(TRGT): setup $(OBJ)
	$(CXX) $(OBJ) -o $@

setup:
	@mkdir -p obj
	@mkdir -p dep

-include $(DEP)

obj/%.o: %.cpp $(INC)
	$(CXX) $(STD) $(DEBUG_FLAGS) $(CFLAGS) $(DEFINITIONS) $(INCLUDES) -MF dep/$(<:.cpp=.d) -MMD -c $< -o $@

clean:
	rm -rf obj dep $(TRGT) test_output *.csv

test: $(TEST) $(TRGT)
	contest contest.yaml

clamshell:
	@cp -R ~/fmt/include .

.PHONY:all setup clean test clamshell
