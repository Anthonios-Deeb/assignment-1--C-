#include "NumClass.h"

int isPalindrome(int num, int ogNum, int revNum) {
    if (num == 0) {
        return ogNum == revNum;
    }
    int temp = num % 10;

    revNum = revNum * 10 + temp;

    return isPalindrome(num / 10, ogNum, revNum);
}

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int isStrong(int num) {
    return revNum(num,0,0);
}

int revNum(int ogNum,int temp,int sum){
    if(temp==0){
        return ogNum==sum;
    }
    sum=(temp%10)+sum*10;
    temp = temp/10;
    
   return revNum(ogNum,temp,sum);
}