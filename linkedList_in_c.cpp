#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct node *head; //NULL 값을 data로 가지고 있는 첫 노드 생성. 
void beginsert(int item){
    struct node *ptr=(struct node *)malloc(sizeof(struct node *));//newNode creation
    if (ptr==NULL){
        ptr->next=NULL;
        head=ptr; //비어있는 첫 노드를 갖고 있는 연결리스트.
    }
    else{
        ptr->data=item;
        ptr->next=head;
        head=ptr;
    }
}
void lastinsert(int item){
    struct node *ptr=(struct node *)malloc(sizeof(struct node *));//newNode creation
    struct node *temp; //check current node
    if (ptr==NULL){
        printf("not working\n");
    }
    else{
        ptr->data=item;
        if (head==NULL){
            ptr->next=NULL;
            head=ptr;
        }
        else{
            temp=head;
            while (temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->next=NULL;
        }
    }
}
void display(){
    struct node *ptr;
    ptr=head;
    if (ptr==NULL){
        printf("nothing to print\n");
    }
    else{
        while (ptr!=NULL){
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
}
void search(int item){
    //searching 대상: item
    struct node *ptr;
    ptr=head;
    int found=0; //못 찾았음을 전제로
    if (ptr==NULL){
        printf("No elements in the list\n");
    }
    else{
        while (ptr!=NULL && found!=1){
            if (ptr->data==item){
                found=1;
                break;
            }
            else{
                ptr=ptr->next;
            }
        }
    }
    if (found==1){
        printf("Item in the list\n");
    }
    else{
        printf("Item not in list\n");
    }
}
void delete(struct node *head, int item){
    struct node *ptr, *prev;
    ptr=head;
    int found=0;
    if (ptr==NULL){
        printf("No element to delete\n");
    }
    else{
        //item이 있나 없나 searching
        while (ptr!=NULL){
            if (ptr->data==item){
                found=1;
                break;
            }
            else{
                prev=ptr;
                ptr=ptr->next;
            }
        }
        if (found==0){
            printf("Item not in list\n");
        }
        else{
            prev->next=ptr->next;
        }
    }
}

void function43to48(){
    /*간단한 방법, insertFront를 하든 insertEnd를 하든 struct node *ptr을 매 함수에 넣어줌으로써
    new node formation을 한다. struct node *head는 첫 노드로써 전역변수로 가장 위에 선언해준다*/

    int item1,item2,item3,item4;
    printf("Enter the item in which you want to insert in the front\n");
    scanf("%d",&item1);
    beginsert(item1);
    printf("Enter another item in which you want to insert in the front\n");
    scanf("%d",&item3);
    beginsert(item3);
    printf("Enter the item in which you want to insert at the end\n");
    scanf("%d",&item2);
    lastinsert(item2);
    display();
    printf("\n");
    printf("Check if the following item 4 is in the list\n");
    search(4);
    printf("Enter the item in which you want to delete\n");
    scanf("%d",&item4);
    delete(head,item4); //traversal
    display();
}
int main(void){
	function43to48();
}
