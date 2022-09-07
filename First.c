#include <stdio.h>
#include <stdlib.h>
#define size 5
struct stack{
    int t;
    int* s;
}*s1;

void initialize(){
    s1 -> s = malloc(size * sizeof(int));
    s1 -> t = -1;
}

void push(int b){
    if(s1 -> t == 4){
        //printf("Full\n");
    }
    else{
        s1 -> t ++;
        s1 -> s[s1 -> t] = b;
    }
}

int pop(){
    if(s1 -> t == -1){
        return -1;
    }
    else{
        s1 -> t--;
        return s1 -> s[s1 -> t + 1];
    }
}

int check(char s){
    if(s == '+' || s == '-' || s == '*' || s == '/' || s == '^'){
        return 1;
    }
    return 0;
}

void post(char arr[], int n){
    for(int i = 0; arr[i] != '\0'; i ++){
        if(check(arr[i]) == 0){
            push(arr[i] - '0');
        }
        else{
            int b = pop();
            int a = pop();
            if(arr[i] == '+'){
                push(a + b);
            }
            else if(arr[i] == '-'){
                push(a - b);
            }
            else if(arr[i] == '*'){
                push(a * b);
            }
            else if(arr[i] == '/'){
                push(a / b);
            }
        }
        
    }
}

int main(){
    s1 = (struct stack*)malloc(sizeof(struct stack));
    initialize();
    char a[5];
    scanf("%s", a);
    post(a, 5);
    printf("%d", pop());
    return 0;
}
