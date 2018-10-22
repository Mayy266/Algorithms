
SRC=src
INC=include
BIN=bin

SRCS=$(wildcard ${SRC}/*.cpp)
OBJS=$(patsubst ${SRC}/%.cpp, ${BIN}/%.o, ${SRCS})
TARGET_BINARY=${BIN}/ex4_poly

CXX ?= clang++
CXXFLAGS += -I${INC} -std=c++14 -pedantic -Wall -Wextra -Wshadow -Wdouble-promotion -Wno-unused

all: ${TARGET_BINARY}

${TARGET_BINARY} : ${OBJS}
	${CXX} $^ -o $@

${BIN}/%.o: ${SRC}/%.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

.PHONY: clean
clean:
	rm -f ${OBJS}
	rm -f ${TARGET_BINARY}
