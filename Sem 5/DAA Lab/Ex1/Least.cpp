//LCA - Least Common Ancestor in BST

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

int LCA(Node *t, int n1, int n2){
	if(t){
		if(n1 < t->val && n2 < t->val)
			return LCA(t->left, n1, n2);
		else if(n1 > t->val && n2 > t->val)
			return LCA(t->right, n1, n2);
		else
			return t->val;
	}
}

int main(){
	Node *root = NULL;
	int n, val, n1, n2;
	cout << "Enter n : ";
	cin >> n;
	for(int i = 0; i < n; i++){
		cout << "Enter Value : ";
		cin >> val;
		root = insertBST(root, val);
	}
	cout << "Enter n1 and n2 : ";
	cin >> n1 >> n2;
	cout << endl << "Least Common Ancestor : " << LCA(root, n1, n2);
	return 0;
}