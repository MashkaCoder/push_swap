# Push_swap
[![Intro](https://img.shields.io/badge/Cursus-Push_swap-success?style=for-the-badge&logo=42)](https://github.com/MashkaCoder/push_swap.git)<br>
The purpose of this project is sorting data on a stack, with a limited set of instructions, using
the lowest possible number of actions. <br>
## Cloning <br>
```
git clone https://github.com/MashkaCoder/push_swap.git
cd push_swap
make
```
## Make rules

- `make` to compile mandatory part. <br>
- `make clean` to clean all object files. <br>
- `make fclean` to remove executable files. <br>
- `make re` to recompile this project.<br>

## Usage <br>
You can enter a random number of positive or negative numbers without any duplicates.

 ```
 $ ./push_swap a set of numbers to sort without " "
 ```
 
 At the output, you will get a set of commands with which the stack was sorted. Below are the descriptions of the commands
 
 - `sa` swap a - swap the first 2 elements at the top of stack a.
 - `sb` swap b - swap the first 2 elements at the top of stack b.
 - `ss` sa and sb at the same time.
 - `pa` push a - take the first element at the top of b and put it at the top of a.
 - `pb` push b - take the first element at the top of a and put it at the top of b. 
 - `ra` rotate a - shift up all elements of stack a by 1.  The first element becomes
        the last one.
 - `rb` rotate b - shift up all elements of stack b by 1.  The first element becomes
        the last one.
 - `rr` ra and rb at the same time.
 - `rra` reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
 - `rrb` reverse rotate b - shift down all elements of stack a by 1. The last element becomes the first one.
 - `rrr` rra and rrb at the same time.

If you want to see a set of sorted numbers, then first in the `push_swap.h` file add the `stdio.h` library to use `printf` function
 
```
#include <stdio.h>
 ```
Then paste the code below in the `push_swap.c` file above the `exit` function
 ```
  int j;
  j = 0;
  while(j < stack.a_size)
  {
    printf("%d\n", stack.a->value);
    stack.a = stack.a->next;
    j++;
  }
  ```
   ## Subject
 > [subject](push_swap.subject.pdf)
