//创建链表，在开头插入节点（没有设置头指针为全局变量）
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
//struct Node* head;

struct Node* Insert(struct Node* head , int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = x;
    temp -> next = head;
    head = temp;
    return head;
}

void Print(struct Node* head){
    printf("List is: ");
    while(head != NULL){
        printf("%d " , head -> data);//已经将头节点的地址赋给head后，执行打印即是头节点的data
        head = head -> next;
    }
    printf("\n");
}

int main(){
    struct Node* head = NULL;
    printf("How many number?\n");
    int n , x;
    scanf("%d" , &n);
    for(int i = 0 ; i < n ; i++){
        printf("Enter the number \n");
        scanf("%d" , &x);
        head = Insert(head , x);
        Print(head);
    }
    return 0;
}