# In this makefile we are accepting the input from user as a command line
# which gets stored in macro ARGS

all:
	gcc parentProc.c -o parentProc
	gcc procReadAndList.c -o procReadAndList
run:
	./FinalExe ${ARGS}
usage:
	@echo 'use as : make ARGS="CommandLine_Argument" run'
clean:
	rm FinalExe
