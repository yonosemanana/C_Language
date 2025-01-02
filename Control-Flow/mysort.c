#define MAXLEN	1000

/* Sort array of integers in place, in ascending order. */
void mysort(int v[], int n) {

        int sorted[MAXLEN];
        int temp;

        int l = 0; // length of sorted array
        for (int i = 0; i < n; ++i) {
                sorted[l] = v[i];
                for (int j = l; j > 0; --j) /* insert v[i] to sorted array */
                        if(sorted[j] < sorted[j-1]) {
                                temp = sorted[j];
                                sorted[j] = sorted[j-1];
                                sorted[j-1] = temp;
                }
                ++l;

        }

        for (int i = 0; i < n; ++i)
                v[i] = sorted[i];
}

/* Sort array of integers in place, in ascending order. 
 * Improved version with less memory usage and without
 * unnecessary operations. */
void mysort2(int v[], int n) {

        int tmp;

        for (int i = 1; i < n; ++i) 
                for (int j = i; j >= 1 && (v[j] < v[j-1]); --j) {
                                tmp = v[j];
                                v[j] = v[j-1];
                                v[j-1] = tmp;
                }
}


