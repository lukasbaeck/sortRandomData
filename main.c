#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(){
    const char filename[] = "data.txt";
    int *numbarray;
    int length;



    WriteRandomData(filename);

    length=CalcDataLength(filename);
    numbarray=ReadData(filename, length);

    PrintData(numbarray, length);
    BubbleSort(numbarray, length);
    PrintData(numbarray, length);

    free(numbarray);
    return 0;
} //end Main
