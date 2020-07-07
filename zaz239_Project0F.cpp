#include <stdio.h>
#include <stdlib.h>


//
// Created by zanez on 6/15/2020.
//
int gcd(int x, int y){
        int count = 1;
        int divisor;
        while (count <= x/2){
            if (x % count ==0){
                divisor = x /count;
                if (y % divisor == 0){
                    count = x;
                }else{
                    count++;
                }
            }else{
                count++;
            }

        }
        if (y % divisor != 0){
            divisor = 1;
        }
    printf("GCD of %d and %d is : %d\n", x, y, divisor);
};

int main (){
    gcd(48, 18);
    gcd(144, 60);
    gcd(65, 12);
    gcd(179, 7);
}
