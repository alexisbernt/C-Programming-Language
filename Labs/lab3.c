// Lab 3 , Alexis Bernthal , Strings, Malloc, free, #define, and IO

// Lab Notes: (From Lab 3)
// string structures not easily facilitated in C
// In C strings = arrays of characters
// In C must make the distinction between address and data (USE POINTERS)


#include <stdio.h>
#include <stdlib.h>
// C allows us to designate macros (defining keywords at top of source file)
#define STR_SIZE 20 // defines STR_SIZE as 20 (can then be called throughout the file)
#define FORMAT_STRING "%19s"

// creating function prototypes (Shown below the main method)
char * getUserInput(char *, char *); // take two char variables and return char

void printWelcome(char *); // take one char and return void

void printUserInput(char *, char *, char *);
// to build an array
//char * myString;

// use malloc() function to allocate some memory for us
// malloc() stands for "memory allocation" and takes a size as argument

// character array
//char * myString = malloc(10 * sizeof(char));

// push into scanf() and take user input
//scanf("%9s", myString); // cannot take over 10 characters or else buffer overflow

// free() function helps free up the resources we have used (avoid a memory leak)
//free(myString);

// multiplies size of char by 20 to create the size of the string array
//char * myString = malloc(STR_SIZE * sizeof(char));

// creating main method
int main() {
  char * welcomePrompt = "Welcome to Lab 3, Let us get to it!\n";
  char * firstNamePrompt = "Please enter your first name: ";
  char * lastNamePrompt = "Please enter your last name: ";
  char * outputFormat = "\n%s %s, welcome to CYBR 401! \n\n";
  char * inputFormat = "%19s";
  //printf("%s", str1);
  printWelcome(welcomePrompt);
  char * firstName = getUserInput(firstNamePrompt, inputFormat);
  char * lastName = getUserInput(lastNamePrompt, inputFormat);
  printUserInput(firstName, lastName, outputFormat);
  // free our two malloc() calls
  free(firstName);
  free(lastName);
}

// getUserInput() function. Take two strings and return one
char * getUserInput(char * prompt, char * format){
  // allocate memory for an input buffer
  char * userInput = malloc(STR_SIZE * sizeof(char));
  userInput[STR_SIZE] = '\0';

  // print prompt for input parameters
  printf("%s", prompt);

  // use scanf to get user input
  scanf("%19s", userInput);

  return userInput;
}

// printWelcome() function
void printWelcome(char * welcome){
  printf("\n%s\n\n", welcome);
}

// function that will print user input
void printUserInput(char * fName, char * lName, char * format){
  printf(format, fName, lName);
}
