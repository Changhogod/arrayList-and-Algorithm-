#include <iostream>
#include <stdio.h>
#include <time.h>
#define SWAP(x, y, tmp) ((tmp)=(x),(x)=(y),(y)=(tmp) )
void perm(char* list, int i, int n) {
	int j;
	char tmp;

	if (i == n) {
		for (j = 0; j <= n; j++) {
			//printf("%c", list[j]);
		}
		//printf("\n");
	}
	else {
		for (j = i; j <= n; j++) {
			SWAP(list[i], list[j], tmp);
			perm(list, i + 1, n);
			SWAP(list[i], list[j], tmp);
		}
	}
}// 순열을 출력하는 재귀함수




int main() {
	char A[] = "abcdefghijklmno";
	double duration;
	clock_t start, stop;
	start = clock();
	stop = clock();
	duration = ((double)(stop - start))/CLOCKS_PER_SEC;
	printf("% .2f\n", duration);
	for (int n = 4; n <= 12; n++) {
		start = clock();
		perm(A, 0, n);
		stop=clock();
		duration = ((double)(stop - start)) / CLOCKS_PER_SEC;
		printf("% .2f\n", duration);

	}









}