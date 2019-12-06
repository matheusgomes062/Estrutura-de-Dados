int swap(int *A, int i, int j){
	int aux;
	aux = A[i];
	A[i] = A[j];
	A[j] = aux;
	return 1;
}

int heapify(int *A, int i, int n){
	int max = i;
	if(2*i+1 <= n && A[2*i+1] > A[i])
		max = 2*i+1;
	if(2*i+2 <= n && A[2*i+2] > A[max])
		max = 2*i+2;
	if(max != i){
		swap(A, i, max);
		heapify(A, max, n);
	}
	return 1;
}

int build_heap(int *A, int n){
	int i;
	for(i = (n-1)/2; i >= 0; i--){
		heapify(A,i,n-1);
	}
	return 1;
}

int heapSort(int *A, int n){
	int tam = n-1;
	build_heap(A, n);
	int i;
	for(i = n-1; i > 0; i--){
		swap(A, 0, i);
		heapify(A, 0, i-1);
	}
	return 1;
}

int main(){
	int n;
	scanf("%d",&n);
	int *A = (int*) malloc (n*sizeof(int));

	int i;
	for(i = 0; i < n; i++){
		scanf("%d",&A[i]);
	}

	heapSort(A, n);

	for(int i = 0; i < n; i++){
		printf("%d - ",A[i]);
	}

	return 0;
}
