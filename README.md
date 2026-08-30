# LinkedList Implementation

A simple C implementation of a singly linked list with basic operations such as creation, insertion, deletion, and display.

## Features
- Create a list with an initial value
- Insert at the beginning
- Insert at the end
- Insert at a specific position
- Delete from the beginning
- Delete from the end
- Delete from a specific position
- Display the list contents

## Project Files
- `headers.h` - declarations for the linked list functions and node structure
- `List.c` - implementation of the linked list operations
- `main.c` - sample usage of the linked list

## Linked List Structure
Each node stores one integer value and a pointer to the next node:

```text
+-------------------+
|    struct node    |
|-------------------|
| int data          |
| struct node *next |
+-------------------+
         |
         v
      head --> +--------+     +--------+     +--------+     NULL
               | data:10| --> | data:20| --> | data:30| -->
               | next   |     | next   |     | next   | 
               +--------+     +--------+     +--------+
```

This pattern matches the implementation in `List.c`, where each node points to the next node and operations like insert/delete update these links.

## Build and Run
Compile and run the program using:

```bash
gcc main.c List.c -o program.exe
./program.exe
```

## Notes
This project is intended as a beginner-friendly example of linked list operations in C.
