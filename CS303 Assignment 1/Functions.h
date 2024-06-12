#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void readFile(int digits[]);
//PRE: digits is an array of integers
//POST: reads the file "A1input.txt" and stores the integers in the array digits

int digitSearch(int num, int digits[], int arraySize);
//PRE: num is a positive integer, digits is a positive integer
//POST: performs a linear search and returns the digit at the position specified by digits, -1 if it doesn't exist

void modifyIndex(int digits[], int arraySize, int i, int newValue);
//PRE: digits is an array of integers, arraySize is the size of the array, i is the index to modify
//POST: modifies the array at index, if it exists. Outputs new and old values

void addToEnd(int digits[], int &arraySize, int newValue);
//PRE: digits is an array of integers, arraySize is the current size of the array, newValue is the value to add
//POST: adds newValue to the end of the array

void setIndexToZero(int digits[], int &arraySize, int i);
//PRE: digits is an array of integers, arraySize is the current size of the array, i is the index to remove
//POST: sets value of index to 0, if it exists

void printArray(int digits[], int arraySize);
//PRE: digits is an array of integers, arraySize is the current size of the array
//POST: prints the array to the console
