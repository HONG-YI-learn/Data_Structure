//迭代法反转链表
#include<stdio.h>
#include<stdlib.h>

// 定义链表节点结构体
struct Node{
    int data;                // 存储节点数据
    struct Node* next;       // 指向下一个节点的指针
};

struct Node* head;           // 全局头指针，指向链表的第一个节点

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

// 反转链表
void Reverse(void){
    struct Node *prev, *current, *next;  // 定义三个指针用于反转操作
    current = head;                      // current指向头节点
    prev = NULL;                         // prev初始化为NULL（将成为新链表的末尾）
    
    // 遍历链表，逐个反转节点指向
    while(current != NULL){
        next = current -> next;          // 保存下一个节点的地址
        current -> next = prev;          // 当前节点指向前一个节点
        prev = current;                  // prev向前移动一位
        current = next;                  // current向前移动一位
    }
    head = prev;                         // 更新头指针，指向新的头节点
}

// 主函数
int main(){
    head = NULL;  // 初始化链表为空
    
    // 插入测试数据
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);
    
    Print();  // 打印初始链表

    Reverse();  // 反转链表

    Print();  // 打印反转后的链表
}