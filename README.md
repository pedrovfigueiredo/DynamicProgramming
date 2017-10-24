# DynamicProgramming
Repository for allocating algorithms solved using dynamic programming for the Analysis and Project of Algorithms course at Federal University of Paraiba.

## Implemented Algorithms
* Knapsack Problem (output consists of solution value and chosen objects)
* Travelling Salesman Problem (output consists of optimal cost and path)

## Compiling and Running:

To compile, just run the command:

* For the Knapsack Problem:

```bash
cd Knapsack
make
```

To run the executable:

```bash
./knapsack PATH_TO_INPUT_FILE.txt
```

* For the Travelling Salesman Problem:

```bash
cd TravellingSalesman
make
```

To run the executable:

```bash
./travellingsalesman PATH_TO_INPUT_FILE.txt
```


## Example of output:

* For the Knapsack Problem:

```bash
./knapsack Instances/mochila01.txt
```

    Solution Value: 107
    Solution Objects: 1, 2, 6, 7

* For the Travelling Salesman Problem:

```bash
./travellingsalesman Instances/pcv10.txt
```

    Solution:
    Cost: 12605
    Path: 1 2 3 4 5 6 7 9 10 8 1
    Elapsed time: 5 ms
