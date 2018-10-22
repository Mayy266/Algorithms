
# Define some variables
SRC=src
INC=include
BIN=bin
TARGET_BINARY=${BIN}/ex1_date

# Extend some standard linux variables
#   = means affect
#  ?= means affect only if not already defined
#  += means concatenate with existing value (and define if not already defined)
# Standard variables can be found here:
#   https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html
CXX ?= g++  # or clang++
CXXFLAGS += -I${INC} -std=c++14 -pedantic -g
CXXFLAGS += -Wall -Wextra -Wshadow -Wno-unused

# Some info about C++ compiler flags:
#  -std=c++14 enables the C++14 standard (c++11, c++14, c++17).
#  -pedantic forces the compiler to comply to the standard.
#            The compiler will warn about non-standard extensions usage.
#  -Wall enable some warnings (not all of them as the name would imply).
#  -Wextra enable even more warnings.
#     See https://stackoverflow.com/questions/2408038/what-does-wall-in-g-wall-test-cpp-o-test-do
#  -W... is the syntax enable an individual warning.
#        For example -Wshadow enable an individual warning about variable shadowing.
#  -Wno-... is the syntax disable an individual warning.
#        For example -Wno-unused disable warnings about declared but unused variables.
# If you want that all warnings become errors you can use -Werror.
# If you want that non standard extensions throw an error use -pedantic-errors instead of -pedantic
# See https://stackoverflow.com/questions/5088460/flags-to-enable-thorough-and-verbose-g-warnings
#   for warnings that are not enabled by -Wall and -Wextra.

# all is the default rule that will be executed when calling 'make'.
all: ${TARGET_BINARY}

# Rule to build the target executable bin/ex1_date given bin/main.o and bin/date.o
${TARGET_BINARY} : ${BIN}/main.o ${BIN}/date.o
	${CXX} $^ -o $@

# Generic rule to build an object file 'bin/*.o' given a C++ source file 'src/*.cpp'.
${BIN}/%.o: ${SRC}/%.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

# Phony rules are executed every time (even if they have no dependencies)
.PHONY: clean
clean:
	rm -f ${BIN}/*.o
	rm -f ${TARGET_BINARY}

#
# What will happen when I call make ?
#   1) make will default to make all
#   2) all depends on ${TARGET_BINARY}, this will call the rule ${TARGET_BINARY}.
#   3) ${TARGET_BINARY} depends on bin/main.o and bin.date.o
#   4) bin/main.o depends on src/main.cpp, if src/main.cpp has been modified since last build,
#       this will call the generic rule to rebuild bin/main.o.
#   5) bin/date.o depends on src/date.cpp, if src/date.cpp has been modified since last build,
#       this will call the generic rule to rebuild bin/date.o.
#   6) Every dependencies of ${TARGET_BINARY} are built, build the target binary by using
#       bin/main.o and bin/date.o.
#
# Usage:
#   make
#   CXX=clang++ make
#   CXX=clang++ CXXFLAGS=-Werror make
#
# How the call a non default rule ?
#   Just specify the target rule: 'make <rule name>'.
#   Examples:
#  		make clean
#   	make bin/main.o
#
