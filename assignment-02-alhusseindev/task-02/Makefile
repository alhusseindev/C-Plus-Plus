CXX:=g++
STD:=-std=c++17
CFLAGS:=-Wall -Werror -Wextra -Weffc++ -pedantic
DEBUG_FLAGS:=-O3

PYTHON:=python3

SRC:=$(wildcard *.cpp)
INC:=$(wildcard include/*.h)
OBJ:=$(SRC:%.cpp=obj/%.o)
DEP:=$(SRC:%.cpp=dep/%.d)
TRGT:=main.exe

ifeq ($(SRC),)
$(error No source files found, there is nothing to build!)
endif

INCLUDES:=-I../include -I include

PYVERSION:=$(shell $(PYTHON) --version)
PY8_REGEX:=^Python [0-9]+\.8\.[0-9]+$

PYTHON_INCLUDES:=$(shell $(PYTHON)-config --includes)
PYTHON_LIB_DIR:=$(shell $(PYTHON)-config --prefix)/lib
ifeq ($(shell echo ${PYVERSION} | egrep "${PY8_REGEX}"),)
PYTHON_LIBS:=$(shell $(PYTHON)-config --libs)
else
PYTHON_LIBS:=$(shell $(PYTHON)-config --libs --embed)
endif
PYTHON_LD_FLAGS:=-Wl,-rpath,$(PYTHON_LIB_DIR) -L$(PYTHON_LIB_DIR) $(PYTHON_LIBS)

HTML:=

$(TRGT): setup $(OBJ)
	$(CXX) $(OBJ) $(PYTHON_LD_FLAGS) -o $@

setup:
	@mkdir -p obj
	@mkdir -p dep

-include $(DEP)

obj/%.o: %.cpp $(INC)
	$(CXX) $(STD) $(DEBUG_FLAGS) $(CFLAGS) $(INCLUDES) $(PYTHON_INCLUDES) -MF dep/$(<:.cpp=.d) -MMD -c $< -o $@

clean:
	rm -rf obj dep $(TRGT) test_output __pycache__ $(HTML) 

test: $(TEST) $(TRGT)
	contest contest.yaml

.PHONY:all setup clean test
