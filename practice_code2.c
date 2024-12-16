// #include <stdio.h>
// #include <stdlib.h>
//
// // defining a global constant
// #define SIZE 10
//
// // array is nothing more than an address
// // a pointer is an address
//
// char * getUserString(char *, int);
// int getUserInt(char *);
//
// int main(){
//   int ui = getUserInt("Enter a integer: ");
//   printf("%d", ui);
//   char * userInput = getUserString("Enter a name: ", ui);
//   char * ui2 = userInput + 4;
//   ui2[4] = '\0';
//   printf("--> %s", ui2);
// }
//
// char * getUserString(char * prompt, int size){
//   char * userInput = malloc(size * sizeof(char));
//   // must null terminate
//   userInput[size] = '\0';
//   printf("%s", prompt);
//   scanf("%s", userInput);
//   return userInput;
// }
//
// int getUserInt(char * prompt){
//   int ui;
//   printf("%s", prompt);
//   scanf("%d", &ui);
//   return ui;
// }

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 100
#define UNITS 10

int str_length(char *);
char * str_copy(char * );

int main(){
  int length = str_length("string");
  printf("%d", length );
  char * copyCat = str_copy("check");
  printf("%s",copyCat );

}

int str_length(char * string){
  int i = 0;
  while (string[i] != '\0'){
    i++;
  }
  return i;
}

char * str_copy(char * string){
  int length = str_length(string);
  char * copiedString = malloc(length * (sizeof(char)));

  for (int i =0; i < length; i++){
    copiedString[i] = string[i];
  }
  return copiedString;
}

// struct process{
//   int * pid;
//   char * name;
// };
//
// struct process_node{
//   int * pid;
//   char * name;
//   struct process_node * next; // pointing to the next node
// };
//
// // function prototype
// int string_length(char * str);
//
// int main(){
//   // ARRAY: define the arrays of struct (static)
//   struct process proc[UNITS];
//
//   // LIST: define the list
//   struct process * proc_list = malloc(sizeof(struct process) * UNITS);
//
//   // LIST: making a linked list
//   struct process_node * start = NULL; // start of the list is empty initially
//
//   // ARRAY: Working with arrays
//   for (int i = 0; i<UNITS; i++){
//     proc[i].pid = malloc(sizeof(int));
//     proc[i].name = malloc(LENGTH * sizeof(char));
//   }
//
//   printf("Printing the PID and Name of Process 1: \n" );
//   printf("Please enter the PID: \n");
//   scanf("%d", proc[0].pid);
//   printf("Please enter the name: \n");
//   char temp[LENGTH];
//   scanf("%s", temp);
//
//   int name_length = string_length(temp); // to count the length of input string
//
//   // Allocate exact memory for the string and copy it manually
//     proc[0].name = realloc(proc[0].name, (name_length + 1) * sizeof(char));
//     for (int i = 0; i <= name_length; i++) {
//         proc[0].name[i] = temp[i];
//       }
//
//   // Display the details
//     printf("\nProcess 1 Details:\n");
//     printf("PID: %d\n", *proc[0].pid);
//     printf("Name: %s (Length: %d characters)\n", proc[0].name, name_length);
//
//     for (int i = 0; i < UNITS; i++) {
//         free(proc[i].pid);
//         free(proc[i].name);
//       }
//     return 0;
// }
//
// int string_length(char * str){ // const char * is pointer to constant character
//   int length = 0;
//   while (str[length] != '\0'){
//     length ++;
//   }
//   return length;
// }

// NOTES
// // to indicate it is an address use *
// char * myString;
// // creating string for char with a size of 10
// myString = malloc(10*sizeof(char));
// // you must null terminate
// myString[10] = '\0';
//
// printf("%s", myString);
// printf("Enter a name: " );
// scanf("%s", myString);
// printf("You entered %s", myString );
