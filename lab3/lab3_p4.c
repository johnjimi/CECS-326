#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


void main(int argc, char *argv[]) {
	static char *new_argv[] = {"lab1", "5", (char *) 0};
	execvp("/home/Documents/lab1", new_argv);
	perror("exec failure");
	exit(1);
}//end main
