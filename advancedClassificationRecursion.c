#include "NumClass.h"
int isPalindromeHelper(int,int,int);
int countDigits(int);
int isArmstrongHelper(int,int);

int isPalindrome(int num){
    int ogNum=num;
    return isPalindromeHelper(num,ogNum,0);
}

int isPalindromeHelper(int num, int ogNum, int revNum) {
    if (num == 0) {
        return ogNum == revNum;
    }
    int temp = num % 10;

    revNum = revNum * 10 + temp;

    return isPalindromeHelper(num / 10, ogNum, revNum);
}

int isArmstrong(int num){
    int c=countDigits(num);
    return num==isArmstrongHelper(num,c);
}

int countDigits(int num) {
    if (num == 0) {
        return 0;
    } else {
        return 1 + countDigits(num / 10);
    }
}

int isArmstrongHelper(int num, int n) {
    if (num == 0) {
        return 0;
    } else {
        int digit = num % 10;
        int result =1;
        for (int i = 0; i < n; ++i) {
            result*=digit;
        }

        return result+isArmstrongHelper(num/10,n);
    }
}