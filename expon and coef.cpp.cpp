#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define COMPARE(a, b) ((a>b)? 1 : (a==b) ? 0 : -1)
typedef struct tmp* polyPointer;
typedef struct tmp{

	float coef;
	int expon;
	polyPointer link;



}polyNode;

polyPointer avail = NULL;

polyPointer create_polynomial();
static int blank = 0;
polyPointer getNode(void);
void retNode(polyPointer node);
void cerase(polyPointer* ptr); 
polyPointer cpadd(polyPointer a, polyPointer b);
void attach(float coefficient, int exponent, polyPointer* c);
void print_polynomial(polyPointer x);
polyPointer singleMul(polyPointer a, polyPointer b);
polyPointer Mul(polyPointer a, polyPointer b);
int main() {
	polyPointer A = create_polynomial();
	polyPointer B = create_polynomial();
	polyPointer C = cpadd(A, B);
	print_polynomial(C);
	cout << endl;
	/*cout << "A는 단항으로 입력하시오(single Mul test)" << endl;
	 polyPointer D = singleMul(A->link, B);
	print_polynomial(D);
	cout << endl;*/
	cout << "Mul test" << endl;
	C=Mul(A, B);
	print_polynomial(C);











}
polyPointer getNode(void) {

	polyPointer node;
	if (avail) {
		node = avail;
		avail = avail->link;
	}
	else {
		node = (polyPointer)malloc(sizeof(polyNode));
		if (!node) {
			fprintf(stderr, "메모리가 충분하지 않습니다.");
			exit(1);
		}
	}

}
void retNode(polyPointer node) {
	node->link = avail;
	avail = node;


}
void cerase(polyPointer * ptr) {

	polyPointer temp;
	
	if (*ptr) {
		temp = (*ptr)->link;
		(*ptr)->link = avail;
		avail = temp;
		*ptr = NULL;
	}


}
polyPointer cpadd(polyPointer a, polyPointer b) {
	polyPointer startA, c, lastC;
	
	int sum; bool done = false;
	startA = a;
	a = a->link;
	b = b->link;
	c = getNode();
	c->expon = -1;
	lastC = c;
	do {
		switch (COMPARE(a->expon, b->expon)) {

		case -1://a->expon < b->expon
			attach(b->coef, b->expon, &lastC);
			b = b->link;
			break;
		case 0:
			if (startA == a) done = true;
			
			else {
				sum = a->coef + b->coef;
				if (sum) attach(sum, a->expon, &lastC);
				a = a->link; b = b->link;
			}
			break;
		case 1: // a->expon > b->expon
			attach(a->coef, a->expon, &lastC);
			a = a->link;


		}
	} while (!done);
	lastC->link = c;
	return c;
}
void attach(float coefficient, int exponent, polyPointer* c)
{
	// 다항식에 새로운 항을 추가하는 함수
	polyPointer temp = getNode();
	temp->coef = coefficient;
	temp->expon = exponent; 
	temp->link = (*c)->link;
	(*c)->link = temp;
	*c = temp;
}

polyPointer create_polynomial() {
	polyPointer A = (polyPointer)malloc(sizeof(polyNode));
	polyPointer rear = A;
	A->link = A;
	A->expon = -1;
	int coef = 0; int expon = 0;
	cout << "계수와 차수를 순차적으로 입력하고 입력완료시 -1 -1을 입력하시오." << endl;
	while(true){
		cin >> coef >> expon;
	if (coef == -1 && expon == -1)
		return A;
	else {

		attach(coef, expon, &rear);
	}
	
	}
	
	

}
void print_polynomial(polyPointer x) {
	polyPointer p = x->link;
	cout << p->coef << "a^" << p->expon;
	p = p->link;
	while (p->expon != -1)
	{
		cout << '+'<<p->coef << "a^" << p->expon ;
		p = p->link;
	}
	
	
	
}
polyPointer singleMul(polyPointer a, polyPointer b) {
	polyPointer A = (polyPointer)malloc(sizeof(polyNode));
	polyPointer rear = A;
	A->link = A;
	A->expon = -1;
	b = b->link;
	while (b->expon != -1) {
		
		attach((a->coef) * (b->coef), (a->expon) + (b->expon), &rear);
		b = b->link;
	}
	return A;



}
polyPointer Mul(polyPointer a, polyPointer b) {
	polyPointer A = (polyPointer)malloc(sizeof(polyNode));
	polyPointer rear = A;
	A->link = A;
	A->expon = -1;
	a = a->link;
	
	while (a->expon != -1) {
		A = cpadd(A,singleMul(a, b));
		a = a->link;

	}
	
	return A;


}