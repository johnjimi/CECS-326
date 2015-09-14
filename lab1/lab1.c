/****************************************************************
* Johnjimy Som
* CECS 326
* Lab 1
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void confirm_args(int argc, char *argv[]);
double calculateAverage(int sum, int elements);

int main(int argc, char *argv[])
{
	/**member declarations/instantiations**/
	int i,j,n;
	int min=0,max=0,sum=0;
	int *randA;

	confirm_args(argc, *argv);

	/**Converting argv to n**/
	n = atoi(argv[1]);

	/**Intialize a random number generator by using time as a base**/
	randA= (int *) malloc(sizeof(int) *n);

	/**Free memory assigning to array**/
	srand(int() time(NULL));

	/**Output the result**/
	printf("\nArray with %d random numbers ranging from -100 to 100\n",n );
	printf("\n Index: \t Element: ");

	/**
	* Creating an arrat that ranges -100 to 100
	* -Find the min, max
	* -Sum of all values
	**/
		for(i=0, i<n; i++){
			j=rand()% 201 - 100;
			randA[i] = j;
			printf("\n%d\t\n" i, j);
			sum+=j;
				if(j>max)
					max=j;
				if(j<min)
					min=j;
		}//end for

	free(randA);
}//end int main(int argc, char argv[1])

/**
* float calculatesAverage(int sum, int elements)
* -Calculates the average of by dividing the sum and elements 
*
* sum: the numbers inputted
* elements: number of array boxes
* return: result of the variables sum and elements
**/
float calculateAverage(int sum, int elements){
	return (float) sum / elements;
}//end float function

/**
* confirms_args(int argc, char *argv[])
* - Checks command line arguments inputted
* - Exits programs if the arguments are invalid
*
* argc: number of command line arguments inputted
* argv: array that contains command line arguments
**/
void confirm_args(int argc, char *argv[]){
	/**Only one command line is inputted**/
	if(argc !=2){
		printf("\n Wrong number in the command line 'arg'. Please enter a valid argument.\n", );
		exit(1);
	}//end if the user enters a invalid argument

	/**If input n (number of elements) is less than  or equal than 0, exit program**/
	if(n <= 0){
		printf("\n error input, please enter a number greater than 0", );
		exit(1);
	}//end if the user enters a number less than 0
}//end void confirm_args(int argc, char *argv[])
