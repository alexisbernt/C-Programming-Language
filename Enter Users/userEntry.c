#include <stdio.h>
#include <stdlib.h>

// The point of this assignment is to create a simple database to take potential users

#define UNITS 20

struct user{
  char * fName;
  char * lName;
  char * email;
  int * phoneNum;
  int * id;
};

// function prototypes
int getUsers();
void getLength(char *);
void * copyString(char *, int);

int main(){
  // explain how to use the program
  printf("\nWelcome to the program. You will be prompted to answer a few questions. Please answer the prompts.\n\n");

  // ask the user for a number to symbolize the number of users
  int numUsers = getUsers();
  printf("\nNumber users entered: %d\n\n", numUsers);
  struct user * list = malloc(numUsers *sizeof(struct user)); // creating a list of users

  for (int i = 0; i < numUsers; i++){
    printf("%s", list[i].fName);
    list[i].fName = malloc(UNITS * sizeof(char));
    list[i].lName = malloc(UNITS * sizeof(char));
    list[i].email = malloc(100 * sizeof(char));
    // list[i].phoneNum = malloc(sizeof(int));
    list[i].phoneNum = malloc(sizeof(int));
    list[i].id = malloc(sizeof(int));

    printf("Enter first name: " );
    scanf("%s", list[i].fName);
    printf("Enter last name: " );
    scanf("%s", list[i].lName);
    printf("Enter email: " );
    scanf("%s", list[i].email);
    printf("Enter phone number: " );
    scanf("%d", list[i].phoneNum);
    printf("Enter User's ID: " );
    scanf("%d", list[i].id);

}

// Would then print all users
  printf("\n --- NOW PRINTING ALL USER INFORMATION BACK ---");
  for(int i = 0; i < numUsers; i++){
    printf("\nFirst Name: \n");
    printf("%s", list[i].fName);
    printf("\nLast name: \n");
    printf("%s", list[i].lName);
    printf("\nEmail: \n" );
    printf("%s", list[i].email);
    printf("\nPhone Number: \n" );
    printf("%d", list[i].phoneNum);
    printf("\nUser ID: \n" );
    printf("%d", list[i].id);
    // would then free()
    free(list[i].fName);
    free(list[i].lName);
    free(list[i].email);
    free(list[i].phoneNum);
    free(list[i].id);
}
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

int getLength(char * string){
  int stringLength = 0;
  while (string[stringLength] != '\0'){
    stringLength++;
  }
  return stringLength;
}

char * copyString(char * userEntry, int length){
  char * newString = malloc(length * sizeof(char));
  newString[length] = '\0';
  printf("%s", userEntry);
  scanf("%s", newString);
  return newString;
}
