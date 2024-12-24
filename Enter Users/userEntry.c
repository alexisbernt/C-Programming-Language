#include <stdio.h>
#include <stdlib.h>

// The point of this assignment is to create a simple database to take potential users

#define UNITS 20

struct user{
  char * fName;
  char * lName;
  char * email;
  int phoneNum;
  int id;
};

// function prototypes
int getUsers();
void copyString(char * destination, char * source);
void printString(const char * string);

int main(){
  // explain how to use the program
  printf("\nWelcome to the program. You will be prompted to answer a few questions. Please answer the prompts.\n\n");

  // ask the user for a number to symbolize the number of users
  int numUsers = getUsers();
  printf("\nNumber users entered: %d\n\n", numUsers);

  // Allocate memory for the list of users
  struct user * list = malloc(numUsers *sizeof(struct user)); // creating a list of users
  if (list == NULL){
    printf("Memory allocation failure. Exiting the program. \n" );
    return 1;
  }

  // Input the user data part of the code
  for (int i = 0; i < numUsers; i++){
    list[i].fName = malloc(UNITS * sizeof(char));
    list[i].lName = malloc(UNITS * sizeof(char));
    list[i].email = malloc(100 * sizeof(char));

    // Don't malloc for the integers
    // list[i].phoneNum = malloc(sizeof(int));
    // list[i].id = malloc(sizeof(int));

    printf("Enter first name for user %d: " , i + 1);
    scanf("%s", list[i].fName);
    printf("Enter last name for user %d: ", i + 1 );
    scanf("%s", list[i].lName);
    printf("Enter email for user %d: ", i + 1 );
    scanf("%s", list[i].email);
    printf("Enter phone number for user %d: ", i + 1 );
    scanf("%d", &list[i].phoneNum);
    printf("Enter User's ID: " );
    scanf("%d", &list[i].id);

}

// Would then print all users
  printf("\n --- NOW PRINTING ALL USER INFORMATION BACK ---\n");
  for(int i = 0; i < numUsers; i++){
    printf("\nFirst Name: \n");
    printString(list[i].fName);
    printf("\nLast name: \n");
    printString(list[i].lName);
    printf("\nEmail: \n" );
    printString(list[i].email);
    printf("\nPhone Number: %d \n", list[i].phoneNum);
    printf("\nUser ID: %d \n" , list[i].id);
    // would then free()
    free(list[i].fName);
    free(list[i].lName);
    free(list[i].email);
}
// free the user list
free(list);
return 0;
}

//tester code
      // int tester = getUsers();
      // printf("This many users: %d", tester);

      // char * fNameCopies = list[i].fName
      // char * test = copyString(fNameCopies, UNITS);
      // printf("%s", test);

int getUsers(){
  int * user_input = malloc(sizeof(int));
  printf("Please enter the number of users: \n");
  scanf("%d", user_input);
  return * user_input;
}

// Manually print a string
void printString(const char *string) {
  // deference operator (*) retrieves the value stored at the memory address the pointer string points to
    while (*string != '\0') {
      // putchar prints a single character to the standard output (the console)
        putchar(*string);
        string++;
    }
}

void copyString(char * destination, char * source){
  // * when used with existing pointer = dereference operator
  // *[name] accesses the value stored at the memory address the pointer points to
  // different from &[name] which is the address of the variable x
  // Therefore: * = dereference , & = address of
  while (* source != '\0'){
    * destination = * source;
    destination ++;
    source ++;
  }
  * destination = '\0'; // Null terminate destination string
}
