# Karatsuba Multiplication in C
This repository contains an implementation of the Karatsuba multiplication algorithm in C.

## Introduction
It is a divide-and-conquer algorithm that reduces the multiplication of two n-digit numbers to three multiplications of n/2-digit numbers and, by repeating this reduction, to at most {\displaystyle n^{\log _{2}3}\approx n^{1.58}} single-digit multiplications. It is therefore asymptotically faster than the traditional algorithm, which performs {\displaystyle n^{2}} single-digit products. 
The Karatsuba algorithm is a fast multiplication algorithm that uses a divide-and-conquer approach to multiply two numbers. It is more efficient than the traditional O(n^2) algorithm for large numbers.

## Files

- `add&sub.h`: Header file for addition and subtraction of two integers.
- `karatsuba.h`: Header file for the Karatsuba algorithm.
- `readfile.h`: Header file to read two integers stored in a file.
- `main.c`: Example usage of the Karatsuba algorithm.
- `input.txt`: A sample input for the Karatsuba algorithm.

## Compilation

To compile the example:
gcc -o main.c main
./main
