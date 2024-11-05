dynpipe		:	dynpipe.o CommandStack.o
	g++ -o dynpipe dynpipe.o CommandStack.o

dynpipe.o	:	dynpipe.cpp
	g++ -c dynpipe.cpp

CommandStack.o	:	CommandStack.cpp CommandStack.h
	g++ -c CommandStack.cpp

debug		:	dynpipe.o CommandStack.o
	g++ -o a dynpipe.o CommandStack.o