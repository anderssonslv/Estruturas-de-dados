#include <stdio.h>

int quick (int data [], int L, int R) {
	int temp, i = L, j = R, mid = data [(L+R)/2];

	while (i <= j){
		while (data[i] < mid) i++;
		while (mid < data[j]) j--;
		
		if (i<=j) {
			swap(&data[i],&data[j]);
			i++; j--;
		}
	}	
	if (L < j)
		quick(data,L,j);
	if (i < R)
		quick (data,i,R);
}

int swap (int **a, int **b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int printVet (int data[],int n){
	for (int i = 0; i < n; i++)
		printf(" %d ",data[i]);
}

int main() {
	int vet [10] = {5,6,8,2,1,9,7,3,4};

	quick (vet,0,10);

	printVet(vet,10);
}