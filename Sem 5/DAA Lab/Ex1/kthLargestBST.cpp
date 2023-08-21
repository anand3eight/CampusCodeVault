//Kth Largest Element in BST

#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct Node Node;
struct Node{
	int val;
	Node *left, *right;
};

Node *createNode(int val){
	Node *t = (Node*)malloc(sizeof(Node));
	t->val = val;
	t->left = t->right = NULL;
	return t;
}

Node* insertBST(Node *t, int val){
	if(!t){
		t = createNode(val);
		return t;
	}
	else{
		if(val < t->val)
			t->left = insertBST(t->left, val);
		else if(val > t->val)
			t->right = insertBST(t->right, val);
	}
	return t;
}

void kthLargest(Node *t, int *k){
	if(t){
		kthLargest(t->right, k);
		*k -= 1;
		if(*k == 0){
			cout << t->val << endl;
			return;
		}
		if(*k > 0)
			kthLargest(t->left, k);
	}
	
}

int main(){
	Node *root = NULL;
	int n, val;
	cout << "Enter n : ";
	cin >> n;
	for(int i = 0; i < n; i++){
		cout << "Enter Value : ";
		cin >> val;
		root = insertBST(root, val);
	}
	cout << "Enter k : ";
	cin >> val;
	cout << endl << "Kth Largest Element : ";
	kthLargest(root, &val);
	return 0;
}