#include <stdio.h>
#include <stdlib.h> //malloc 사용 

typedef int element; //giving a particular type a special name, int->element
typedef struct ListNode{
	element data;
	struct ListNode *link;
} ListNode;
void insertNode(ListNode **phead, ListNode *p, ListNode *new_node){
	//세 가지 경우-1)no elements, 2)one element, 3)general case
	//해당 노드 앞에 넣기 
	if (*phead==NULL){
		new_node->link=NULL;
		*phead=new_node;
	}
	else if (p==NULL){
		new_node->link=*phead;
		*phead=new_node;
	}
	else {
		new_node->link=p->link;
		p->link=new_node;}
}
void insert_node_after_value(ListNode *head, int value, ListNode *new_node){
	ListNode *p=head;
	int found=0;
	while (p!=NULL && found==0){
		if (p->data==value){
			found=1;
			break;
		}
		else{
			p=p->link;
		}
	}
	if (found==0){
		printf("찾고자 하는 value 없음");
	}
	else{
		//현재 p 지점이 value 담고 있어
		new_node->link=p->link;
		p->link=new_node;	 
	} 	
}
void remove_node_by_value(ListNode **phead, ListNode *head, int value){
	ListNode *p=head;
	int found=0;
	
	ListNode *prev;
	while (p!=NULL && found==0){
		if (p->data == value){
			found=1;
			break;
		}
		else{
		    prev=p;
			p=p->link;
		}
	}
	if (found==0){
		printf("찾고자 하는 value 없음");
		printf("\n");
	}
	else{
		prev->link=p->link;
	} 
	free(p);
}
void display(ListNode *head){
	ListNode *p= head;
	while (p!=NULL){
		printf("%d ",p->data);
		p=p->link;
	}
	printf("\n");
}
void count(ListNode *head){
	int cnt=0;
	ListNode *p=head;
	while (p!=NULL){
		cnt++;
		p=p->link;
	}
	printf("%d ",cnt);
	printf("\n");
}
int main(int argc, const char *argv[]){
	//head 노드 초기화시키기
    struct ListNode *head1 = malloc(sizeof(struct ListNode));
	head1=NULL;
	int i;
	//1에서 5까지의 값을 포함한 연결리스트 만들기
	//1)노드의 생성, 2)insertNode function을 통한 노드연결(연결리스트 만들기)
	for (i=1;i<=5;i++){
		struct ListNode *newNode=malloc(sizeof(struct ListNode));
		newNode->link=NULL;
		newNode->data=i;
		insertNode(&head1,NULL,newNode);//head1 as a pointer of the head pointer
		//only working with single nodes, no predecessor assumed 
	}
	printf("연결리스트 출력\n");
	display(head1);
	printf("연결리스트 count 출력\n");
    count(head1);
    
    printf("새로운 노드 11을 4 뒤에 넣기\n");
	struct ListNode *new_node = malloc(sizeof(struct ListNode));
    new_node->link = NULL;
    new_node->data = 11;
    insert_node_after_value(head1, 4, new_node);
    display(head1);
    
    printf("새로운 노드 11을 0 (없는 값) 뒤에 넣기\n");
    struct ListNode *new_node2 = malloc(sizeof(struct ListNode));
    new_node2->link = NULL;
    new_node2->data = 11;
    insert_node_after_value(head1, 0, new_node);
    display(head1);

 	printf("노드 11을 삭제하기\n");
    remove_node_by_value(&head1, head1, 11);
    display(head1);
    printf("노드 1을 삭제하기\n");
    remove_node_by_value(&head1, head1, 1);
    display(head1);
    printf("노드 10을 삭제하기\n");
    remove_node_by_value(&head1, head1, 10);
    display(head1);
    printf("노드 1을 삭제하기\n");
    remove_node_by_value(&head1, head1, 1);
    display(head1);


}
