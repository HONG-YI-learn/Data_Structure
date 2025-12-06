//队列：使用链表实现（使用全局变量）
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// 定义队列节点结构体
typedef struct Node{
    int data;               // 节点存储的数据
    struct Node* next;      // 指向下一个节点的指针
}Node;

// 全局指针，分别指向队列的头部和尾部
Node* front = NULL;
Node* rear = NULL;

/**
 * 判断队列是否为空
 * @return true表示队列为空，false表示队列不为空
 */
bool IsEmpty(){
    // 当front和rear都为NULL时，队列为空
    if(front == NULL && rear == NULL){
        return true;
    }
    else{
        return false;
    }
}

/**
 * 获取队首元素
 * @return 队首元素的值，如果队列为空则返回-1
 */
int Front(){
    // 添加安全检查，防止访问空队列
    if(IsEmpty()){
        printf("队列为空，无法获取队首元素\n");
        return -1; // 返回错误值
    }
    return front->data;
}

/**
 * 入队操作，在队列尾部添加新元素
 * @param data 要添加的数据
 */
void Enqueue(int data){
    // 创建新节点并分配内存
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    
    // 如果队列为空，则新节点既是队首也是队尾
    if(IsEmpty()){
        front = rear = temp;
    }
    else{
        // 将新节点添加到队尾，并更新队尾指针
        rear->next = temp;
        rear = temp;
    }
}

/**
 * 出队操作，移除队列头部的元素
 */
void Dequeue(){
    // 保存当前队首节点的地址
    Node* temp = front;
    
    // 如果队列为空，则直接返回
    if(IsEmpty()){
        return;
    }
    
    // 如果队列只有一个节点，则出队后队列变为空
    if(front == rear){
        front = rear = NULL;
    }
    else{
        // 更新队首指针，指向下一个节点
        front = front->next;
    }
    
    // 释放原队首节点的内存
    free(temp);
}

/**
 * 打印队列中的所有元素
 */
void PrintQueue() {
    // 如果队列为空，直接返回提示信息
    if (IsEmpty()) {
        printf("队列为空\n");
        return;
    }
    
    printf("队列内容: ");
    // 从队首开始遍历，依次打印每个节点的数据
    Node* current = front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

/**
 * 主函数，用于测试队列的各种操作
 */
int main() {
    printf("=== 链表实现队列测试 ===\n");
    
    // 测试空队列
    printf("1. 测试空队列:\n");
    if (IsEmpty()) {
        printf("队列为空\n");
    }
    
    // 测试入队操作
    printf("\n2. 测试入队操作:\n");
    Enqueue(10);
    printf("入队 10 后: ");
    PrintQueue();
    
    Enqueue(20);
    printf("入队 20 后: ");
    PrintQueue();
    
    Enqueue(30);
    printf("入队 30 后: ");
    PrintQueue();
    
    // 测试获取队首元素
    printf("\n3. 测试获取队首元素:\n");
    if (!IsEmpty()) {
        printf("队首元素: %d\n", Front());
    }
    
    // 测试出队操作
    printf("\n4. 测试出队操作:\n");
    Dequeue();
    printf("出队一次后: ");
    PrintQueue();
    
    Dequeue();
    printf("出队两次后: ");
    PrintQueue();
    
    // 继续添加元素并测试
    printf("\n5. 继续添加元素:\n");
    Enqueue(40);
    Enqueue(50);
    printf("入队 40 和 50 后: ");
    PrintQueue();
    
    // 全部出队
    printf("\n6. 全部出队:\n");
    while (!IsEmpty()) {
        printf("出队 %d: ", Front());
        Dequeue();
        PrintQueue();
    }
    
    return 0;
}