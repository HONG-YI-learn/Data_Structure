//通义：使用栈反转字符串（使用全局变量）
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// 定义栈结构
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

// 声明全局栈变量
Stack stack;

// 初始化栈
void initStack(void) {
    stack.top = -1;
}

// 判断栈是否为空
int isEmpty(void) {
    return stack.top == -1;
}

// 判断栈是否已满
int isFull(void) {
    return stack.top == MAX_SIZE - 1;
}

// 入栈操作
int push(char ch) {
    if (isFull()) {
        printf("Stack overflow!\n");
        return 0;
    }
    stack.data[++stack.top] = ch;
    return 1;
}

// 出栈操作
char pop(void) {
    if (isEmpty()) {
        printf("Stack underflow!\n");
        return '\0';
    }
    return stack.data[stack.top--];
}

// 使用栈实现字符串反转
void reverseString(char* str) {
    initStack();  // 初始化全局栈
    
    // 将字符串中的每个字符入栈
    for (int i = 0; i < strlen(str); i++) {
        push(str[i]);
    }
    
    // 从栈中依次弹出字符，实现反转
    for (int i = 0; i < strlen(str); i++) {
        str[i] = pop();
    }
}

int main() {
    char str[MAX_SIZE];
    
    printf("请输入一个字符串: ");
    fgets(str, sizeof(str), stdin);
    
    // 移除换行符（如果存在）
    str[strcspn(str, "\n")] = '\0';
    
    printf("原字符串: %s\n", str);
    
    // 反转字符串
    reverseString(str);
    
    printf("反转后字符串: %s\n", str);
    
    return 0;
}