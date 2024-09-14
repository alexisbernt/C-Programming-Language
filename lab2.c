// Bernthal, Alexis. Lab 2

// C requires data type specifications
// ex: Wanting to use an int in a variable: int someVar
#include <stdio.h>

// Declaring a Function
int getUserInput(){
  int number;
  printf("Please enter a number between 1 and 10: " );
  // then read the input and want to store it in a variable (number)
  scanf("%d", &number );

  if (number > 0 && number < 11){
    // printf("\nYou chose the value: %d", number ); // will return the value
    return number;
  } else {
    // printf("\nNon-valid entry. " );
    return -1; // -1 is an error code (looked up online)
  }
}

// Creating method calcAvg()
int calcAvg(){
  int number = getUserInput();
  printf("\nThe starting value is: %d\nNow looping through...\n", number);
  // using a while loop starting at 0 then go up to entered number
  int i = 0;
  // sum variable will keep the sum
  int sum = 0;
  while (i <= number){
    printf("%d\n", i);
    // add current number to the sum variable
    sum += i;
    // ++ adds 1 to the counter
    i++;
  }
  printf("\nThe sum of all these numbers is: %d\n", sum);
  float mean = (sum/i);
  printf("\nThe mean of all these numbers is: %f\n", mean);
  return number;
}

// Creating method farewell()
char farewell(){
  char str2[] = "\nFarewell! Thanks for using this program!\n\n";
  printf("%s", str2);
  return 0;
}

int main() {
  char str1[] = "Welcome to Lab 2, YAY\n";
  printf("%s", str1);

  // Calling function created above getUserInput
  int returned_number = getUserInput();

 // Then have to print out the returned value in the main method
 // commented out section below and section below that both work
  // if (returned_number != 1) {
  //   // %d will display the number
  //   printf("\nYou chose the number: %d\n", returned_number); // print new line first
  // }
  if (returned_number > 0 && returned_number < 11){
    printf("\nYou chose the value: %d\n", returned_number ); // will return the value
    //return returned_number;
  } else {
    printf("\nNon-valid entry. \n" );
    //return -1; // -1 is an error code (looked up online)
  }
  int i = 0;
  calcAvg();

  farewell();

  return 0;
}

void printValues(){
  int val1 = 5;
  int val2 = 10;
  int val3 = 20;
  // to print to the console
//  printf("This is the value: %d\n", val);
 // positional printing
  printf("val1 = %d, val2 = %d, and val3 = %d\n", val1, val2, val3);

int val;
scanf("%d", &val);

// // to take input into a string
// scanf("%s", string);
}
// void printTen() {
// printf("%d\n", 10);
// }
