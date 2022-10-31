#include "lib.h"
/*
void insertionSort(int vet[],int t) {
	int chave,i;
	for (int z = 1; z < t ; z++ ){
		chave = vet[z];
		i=z-1;
		while (vet[i] > chave) {
			vet[i+1] = vet [i];
			i=i-1;
		}
		vet[i+1]=chave;
	}
}

void Quicksort(int data[],int left,int right) {
	int mid,tmp,i,j; 
	i = left; 
	j = right; 
	mid = data[(left+ right)/2]; 
	do { 
		while(data[i] < mid)
			i++; 
		while(mid< data[j]) 
			j--;
		if(i <= j) {
			tmp= data[i];
			data[i] = data[j];
			data[j] = tmp; i++;
			j--;
		}
	} while(i <= j); if(left< j) 
		Quicksort(data,left,j); 
	if(i < right) 
		Quicksort(data,i,right); 
}

void Selectsort(int data[],int n) {
	int min,tmp,i,j,min_id; 
	
	for(i=0; i<n-1; i++) { 
		min = data[i];
		for(j=i+1; j<n; j++) 
			if(data[j] < min) { 
				min = data[j];
				min_id= j;
			} 
		tmp= data[i];
		data[i] = data[min_id];
		data[min_id] = tmp;
		min_id= i+1;
	} 
}

void merge(int arr[], int l, int m, int r) {

	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];//Vetores estaticos, estouram apos numero muito grande

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];
	
	i = 0;
	j = 0;
	k = l;
	
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}

}

void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		int m = l+(r-l)/2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		merge(arr, l, m, r);
	}
}


//EXTRAS

int check(int vet[],int n){
	for (int i = 1; i < n; i++) {
		if (vet[i-1]>vet[i])
			return FALSE;
	}
	return TRUE;
}

void printa(int vet[],int n){
	for (int i = 1; i < n; i++) {//Sujeira pro tapete nesse 1
		printf("%d ",vet[i]);
	}
}

void randomize (int vet[],int n) {
	for (int i = 0; i < n; i++) {
		vet[i] = rand() % 10000000000000;
	}
}

*/