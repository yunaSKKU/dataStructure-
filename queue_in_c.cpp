#include <stdio.h>
#define max_length 5
int front=0; //empty인 상태. 초기화.
int rear=0;
int queue[max_length];

void is_empty(){
	if (front==rear){
		printf("queue size 0, queue is empty!\n");
	}
	else{
		printf("queue size not 0\n");
	}
}
void size(){
	if (front==0){
		printf("queue size 0, queue is empty!\n");
	}
	else{
		printf("%d ",front+1);
	}
}
void enqueue(int element){
	if (rear==max_length){
		printf("cannnot enqueue element, queue is full!\n");
	}
	else{
		queue[rear++]=element;
		
	}
}
int dequeue(){
	if (front==rear){
		printf("cannot dequeue element, queue is empty!\n");
	}
	else{
		int a;
		for (int a=0;a<rear-1;a++){
			queue[a]=queue[a+1];
		}
		rear--;
		return queue[0];
	}
}
void printElement(){
	int i;
	for (i=front;i<rear;i++){
		printf("%d ",queue[i]);
	}
}
		
int main(void){
	
	size();
	enqueue(1);
	enqueue(2);
	printElement(); // 1 2
	printf("\n");
	dequeue();
	printf("\n");
	printElement(); // 2
	printf("\n");
	is_empty(); //FALSE
	printf("\n");
	enqueue(3);// 2 3
	enqueue(4);// 2 3 4
	enqueue(5);// 2 3 4 5
	enqueue(6);// 2 3 4 5 6
	printElement();
	enqueue(7);
}
	
