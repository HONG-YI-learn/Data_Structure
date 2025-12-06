//队列：数组实现（用struct封装）
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define N 10

// 定义队列结构体
typedef struct {
    int A[N];        // 存储数据的数组
    int front;       // 队头指针
    int rear;        // 队尾指针
} Queue;

// 初始化队列
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// 判断队列是否为空
bool isEmpty(Queue* q) {
    return (q->front == -1 && q->rear == -1);
}

// 判断队列是否已满
bool isFull(Queue* q) {
    return ((q->rear + 1) % N == q->front);
}

// 入队操作
void enqueue(Queue* q, int data) {
    if (isFull(q)) {
        printf("The Queue is full!\n");
        return;
    }
    else if (isEmpty(q)) {
        q->front = q->rear = 0;
    }
    else {
        q->rear = (q->rear + 1) % N;
    }
    q->A[q->rear] = data;
}

// 出队操作
void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("The Queue is empty!\n");
        return;
    }
    else if (q->front == q->rear) {
        q->front = q->rear = -1;
    }
    else {
        q->front = (q->front + 1) % N;
    }
}

// 获取队头元素
int front(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1; // 返回错误值
    }
    return q->A[q->front];
}

// 打印队列状态（用于调试）
void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Queue elements: ");
    int i = q->front;
    do {
        printf("%d ", q->A[i]);
        i = (i + 1) % N;
    } while (i != (q->rear + 1) % N);
    printf("\n");
}

int main() {
    // 创建并初始化队列
    Queue q;
    initQueue(&q);
    
    printf("=== 非全局变量环形队列测试 ===\n");
    
    // 测试空队列状态
    printf("初始状态 - 队列是否为空: %s\n", isEmpty(&q) ? "是" : "否");
    
    // 测试入队操作
    printf("\n--- 测试入队操作 ---\n");
    for(int i = 1; i <= 5; i++){
        enqueue(&q, i * 10);
        printf("入队: %d, 队头元素: %d\n", i * 10, front(&q));
    }
    
    // 测试出队操作
    printf("\n--- 测试出队操作 ---\n");
    for(int i = 0; i < 3; i++){
        printf("队头元素: %d ", front(&q));
        dequeue(&q);
        printf("出队完成\n");
    }
    
    // 继续入队，测试循环特性
    printf("\n--- 测试循环特性 ---\n");
    for(int i = 6; i <= 13; i++){
        enqueue(&q, i * 10);
        printf("入队: %d, 队头元素: %d\n", i * 10, front(&q));
    }
    
    // 测试队满情况
    printf("\n--- 测试队满情况 ---\n");
    printf("队列是否已满: %s\n", isFull(&q) ? "是" : "否");
    enqueue(&q, 999);
    
    // 清空队列
    printf("\n--- 清空队列 ---\n");
    while(!isEmpty(&q)){
        printf("出队: %d\n", front(&q));
        dequeue(&q);
    }
    
    printf("最终状态 - 队列是否为空: %s\n", isEmpty(&q) ? "是" : "否");
    
    return 0;
}