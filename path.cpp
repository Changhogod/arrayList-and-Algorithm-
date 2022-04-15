#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std; 
int n;
int m;
void shortestPath(int v, int** cost, int distance[], int n, short int found[]);
int choose(int distance[], int n, short int found[]);
void allCosts(int** cost, int** distance, int n);
int main() {
	int from, to, w;
	cout << "노드 수 : " << endl;
	cin >> n;

	int** G;
	G = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		G[i] = (int*)malloc(sizeof(int) * n);
	}
	int** distance;
	distance = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		distance[i] = (int*)malloc(sizeof(int) * n);
	}
	short int* found = (short int*)malloc(sizeof(short int) * n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			G[i][j] = 1000;
		}
	}
	int** A;
	A = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		A[i] = (int*)malloc(sizeof(int) * n);
	}
	
	while (true) {
	cout << "시작 정점, 종료 정점, 가중치값을 순차적으로 입력하시오." << endl;
	cin >> from >> to >> w;
	G[from][to] = w;
	cout << "입력을 종료하려면 -1을 입력하시오." << endl;
	cin >> m;
	if (m == -1) break;
}
	shortestPath(4, G, distance[0], n, found);
	for (int i = 0; i < n; i++)
		cout << distance[0][i]<<"  ";

	cout << "allcosts Test!" << endl;
	cout << "노드 수 : " << endl;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = 1000;
		}
	}
	for (int i = 0; i < n; i++) {
		A[i][i] = 0;
	}
	while (true) {
		cout << "시작 정점, 종료 정점, 가중치값을 순차적으로 입력하시오." << endl;
		cin >> from >> to >> w;
		A[from][to] = w;
		cout << "입력을 종료하려면 -1을 입력하시오." << endl;
		cin >> m;
		if (m == -1) break;
	}
	allCosts(A, distance, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			cout << distance[i][j] << " ";
		}
		cout << endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	for (int i = 0; i < n; i++) {
		free(G[i]);
	}
	free(G);
	for (int i = 0; i < n; i++) {
		free(distance[i]);
	}
	free(distance);
	free(found);





}
void shortestPath(int v, int **cost, int distance[], int n, short int found[]) {
	int i, u, w;
	for (i = 0; i < n; i++) {
		found[i] = false;
		distance[i] = cost[v][i];
	}
	found[v] = true;
		distance[v] = 0;
		for (i = 0; i < n - 2; i++) {
			u = choose(distance, n, found);
			found[u] = true;
			for (w = 0; w < n; w++) {
				if (!found[w])
					if (distance[u] + cost[u][w] < distance[w])
						distance[w] = distance[u] + cost[u][w];
			}
		}
	}


int choose(int distance[], int n, short int found[]) {
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for(i = 0;i<n; i++)
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}

void allCosts(int **cost, int **distance, int n) {

	int i, j, k;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) 
			distance[i][j] = cost[i][j];
	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (distance[i][k] + distance[k][j] < distance[i][j])
					distance[i][j] = distance[i][k] + distance[k][j];





}