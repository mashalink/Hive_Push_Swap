#Push_swap

The Push_swap project is a very simple and highly effective algorithm project: data will need to be sorted You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks.

Objectives

This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the one (of many) most appropriate solution for an optimized data sorting.

Allowed operations

* sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
* sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
* ss : sa and sb at the same time.
* pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
* pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
* ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
* rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
* rr : ra and rb at the same time.
* rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
* rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
* rrr : rra and rrb at the same time.

3 integers or less
1. The largest integer is found, and rotated to the bottom of the stack.
    This can always be done with a single move, either ra or rra. The largest digit is now sorted.
2. The digits above are either in the correct place, or need to be swapped with sa.

The stack is now sorted.

5 integers or less
1. The largest integer is found, rotated to the top with either ra or rra, then pushed to stack B.
2. The smallest integer is found, rotated to the top with either ra or rra, then pushed to stack B.
3. Stack A is sorted with the "3 integers or less" algorithm.
4. Both digits are pushed from stack B to stack A.
5. Stack A is rotated once with ra to push the largest integer to the bottom.

The stack is now sorted.

100 integers or less
1. Integers are divided into 5 groups by size.
    Group 1 containing the smallest integers and group 5 containing the largest integers.
2. An integer from the first group is rotated to the top of stack A.
    The integer requiring the fewest moves to rotate to the top is chosen. If stack B does not have it's largest number on     top, it will be rotated simultaneously with stack A. This saves several moves throughout the sorting.
3. Stack B is rotated to push the largest integer to the top.
4. The integer on top of stack A is pushed to stack B.
5. Steps 2-4 are repeated until all numbers from the group are in stack B.
6. The next group is chosen, and steps 2-5 are repeated until all groups are in stack B.
    Stack A will now be empty, stack B will contain all integers divided into groups.
7. All integers are pushed back to stack A from largest to smallest.
    Stack B will be rotated when needed to find the largest number.

The stack is now sorted.

500+ integers
The algorithm for 500 integers or more is the same as "100 integers or less", except the amount of groups is increased to 11.

How to use

./push_swap [args ...]

#Checker

Checker takes integers as arguments. On execution, checker will wait for instructions on the standard input. When reading is stopped, checker will print "OK" if the instructions result in a sorted array, and "KO" if not.

The optional -v flag enables debug mode, which prints both stacks after each operation.

How to use

./checker [-v] [args ...]

Grade
125/100
