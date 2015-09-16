/**************************************************/
// Lab 2
// CECS 326, Fall 2015
// Johnjimy Som
/**************************************************/
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

void confirm_args(int argc, char *argv[]);

int main(int argc, char *argv[])
{
	//Member Declaration/Instatiantions
	int i, m, n, sleeptimer, seed;
	//Process ID called childpid
	pid_t childpid;
	
	confirm_args(argc, argv);
	
	//Covert to integer
	n = atoi(argv[1]); 
	m = atoi(argv[2]);

	childpid = 0;
	
	for (i=0; i<n;i++) {
		
		if (childpid = fork()) 
			break;
		
		if (childpid == -1) {
			perror ("\n The fork failed\n");
			exit(1);
		}//end if
	
		printf("\n %d: Process ID:%6ld Parent ID:%6ld Child ID:%6ld",i, (long)getpid(), (long)getppid(), (long)childpid);
	
		seed = (int)(getpid() + childpid);
		srand(seed);
	
		/*Each process will have different ChildPID.
		- The seed number will restart the random method.
		- Each process will have a different sleeptime.
		*/
		sleeptimer = rand() % m;
		printf (" Sleep = %d\n", sleeptimer);
		sleep(sleeptimer);
	}//end for loop
        wait(); //waits until the child process finish
	exit(0); //when the child process finshes, quit
}//end int main(int argc, char *argv[])

/*
* Function: void confirm_args(int argc, char *argv[]) 
* - Checks the command line arguments, 
* - Exits program with warning if arguments are inputted
*   incorrectly or if its not valid.
*
* argc: Inputs the number of command line arguments entered
* argv: Array that contains command line arguments, (like a pointer)
*/
void confirm_args(int argc, char *argv[])
{
	/* Confirms that only one command line argument is given */
	if(argc != 3) {
		printf("Usage: ./lab2 <number-of-processes> <max-sleep-seconds>\n");
		exit(1);
	}//end if
	
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);

	if(n <= 0 || n >= 10) {
		printf("Usage: ./lab2 <number-of-processes> <max-sleep-seconds>\n");
   	 	printf("Error input, number of processes must be an integer > 0 and < 10.\n");
		exit(1);
	}//end if 

    if(m < 0 || m >= 20) {
    	printf("Usage: ./lab2 <number-of-processes> <max-sleep-seconds>\n");
		printf("Error input, max sleep seconds must be an integer >= 0 and < 20.\n");
        exit(1);
    }//end if
}//end void confirm_args(int argc, char *argv[]) 	
