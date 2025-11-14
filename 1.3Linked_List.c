// 删除任意位置的节点
#include<stdio.h>
#include<stdlib.h>

// 定义链表节点结构体
struct Node{
    int data;              // 节点存储的数据
    struct Node* next;     // 指向下一个节点的指针
};

struct Node* head;         // 全局头指针，指向链表的第一个节点

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

// 打印链表中的所有节点数据
void Print(void){
    struct Node* temp = head;  // 创建临时指针指向链表头节点，避免修改全局head指针
    printf("List is: ");       // 打印提示信息
    
    // 遍历链表直到末尾（temp为NULL）
    while(temp != NULL){
        printf("%d " , temp -> data);  // 打印当前节点的数据
        temp = temp -> next;           // 移动到下一个节点
    }
    
    printf("\n");  // 打印换行符，使输出更美观
}

// 删除链表中指定位置的节点
void Delete(int n){
    // 检查链表是否为空
    if(head == NULL){
        printf("链表为空，无法删除\n");
        return;
    }
    
    struct Node* temp1 = head;
    
    // 删除头节点（第一个节点）
    if(n == 1){
        head = temp1 -> next;  // 更新头指针
        free(temp1);           // 释放被删除节点的内存
        return;
    }

    // 遍历到要删除节点的前一个节点
    for(int i = 0 ; i < n - 2 ; i++){
        // 检查位置是否超出链表范围
        if(temp1 -> next == NULL){
            printf("位置超出链表范围\n");
            return;
        }
        temp1 = temp1 -> next;
    }
    
    // 获取要删除的节点
    struct Node* temp2 = temp1 -> next;
    
    // 检查要删除的节点是否存在
    if(temp2 == NULL){
        printf("位置超出链表范围\n");
        return;
    }
    
    // 修改指针跳过要删除的节点
    temp1 -> next = temp2 -> next;
    
    // 释放被删除节点的内存
    free(temp2);
}

int main(){
    head = NULL;  // 初始化链表为空
    int n;
    
    // 插入测试数据
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);
    
    Print();  // 打印初始链表
    
    printf("输入要删除第几个节点：");
    scanf("%d" , &n);
    
    Delete(n);  // 删除指定位置的节点
    
    Print();    // 打印删除后的链表
    return 0;
}