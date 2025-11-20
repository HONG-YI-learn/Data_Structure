// 栈的链表实现
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> // 引入布尔类型支持

// 定义链表节点结构体
struct Node{
    int data;              // 节点存储的数据
    struct Node* link;     // 指向下一个节点的指针
};

struct Node* top = NULL;   // 初始化栈顶指针为NULL，表示空栈

// 入栈操作：在栈顶插入新元素
void Push(int data){
    // 分配新节点的内存空间
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = data;   // 将数据存入新节点
    temp -> link = top;    // 新节点指向原来的栈顶节点
    top = temp;            // 更新栈顶指针指向新节点
}

// 出栈操作：删除栈顶元素
void Pop(){
    struct Node* temp;
    // 检查栈是否为空
    if(top == NULL){
        return;            // 空栈直接返回
    }
    temp = top;            // 保存当前栈顶节点
    top = top -> link;     // 栈顶指针指向下一個节点
    free(temp);            // 释放原栈顶节点的内存
}

// 获取栈顶元素：返回栈顶元素
int Top(){
    return top -> data;    // 返回栈顶节点的数据
}

// 判断栈是否为空：返回布尔值
bool IsEmpty(){
    /*
    if(top == NULL){
        return true;
    }
    else{
        return false;
    }
    */
    return top == NULL;    // 直接返回栈顶指针是否为NULL的判断结果
}

// 打印栈中所有元素
void Print(){
    struct Node* temp = top;  // 从栈顶开始遍历
    printf("Stack: ");
    // 遍历链表，打印每个节点的数据
    while(temp != NULL){
        printf("%d " , temp -> data);
        temp = temp -> link;  // 移动到下一个节点
    }
    printf("\n");
}

// 主函数：测试栈的各种操作
int main(void){
    // 测试初始状态下的栈是否为空
    printf("bool value is %d\n" , IsEmpty());  // 输出布尔值(1表示true, 0表示false)
    
    // 使用条件语句显示栈是否为空的可读信息
    if(IsEmpty()){
        printf("Stack is empty: true\n");
    } else {
        printf("Stack is empty: false\n");
    }

    // 执行一系列栈操作并打印结果
    Push(9);Print();   // 入栈9并打印
    Push(8);Print();   // 入栈8并打印
    Pop();Print();     // 出栈一次并打印
    Push(6);Print();   // 入栈6并打印
    Push(7);Print();   // 入栈7并打印
    Pop();Print();     // 出栈一次并打印
    Push(1);Print();   // 入栈1并打印
    printf("top is %d\n" , Top());  // 打印当前栈顶元素

    // 再次检查栈的状态
    if(IsEmpty()){
        printf("Stack is empty: true\n");
    } else {
        printf("Stack is empty: false\n");
    }
    
    // 最后再次输出栈是否为空的布尔值
    printf("bool value is %d\n" , IsEmpty());
    
    return 0;  // 程序正常结束
}