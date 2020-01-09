# this makefile can be used to easily compile the project.

SRCS = main.cpp
CFLAGS = -Wall -g
LIBS = . 
TARGET = joystick-udp

all: $(SRCS)
	@echo Installing the joystick-udp program.
	g++ $(CFLAGS) $(SRCS) -I $(LIBS)-o $(TARGET)
	@echo Done!
	./joystick-udp
clean: 
	@echo Removing the executable..
	rm $(TARGET)