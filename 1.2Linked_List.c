//在链表任意位置插入节点
#include<stdio.h>
#include<stdlib.h>

// 定义链表节点结构体
struct Node{
    int data;              // 节点存储的数据
    struct Node* next;     // 指向下一个节点的指针
};

struct Node* head;         // 全局头指针，指向链表的第一个节点

// 在链表的第n个位置插入数据为data的节点
void Insert(int data , int n){
    // 创建新节点并分配内存
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1 -> data = data;   // 设置新节点的数据
    temp1 -> next = NULL;   // 初始化next指针为NULL
    
    // 如果插入位置是第1个位置
    if (n == 1){
        temp1 -> next = head;  // 新节点指向原来的第一个节点
        head = temp1;          // 更新头指针指向新节点
        return;
    }
    
    // 找到第(n-1)个节点
    struct Node* temp2 = head;
    for(int i = 0 ; i < n - 2 ; i++){//从头节点开始移动的步数 = (n-1) - 1 = n-2
        temp2 = temp2 -> next;  // 移动到下一个节点
    }
    
    // 插入新节点到链表中
    temp1 -> next = temp2 -> next;  // 新节点指向原来第n个节点
    temp2 -> next = temp1;          // 第(n-1)个节点指向新节点
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

// 主函数，测试链表操作
int main(){
    head = NULL;           // 初始化空链表
    
    // 依次插入节点进行测试
    Insert(2 , 1);         // 在位置1插入2 -> 链表: [2]
    Insert(3 , 2);         // 在位置2插入3 -> 链表: [2, 3]
    Insert(4 , 1);         // 在位置1插入4 -> 链表: [4, 2, 3]
    Insert(5 , 2);         // 在位置2插入5 -> 链表: [4, 5, 2, 3]
    
    Print();               // 打印最终链表: "List is: 4 5 2 3"
}