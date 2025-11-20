// 栈的数组实现
#include<stdio.h>
#define Max_Size 101  // 定义栈的最大容量为101

int A[Max_Size];      // 创建数组A作为栈的存储空间
int top = -1;         // 初始化栈顶指针为-1，表示空栈

// 入栈操作：向栈中添加一个元素
void Push(int data){
    // 检查栈是否已满
    if(top == Max_Size - 1){
        printf("栈已满，无法执行");
        return;  // 栈满则返回，不执行入栈操作
    }
    // 将栈顶指针加1，然后将数据存入栈顶位置
    A[++top] = data;
}

// 出栈操作：从栈中移除一个元素
void Pop(){
    // 检查栈是否为空
    if(top == -1){
        printf("空栈，无法执行");
        return;  // 栈空则返回，不执行出栈操作
    }
    // 将栈顶指针减1，实现元素的删除（逻辑删除）
    top--;
}

// 获取栈顶元素：返回栈顶元素但不删除它
int Top(){
    return A[top];  // 直接返回栈顶元素
}

// 打印栈中所有元素
void Print(){
    printf("Stack: ");
    // 遍历从索引0到top的所有元素并打印
    for(int i = 0 ; i <= top ; i++){
        printf("%d " , A[i]);
    }
    printf("\n");
}

// 主函数：测试栈的各种操作
int main(void){
    Push(9);Print();   // 入栈9并打印
    Push(8);Print();   // 入栈8并打印
    Pop();Print();     // 出栈一次并打印
    Push(6);Print();   // 入栈6并打印
    Push(7);Print();   // 入栈7并打印
    Pop();Print();     // 出栈一次并打印
    Push(1);Print();   // 入栈1并打印
    printf("top is %d\n" , Top());  // 打印当前栈顶元素
    
    return 0;  // 程序正常结束
}