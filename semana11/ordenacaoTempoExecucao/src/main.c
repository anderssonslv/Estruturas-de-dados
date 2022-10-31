#include <time.h>
#include "../lib/lib.h"
#include "../lib/sort.c"

void insertionSort(int array[], int n){ //Best n, Average/worst n²
    int i, element, j;//1
    for (i = 1; i < n; i++) {//O(n)
		element = array[i]; //1
		j = i - 1;//1
		while (j >= 0 && array[j] > element) {//O(m)*O(n)+2
            array[j + 1] = array[j]; //1
            j = j - 1; //1
        } 
        array[j + 1] = element; //1
    } 
} // Complexidade  = O(n)*O(m)+8 == O(n²)

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
}//BEST nlog(n) AVERAGE nlog(n) Worst n²

void Selectsort(int data[],int n) {//n²
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

void merge(int arr[], int l, int m, int r) {//nlogn
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

void randomizeAll (){
	randomize(V,SIZE/2);
	randomize(VV,SIZE);
	randomize(VVV,SIZE*5);
}

void testInsertion () {
	printf("\n INSERTION SORT");
	
	start = clock ();
	insertionSort(V,SIZE/2);
	end = clock();
	elapsed = ( end - start )/ CLOCKS_PER_SEC;

	if (check(V,SIZE/2))
		printf("\nTeste Curto [%d]: %.3f",SIZE/2,elapsed);

	start = clock();
	insertionSort(VV,SIZE);
	end = clock();
	elapsed = (end-start)/CLOCKS_PER_SEC;

	if (check(VV,SIZE))
		printf("\nTeste Medio [%d]: %.3f",SIZE,elapsed);

	start = clock();
	insertionSort(VVV,SIZE*5);
	end = clock();
	elapsed = (end-start)/CLOCKS_PER_SEC;

	if (check(VVV,SIZE))
		printf("\nTeste Longo [%d]: %.3f",SIZE*5,elapsed);

	printf("\n\n");
	printa(V,10);
	printf("\n");
	printa(VV,10);
	printf("\n");
	printa(VVV,10);
	printf("\n");
}

void testQuick () {
	randomizeAll();
	printf("\n QUICK SORT");
	
	start = clock ();
	Quicksort(V,0,SIZE/2);
	end = clock();
	elapsed = ( end - start )/ CLOCKS_PER_SEC;

	if (check(V,SIZE/2))
		printf("\nTeste Curto [%d]: %.3f",SIZE/2,elapsed);

	start = clock();
	Quicksort(VV,0,SIZE);
	end = clock();
	elapsed = (end-start)/CLOCKS_PER_SEC;

	if (check(VV,SIZE))
		printf("\nTeste Medio [%d]: %.3f",SIZE,elapsed);

	start = clock();
	Quicksort(VVV,0,SIZE*5);
	end = clock();
	elapsed = (end-start)/CLOCKS_PER_SEC;

	if (check(VVV,SIZE))
		printf("\nTeste Longo [%d]: %.3f",SIZE*5,elapsed);

	printf("\n\n");
	printa(V,10);
	printf("\n");
	printa(VV,10);
	printf("\n");
	printa(VVV,10);
	printf("\n");
}

void testSelect () {
	randomizeAll();
	printf("\n SELECT SORT");
	
	start = clock ();
	Selectsort(V,SIZE/2);
	end = clock();
	elapsed = ( end - start )/ CLOCKS_PER_SEC;

	if (check(V,SIZE/2))
		printf("\nTeste Curto [%d]: %.3f",SIZE/2,elapsed);

	start = clock();
	Selectsort(VV,SIZE);
	end = clock();
	elapsed = (end-start)/CLOCKS_PER_SEC;

	if (check(VV,SIZE))
		printf("\nTeste Medio [%d]: %.3f",SIZE,elapsed);

	start = clock();
	Selectsort(VVV,SIZE*5);
	end = clock();
	elapsed = (end-start)/CLOCKS_PER_SEC;

	if (check(VVV,SIZE))
		printf("\nTeste Longo [%d]: %.3f",SIZE*5,elapsed);

	printf("\n\n");
	printa(V,10);
	printf("\n");
	printa(VV,10);
	printf("\n");
	printa(VVV,10);
	printf("\n");
}

void testMerge () {
	randomizeAll();
	printf("\n MERGE SORT");
	
	start = clock ();
	mergeSort(V,0,SIZE/2);
	end = clock();
	elapsed = ( end - start )/ CLOCKS_PER_SEC;

	if (check(V,SIZE/2))
		printf("\nTeste Curto [%d]: %.3f",SIZE/2,elapsed);

	start = clock();
	mergeSort(VV,0,SIZE);
	end = clock();
	elapsed = (end-start)/CLOCKS_PER_SEC;

	if (check(VV,SIZE))
		printf("\nTeste Medio [%d]: %.3f",SIZE,elapsed);

	start = clock();
	mergeSort(VVV,0,SIZE*5);
	end = clock();
	elapsed = (end-start)/CLOCKS_PER_SEC;

	if (check(VVV,SIZE))
		printf("\nTeste Longo [%d]: %.3f",SIZE*5,elapsed);

	printf("\n\n");
	printa(V,10);
	printf("\n");
	printa(VV,10);
	printf("\n");
	printa(VVV,10);
	printf("\n");
}

int main () {
	srand(time(NULL));
	V = malloc ((SIZE/2) * sizeof(int));
    VV = malloc (SIZE * sizeof(int));
    VVV = malloc ((SIZE*5) * sizeof (int));

	int b [5] = {2,4,1,3,5};

	clock_t start, end, elapsed;

	start = clock();

	int i=0;
	for (i = 0; i < 1000*1000*1000; i++){
		end = clock();
		elapsed = (end - start) / CLOCKS_PER_SEC;
		if (elapsed == 1)
			break;
	}
	printf("%d",i);
	

	//insertionSort(b,5);
	
	//testInsertion();
	//testQuick();
	//testSelect();
	//testMerge();

	system("pause");
}


/*
	randomize(vet,n);
	printf("\nNovos valores fora de ordem");
	printa(vet,n);


	mergeSort(vet,0,n);
	if (!check(vet,n))
		printf("\nErro de ordenação!");
	else printa(vet,n);


	randomize(vet,n);

	Quicksort(vet,0,n);
	if (!check(vet,n))
		printf("\nErro de ordenação!");
	else printa(vet,n);

	randomize(vet,n);

	Selectsort(vet,n);
	if (!check(vet,n))
		printf("\nErro de ordenação!");
	else printa(vet,n);
*/




/*

	if (!check(V,SIZE/2) || !check(VV,SIZE) || !check(VVV,SIZE*5))
		printf("\nErro de ordenação!");
	else {
		printf("\nINSERTION SORT\n");
		printf("\nTeste Curto [25K]: %.3f",elapsed1);
		printf("\nTeste Médio [50K]: %.3f",elapsed2);
		printf("\nTeste Longo [100K]: %.3f \n",elapsed3);
	}

	printf("\n");
	printa(V,10);
	printf("\n");
	printa(VV,10);
	printf("\n");
	printa(VVV,10);
	printf("\n");



	randomize(V,SIZE/2);
	start1 = clock();
	mergeSort(V,0,SIZE/2);
	end1 = clock();
	elapsed1 = (end1-start1)/CLOCKS_PER_SEC;

	randomize(VV,SIZE);
	start2 = clock();
	mergeSort(VV,0,SIZE);
	end2 = clock();
	elapsed2 = (end2-start2)/CLOCKS_PER_SEC;

	randomize(VVV,SIZE*5);
	start3 = clock();
	mergeSort(VVV,0,SIZE*5);
	end3 = clock();
	elapsed3 = (end3-start3)/CLOCKS_PER_SEC;

	if (!check(V,SIZE/2) || !check(VV,SIZE) || !check(VVV,SIZE*5))
		printf("\nErro de ordenação!");
	else {
		printf("\nMERGE SORT\n");
		printf("\nTeste Curto [25K]: %.3f",elapsed1);
		printf("\nTeste Médio [50K]: %.3f",elapsed2);
		printf("\nTeste Longo [100K]: %.3f \n",elapsed3);
	}

	printf("\n");
	printa(V,10);
	printf("\n");
	printa(VV,10);
	printf("\n");
	printa(VVV,10);
	printf("\n");





	randomize(V,SIZE/2);
	start1 = clock();
	Quicksort(V,0,SIZE/2);
	end1 = clock();
	elapsed1 = (end1-start1)/CLOCKS_PER_SEC;

	randomize(VV,SIZE);
	start2 = clock();
	Quicksort(VV,0,SIZE);
	end2 = clock();
	elapsed2 = (end2-start2)/CLOCKS_PER_SEC;

	randomize(VVV,SIZE*5);
	start3 = clock();
	Quicksort(VVV,0,SIZE*5);
	end3 = clock();
	elapsed3 = (end3-start3)/CLOCKS_PER_SEC;

	if (!check(V,SIZE/2) || !check(VV,SIZE) || !check(VVV,SIZE*5))
		printf("\nErro de ordenação!");
	else {
		printf("\nQUICK SORT\n");
		printf("\nTeste Curto [25K]: %.3f",elapsed1);
		printf("\nTeste Médio [50K]: %.3f",elapsed2);
		printf("\nTeste Longo [100K]: %.3f \n",elapsed3);
	}
	printf("\n");
	printa(V,10);
	printf("\n");
	printa(VV,10);
	printf("\n");
	printa(VVV,10);
	printf("\n");




	randomize(V,SIZE/2);
	start1 = clock();
	Selectsort(V,SIZE/2);
	end1 = clock();
	elapsed1 = (end1-start1)/CLOCKS_PER_SEC;

	randomize(VV,SIZE);
	start2 = clock();
	Selectsort(VV,SIZE);
	end2 = clock();
	elapsed2 = (end2-start2)/CLOCKS_PER_SEC;

	randomize(VVV,SIZE*5);
	start3 = clock();
	Selectsort(VVV,SIZE*5);
	end3 = clock();
	elapsed3 = (end3-start3)/CLOCKS_PER_SEC;

	if (!check(V,SIZE/2) || !check(VV,SIZE) || !check(VVV,SIZE*5))
		printf("\nErro de ordenação!");
	else {
		printf("\nSELECT SORT\n");
		printf("\nTeste Curto [25K]: %.3f",elapsed1);
		printf("\nTeste Médio [50K]: %.3f",elapsed2);
		printf("\nTeste Longo [100K]: %.3f \n",elapsed3);
	}

	printf("\n");
	printa(V,10);
	printf("\n");
	printa(VV,10);
	printf("\n");
	printa(VVV,10);
	printf("\n");


*/