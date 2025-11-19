//双向链表
#include<stdio.h>
#include<stdlib.h>

// 定义双向链表节点结构体
struct Node{
    int data;              // 节点存储的数据
    struct Node* next;     // 指向下一个节点的指针
    struct Node* prev;     // 指向前一个节点的指针
};

struct Node* head;         // 全局头指针，指向链表的第一个节点

// 创建新节点的函数
// 参数: data - 要存储在新节点中的数据
// 返回值: 指向新创建节点的指针
struct Node* GetNewNode(int data){
    struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
    NewNode -> data = data;     // 设置节点数据
    NewNode -> next = NULL;     // 初始化next指针为空
    NewNode -> prev = NULL;     // 初始化prev指针为空
    return NewNode;             // 返回新节点指针
}

// 在链表头部插入新节点
// 参数: data - 要插入的数据
void Insert_at_Head(int data){
    struct Node* NewNode = GetNewNode(data);  // 创建新节点
    if(head == NULL){                         // 如果链表为空
        head = NewNode;                       // 新节点成为头节点
        return;
    }
    head -> prev = NewNode;                   // 原头节点的prev指向新节点
    NewNode -> next = head;                   // 新节点的next指向原头节点
    head = NewNode;                           // 更新头指针指向新节点
}

// 在链表尾部插入新节点
// 参数: data - 要插入的数据
void Insert_at_Tail(int data){
    struct Node* NewNode = GetNewNode(data);  // 创建新节点
    if(head == NULL){                         // 如果链表为空
        head = NewNode;                       // 新节点成为头节点
        return;
    }
    struct Node* temp = head;                 // 从头节点开始遍历
    while(temp -> next != NULL){              // 遍历到链表末尾
        temp = temp -> next;
    }
    temp -> next = NewNode;                   // 原末节点的next指向新节点
    NewNode -> prev = temp;                   // 新节点的prev指向原末节点
}

// 正向打印链表（从头到尾）
void Print(){
    struct Node* temp = head;                 // 从头节点开始
    if(temp == NULL){                         // 如果链表为空
        return;                               // 直接返回
    }
    printf("Forward: ");                      // 打印提示信息
    while(temp != NULL){                      // 遍历链表直到末尾
        printf("%d ", temp -> data);          // 打印当前节点的数据
        temp = temp -> next;                  // 移动到下一个节点
    }
    printf("\n");                             // 打印换行符
}

// 反向打印链表（从尾到头）
void ReversePrint(){
    struct Node* temp = head;                 // 从头节点开始
    if(temp == NULL){                         // 如果链表为空
        return;                               // 直接返回
    }
    while(temp -> next != NULL){              // 遍历到链表末尾
        temp = temp -> next;
    }
    printf("Reverse: ");                      // 打印提示信息
    while(temp != NULL){                      // 从末尾向前遍历
        printf("%d ", temp -> data);          // 打印当前节点的数据
        temp = temp -> prev;                  // 移动到前一个节点
    }
    printf("\n");                             // 打印换行符
}

// 主函数
int main(void){
    head = NULL;                              // 初始化链表为空
    
    // 插入测试数据
    Insert_at_Tail(3);                        // 在尾部插入3
    Insert_at_Head(2);                        // 在头部插入2
    Insert_at_Tail(4);                        // 在尾部插入4
    Insert_at_Head(1);                        // 在头部插入1
    Insert_at_Tail(5);                        // 在尾部插入5
    Insert_at_Head(0);                        // 在头部插入0
    
    // 最终链表结构: 0 <-> 1 <-> 2 <-> 3 <-> 4 <-> 5
    
    Print();                                  // 正向打印: 0 1 2 3 4 5
    ReversePrint();                           // 反向打印: 5 4 3 2 1 0
    
    return 0;                                 // 程序正常退出
}