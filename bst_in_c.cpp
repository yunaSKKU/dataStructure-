#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int element;
	struct Node *left;
	struct Node *right;
}Node;

struct Node *root=NULL; //initialization

Node* insertion(Node *root,int value){
	//case1: root==NULL
	//case 2&3: determine which direction to go depending on
	//the value of root. recursively implement
	if (root==NULL){
		root=(Node *)malloc(sizeof(Node));
		//same as Node(value) in python. but consider memory allocation 
		root->element=value;
		root->left=root->right=NULL;
		//return root;
	}
	else if (root->element<value){
		//case 2, left side
		root->left=insertion(root->left,value);
	}
	else{
		//case 3, right side
		root->right=insertion(root->right,value);
	}
}

Node *findMinNode(Node *root){
	Node *tmp=root;
	while (tmp->left!=NULL){
		tmp=tmp->left;
	}
	return tmp;
}

Node *deletion(Node *root,int value){
	if (root==NULL){
		return NULL;
	}
	if (root->element>value){
		root->left=deletion(root->left,value);
	}
	else if (root->element<value){
		root->right=deletion(root->right,value);
	}
	else{
		Node *tnode=NULL;
		 //when the value is found
		if (root->left==NULL && root->right==NULL){
		 	return NULL;
		}
		else if (root->left==NULL || root->right==NULL){
		 	if (root->left==NULL){
		 		return root->right;
			}
			else{
				return root->left;
			}
		}
		else if (root->left!=NULL && root->right==NULL){
			tnode=findMinNode(root->right);
			root->element=tnode->element;
			root->right=deletion(root->right,tnode->element);
		}
	}
	return root;
}

Node *search(Node *root, int value){
	if (root==NULL){
		printf("No value in tree");
	}
	if (root->element==value){
		return root;
	}
	else if (root->element>value){
		return search(root->left,value);
	}
	else{
		return search(root->right,value);
	}
}

void printNodes(Node *root){
	if (root==NULL){
		return ;
	}
	printf("%d ",root->element);
	printNodes(root->left);
	printNodes(root->right);
}

int main(void){
	root=insertion(root,1);
	root=insertion(root,2);
	printNodes(root); //1 2
	root=deletion(root,2);
	//printNodes(root);
	root=insertion(root,5);
	root=insertion(root,9);
	printNodes(root); //1 5 9
	search(root,3); //NULL
}
