//通义：使用栈实现反转链表（使用全局变量）
#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct ListNode {
    int data;                 // 节点数据
    struct ListNode* next;    // 指向下一个节点的指针
} ListNode;

// 定义栈的最大容量
#define MAX_STACK_SIZE 100

// 使用全局变量定义栈
ListNode* stack[MAX_STACK_SIZE];  // 存储节点指针的全局数组
int top = -1;                     // 栈顶指针，初始为-1表示空栈

/**
 * 创建新节点
 * @param data 节点数据
 * @return 新创建的节点指针
 */
ListNode* createNode(int data) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/**
 * 判断栈是否为空
 * @return 1表示空栈，0表示非空
 */
int isEmpty() {
    return top == -1;
}

/**
 * 判断栈是否已满
 * @return 1表示栈满，0表示未满
 */
int isFull() {
    return top == MAX_STACK_SIZE - 1;
}

/**
 * 入栈操作
 * @param node 要入栈的节点指针
 */
void push(ListNode* node) {
    if (isFull()) {
        printf("栈溢出\n");
        return;
    }
    // 栈顶指针上移，将节点指针存入栈中
    stack[++top] = node;
}

/**
 * 出栈操作
 * @return 出栈的节点指针
 */
ListNode* pop() {
    if (isEmpty()) {
        printf("栈为空\n");
        return NULL;
    }
    // 返回栈顶元素，并将栈顶指针下移
    return stack[top--];
}

/**
 * 使用全局变量栈反转链表
 * @param head 原链表的头节点
 * @return 反转后链表的头节点
 */
ListNode* reverseListWithGlobalStack(ListNode* head) {
    // 如果链表为空或只有一个节点，直接返回
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // 重置栈顶指针
    top = -1;
    
    // 将链表的所有节点依次入栈
    ListNode* current = head;
    while (current != NULL) {
        push(current);
        current = current->next;
    }
    
    // 出栈的第一个节点作为新链表的头节点
    ListNode* newHead = pop();
    current = newHead;
    
    // 依次出栈其余节点，重新连接成链表
    while (!isEmpty()) {
        current->next = pop();
        current = current->next;
    }
    
    // 最后一个节点的next指针置为NULL
    current->next = NULL;
    
    return newHead;
}

/**
 * 打印链表
 * @param head 链表头节点
 */
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

/**
 * 释放链表内存
 * @param head 链表头节点
 */
void freeList(ListNode* head) {
    ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/**
 * 主函数 - 测试反转链表功能
 */
int main() {
    // 创建测试链表: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    
    printf("原始链表: ");
    printList(head);
    
    // 使用全局变量栈反转链表
    ListNode* reversedHead = reverseListWithGlobalStack(head);
    
    printf("反转链表: ");
    printList(reversedHead);
    
    // 释放内存
    freeList(reversedHead);
    
    return 0;
}