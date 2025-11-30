#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// 栈节点结构定义
// 用于表示栈中的每个元素，包含数据和指向下一个节点的指针
typedef struct StackNode {
    char data;                  // 存储括号字符
    struct StackNode* next;     // 指向下一个节点的指针
} StackNode;

// 栈结构定义
// 包含指向栈顶节点的指针
typedef struct Stack {
    StackNode* top;             // 指向栈顶节点的指针
} Stack;

// 创建一个新的空栈
// 返回值: 指向新创建栈的指针
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));  // 分配栈结构体内存
    stack->top = NULL;                             // 初始化栈顶为空
    return stack;
}

// 将元素压入栈中
// 参数: stack - 栈指针, item - 要压入的字符
void push(Stack* stack, char item) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));  // 创建新节点
    newNode->data = item;                                        // 设置节点数据
    newNode->next = stack->top;                                  // 新节点指向原栈顶
    stack->top = newNode;                                        // 更新栈顶为新节点
}

// 从栈中弹出元素
// 参数: stack - 栈指针
// 返回值: 栈顶元素，如果栈为空则返回'\0'
char pop(Stack* stack) {
    // 检查栈是否为空
    if (stack->top == NULL) {
        return '\0';  // 空栈返回空字符
    }
    
    StackNode* temp = stack->top;      // 保存当前栈顶节点
    char data = temp->data;            // 获取栈顶数据
    stack->top = stack->top->next;     // 更新栈顶为下一个节点
    free(temp);                        // 释放原栈顶节点内存
    return data;                       // 返回弹出的数据
}

// 检查栈是否为空
// 参数: stack - 栈指针
// 返回值: true表示栈为空，false表示栈不为空
bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// 判断两个括号是否匹配
// 参数: opening - 左括号, closing - 右括号
// 返回值: true表示匹配，false表示不匹配
bool isMatchingPair(char opening, char closing) {
    // 检查三种括号类型的匹配情况
    if (opening == '(' && closing == ')') return true;  // 圆括号匹配
    if (opening == '[' && closing == ']') return true;  // 方括号匹配
    if (opening == '{' && closing == '}') return true;  // 花括号匹配
    return false;  // 不匹配
}

// 检查括号字符串是否匹配
// 参数: expression - 待检查的括号表达式字符串
// 返回值: true表示所有括号都正确匹配，false表示存在不匹配
bool isBalanced(const char* expression) {
    Stack* stack = createStack();              // 创建一个空栈
    int length = strlen(expression);           // 获取表达式长度
    
    // 遍历表达式中的每个字符
    for (int i = 0; i < length; i++) {
        char current = expression[i];          // 获取当前字符
        
        // 如果是左括号，将其压入栈中
        if (current == '(' || current == '[' || current == '{') {
            push(stack, current);
        }
        // 如果是右括号
        else if (current == ')' || current == ']' || current == '}') {
            // 栈为空说明没有对应的左括号，出现不匹配
            if (isEmpty(stack)) {
                // 释放栈内存
                StackNode* node = stack->top;
                while (node != NULL) {
                    StackNode* temp = node;
                    node = node->next;
                    free(temp);
                }
                free(stack);
                return false;
            }
            // 弹出栈顶元素并检查是否与当前右括号匹配
            char top = pop(stack);
            if (!isMatchingPair(top, current)) {
                // 括号类型不匹配，释放剩余栈内存并返回false
                StackNode* node = stack->top;
                while (node != NULL) {
                    StackNode* temp = node;
                    node = node->next;
                    free(temp);
                }
                free(stack);
                return false;
            }
        }
        // 忽略其他非括号字符
    }
    
    // 检查是否还有未匹配的左括号
    bool result = isEmpty(stack);
    
    // 释放栈内存
    StackNode* node = stack->top;
    while (node != NULL) {
        StackNode* temp = node;
        node = node->next;
        free(temp);
    }
    free(stack);
    
    return result;  // 栈为空表示所有括号都已正确匹配
}

// 主函数 - 测试括号匹配功能
int main() {
    // 预定义的测试用例数组
    char* testCases[] = {
        "()",           // 简单匹配
        "()[]{}",       // 多种括号匹配
        "(]",           // 类型不匹配
        "([)]",         // 嵌套不匹配
        "{[()]}",       // 正确嵌套匹配
        "((()))",       // 多层圆括号匹配
        "({[]})",       // 复杂嵌套匹配
        "(",            // 缺少右括号
        ")",            // 缺少左括号
        ""              // 空字符串
    };
    
    // 计算测试用例数量
    int numTests = sizeof(testCases) / sizeof(testCases[0]);
    
    printf("括号匹配检查结果:\n");
    printf("==================\n");
    
    // 遍历所有测试用例并输出结果
    for (int i = 0; i < numTests; i++) {
        bool result = isBalanced(testCases[i]);  // 检查当前测试用例
        printf("表达式 \"%s\" -> %s\n", 
               testCases[i], 
               result ? "匹配" : "不匹配");  // 根据结果输出对应信息
    }
    
    // 提供交互式输入测试功能
    printf("\n请输入要检查的括号表达式 (输入 'quit' 退出): \n");
    char input[1000];  // 输入缓冲区
    
    // 循环接收用户输入直到输入"quit"
    while (1) {
        printf("> ");
        if (fgets(input, sizeof(input), stdin) != NULL) {  // 读取用户输入
            // 移除输入字符串末尾的换行符
            input[strcspn(input, "\n")] = 0;
            
            // 检查是否需要退出程序
            if (strcmp(input, "quit") == 0) {
                break;
            }
            
            // 检查输入表达式的括号匹配情况
            bool result = isBalanced(input);
            printf("结果: %s\n", result ? "匹配" : "不匹配");
        }
    }
    
    return 0;  // 程序正常结束
}