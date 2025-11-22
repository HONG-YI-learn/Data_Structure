//通义：使用栈实现反转链表
#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct ListNode {
    int data;                 // 节点数据
    struct ListNode* next;    // 指向下一个节点的指针
} ListNode;

// 定义栈结构体
typedef struct Stack {
    ListNode** items;         // 存储节点指针的数组
    int top;                  // 栈顶指针
    int capacity;             // 栈的容量
} Stack;

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
 * 初始化栈
 * @param capacity 栈的容量
 * @return 初始化后的栈指针
 */
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    
    // 为栈中的节点指针数组分配内存
    stack->items = (ListNode**)malloc(capacity * sizeof(ListNode*));
    if (stack->items == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    
    stack->top = -1;          // 初始化栈顶指针为-1，表示空栈
    stack->capacity = capacity;
    return stack;
}

/**
 * 判断栈是否为空
 * @param stack 栈指针
 * @return 1表示空栈，0表示非空
 */
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

/**
 * 判断栈是否已满
 * @param stack 栈指针
 * @return 1表示栈满，0表示未满
 */
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

/**
 * 入栈操作
 * @param stack 栈指针
 * @param node 要入栈的节点指针
 */
void push(Stack* stack, ListNode* node) {
    if (isFull(stack)) {
        printf("栈溢出\n");
        return;
    }
    // 栈顶指针上移，将节点指针存入栈中
    stack->items[++stack->top] = node;
}

/**
 * 出栈操作
 * @param stack 栈指针
 * @return 出栈的节点指针
 */
ListNode* pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("栈为空\n");
        return NULL;
    }
    // 返回栈顶元素，并将栈顶指针下移
    return stack->items[stack->top--];
}

/**
 * 使用栈反转链表
 * @param head 原链表的头节点
 * @return 反转后链表的头节点
 */
ListNode* reverseListWithStack(ListNode* head) {
    // 如果链表为空或只有一个节点，直接返回
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // 首先计算链表长度，用于初始化栈的容量
    int length = 0;
    ListNode* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    
    // 创建与链表长度相同的栈
    Stack* stack = createStack(length);
    
    // 将链表的所有节点依次入栈
    current = head;
    while (current != NULL) {
        push(stack, current);
        current = current->next;
    }
    
    // 出栈的第一个节点作为新链表的头节点
    ListNode* newHead = pop(stack);
    current = newHead;
    
    // 依次出栈其余节点，重新连接成链表
    while (!isEmpty(stack)) {
        current->next = pop(stack);
        current = current->next;
    }
    
    // 最后一个节点的next指针置为NULL
    current->next = NULL;
    
    // 释放栈资源
    free(stack->items);
    free(stack);
    
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
    
    // 使用栈反转链表
    ListNode* reversedHead = reverseListWithStack(head);
    
    printf("反转链表: ");
    printList(reversedHead);
    
    // 释放内存
    freeList(reversedHead);
    
    return 0;
}