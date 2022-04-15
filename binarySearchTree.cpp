#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
using namespace std;

typedef struct node {
	int key;
	double value;
	node* lchild;
	node * rchild;
}node;
node* make_bst(int n);
void insert(struct node** root, int k, double theItem);
struct node* search(struct node* root, int key);
struct node* iterSearch(struct node* tree, int k);
int get_node_count(struct node* ptr);
struct node* modified_search(struct node* root, int key);
void inorder(struct node* ptr);
int get_height_count(struct node* ptr);
int get_leaf_count(struct node* ptr);
int main() {
	
		printf("n을 입력하세요>>");
		int n;
		scanf_s("%d", &n);
		clock_t start, end;
		start = clock();
		node* tree = make_bst(n);
		inorder(tree);
		end = clock();
		printf("[time : %f]\n", (float)(end - start) / CLOCKS_PER_SEC);
		printf("노드수 : %d\n", get_node_count(tree));

		printf("높이 : %d\n", get_height_count(tree));
		printf("리프 노드 수 : %d\n", get_leaf_count(tree));

		cout << "종료하려면 -1을 입력하세요.";
		int temp;

		cin >> temp;
		if (temp == -1)
			exit(1);
	





}
void insert(struct node**root, int k, double theItem)
{
	struct node * ptr, *temp = modified_search(*root, k);
	if (temp || !(*root)) {
		ptr = (struct node*)malloc(sizeof(struct node));
		if (!ptr) {
			fprintf(stderr, "Insufficient memory");
			exit(1);
		}
		ptr->key = k;
		ptr->value = theItem;
		ptr->lchild = ptr->rchild = NULL;
		if (*root) {
			if (k < temp->key) { temp->lchild = ptr; }
			else { temp->rchild = ptr; }
		}
		else *root = ptr;
	}
}

struct node * search(struct node*root , int key) {
	if (!root) return NULL;
	if (key == root->key) return root;
	if (key < root->key)
		return search(root->lchild, key);
	return search(root->rchild, key);


}
struct node* iterSearch(struct node *tree, int k) {
	while (tree) {
		if (k == tree->key) return tree;
		if (k < tree->key)
			tree = tree->lchild;
		else
			tree = tree->rchild;
	}
	return NULL;

}
int get_node_count(struct node* ptr) {
	int count = 0;
	if (ptr != NULL)
		count = 1 + get_node_count(ptr->lchild) + get_node_count(ptr->rchild);
	return count;
}
int get_height_count(struct node* ptr) {
	int count = 0;
	if (ptr != NULL)
		if (get_height_count(ptr->lchild) > get_height_count(ptr->rchild))
			count = 1 + get_height_count(ptr->lchild);
		else
			count = 1 + get_height_count(ptr->rchild);
	return count;
}
struct node* modified_search(struct node* root, int key) {
	for (struct node* ptr = root; ptr != NULL;) {
		if (ptr->key == key)
			return NULL;
		if (key < ptr->key) {
			if (ptr->lchild == NULL)
				return ptr;
			else ptr = ptr->lchild;
		}
		else {
			if (ptr->rchild == NULL)
				return ptr;
			else ptr = ptr->rchild;
		}
	}
	return NULL;
}
void inorder(struct node* ptr)
{
	if (ptr) {
		inorder(ptr->lchild);
		printf("(%d, %f)", ptr->key,ptr->value);
		inorder(ptr->rchild);
	}
}
node* make_bst(int n) {
	int i = 0;
	node* tree = NULL;
	for (; i < n; i++) {
		insert(&tree, (rand() / (0x7fff * 1.0)) * 100000000, 1.0 / (rand() / (0x7fff * 1.0)) * 100000000);
	}
	return tree;
}
int get_leaf_count(struct node* ptr)
{
	int count = 0;
	if (ptr != NULL) {
		if (ptr->lchild == NULL &&
			ptr->rchild == NULL) // 단말 노드
			return 1;
		else count = get_leaf_count(ptr->lchild) +
			get_leaf_count(ptr->rchild);
	}
	return count;
}
