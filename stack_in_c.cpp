#include <stdio.h>
#define max_size 8

int stack[max_size];
int top=-1;

void push(int element){
	//when stack is full
	if (top>=max_size-1){
		printf("cannot push stack, stack already full!");
	}
	else{
		stack[++top]=element;
	}
}

int pop(){
	//when stack is empty
	if (top==-1){
		printf("cannot pop stack, stack is empty!");
		return 0;
	}
	else{
		int popped;
		popped=stack[top];
		top=top-1;
		return popped;
	}
}

void size(){
	//when stack is empty
	if (top==-1){
		printf("size of stack:0, stack is empty ");
	}
	else{
		printf("%d",top+1);
	}
}

void printElements(){
	int i;
	for (i=0;i<=top;i++){
		printf("%d ",stack[i]);
	}
}

//½ÇÇà
int main(void){
	size();//"size of stack:0, stack is empty"
	push(1);
	push(2);
	printElements(); //1 2
	printf("\n");
	push(3);
	push(4);
	push(5);
	push(6);
	push(7);
	push(8);
	printElements(); //1 2 3 4 5 6 7 8
	printf("\n");
	printf("%d",pop()); //8
	printf("\n");
	printElements();//1 2 3 4 5 6 7
	printf("\n");
	push(9);
	push(10); //"cannot push stack, stack is empty!"
}




	
