#include "NumClass.h"
int factorial(int);

int isPrime(int x){
    for(int i=2;i<x;i++){
        if(x%i==0)
            return 0;
    }
    return 1;
}

int isStrong(int x){
    int temp=x;
    int count;
    int sum=0;

    while(temp!=0){
        count=temp%10;
        sum+=factorial(count);
        temp=temp/10;
    }

    return sum==x;
}

int factorial(int count){
    int sum=1;
    for (int i = 1; i <= count; i++){
        sum=sum*i;
    }
    return sum;
}