//队列：使用数组实现
#include<stdio.h>
#include<stdbool.h>

// 定义队列的最大容量
#define N 10

// 存储队列元素的数组
int A[N];
// 队头指针，指向队列的第一个元素
int front = -1;
// 队尾指针，指向队列的最后一个元素
int rear = -1;

/**
 * 判断队列是否为空
 * @return true表示队列为空，false表示队列不为空
 */
bool IsEmpty(){
    // 当front和rear都为-1时表示队列为空
    if(front == -1 && rear == -1){
        return true;
    }
    else{
        return false;
    }
}

/**
 * 判断队列是否已满
 * @return true表示队列已满，false表示队列未满
 */
bool IsFull(){
    // 循环队列的判断条件：(rear+1)%N == front
    // 牺牲一个空间来区分队空和队满的情况
    if((rear + 1) % N == front){
        return true;
    }
    else{
        return false;
    }
}

/**
 * 向队列中添加元素（入队）
 * @param data 要入队的数据
 */
void Enqueue(int data){
    // 检查队列是否已满
    if(IsFull()){
        printf("The Queue is full!\n");
        return;
    }
    // 如果队列为空，初始化front和rear为0
    else if(IsEmpty()){
        front = rear = 0;
    }
    // 队列不为空时，rear指针循环递增
    else{
        rear = (rear + 1) % N;
    }
    // 将数据存入队尾位置
    A[rear] = data;
}

/**
 * 从队列中删除元素（出队）
 */
void Dequeue(){
    // 检查队列是否为空
    if(IsEmpty()){
        printf("The Queue is empty!\n");
        return;
    }
    // 如果队列只有一个元素，出队后队列变空
    else if(front == rear){
        front = rear = -1;
    }
    // 多个元素的情况，front指针循环递增
    else{
        front = (front + 1) % N;
    }
}

/**
 * 获取队头元素
 * @return 队头元素的值
 */
int Front(){
    return A[front];
}

/**
 * 主函数：测试环形队列的功能
 */
int main(){
    // 初始化测试
    printf("=== 环形队列测试 ===\n");
    
    // 测试空队列状态
    printf("初始状态 - 队列是否为空: %s\n", IsEmpty() ? "是" : "否");
    
    // 测试入队操作
    printf("\n--- 测试入队操作 ---\n");
    for(int i = 1; i <= 5; i++){
        Enqueue(i * 10);
        printf("入队: %d, 队头元素: %d\n", i * 10, Front());
    }
    
    // 测试出队操作
    printf("\n--- 测试出队操作 ---\n");
    for(int i = 0; i < 3; i++){
        printf("队头元素: %d ", Front());
        Dequeue();
        printf("出队完成\n");
    }
    
    // 继续入队，测试循环特性
    printf("\n--- 测试循环特性 ---\n");
    for(int i = 6; i <= 13; i++){
        Enqueue(i * 10);
        printf("入队: %d, 队头元素: %d\n", i * 10, Front());
    }
    
    // 测试队满情况
    printf("\n--- 测试队满情况 ---\n");
    printf("队列是否已满: %s\n", IsFull() ? "是" : "否");
    Enqueue(999); // 尝试入队已满的队列
    
    // 清空队列
    printf("\n--- 清空队列 ---\n");
    while(!IsEmpty()){
        printf("出队: %d\n", Front());
        Dequeue();
    }
    
    printf("最终状态 - 队列是否为空: %s\n", IsEmpty() ? "是" : "否");
    
    return 0;
}