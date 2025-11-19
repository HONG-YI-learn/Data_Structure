// 使用递归反转链表(不使用全局变量head)
#include<stdio.h>
#include<stdlib.h>

// 定义链表节点结构体
struct Node{
    int data;           // 节点存储的数据
    struct Node *next;  // 指向下一个节点的指针
};

//struct Node *head;      // 全局头指针，指向链表的第一个节点

// 在链表末尾插入节点
// 参数: data - 要插入的数据
struct Node* Insert(int data , struct Node* head){
    // 创建新节点并分配内存
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    
    // 检查内存分配是否成功
    if(temp1 == NULL){
        printf("内存分配失败\n");
        return 0;
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
    return head;
}

// 打印链表中的所有节点数据
void Print(struct Node* head){
    struct Node *temp = head;     // 创建临时指针指向链表头节点
    printf("List is: ");          // 打印提示信息
    while(temp != NULL){          // 遍历链表直到末尾
        printf("%d ", temp -> data);   // 打印当前节点的数据
        temp = temp -> next;           // 移动到下一个节点
    }
    printf("\n");                 // 打印换行符
}

// 使用递归方法反转链表
// 参数: p - 当前处理的节点指针
struct Node* Reverse(struct Node* head){
    // 处理空链表情况
    if(head == NULL || head -> next == NULL){
        return head;  // 空链表或只有一个节点时，直接返回
    }
    
    struct Node* p = head;
    if(p -> next == NULL){
        return p;  // 最后一个节点，作为新头节点返回
    }
    
    // 递归处理下一个节点，并接收新的头节点，新的头节点始终是原链表的最后一个节点
    struct Node* newHead = Reverse(p -> next);
    
    // 回溯阶段：调整节点指向，实现链表反转
    p -> next -> next = p;   // 让下一个节点指向当前节点
    p -> next = NULL;        // 当前节点指向NULL，完成反转
    
    // 注释掉的代码是另一种实现方式：
    // struct Node *q = p -> next;  // q指向下一个节点
    // q -> next = p;               // 下一个节点指向当前节点
    // p -> next = NULL;            // 当前节点指向NULL

    return newHead;  // 返回新的头节点
}

// 主函数
int main(void){
    struct Node* head = NULL;  // 初始化链表为空
    
    // 循环插入数据 0, 1, 2, 3, 4
    for(int i = 0 ; i < 5 ; i++){
        head = Insert(i , head);
    }
    
    printf("未反转前：");
    Print(head);           // 打印原始链表: 0 1 2 3 4
    
    head = Reverse(head);     // 递归反转链表
    
    printf("反转后：");
    Print(head);           // 打印反转后的链表: 4 3 2 1 0
    return 0;
}