// Alexis Bernthal. Homework 1. Operating Systems Fall 2024

#include <stdio.h>
#include <stdlib.h>
#define SIZE 20 // defines SIZE as 20 (macro)
#define PRINT "\n\n***** BEGIN PRINTOUT *****\n\n"
#define WELCOME "\nWelcome to Assignment 1 where we create a database that can add users!"
#define START "\n***** PROGRAM START *****"
#define FREE "\n\n***** BEGIN FREE *****"
struct user{
  // build struct --> the struct is grouping data together
        int userNum;
        char *userName;
        char *userFirst;
        char *userLast;
};

void freeMemory(struct user users[SIZE]){
  int num = -1;
  int count = 0;
  printf("%s", FREE);
  while (num != 0 && count < SIZE){
    num = users[count].userNum;
    if (num != 0){
      free(users[count].userName);
      free(users[count].userFirst);
      free(users[count].userLast);
    }
    count++;
  }
}

// main needs to be at the top
int main() {
  int num = 0;
  //struct user * users = malloc(sizeof(SIZE));
  struct user users[SIZE];
  // struct user *users = malloc(sizeof(struct user) *(SIZE));
  users[SIZE].userNum = 0;
  printWelcome();
  num = getNumUsers(); // catch in getNumUsers
  addUsers(num, users);
  printUsers(users);
  freeMemory(users);
  return 0;
}

// ask user to enter the number of users that they would like to entered
int getNumUsers(){
  int number;
  char term;
  printf("\nPlease enter the number of users you would like to add: " );
  // using a perpetual for loop
  for(;;){
    if(scanf("%d%c", &number, &term) !=2 || term != '\n'){
      printf("\nPlease enter an integer! Try again: \n" );
      clearStdin();
    } else {
      break;
    }
  }
return number;
}

int clearStdin(){
  int c = 0;
  while (('\n' != (c=fgetc(stdin)))&&(c != EOF)){
    if (c==EOF) break;
  }
  return 0;
}

// user has a user number, username, first name, and last fName
char * addString(char * prompt){
  // allocate memory for an input buffer
  char * str = malloc(SIZE * sizeof(char));
  str[SIZE] = '\0'; // null terminating
  printf("%s", prompt);
  // use scanf to get user input str
  scanf("%19s", str);
  return str;
}

int addInt(int * num, char * prompt){
  printf("\n\tEnter user number: ");
  scanf("%d", num);
  return *num;
}

int addUsers(int loopNum, struct user users[SIZE]){
  int i = 0; // declaring int called i
  for (i = 0; i < loopNum; i++){
    printf("\n***** New User %d *****", i+1);
    // use & character to get the address of the variable // call addInt using address of user array
    addInt(&users[i].userNum, "\n\tEnter User Number: ");
    users[i].userName = addString("\n\tEnter Username: ");// catch the output into users[i].username
    users[i].userFirst = addString("\n\tEnter First Name: ");
    users[i].userLast = addString("\n\tEnter Last Name: ");
  }
  users[loopNum].userNum = 0; // set user number for user at loopNum
  return 0;
}

// was char * printWelcome but now int printWelcome bc char * differs in levels
int printWelcome(){
  printf("%s\n", WELCOME);
  printf("%s\n", START);
  return 0;
}

// print all users in the users structure array
int printUsers(struct user users[SIZE]){
  int num = -1;
  int count = 0;
  printf("%s", PRINT);
  while (num != 0 && count < SIZE){ // logical AND operator
    num = users[count].userNum;
    if (num != 0){
      printf("\n***** User Number %d Summary *****\n", count+1);
      printf("\n\tUser number: %d", count + 1); // \t for tab
      printf("\n\tUsername: %s", users[count].userName);
      printf("\n\tUser First: %s", users[count].userFirst);
      printf("\n\tUser Last: %s\n", users[count].userLast);
    }
    count ++;
  };
  return 0;
}
