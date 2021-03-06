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
	$(LAUNCH)
clean: 
	find . -name \*~ -exec rm -rf {} \;
	$(RM) -rf html
	$(RM) $(NAME)

site:
	doxygen Doxyfile
	firefox "html/index.html"
