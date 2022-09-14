#include <stdio.h>
#define size 5

struct cqueue{
    int *arr;
    int f;
    int r;
}*cq;
typedef struct cqueue q;
    
void initialize(){
    cq -> arr = malloc(size * sizeof(int));
    cq -> f = -1;
    cq -> r = -1;
}

void push(q *cq, int p){
    if ((cq -> r + 1) % size == cq -> f){
        printf("The queue is already full\n");
    }
    else{
        if(cq -> f == -1 && cq -> r == -1){
            cq -> f = 0;
            cq -> r = 0;
            cq -> arr[cq -> r] = p;
        }
        else{
            cq -> r = (cq -> r + 1) % size;
            cq -> arr[cq -> r] = p;
        }
    }
}

int pop(){
    if(cq -> f == -1 && cq -> r == -1){
        printf("The queue is empty");
        return -1;
    }
    else if(cq -> f == cq -> r){
        int temp = cq -> arr[cq -> f];
        cq -> f == -1;
        cq -> r == -1;
        return temp;
    }
    else{
        if(cq -> f + 1 == size){
            int temp = cq -> arr[cq -> f];
            cq -> f = cq -> f + 1;
            return temp;
        }
        cq -> f = (cq -> f + 1) % size;
        return cq -> arr[cq -> f - 1];
    }
}

void main(){
        cq = (q *)malloc((sizeof(q)));
        initialize();
        for(int i = 0; i < 5; i ++){
            int a;
            scanf("%d", &a);
            push(cq, a);
        }
        for(int i = 0; i < 5; i ++){
            printf("%d ", pop());
        }
    }
