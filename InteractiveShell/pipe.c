#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Inter-process communication
int main (int argcount, char ** arguments, char ** environment)
{
	int thePipe[2];
	pipe(thePipe);
	pid_t id = fork(); // create new child process
	if(id == 0) // for the child Process
	{
		char array[100];
		close(STDIN_FILENO); // close standard input
		close(thePipe[1]); // closes write end bc child only reads
		dup2(thePipe[0], STDIN_FILENO); // redirect to read end of pipe
		scanf("%s", array);
		printf("The array is %s\n", array); // print received string w printf
	}
	else // id > 0 for the Parent Process
	{
		close(STDOUT_FILENO);
		close(thePipe[0]); // close read end bc parent only writes to the pipe
		dup2(thePipe[1], STDOUT_FILENO); // redirects the write end of the pipe
		printf("Hello"); // writes hello to the pipe
	}

}
// pipe(thePipe) // creates a pipe
// thePipe[0] // the read end
// thePipe[1] // the write end
