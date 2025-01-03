// CYBR 401 - Operating Systems
// Homework Assignment #5. Student: Alexis Bernthal. Date: 12/16/2024.
// Memory Management Modeling / Memory Management Simulation PROGRAM
// This program will model process creation, memory acquisition, memory release, and the emptying of memory area buffers.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Macros go here
#define MAXSIZE 20
#define TIMESIZE 10
#define MEMSIZE 100

// *******************************  START HERE!  ********************************
//
// For this assignment, the impetus is on YOU. I have given you ALL the tasks
// you need to accomplish, but I am not going to spoon feed you the order
// in which you must do them. You can work in whatever order you would like.
// Please familiarize yourself with the main() and run() methods so that you can
// pick the best order possible for development. as you are working through
// development. As you code, comment things out and test as you build out your
// program. Again, it is up to you as to the order in which you write your code.
// If you think it through, you can write the code in a way such that you can
// test EACH function and structure before moving forward. Be careful and move
// SLOWLY and METHODICALLY.
//
// NOTE!!! ------> THIS STARTER CODE DOES NOT COMPILE! Comment stuff out or write
//                 code to get it to work!!!!
//
// *****************************************************************************

// Make a structure called Process. This structure represents a process.
struct Process {
  // contains three ints
  int ProcNum;
  int size;
  int time;
};

// Make a structure called MemoryArea. This structure represents an area
// in memory including the process that occupies it. It contains:
// an integer called start, an integer called end, and a Process structure called proc.

struct MemoryArea {
  int start;
  int end;
  Process proc;
};

// Make a structure called Memory. This structure represents the memory
// in your program. It has an integer called size that represents the
// total size of memory and an array of MemoryArea structures called free.

struct Memory{
  int size;
  char * free;
};

// Function prototypes go here
struct MemoryArea makeMemoryArea(int, int);
struct MemoryArea * makeBuffer(int);
int addAreaToBuffer(struct MemoryArea *, int size, int key);
struct Memory makeMemory(int);
void printMemory(struct Memory);
void printBuffer(struct MemoryArea *, int size);
struct Process makeProcess(int);
void printProcess(struct Process);
int run(struct Memory);
void aquire(struct Memory, struct Process);
void updateMemory(struct Memory);
void release(struct Memory, struct Process);
void resetEnd(int, struct Memory);
int isEmpty(struct Memory);

int main() {
  // initializes a new memory structure
  struct Memory m = makeMemory(MEMSIZE);
  // prints the structure using the printMemory
  printMemory(m);
  // invokes the run() command with the new memory object m
  run(m);
  // when done it frees the memory
}

///////////////////////////////////////////////////////////////
//
//
// run() -  The run method spins up totalProcesses processes. Each
//          process has a size and an execution time. At the creation
//          of each process, the acquire method is called as an attempt
//          to grab the needed memory for the process. After totalProcesses
//          processes have been created, the run function iterates until
//          all processes have fully executed their code. To determine if
//          Memory is empty, the function isEmpty() is called.
//
// NOTE: Don't change this.
//
///////////////////////////////////////////////////////////////
int run(struct Memory m) {
  int totalProcesses = 1;
  int empty = -1;
  srand(time(NULL));
  do {
    printf("\n*********************** ITERATION ***************************\n");
    updateMemory(m);
    if (totalProcesses < 15) {
      struct Process p = makeProcess(totalProcesses);
      printProcess(p);
      aquire(m, p);
      totalProcesses++;
    }
    printMemory(m);
    printf("\n********************** ITERATION END *************************\n\n");
    empty = isEmpty(m);
  } while (empty == 0);
  return 0;
}

/////////////////////////////////////////////////////////////
//
//
//  PROCESS FUNCTIONS
//
//
/////////////////////////////////////////////////////////////
//
// TASK:    makeProcess will take in a process number, create a
//          process structure called p, set the procNum to the incoming
//          argument, then generate a random size using the MAXSIZE
//          macro as a modulo and assign it to the size variable in the
//          process. It will then generate a random time using the
//          TIMESIZE macro as a modulo and set that into the time variable
//          in the process. Return the new process p.
//
//          Use rand() % someThing to randomly generate numbers. It's
//          also ESSENTIAL that you modify the random numbers such that:
//          1) no program can have a size of zero and 2) time is at least
//          three above the minimum generated time size.
//
struct Process makeProcess(int procNum) {
  printf("Your Code Here.");
}

// TASK:    printProcess takes in a process and prints it's information. The
//          format must look like:
//
//          PROCESS:
//          --->Num:--->{procNum}
//          --->Size:--->{size}
//          --->Time:--->{time}
//
//          NOTE: ---> indicates a tab.
//
void printProcess(struct Process p) {
  printf("Your Code Here.");
}

/////////////////////////////////////////////////////////////
//
//
//  MEMORY FUNCTIONS
//
//
/////////////////////////////////////////////////////////////
//
// TASK:    isEmpty can be applied however you feel is best.
//          it serves to indicate whether your Memory structure
//          has NO processes left running.
//
// HINT:    Looking at the size of the first MemoryArea can
//          help discover if the Memory is empty.
//
int isEmpty(struct Memory m) {
  printf("Your Code Here.");
}

// TASK:    This one is difficult... So think carefully about what's going on.
//          The function will search the Memory structure m and find the next
//          available slot. To find the next slot, iterate through the MemoryArea
//          list in the Memory structure and find the MemoryArea with a start
//          of -1. This indicates that it is uninitialized and outside the memory
//          Grab the index one before that area and exit the loop immediately.
//          Check the size of the available block by subtracting it's start from
//          its end.
//
//          If that range is greater than the size of the incoming Process p, then:
//          Set the available block's proc to the incoming process p. Set the end
//          of the block to blocks start plus the process’ size. Set the NEXT
//          MemoryArea's start to the available block's end plus 1. Set the NEXT
//          MemoryArea's end to the size of Memory structure m.
//
//          Else: printf("Not Enough Room! Releasing Memory.") with a newline.
//
void aquire(struct Memory m, struct Process p) {
  printf("Your Code Here.");
}

// TASK:    This is another difficult one. Possibly the most difficult. So think
//          CAREFULLY about the process. This process releases a Process p's
//          MemoryArea from Memory m.
//
//          First, find the index at which the process resides by matching the
//          procNum from the Memory's MemoryArea to the procNum of the incoming
//          Process p. Next, find the end location of the Memory area. You do
//          this by looking at the NEXT MemoryArea's end. If it is -1, the
//          current MemoryArea is your end index. I used a single for loop and
//          iterated over m using m.size as a length. When I found the process,
//          I saved i as the start location and when I found the -1, I saved the
//          i as the end location and then set i to the size of m to exit the loop.
//
//          Now that you have a the start index and the end index, you need to
//          roll processes forward into the vacant slot. When you get to the end,
//          you need to open the rest of the space back up for other processes.
//          Doing this takes some deeper thought. So... first, we want to loop from
//          the start location to the end location using a for loop. Inside the
//          loop we're looking for two cases: 1) are we at the end location
//          where we need to consolidate or 2) are we not. If we aren't at the
//          end, we shift the process forward. If we are at the end, we reset
//           the end blocks.
//
//          Let's start with case 2 as it's the easier of the two: we are not at
//          the end. If we aren't at the end we need to: set the current MemoryArea
//          end to the current MemoryArea's start plus the NEXT MemoryArea's end
//          minus the NEXT MemoryArea's start. This gives us a new end for the
//          current MemoryArea. Next, we set the current MemoryArea's proc to
//          the NEXT MemoryArea's proc. Finally, we adjust the NEXT MemoryArea's
//          start to our current MemoryArea's end plus one.
//
//          When we get to i == end_location - 1, we have to do something
//          different... I actually created a helper function for this, but you
//          can just put it right within the decision structure. First, we set
//          our current start to the PREVIOUS MemoryArea's end plus 1. Next, we
//          set our current end to m.size. We then set the current proc's
//          procNum and time to zero. Finally we deinitialize the memory by
//          setting the NEXT MemoryArea's start and end to -1.
//
//          Read this description... a TON and understand what you are trying to do.
//
void release(struct Memory m, struct Process p) {
  printf("Your Code Here.");
}

// TASK:    updateMemory will take in a Memory structure m, iterate the contents
//          and update each Processes time by subtracting one. If the time is 0
//          or below, it will call release() with m and the current MemoryArea's
//          process.
//
//          To do this, iterate over m using m.size. If the procNum of the current
//          MemoryArea is not zero check the proc time. If the time of the proc of
//          the current MemoryArea is less than or equal to zero, call release
//          using m and the current Process in the MemoryArea. Otherwise, decrement
//          the time of the proc of the current MemoryArea by one.
//
void updateMemory(struct Memory m) {
  printf("Your Code Here.");
}

// TASK:    makeMemoryArea() takes in a start and end as integer, creates a new
//          MemoryArea structure, sets the structures start and end to the incoming
//          values, and returns the new MemoryArea structure.
//
struct MemoryArea makeMemoryArea(int start, int end) {
  printf("Your Code Here.");
}

// TASK:    makeBuffer() takes in an integer size and builds a list of
//          MemoryAreas. Remember, a list of characters is a char *, a list of ints
//          is int *, thus a list of MemoryAreas should follow the same pattern.
//          In the function, create a new list of MemoryAreas called buffer.
//          Malloc the buffer to size times the sizeof a MemoryArea structure.
//          Iterate over the size using a for loop. If i is 0, set the start of the
//          MemoryArea to 0 and the end to size, else set the start to -1 and the
//          end to -1. Return buffer.
//
struct MemoryArea * makeBuffer(int size) {
  printf("Your Code Here.");
}

// TASK:    makeMemory will take in a size, declare a Memory structure called m
//          and will call the makeBuffer() function for the free value and set the
//          size value to size. Return m.
//
struct Memory makeMemory(int size) {
  printf("Your Code Here.");
}


// TASK:    printMemory() takes in a Memory structure mem, prints "BUFFER", a newline,
//          then calls the printBuffer() function with mem.free and mem.size.
//
void printMemory(struct Memory mem) {
  printf("Your Code Here.");
}

// TASK:    printBuffer() will iterate through the list of MemoryAreas and for each
//          MemoryArea that doesn't have start value of -1, print with the following
//          format:
//
//          --->Start:--->{start}
//          --->End:--->{end}
//          --->Size:--->{proc.size}
//          --->Proc:--->{proc.procNum}
//          --->Time:--->{proc.time}
//          \n
//
//          Again, ---> indicates a tab.
//
void printBuffer(struct MemoryArea * m, int size) {
  printf("Your Code Here.");
}
