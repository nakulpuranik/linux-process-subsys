# In this makefile we are accepting the input from user as a command line
# which gets stored in macro ARGS

all:
	#gcc processHierarchy.c -o FinalExe
	gcc proc1.c -o proc1
	gcc proc2.c -o proc2
	gcc proc3.c -o proc3
run:
	./FinalExe ${ARGS}
usage:
	@echo 'use as : make ARGS="CommandLine_Argument" run'
clean:
	rm FinalExe
