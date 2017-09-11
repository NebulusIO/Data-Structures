#
# Makefile framework for CptS223
#
# Hacked up by Aaron Crandall, 2017
#

# Variables
GPP     = g++
CFLAGS  = -g -std=c++0x
RM      = rm -f
BINNAME = bstheights

# Default is what happenes when you call make with no options
#  In this case, it requires that 'all' is completed
default: all

# All is the normal default for most Makefiles
#  In this case, it requires that Hello is completed
all: build

# Hello depends upon helloworld.cpp, then runs the command:
#  g++ -g -std=c++0x -o HelloWorld helloworld.cpp
build: main.cpp
	$(GPP) $(CFLAGS) -o $(BINNAME) main.cpp balancedArray.cpp

run: build
	./$(BINNAME)

test: build
	@echo "This $(BINNAME) program has no tests (yet)."
	./$(BINNAME) --test

# If you call "make clean" it will remove the built program
#  rm -f HelloWorld
clean veryclean:
	$(RM) $(BINNAME)
