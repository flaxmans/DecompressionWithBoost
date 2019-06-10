# Makefile for compiling tests of boost gz parsing

TARGET = TestBoostZip
CC = g++
LINKFLAGS = -lboost_iostreams
CFLAGS = -O3

# what gets built when you just type 'make':
all: ${TARGET}


# rule for compiling target:
${TARGET}: ${TARGET}.cpp
	${CC} ${CFLAGS} ${TARGET}.cpp ${LINKFLAGS} -o ${TARGET}


# rule for clean:
clean:
	rm -f ${TARGET}


