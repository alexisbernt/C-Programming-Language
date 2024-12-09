# Programming in C

 The C code that the OS uses directly connects to the hardware via drivers, and directly controls the CPU via scheduling.

C is super close to the operating system. This is because the kernel is typically written in C for operating systems.

 C is a programming language where the types for variables (ex: int, float, char) are declared and function signatures are declared explicitly.

 C is a static typed langauge (where the type declarations are required at compile time).

 An array in C is a collection of variables that are stored in contiguous memory locations.
 
 First declare the data type: 
 Example with int: int myNumbers[] = {25, 50, 75, 100};

## Data Types:

### int

### char

### pointer : char * is a pointer
 
### char *
 char * = A pointer to a char. char * is typically used to represent a string. A string is an array of characters that ends with a null character ('\0'). An array of characters that will be terminated by a null character.
 You dynamically allocate memory for strings using malloc (allocate memory space)

### char ** 
 char ** = a pointer to a char *, meaning it points to a memory location that stores the address of another char. Use When using a list of strings / array of strings. 

 ### float

 ### double
 
 Example: char ** array[] = {"a", "b", "c"}; ... char ** ptr = arr; // will point to an array of char * strings

### System Calls
fork() = creates something (a child) you can make a process with 
dup() = takes data produced by child and puts it in to parent process 
wait() 
exec() = takes the information that is needed 
