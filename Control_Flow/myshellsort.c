
void myshellsort(int v[], int n) {
	int tmp;

	for (int d = n / 2; d > 0; d /= 2) 
		for (int i = d; i < n; ++i)
			for (int j = i; j >= d && (v[j] < v[j-d]); j = j-d) {
				tmp = v[j];	
				v[j] = v[j-d];
				v[j-d] = tmp;				

				/* Debugging code
				printf("d = %d, i = %d, j = %d\n", d, i, j);
				for (int z = 0; z < n; ++z)
					printf("%d ", v[z]);
				printf("\n"); */
			}
}


