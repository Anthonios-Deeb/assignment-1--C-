#include <stdio.h>
#include "NumClass.h"
int main(){
    int x,y;
    printf("enter a number for x:");
    scanf("%d",&x);
    printf("enter a number for y:");
    scanf("%d",&y);

    printf("The Armstrong numbers are:");
    for(int i=x;i<=y;i++){
        if(isArmstrong(i)){
            printf(" %d",i);
        }
    }
    printf("\nThe Palindromes are:"); 
    for(int i=x;i<=y;i++){
        if(isPalindrome(i)){
            printf(" %d",i);
        }
    }

    printf("\nThe Prime numbers are:");
    for(int i=x;i<=y;i++){
        if(isPrime(i)){
            printf(" %d",i);
        }
    }

    printf("\nThe Strong numbers are:");
    for(int i=x;i<=y;i++){
        if(isStrong(i)){
            printf(" %d",i);
        }
    }
    printf("\n");
}