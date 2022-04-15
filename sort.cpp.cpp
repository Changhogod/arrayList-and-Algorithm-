#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define SWAP(a, b, temp) ((temp)= (a),((a) = (b)), (b)= (temp)) 
using namespace std;
void sort(int list[], int n);
void insertSort(int list[], int n);
void quicksort(int list[], int left, int right);
void descSorted(int a[], int n);
void isSorted(int a[], int n);
int main() {
    int n = 0;
    cout << "원소수를 입력하시오.>>";
    cin >> n;
    int* A = new int[n];
    int* B = new int[n];

    clock_t start, end;

    for (int i = 0; i < n; i++) {
        A[i] = (rand() / (0x7fff * 1.0)) * 100000000;
    }
    for (int i = 0; i < n; i++) {
        B[i] = A[i];
    }
    quicksort(A, 0, n);
    descSorted(A, n);

    start = clock();

    quicksort(A, 0, n);
    end = clock();

    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    cout << duration << " Sec";
    isSorted(A, n);
    












}
void sort(int list[], int n) {

    int i, j, min, temp;

    for (i = 0; i < n - 1; i++) {
        min = i;

        for (j = i + 1; j < n; j++) {
            if (list[j] < list[min])
                min = j;
            
        }
        SWAP(list[i], list[min], temp);
    }
}

void insertSort(int list[], int n) {

    int i, j, next;
    for (i = 1; i < n; i++) {
        next = list[i];

        for (j = i - 1; j >= 0 && next < list[j]; j--) {
            list[j + 1] = list[j];

        }
        list[j + 1] = next;
    }

}

void quicksort(int list[], int left, int right) {

    int pivot, i, j;
    int temp;

    if (left < right) {
        i = left;
        j = right + 1;
        pivot = list[left];
        do {
            do i++;
            while (list[i] <= pivot&&i<=right);
            do j--;
            while (list[j] > pivot);
            if (i < j)
                SWAP(list[i], list[j], temp);
        } while (i < j);
        SWAP(list[left], list[j], temp);
        quicksort(list, left, j - 1);
        quicksort(list, j + 1, right);

    }
}

void isSorted(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1])
        {
            cout << "is not Sorted" << endl;
            return;
        }

    }
    cout << "isSorted" << endl;


}

void descSorted(int a[], int n) {
    for (int i = n - 1, j = 0; i > j; i--, j++)
    {
        int temp;
        SWAP(a[i], a[j], temp);
    }
}