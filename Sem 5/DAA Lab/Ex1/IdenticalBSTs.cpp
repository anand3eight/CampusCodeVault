//Identical BST

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

bool identicalBSTs(Node *n1, Node *n2){
	if(n1 && n2 && n1->val == n2->val)
		return identicalBSTs(n1->left, n2->left) && identicalBSTs(n1->right, n2->right);
	if(!n1 && !n2)
		return true;
	return false;
	
}
int main(){
	Node *root1 = NULL, *root2 = NULL;
	int n, val, n1, n2;
	cout << "Enter n for Tree 1 : ";
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> val;
		root1 = insertBST(root1, val);
	}
	cout << "Enter n for Tree 2 : ";
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> val;
		root2 = insertBST(root2, val);
	}
	if(identicalBSTs(root1, root2))
		cout << "True";
	else
		cout << "False";
	return 0;
}