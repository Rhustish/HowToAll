#include<stdio.h>

typedef struct Stack{

    int arr[__INT_MAX__];
    int top;

}Stack;

void peek(Stack st){
    if(st.top == -1) return -1;
    return st.arr[st.top];
}

int isempty(Stack st){
    if(st.top== -1 )return 1;
    return 0;
}

void pop(Stack st){
    if(st.top > -1) st.top--;
    return;
}

int size(Stack st){
    return st.top+1;
}

void push(Stack st , int data){
    st.top++;
    st.arr[st.top] = data;
}

int main(){
   Stack st;
   st.top = -1;

    printf("%d",size(st));

return 0;
}