//通义：使用栈反转字符串（不使用全局变量）
#include <stdio.h>      // 标准输入输出库
#include <stdlib.h>     // 标准库函数
#include <string.h>     // 字符串处理函数

#define MAX_SIZE 100    // 定义栈的最大容量为100

// 定义栈结构体
typedef struct {
    char data[MAX_SIZE];  // 用于存储栈中元素的数组，最大可存储100个字符
    int top;              // 栈顶指针，指示当前栈顶元素的位置
} Stack;

// 初始化栈函数
// 参数：指向栈结构体的指针
void initStack(Stack* stack) {
    stack->top = -1;  // 将栈顶指针设置为-1，表示空栈状态
}

// 判断栈是否为空函数
// 参数：指向栈结构体的指针
// 返回值：1表示栈为空，0表示栈不为空
int isEmpty(Stack* stack) {
    return stack->top == -1;  // 当栈顶指针为-1时表示栈为空
}

// 判断栈是否已满函数
// 参数：指向栈结构体的指针
// 返回值：1表示栈已满，0表示栈未满
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;  // 当栈顶指针达到最大索引时表示栈满
}

// 入栈操作函数
// 参数：指向栈结构体的指针，要入栈的字符
// 返回值：1表示入栈成功，0表示入栈失败
int push(Stack* stack, char ch) {
    if (isFull(stack)) {           // 检查栈是否已满
        printf("Stack overflow!\n");  // 栈溢出提示
        return 0;                  // 入栈失败
    }
    // 先将栈顶指针加1，然后将字符存入新的栈顶位置
    stack->data[++stack->top] = ch;
    return 1;  // 入栈成功
}

// 出栈操作函数
// 参数：指向栈结构体的指针
// 返回值：返回出栈的字符，若栈空则返回'\0'
char pop(Stack* stack) {
    if (isEmpty(stack)) {          // 检查栈是否为空
        printf("Stack underflow!\n"); // 栈下溢提示
        return '\0';               // 返回空字符表示出栈失败
    }
    // 先取出当前栈顶元素，然后将栈顶指针减1
    return stack->data[stack->top--];
}

// 使用栈实现字符串反转函数
// 参数：要被反转的字符串指针
void reverseString(char* str) {
    Stack stack;              // 创建一个栈实例
    initStack(&stack);        // 初始化栈
    
    // 将字符串中的每个字符依次入栈
    // 遍历字符串，将每个字符压入栈中
    for (int i = 0; i < strlen(str); i++) {
        push(&stack, str[i]);  // 将第i个字符入栈
    }
    
    // 从栈中依次弹出字符，利用栈的后进先出特性实现字符串反转
    // 将出栈的字符重新填入原字符串数组中
    for (int i = 0; i < strlen(str); i++) {
        str[i] = pop(&stack);  // 将出栈的字符赋给字符串的第i个位置
    }
}

// 主函数
int main() {
    char str[MAX_SIZE];  // 创建用于存储输入字符串的字符数组
    
    printf("请输入一个字符串: ");      // 提示用户输入字符串
    fgets(str, sizeof(str), stdin);   // 从标准输入读取一行字符串
    
    // 移除fgets可能读入的换行符
    // strcspn返回str中第一个匹配"\n"的位置索引
    str[strcspn(str, "\n")] = '\0';   // 将换行符替换为字符串结束符
    
    printf("原字符串: %s\n", str);    // 输出原始字符串
    
    // 调用字符串反转函数
    reverseString(str);
    
    printf("反转后字符串: %s\n", str); // 输出反转后的字符串
    
    return 0;  // 程序正常退出
}