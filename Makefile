# this makefile can be used to easily compile the project.
CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -g

SRCS =  main.cpp
OBJS = ${SRCS:.cpp=.o}
HEADERS = main.h udp.h sensordata.h

MAIN = joystick-udp

all: ${MAIN}
		@echo Done 

${MAIN}: ${OBJS}
		${CXX} ${CXXFLAGS} ${OBJS} -o ${MAIN}

.cpp.o:
		${CXX} ${CXXFLAGS} -c $< -o $@

clean:
		${RM} ${PROGS} ${OBJS} *.o *~.