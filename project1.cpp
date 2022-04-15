#include<iostream>
using namespace std;
#define MAX_ELEMENTS 100
int scores[MAX_ELEMENTS];
int get_max_score(int n) {
	int i, largest;
	largest = scores[0];
		for (int i = 1; i < n; i++) {
			if (scores[i] > largest)
				largest = scores[i];
		}
		return largest;
}
int main() {
	int scores[MAX_ELEMENTS] = { 100, 17, 24, 201, 400 };
	cout << scores[0];


}