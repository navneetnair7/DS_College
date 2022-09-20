#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct queue{
    int index;
    int size;
    char* queue;
}*s;

int fnf(int A[5], int index)//finds next free spot
{
    int in = index + 1;
    while(1)
    {
        if(in == s->size)
        {
            in = 0;
        }
        if(in == index)
        {
            return -1;
        }
        if(A[in] == 0 && in<s->size)
        {
            return in;
        }
        in++;
    }
    return in;
}

int josephus(int size) {//takes size of circular array
    printf("Enter the value of k: ");
    int k;
    scanf("%d", &k);
    int count = size;
    int cur = 0; //pointer to next start in array
    int B[] = {0, 0, 0, 0, 0}; //zero in the array means use, 1 means ignore
    while(count>1)
    {
        for(int i = 0; i<k-1; i++)
        {
            cur = fnf(B, cur);
        }
        B[cur] = 1;
        count--;
        cur = fnf(B, cur);
    }
    return cur;
    
}
int main() {
    s = (struct queue*)malloc(sizeof(struct queue));
    s->size = SIZE;
    s->index = 0;
    s->queue = (char*) malloc(s->size * sizeof(char));
    for(int i = 0; i<5; i++){
        s->queue[i] = i;
    }
    fflush(stdin);
    printf("To survive one must be at index %d in circular array\n",josephus(s->size));
}