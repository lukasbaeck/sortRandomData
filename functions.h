#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void WriteRandomData(const char filename[]);
int *ReadData(const char filename[], int length);
int *ReadData2(const char filename[]);
long CalcDataLength (const char filename[]);
void PrintData(int* numbarray, int length);

void BubbleSort(int *array, int lenght);
void SwapArrayElement(int *array, int index1, int index2);
void QuickSort(int *array, int l, int r);
int Position (int *array, int l, int r);



#endif // FUNCTIONS_H_INCLUDED
