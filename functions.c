#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

#define RANDOM_DATA_LENGTH 10000


void BubbleSort(int *array, int lenght){
    clock_t t;
    int i,j;

    t=clock();
    for(j=lenght-1; j>0; j=j-1){
        for(i=0; i<j; i=i+1){
            if(array[i] > array[i+1]){
                SwapArrayElement(array, i, i+1);
            }
        }
    }
    t=clock()-t;
    printf("BubbleSort clocks:%ld time: %f\n", t, ((float)t)/CLOCKS_PER_SEC);
} // end BubbleSort

void SwapArrayElement(int *array, int index1, int index2){
    int h;

    h=array[index1];
    array[index1] = array[index2];
    array[index2] = h;
} // end SwapArrayElement

int Position (int *array, int l, int r){
    int value, j, i;
    value = array[r];
    i=l;
    j=r-1;

    while(1){
        while(array[i] < value) //Suche von links, größer gleich Pivot
            i=i+1;
        while((array[j]>value) && (j>0)) //Suche von rechts, kleiner Pivot
            j=j-1;
        if(j <= i)
            break;
        SwapArrayElement(array, i,j); //Tausche in jeweils richtige Teilliste
        i=i+1;
        j=j-1;
    }
    SwapArrayElement(array, i,r); //Tausche Pivot mit entgültiger Position
    return i;
} // end Position


void QuickSort(int *array, int l, int r){
    if(r>l){
        long pos;
        pos = Position(array, l, r);
        QuickSort(array, l, pos-1);
        QuickSort(array, pos+1, r);
    }
} //end QuickSort

void QuickSortTime(int *array, int l, int r){
    clock_t t;

    t=clock();
    QuickSort(array,l,r);
    t=clock()-t;
    printf("QuickSort Clocks:%ld time: %f\n", t, ((float)t)/CLOCKS_PER_SEC);
} // end QuickSortTime


long CalcDataLength (const char filename[]){
    FILE *data;
    long length=0;

     if((data = fopen(filename, "r"))){
        while((fscanf(data, "%*d")) != EOF)
                length++;
        fclose(data);
    }
    else{
      printf("ERROR: opening data @CalcDataLength");
      return 0;
    }
    return length;
} // end CalcDataLength


void WriteRandomData(const char filename[]){
    FILE *data;
    int length = RANDOM_DATA_LENGTH;
    int i;
    time_t t;

    srand((unsigned) time(&t));

    if((data = fopen(filename, "w"))){
        for(i=0; i<length;i++){
            fprintf(data,"%d\n", (int)rand()%1000);
        }
        fclose(data);
    }
    else{
        printf("ERROR: opening Data @WriteRandomData\n");
    }
} //end WriteRandomData


int* ReadData(const char filename[], int length){
    FILE *data;
    int *numbarray;

    if((data = fopen(filename, "r"))){
        if((numbarray = malloc(length *sizeof(int))) != 0){
            int i=0;
            while((fscanf(data, "%d", &numbarray[i])) != EOF){
                i++;
            }
        }
        else{
            printf("ERROR: memory allocation @ReadData\n");
            return 0;
        }
    }
    else{
        printf("ERROR: opening data @ReadData\n");
        return 0;
    }
    return numbarray;
} // end DataRead


int *ReadData2(const char filename[]){
    FILE *data;
    int *numbarray;
    int i= 0;
    int j= 2;

    if((numbarray = malloc(sizeof(int))) != 0){
        if((data = fopen(filename, "r"))){
            while((fscanf(data, "%d", &numbarray[i])) != EOF){
                if((numbarray = realloc(numbarray, j*sizeof(int))) != 0){
                    i++;
                    j++;
                }
                else{
                    printf("ERROR: memory allocation realloc @ReadData2\n");
                    return 0;
                }
            }
        }
        else{
            printf("ERROR: opening data @ReadData2\n");
            return 0;
        }
    }
    else{
       printf("ERROR: memory allocation malloc @ReadData2\n");
       return 0;
    }
    return numbarray;
} //end ReadData2

void PrintData(int* numbarray, int length){

    for(int i=0; i<length; i++)
        printf("%d\n", numbarray[i]);
} //end PrintData
