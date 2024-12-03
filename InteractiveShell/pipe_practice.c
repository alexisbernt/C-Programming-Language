// Def Pipe: Interprocess communication (one process gives data to another)
// A pipe is going to run the first command and then feed the output of the first command into the input of the second command

// Credit: Professor Adam Spanier's Operating Systems Class

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

int thePipe[2];
 pipe(thePipe);
 pid_t id = fork(); // create new child process
 if(id == 0) // for the child Process
 {
   char ** array[100];
   close(STDIN_FILENO); // close standard input
   close(thePipe[1]); // closes write end bc child only reads
   dup2(thePipe[0], STDIN_FILENO); // redirect to read end of pipe
   if (isPipe(STDIN_FILENO)){
        printf("Child process: stdin is connected to a pipe\n" );
   } else {
        printf("Child process: stdin is NOT connected to a pipe\n" );
   }
 }
    scanf("%s", array);
    printf("The array is %s\n", array); // print received string w printf
}
    else // id > 0 for the Parent Process
    {
        close(STDOUT_FILENO);
        close(thePipe[0]); // close read end bc parent only writes to the pipe
        dup2(thePipe[1], STDOUT_FILENO); // redirects the write end of the pipe
        if (isPipe(STDOUT_FILENO)){
        printf("Parent process: stdout is connected to a pipe\n" );
        }else {
        printf("Parent process: stdout is NOT connected to a pipe\n" );
        }
        printf("Hello"); // writes hello to the pipe
}
return 0;
}

int isPipe(char * input) {
  struct stat statbuf; // statbuf will get filled with info about the file or resource
  if (fstat(fd, &statbuf) == -1) {
      perror("fstat");
      return -1; // this means error occurred
  }
  // Check if the file descriptor refers to a pipe
  return S_ISFIFO(statbuf.st_mode);
}
