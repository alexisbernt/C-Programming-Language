// Lab 4 , Alexis Bernthal

// Subjects: struc programming concept: a solution for organizing data
// Define simple struct, declare an instance, populate the data, print data, and free memory

#include <stdio.h>
#include <stdlib.h>

// define macros
#define WELCOME "\nWelcome to the Process Manager\n"
#define END "\nEnding Process Manager\n"
#define SIZE 10

// create function prototypes
void printWelcome();
struct process makeProcess();
int getID();
char * getName();
void printProcess(struct process);
void printEnd();
void freeProc(struct process);

// defining a structure
//struct myStruct{
//  member definition;
//  member definition;
// };

struct process{
  int id;
  char * name;
};

void printWelcome(){
  printf("%s", WELCOME);
}

void printEnd(){
  printf("%s", END);
}

int getID() {
  int num;
  printf("Enter ID: ");
  scanf("%d", &num); // & is the address operator
  // address operator: (get the address of variable num)
  return num;
}

// after allocating memory for the char we must null terminate
char * getName(){
  char * temp = malloc(SIZE * sizeof(char));
  temp[SIZE] = '\0';
  printf("Enter name: ");
  scanf("%s", temp);
  return temp;
}

// making the process
struct process makeProcess() {
  printf("\n**********GET INPUT*********\n\n");
  struct process p1; // creating an instance of the proces struct
  p1.id = getID(); // setting p1's id integer to the value of getID
  p1.name = getName();
  return p1;
}

// printing out the process Function
void printProcess(struct process p1) {// taking in the struct process as parameter
  printf("\n********PRINT OUT********\n\n");
  printf("Process ID: %d\n", p1.id);
  printf("Process Name: %s\n", p1.name);
}

// freeProc will free up allocated memory inside of the process
void freeProc(struct process p1) {
  free(p1.name); //free up allocated memory from p1.name
}

int main() {
  //char str1[] = "Welcome to Lab 4. Don't hit the door on your way out.\n";
  //printf("%s", str1);
  printWelcome();
  struct process p1; // creating the process
  p1 = makeProcess(); // output goes to p1
  printProcess(p1);
  freeProc(p1);
  printEnd();
  return 0;
}
