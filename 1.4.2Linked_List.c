//使用递归方法打印链表
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head;

// 在链表末尾插入节点
void Insert(int data){
    // 创建新节点并分配内存
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    
    // 检查内存分配是否成功
    if(temp1 == NULL){
        printf("内存分配失败\n");
        return;
    }
    
    // 初始化新节点
    temp1 -> data = data;
    temp1 -> next = NULL;

    // 如果链表为空，新节点成为头节点
    if (head == NULL) {
        head = temp1;
        return;
    }

    // 遍历到链表末尾
    struct Node* temp2 = head;
    while(temp2 -> next != NULL){
        temp2 = temp2 -> next;
    }
    
    // 将新节点连接到链表末尾
    temp1 -> next = NULL;
    temp2 -> next = temp1;
}

void Print(struct Node *p){
    if(p == NULL){
        printf("\n");
        return;
    }
    printf("%d " , p -> data);
    Print(p -> next);
}

void ReversePrint(struct Node *p){
    if(p == NULL){
        return;
    }
    ReversePrint(p -> next);
    printf("%d " , p -> data);
}

int main(void){
    head = NULL;
    for(int i = 0 ; i < 5 ; i++){
        Insert(i);
    }
    printf("顺序打印：");
    Print(head);
    printf("逆序打印：");
    ReversePrint(head);
    printf("\n");
}