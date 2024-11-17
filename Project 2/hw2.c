// Homework 2. Alexis Bernthal. Oct. 30 2024
// Interactive shell for OS -- want to be able to run commands
/*
Alexis Bernthal. Homework 2.

take in command line input
make sure there are only 3 inputs
use a function to split the string into substrings at the delimiter
store those substrings into a string array
pass that back

// CREDIT: Nova did send me their funner.c script after I missed Friday's class
and I took inspiration from formatting and that code for this assignment. Juan also
helped me with the parse function some initially when I was struggling with that.
Finally, I did reference some online sources like GeeksforGeeks and W3Schools.

FOR UNIX MACHINE RUN GCC
command line call used (after gcc):
	./a.out ":" "aaaaa:bbbbbb:cccc"

FOR WINDOWS MACHINE RUN CL INSTEAD OF GC
command line call used:
cl Funner.c -o Funner
then run Funner.exe ":" "aaaaa:bbbbbb:cccc"

*/
#include <stdio.h>
#include <stdlib.h>
// Take command line input (1) delimiter (2) string --> split

// --- MACROS ------------------------------(n/a)----

// --- STRUCTURES --------------------------(n/a)----

// --- PROTOTYPES ------------------------------------
char ** parse(char delim, char * parsee, char ** arr); // parse will not return a value
// build a char ** (list of strings)
char * substring(int, int, char *);
char ** create2DArray(int);
int twoDSize(char delim, char * parsee);

// --- MAIN ------------------------------------------
// Using command line args to get string and delimiter
int main(int argc, char ** argz) {
  // making sure there are enough command line arguments
	if (argc == 3) {
		printf("\nYay! Things are working.\n\n");
	} else {
		printf("\n*Sigh* Things are no working.\n");
}
  char * parsee = argz[2]; // refers to string being parsed
  char delim = argz[1][0]; // refers to delimiter
  int count = twoDSize(delim, parsee); // count the delimiters
  // count will be the number of substrings expected

  // malloc char ** before calling parse
  char ** substrings = malloc(count * sizeof(char *)); // each char * points to a substring
// each char * used to store a substring
  if (substrings == NULL){
    printf("Error. Fail to allocate memory.");
    return 1;
  }

  // Parse the string and fill the allocated array
    substrings = parse(delim, parsee, substrings);


  for (int i=0; i < count; i++) {
    // free memory
    free(substrings[i]);
  }
  free(substrings);
  return 0;
}

// --- FUNCTIONS -------------------------------------
// do the parse thing
// the parse thing will take a delimiter and a string and array
char ** parse(char delim, char * parsee, char ** arr) {
	int start = 0;
	int end = 0;
  int index = 0; // keep track of position in arr (array) where next substring
  // count the delimiters (delims)
  while (parsee[end] != '\0'){ // go until reach end of string '\0'
    if (parsee[end] == delim){
      // getting the first char from argument 1 and going on (here you get substring):
      arr[index] = substring(start, end, parsee); // arr in array of char* that holds each substring
      printf("Substring: %d: '%s', Length: %d\n", index, arr[index], end-start);
      index++;
      start = end +1;
    }
    end++; // go to next
  }
  arr[index] = substring(start, end, parsee); // store final substring in arr[index]
  printf("Substring %d: '%s', Length: %d\n", index, arr[index], end - start);
	return arr;
}

// FURTHER ATTEMPTS -------------------------------------------
  // This section gets the length of the string
  // char * stringParse = parsee[2]; // grabbing the entire string
  // printf("%s", stringParse);
  // int getLength = stringLength(stringParse);
  // printf("\nThe length of the string is: %d\n", getLength);

  // This section does a second pass to store the substrings
//   int index = 0;
//   while (parsee[end] != '\0') {
// 		printf("start = %d; end = %d;   %c\n", start, end, parsee[end]);
// 		if (parsee[end] == delim) {
// 			// char * sub = substring(start, end, parsee);
//       arr[index++] = substring(start, end, parsee);
// 			// printf("%s\n", sub);
// 			start = end+1;
// 		}
// 		end++;
// 	}
//-------------------------------------------------------------

// parse out the number of substrings --> creates a substring from parsee[start] to parsee[end]
char * substring(int start, int end, char * superstring) {
	int length = end - start;
	char * substr = malloc(length * sizeof(char)); // substr is pointer to char
  if (substr == NULL) {
    printf("Failed to allocate memory"); // error checking
    exit(1);
  }
	int i =0;
  while (i < length) {
    substr[i] = superstring[start+i]; // copy the char
    i ++;
  }
	substr[length] = '\0';
	return substr; // substr will have chars from superstring in right amount
}

// want to create a function that can get the length of the sequence --> then call from parse function
int stringLength(char * input) {
  int count = 0;
  while (input[count] != '\0'){
    count++;
  }
  return count;
}

// to create 2D array (if needed)
char ** create2DArray(int size){
  char ** array = malloc(size * sizeof(char *));
  array[size] = NULL;
  int i = 0;
  while(i<size){
    array[i] = malloc(1 * sizeof(char));
    array[i][1] = '\0';
    i++;
  }
  return array;
}

int twoDSize(char delim, char * parsee){
  int count = 1; // start at 1 to get the last segment after the last delimiter
  while (* parsee != '\0') {
    if (* parsee == delim) {
      count++;
      printf("%d\n", count);
    }
    parsee++;
  }
  return count;
}
