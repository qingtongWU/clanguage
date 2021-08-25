#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//结点结构体定义
typedef struct node_s{
    int data;
    struct node_s *next;
}Node_t,*pNode_t;

//栈的结构体定义
typedef struct stack_s{
    int size;
    pNode_t head;//栈顶指针
}Stack_t,*pStack_t;

//栈的初始化
void init(pStack_t pstack){
    memset(pstack, 0, sizeof(Stack_t));
}

//栈的大小
int size(pStack_t pstack){
    return pstack->size;
}

//栈空
int isEmpty(pStack_t pstack){
    return pstack->size == 0;
}

//入栈
void push(pStack_t pstack, int val){
    pNode_t newNode = (pNode_t)calloc(1, sizeof(Node_t));//申请新的节点空间
    newNode->data = val;//数据域
    newNode->next = pstack->head;//指针域

    pstack->head = newNode;//改变栈顶指针
    ++pstack->size;
}

//出栈
void pop(pStack_t pstack){
    if(isEmpty(pstack)){ //判空
        fprintf(stderr, "stack is empty\n");
        return;
    }

    pNode_t cur = pstack->head;//临时指针暂存栈顶指针
    pstack->head = cur->next;//修改栈顶指针
    free(cur);
    cur = NULL;
    --pstack->size;
}

//打印栈顶元素
int top(pStack_t pstack){
    if(isEmpty(pstack)){
        fprintf(stderr, "stack is empty\n");
        return -1;
    }
    return pstack->head->data;
}

//打印所有栈内元素
void print(pStack_t pstack){
    pNode_t cur = pstack->head;
    while(cur){
        printf("%3d", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

//测试函数
void test(){
    Stack_t stack;
    init(&stack);
    for(int i = 0; i < 5; ++i){
        push(&stack, i);
        print(&stack);
    }
    for(int i = 0; i < 6; ++i){
        printf("top = %d\n",top(&stack));
        pop(&stack);
        print(&stack);
    }
}
int main(){
    test();
    return 0;
}
