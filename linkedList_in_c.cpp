#include <stdio.h>
#include <stdlib.h>

struct node{
	int element;
	struct node *next;
};
struct node *head; //NULL initialization

void beginsert(node *head, int item){
	struct node *newNode=(struct node *)malloc(sizeof(struct node *));
	if (head==NULL){
		newNode->link=NULL;
		head=newNode;
	}
	else{
		newNode->link=head;
		head=newNode;
		
	
int main(){
	int numArr[5];
	int i;
	printf("Enter elements that you want to insert in the beginning of the node\n");
	for (i=0;i<5;i++){
		scanf("%d",&numArr[i]);
		beginsert(&head, numArr[i]);
	}
}
