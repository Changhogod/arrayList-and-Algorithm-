#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define MAX_SIZE 100000
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
void sort(int[], int); /*selection sort*/
void main(void)
{

	//int i, n;

	//int A[MAX_SIZE];
	//for (int i = 0; i < 100000; i++) {
	//	A[i] = rand() % 100000;
	//}
	//printf("Enter the number of numbers to generate: ");
	//scanf("%d", &n);
	//if (n < 1 || n > MAX_SIZE) {
	//	fprintf(stderr, "Improper value of n\n");
	//	exit(EXIT_FAILURE);
	//}
	//for (i = 0; i < n; i++) {/*randomly generate numbers*/
	//	A[i] = rand() % 1000;
	//	printf("%d ", A[i]);
	//}
	//sort(A, n);
	//printf("\n Soretd array:\n ");
	//for (i = 0; i < n; i++) /* print out sorted numbers */
	//	printf("%d  ", A[i]);
	//printf("\n");
	int i, n, step = 10;;
	int a[MAX_SIZE];
	double duration;
	clock_t start;

	/* times for n = 0, 10, ..., 100, 200, ..., 1000 */
	printf("      n      time\n");
	for (n = 0; n <= 100000; n += step)
	{  /* get time for size n */
		/* initialize with worst-case data */
		for (i = 0; i < n; i++)
			a[i] = n - 1;

		start = clock();
		sort(a, n);
		duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;
		printf("%6d    %f\n", n, duration);
		if (n == 100) step = 900;
		if (n == 1000) step = 1000;
		if (n == 10000) step = 10000;
	}
}
void sort(int A[], int n)
{
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (A[j] < A[min])
				min = j;
		SWAP(A[i], A[min], temp);
	}
}
