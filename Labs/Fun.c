#include <stdio.h>
#include <stdlib.h>

//figure out multidimenstional arrays
//figure out command line getUserInput

int stringLength(char *);
int tootySize(char **);
char * stringCopy(char *);
char ** create2DArray(int);

int main(int argc, char ** argz) {
    char ** newArray = create2DArray(10);
    int size = tootySize(newArray);
    printf("%d\n", size);
}

char ** create2DArray(int size){
  char ** array = malloc(size * sizeof(char *));
  array[size] = NULL;
  int i;
  for(i=0; i<size; i++){
    array[i] = malloc(1 * sizeof(char));
    array[i][1] = '\0';
  }
  return array;
}

int tootySize(char ** inputArray){
  int count = 0;
  while (inputArray[count] != NULL) {
    count++;
    printf("%d\n", count);
  }
  return count;
}

int stringLength(char * input) {
  int count = 0;
  while (input[count] != '\0'){
    count++;
  }
  return count;
}

char * stringCopy(char * input) {
  int length = stringLength(input);
  int i;
  printf("%d\n", length);

  char * copied = malloc(10 * sizeof(char));
  for (i=0; i <= length; i++){
    copied[i] = input[i];
  }
  return copied;

}
