#include "NumClass.h"
int countDigits(int);

int isPalindrome(int num){
    int temp = num;
    int revNum = 0;

    while (temp > 0) {
        int x = temp % 10;
        revNum = revNum * 10 + x;
        temp /= 10;
    }

    return num == revNum;
}

int isArmstrong(int num){
    int temp=num;
    int count=countDigits(num);
    int temp2=0;
    int sum=0; 

    while (temp!=0){
        temp2=temp%10;

        for(int i=0;i<count;i++){
            temp2=temp2*temp2;
        }

        sum=temp2+sum;
    }

    return num==sum;
}

int countDigits(int number) {
    int count = 0;

    if (number == 0) {
        return 1;
    }

    while (number != 0) {
        number /= 10; 
        count++;
    }

    return count;
}