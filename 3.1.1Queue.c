//队列：使用链表实现（不使用全局变量，用struct封装）
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// 定义队列节点结构体
typedef struct Node{
    int data;               // 节点存储的数据
    struct Node* next;      // 指向下一个节点的指针
}Node;

// 定义队列结构体，包含队首和队尾指针
typedef struct Queue{
    Node* front;            // 指向队首节点
    Node* rear;             // 指向队尾节点
}Queue;

/**
 * 初始化队列
 * @return 指向新创建队列的指针
 */
Queue* CreateQueue(){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

/**
 * 判断队列是否为空
 * @param queue 队列指针
 * @return true表示队列为空，false表示队列不为空
 */
bool IsEmpty(Queue* queue){
    // 当front和rear都为NULL时，队列为空
    if(queue->front == NULL && queue->rear == NULL){
        return true;
    }
    else{
        return false;
    }
}

/**
 * 获取队首元素
 * @param queue 队列指针
 * @return 队首元素的值，如果队列为空则返回-1
 */
int Front(Queue* queue){
    // 添加安全检查，防止访问空队列
    if(IsEmpty(queue)){
        printf("队列为空，无法获取队首元素\n");
        return -1; // 返回错误值
    }
    return queue->front->data;
}

/**
 * 入队操作，在队列尾部添加新元素
 * @param queue 队列指针
 * @param data 要添加的数据
 */
void Enqueue(Queue* queue, int data){
    // 创建新节点并分配内存
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    
    // 如果队列为空，则新节点既是队首也是队尾
    if(IsEmpty(queue)){
        queue->front = queue->rear = temp;
    }
    else{
        // 将新节点添加到队尾，并更新队尾指针
        queue->rear->next = temp;
        queue->rear = temp;
    }
}

/**
 * 出队操作，移除队列头部的元素
 * @param queue 队列指针
 */
void Dequeue(Queue* queue){
    // 如果队列为空，则直接返回
    if(IsEmpty(queue)){
        return;
    }
    
    // 保存当前队首节点的地址
    Node* temp = queue->front;
    
    // 如果队列只有一个节点，则出队后队列变为空
    if(queue->front == queue->rear){
        queue->front = queue->rear = NULL;
    }
    else{
        // 更新队首指针，指向下一个节点
        queue->front = queue->front->next;
    }
    
    // 释放原队首节点的内存
    free(temp);
}

/**
 * 打印队列中的所有元素
 * @param queue 队列指针
 */
void PrintQueue(Queue* queue) {
    // 如果队列为空，直接返回提示信息
    if (IsEmpty(queue)) {
        printf("队列为空\n");
        return;
    }
    
    printf("队列内容: ");
    // 从队首开始遍历，依次打印每个节点的数据
    Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

/**
 * 释放队列占用的所有内存
 * @param queue 队列指针
 */
void DestroyQueue(Queue* queue) {
    // 依次出队所有元素，释放节点内存
    while (!IsEmpty(queue)) {
        Dequeue(queue);
    }
    // 释放队列结构体内存
    free(queue);
}

/**
 * 主函数，用于测试队列的各种操作
 */
int main() {
    printf("=== 链表实现队列测试（无全局变量版本） ===\n");
    
    // 创建队列
    Queue* queue = CreateQueue();
    
    // 测试空队列
    printf("1. 测试空队列:\n");
    if (IsEmpty(queue)) {
        printf("队列为空\n");
    }
    
    // 测试入队操作
    printf("\n2. 测试入队操作:\n");
    Enqueue(queue, 10);
    printf("入队 10 后: ");
    PrintQueue(queue);
    
    Enqueue(queue, 20);
    printf("入队 20 后: ");
    PrintQueue(queue);
    
    Enqueue(queue, 30);
    printf("入队 30 后: ");
    PrintQueue(queue);
    
    // 测试获取队首元素
    printf("\n3. 测试获取队首元素:\n");
    if (!IsEmpty(queue)) {
        printf("队首元素: %d\n", Front(queue));
    }
    
    // 测试出队操作
    printf("\n4. 测试出队操作:\n");
    Dequeue(queue);
    printf("出队一次后: ");
    PrintQueue(queue);
    
    Dequeue(queue);
    printf("出队两次后: ");
    PrintQueue(queue);
    
    // 继续添加元素并测试
    printf("\n5. 继续添加元素:\n");
    Enqueue(queue, 40);
    Enqueue(queue, 50);
    printf("入队 40 和 50 后: ");
    PrintQueue(queue);
    
    // 全部出队
    printf("\n6. 全部出队:\n");
    while (!IsEmpty(queue)) {
        printf("出队 %d: ", Front(queue));
        Dequeue(queue);
        PrintQueue(queue);
    }
    
    // 释放队列内存
    DestroyQueue(queue);
    
    return 0;
}