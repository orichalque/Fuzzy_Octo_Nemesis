# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++ -std=c++11
FILE=Game.cpp
POSTFLAG=-lncurses
NAME=FuzzyOctoNemesis

all: fuzzyoctonemesis

fuzzyoctonemesis: Game.cpp
	$(CC) $(FILE) $(POSTFLAG) -o $(NAME)


