#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/*
 * Stored in lab1 folder
 */
void main(int argc, char *argv[]) {
	if (argc > 1) {
		execlp("home/Documents/lab1", "lab1", argv[1], (char *) NULL);
		perror ("exec failure");
		exit(1);
	}//end if
	printf("\n Usage: %s text_file\n", *argv); 
	exit(1);
}//end main
