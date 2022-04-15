#include <iostream>
#define COMPARE(x,y) (((x)<(y)) ? -1 : ((x)==(y))? 0 : 1 )
using namespace std; 
int counter = 0;
int main() {
	
	int binsearch(int list[], int searchnum, int left, int right);
	int a[100000];
	int b[50000];
	for (int i = 0; i < 100000; i++)
		 a[i] = i;
	for (int i = 0; i < 50000; i++)
		b[i] = i;

	binsearch(a, 1, 0, 99999);
	cout << counter << endl;
	 counter = 0;
	binsearch(a, 10, 0, 99999);
	cout << counter << endl;
	 counter = 0;
	binsearch(a, 100, 0, 99999);
	cout << counter << endl;
	 counter = 0;
	binsearch(a, 1000, 0, 99999);
	cout << counter << endl;
	 counter = 0;
	binsearch(a, 10000, 0, 99999);
	cout << counter << endl;
	 counter = 0;
	binsearch(a, 12500, 0, 99999);
	cout << counter << endl;
	 counter = 0;
	binsearch(a, 50000, 0, 99999);
	cout << counter << endl;
	 counter = 0;
	binsearch(a, 53125, 0, 99999);
	cout << counter << endl;
	 counter = 0;
	binsearch(a, 75000, 0, 99999);
	cout << counter << endl;
	 counter = 0;
	binsearch(a, 75195, 0, 99999);
	cout << counter << endl;
	 counter = 0;
	binsearch(a, 100000, 0, 99999);
	cout << counter << endl;
	binsearch(b, 5, 0, 49999);
	cout << counter<<' ';
	counter = 0;
	binsearch(b, 50, 0, 49999);
	cout << counter << ' ';
	counter = 0;
	binsearch(b, 195, 0, 49999);
	cout << counter << ' ';
	counter = 0;
	binsearch(b, 500, 0, 49999);
	cout << counter << ' ';
	counter = 0;
	binsearch(b, 781, 0, 49999);
	cout << counter << ' ';
	counter = 0;
	binsearch(b, 5000, 0, 49999);
	cout << counter << ' ';
	counter = 0;
	binsearch(b, 12548, 0, 49999);
	cout << counter << ' ';
	counter = 0;
	binsearch(b, 25012, 0, 49999);
	cout << counter << ' ';
	counter = 0;
	binsearch(b, 28125, 0, 49999);
	cout << counter << ' ';
	counter = 0;
	binsearch(b, 37500, 0, 49999);
	cout << counter << ' ';
	counter = 0;
	binsearch(b, 50000, 0, 49999);
	cout << counter << ' ';
	
	}

int binsearch(int list[], int searchnum, int left, int right)
{ /* search list[0] <= list[1] <= ... <= list[n-1] for searchnum.
	 Return its postion if found. Otherwise return -1 */
	int middle;


	while (left <= right) {
		middle = (left + right) / 2;
		switch (COMPARE(list[middle], searchnum))
		{
		case -1: left = middle + 1;
			break;
		case  0: return middle;
		case  1: right = middle - 1;
		}
		counter++;
	}
	return -1;
}






