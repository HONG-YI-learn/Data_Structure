//使用递归方法打印链表
#include<stdio.h>
#include<stdlib.h>

// 定义链表节点结构体
struct Node{
    int data;           // 节点存储的数据
    struct Node *next;  // 指向下一个节点的指针
};

struct Node *head;      // 全局头指针，指向链表的第一个节点

// 在链表末尾插入节点
// 参数: data - 要插入的数据
void Insert(int data){
    // 创建新节点并分配内存
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    
    // 检查内存分配是否成功
    if(temp1 == NULL){
        printf("内存分配失败\n");
        return;
    }
    
    // 初始化新节点
    temp1 -> data = data;    // 设置节点数据
    temp1 -> next = NULL;    // 新节点作为最后一个节点，next设为NULL

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
    temp1 -> next = NULL;    // 确保新节点指向NULL
    temp2 -> next = temp1;   // 原末节点指向新节点
}

// 递归正序打印链表
// 参数: p - 当前要打印的节点指针
void Print(struct Node *p){
    // 递归终止条件：如果当前节点为空，说明已到达链表末尾
    if(p == NULL){
        printf("\n");  // 打印换行符，使输出更美观
        return;
    }
    printf("%d ", p -> data);  // 打印当前节点的数据
    Print(p -> next);          // 递归打印下一个节点
}

// 递归逆序打印链表
// 参数: p - 当前要处理的节点指针
void ReversePrint(struct Node *p){
    // 递归终止条件：如果当前节点为空，说明已到达链表末尾
    if(p == NULL){
        return;  // 直接返回，不进行任何操作
    }
    ReversePrint(p -> next);   // 先递归处理下一个节点
    printf("%d ", p -> data);  // 回溯时打印当前节点数据，实现逆序打印
}

// 主函数
int main(void){
    head = NULL;  // 初始化链表为空
    
    // 循环插入数据 0, 1, 2, 3, 4
    for(int i = 0 ; i < 5 ; i++){
        Insert(i);
    }
    
    printf("顺序打印：");
    Print(head);      // 正序打印链表
    
    printf("逆序打印：");
    ReversePrint(head);  // 逆序打印链表
    printf("\n");        // 打印换行符
    return 0;
}