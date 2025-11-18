//迭代法反转链表（没有设置头指针为全局变量）
#include<stdio.h>
#include<stdlib.h>

// 定义链表节点结构体
struct Node{
    int data;                // 存储节点数据
    struct Node* next;       // 指向下一个节点的指针
};

// 在链表末尾插入节点
// 参数: head - 链表头指针, data - 要插入的数据
// 返回值: 更新后的链表头指针
struct Node* Insert(struct Node *head , int data){
    // 创建新节点并分配内存
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    
    // 检查内存分配是否成功
    if(temp1 == NULL){
        printf("内存分配失败\n");
        return head;
    }
    
    // 初始化新节点
    temp1 -> data = data;    // 设置节点数据
    temp1 -> next = NULL;    // 新节点作为最后一个节点，next设为NULL

    // 如果链表为空，新节点成为头节点
    if (head == NULL) {
        head = temp1;
        return head;
    }

    // 遍历到链表末尾
    struct Node* temp2 = head;
    while(temp2 -> next != NULL){
        temp2 = temp2 -> next;
    }
    
    // 将新节点连接到链表末尾
    temp1 -> next = NULL;    // 确保新节点指向NULL
    temp2 -> next = temp1;   // 原末节点指向新节点
    return head;             // 返回头指针
}

// 打印链表中的所有节点数据
// 参数: head - 链表头指针
void Print(struct Node *head){
    struct Node* temp = head;  // 创建临时指针指向链表头节点，避免修改传入的head指针
    printf("List is: ");       // 打印提示信息
    
    // 遍历链表直到末尾（temp为NULL）
    while(temp != NULL){
        printf("%d " , temp -> data);  // 打印当前节点的数据
        temp = temp -> next;           // 移动到下一个节点
    }
    
    printf("\n");  // 打印换行符，使输出更美观
}

// 反转链表
// 参数: head - 链表头指针
// 返回值: 反转后的新链表头指针
struct Node* Reverse(struct Node *head){
    struct Node *prev, *current, *next;  // 定义三个指针用于反转操作
    current = head;                      // current指向当前处理的节点（初始为头节点）
    prev = NULL;                         // prev指向当前节点的前一个节点（初始为NULL）
    
    // 遍历链表，逐个反转节点指向
    while(current != NULL){
        next = current -> next;          // 保存下一个节点的地址（防止丢失）
        current -> next = prev;          // 当前节点的next指向前一个节点（实现反转）
        prev = current;                  // prev向前移动一位，指向当前节点
        current = next;                  // current向前移动一位，指向原下一个节点
    }
    head = prev;                         // 反转完成后，prev指向原链表的最后一个节点，即新链表的头节点
    return head;                         // 返回新的头指针
}

// 主函数
int main(){
    struct Node *head = NULL;  // 初始化链表为空，局部变量head替代全局变量
    
    // 插入测试数据
    head = Insert(head , 1);
    head = Insert(head , 2);
    head = Insert(head , 3);
    head = Insert(head , 4);
    head = Insert(head , 5);
    
    Print(head);  // 打印初始链表

    head = Reverse(head);  // 反转链表，接收返回的新头指针

    Print(head);  // 打印反转后的链表
}