 When programming in C, pipes are a mechanism for inter-process communication (IPC) that allows data to flow from one process to another.
 Pipes are commonly used to enable one-way communication between processes.

Key Features:
Unidirectional Communication: Data flows in one direction, either from a producer to a consumer or vice versa.
Parent-Child Process Communication: Pipes are typically used between related processes (e.g., parent and child processes).
File Descriptor-based: A pipe is represented by two file descriptors:
- Read end: To read data from the pipe.
- Write end: To write data into the pipe.

pipe(thePipe): --> Creates a pipe.

fork() creates new child process.

Pipes determine flow of data. 
