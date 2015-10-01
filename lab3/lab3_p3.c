#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/*
 * 
 * Runs the execvp function passing argv[1]
 *  argv[1] parameter
 * If exec call fails, "exec failure" output and exits the program
 *
 */
void main(int argc, char *argv[]) {
	execvp(argv[1], &argv[1]);
	perror ("exec failure");
	exit(1);			
}//end void int main(int argc, char const *argv[])
