#ifndef _LIB_H
#define _LIB_H

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define SIZE 100000

clock_t start,end;
double elapsed;
int *V,*VV,*VVV;

void insertionSort(int vet[],int t);
void Quicksort(int data[],int left,int right);
void Selectsort(int data[],int n);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);

#endif