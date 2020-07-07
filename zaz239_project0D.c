#include <stdio.h>

void printMultTableInt(int n);
void printMultTableFrac(int n);

int main(void){

    // You can change this to test your code
    int size = 10;

    printMultTableInt(size);
    printMultTableFrac(size);

    return 0;

}

// Prints multiplication table of integers from 1 to n
void printMultTableInt(int n){

    //write code for part A here
    int column = 0;
    int row = 0;
    int number;


    while (column != n){
        column++;
        row = 0;
        while (row != n){
            row++;
            number = column * row;
            if (row == 1){
                printf("%d. ", number);
            }
            if (row == n){
                printf("%d\n", number);
            }
            if (row != 1 && row != n){
                printf("%d ", number);
            }
        }


    }

}

// Prints multiplication table for fractions from 1, 1/2, 1/3 to 1/n
void printMultTableFrac(int n){

    // WRITE CODE FOR PART B HERE
    int row1 = 0;
    int column1 = 0;
    double number1;
    while (column1 != n) {
        column1++;
        row1 = 0;
        while (row1 != n) {
            row1++;
            number1 = (column1 * row1);
            number1 = 1/number1;
            if (row1 == 1) {
                printf("%.2f. ", number1);
            }
            if (row1 == n) {
                printf("%.2f\n", number1);
            }
            if (row1 != 1 && row1 != n) {
                printf("%.2f ", number1);
            }
        }
    }
}
