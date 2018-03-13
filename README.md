## Pouring Water puzzle
written by @spencereanes, @silverschiller, @MagnusCardell

A breadth first search implemented solution

We have three containers whose sizes are 10 pints, 7 pints, and 4 pints respectively. The 7-pint and 4-pint containers start out full of water, but the 10-pint container is initially empty. We are allowed one type of operation: pouring the contents of one container into another, stopping only when the source container is empty or the destination container is full. We want to know if there is a sequence of pourings that leaves exactly 2 pints in the 7- or 4-pint container. 


Our algorithm finds a solution with 7 pours. 

When running this algorithm, you will get an output of keys upon finding successfull final state. 074 is the start state where there is an empty (0) 10-pint, full (7) seven pint, and full (4) four-pint container. 

This is the solution with keys
074
470
1010
614
650
254
272


To compile use c++11 because we use to_string().
g++ -std=c++11 PouringWater.cpp -o PouringWater.o   