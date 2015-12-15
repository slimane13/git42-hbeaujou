# get-next-line: a 42 project

The goal of this project was to write a function to read and return the next line of a file prototyped as such:
```
￼int get_next_line(int const fd, char **line);
```

The first parameter is the file descriptor from which to read
, and the second is a pointer to where the client would like the next line to be placed.
The function will return the next line of a file without the '\n' at the end. 
The function will return 1 if successful, 0 if the file has nothing to read, and -1 if there is an error. 
There was a required BUF_SIZE in the project specification for my school
, but my buffer size (and thus call to read) grows exponentially to accomadate the line length.
Multiple file descriptors are handled (up to MAX_FD, defined in the .h file). 

To compile my project, use the commands below: 
$> make -C libft/
$> gcc -Wall -Wextra -Werror -I libft/includes/ -c get_next_line.c
$> gcc -Wall -Wextra -Werror -I libft/includes/ -c main.c
$> gcc -o test_gnl get_next_line.o main.o -L libft/ -lft

I have included a test suite located in the unit-test folder.
The bash script compiles the program and runs it with a number of test files, which are also included. 
The large number of small test files ("4-one", "16-three", etc.)
were included because they were part of the correction at my school. 
To run, use the command "sh run.sh" while in the unit-test folder. To test large files, run "sh hard_run.sh". 

Authorized functions: 
- read
- malloc
- free
