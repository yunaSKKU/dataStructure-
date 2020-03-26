#include <stdio.h>
#include <string.h> //strlen을 쓰기 위해
#define max_size 100

char randomStr[max_size]; //입력값 들어가
char stack[max_size]; //스택 활용 위해
int top=-1;

void push(char element){
	//when stack is full
	if (top>=max_size-1){
		printf("cannot push stack, stack already full!\n");
	}
	else{
		stack[++top]=element;
	}
}

char pop(){
	//when stack is empty
	if (top==-1){
		printf("cannot pop stack, stack is empty!\n");
		return 0;
	}
	else{
		return stack[top--];
		//char tmp[]= stack[top];
		//strcpy(stack[top],popped);
		//top=top-1;
		//printf("%s ",tmp);
	}
}

int size(){
	//when stack is empty
	if (top==-1){
		printf("size of stack:0, stack is empty!\n");
	}
	else{
		return top+1;;
	}
}

void printElements(){
	int i;
	for (i=0;i<=top;i++){
		printf("%c ",stack[i]);
	}
}

//실행
int main(void){
	//먼저 stack에 문자열 입력
	printf("palindrome을 판별할 문자열을 입력하세요.\n");
	scanf("%s",randomStr);
	int i,value,length;
	length=strlen(randomStr);
	int mid=length/2;
	
	for (i=0;i<mid;i++){
		push(randomStr[i]);
	}
	if (length%2!=0){
		i++;
	}
	while (randomStr[i]!='\0'){
		char ele=pop();
		if (ele!=randomStr[i]){
			value=0;
		}
		else{
			value=1;
		}
		i++;}
	if (value==1){
		printf("palindrome");
	}
	else{
		printf("not palindrome!");
	}
}







	
