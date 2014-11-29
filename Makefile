# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++
FLAG=-std=c++11
FILE=Game.cpp
POSTFLAG=-lncurses
NAME=FuzzyOctoNemesis
LAUNCH=./FuzzyOctoNemesis
RM=rm

all: fuzzyoctonemesis

fuzzyoctonemesis: 
        $(CC) $(FLAG) $(FILE) $(POSTFLAG) -o $(NAME)

run: 
        ./FuzzyOctoNemesis
        
clean: 
        $(RM) *~ 
